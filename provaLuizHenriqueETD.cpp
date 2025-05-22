//Prova 1  estrutura de dados

#include<iostream>
#include<cstring>

using namespace std;

// 2 BST com meses do ano ordenada alfabeticamente
struct NoBST {
    string nome;
    NoBST* dir;
    NoBST* esq;
};

NoBST* start(){
    return nullptr;
}

//pelo menos isso esta correto
void inserir_mes(NoBST*& root, string nome_mes){
    if (root == nullptr) // Se a árvore estiver vazia
    {
        root = new NoBST; // Cria um novo nó
        if(nome_mes == "novembro"){
            root->nome = nome_mes + " (parabens para mim)"; // faço aniversário em novembro no caso
        } else {
        root->nome = nome_mes; // Atribui o nome ao nó
        } 
        root->esq = nullptr; // Inicializa o filho esquerdo como nulo
        root->dir = nullptr; // Inicializa o filho direito como nulo
    }
    else if (nome_mes < root->nome) // Se o valor for menor que o valor do nó atual
    {
        inserir_mes(root->esq, nome_mes); // Adiciona à subárvore esquerda
    }
    else if (nome_mes > root->nome) // Se o valor for maior que o valor do nó atual
    {
        inserir_mes(root->dir, nome_mes); // Adiciona à subárvore direita
    }
}

// nao esta alfabetico
void exibir_em_ordem(NoBST*& root){
        if (root != nullptr) // Se o nó não for nulo
    {
        exibir_em_ordem(root->esq); // Visita a subárvore esquerda
        cout << root->nome << ", "; // Imprime o valor do nó atual
        exibir_em_ordem(root->dir); // Visita a subárvore direita
    }
        //nao sei o que fazer para por em ordem alfabetica
}

// eu até tentei chegar em algum lugar, mas como eu ja espera eu nao consegui resolver nada e desisti de tudo que eu fiz (e nao funcionou) pra ficar comentando
void exibir_pre_ordem(NoBST*& root){
    if (root != nullptr) {
        cout << root->nome + ", ";
        exibir_pre_ordem(root->esq);
        exibir_pre_ordem(root->dir);
    }
}

//1 verificador de palindromos
/*
    1-> O programa solicita palavras de tamanho ímpar;
    2-> Deve ter as seguintes funções:
       -  inserir_inicio(elemento)
       -  inserir_fim(elemento)
       -  remover_inicio()
       -  remover_fim()
    3-> Recomendado o uso de lista duplamente encadeada
 */

/*  RACIOCÍNIO 
 A lógica é simples, se a palavra for exatamente igual a ela mesma ao contrario, para fazer essa comparação se usaria a lista eu imagino, então ela é um palíndromo, caso contrario não é,
 como as palavras: ovo e arara por exemplo; Não sei como se implementa isso.
*/

 struct DuplamenteEncadeada
{
    int valor;
    DuplamenteEncadeada* ant;
    DuplamenteEncadeada* prox;
};

void inserir_inicio(string/*? nao se nem qual tipo de dado deve ser usado aqui*/ elemento){
    //nao sei pra que se usa essa função
}

void inserir_fim(string/*? nao se nem qual tipo de dado deve ser usado aqui*/ elemento){
    //tambem nao sei essa
}

void remover_inicio();//remove o inicio porque? nao entendo nada do que esta acontecendo

void remover_fim();


// 3

struct No {
    int chave;
    int bal; // Balanceamento do nó (-1, 0, 1)
    No* esq;
    No* dir;
};

// Função para criar um novo nó
No* criarNo(int chave) {
    No* novo = new No;
    novo->chave = chave;
    novo->bal = 0;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Rotação simples à esquerda
No* rotacaoL(No* p) {
    No* u = p->esq;
    if (u->bal == -1) { // Rotação LR 
        cout << "Rotação LR necessária" << endl;
        No* v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if (v->bal == -1) 
            p->bal = 1;
        else 
            p->bal = 0;

        if (v->bal == 1) 
            u->bal = -1;
        else 
            u->bal = 0;

        v->bal = 0;

        return v;
    }
    // Rotação LL
    cout << "Rotação LL necessária" << endl;
    p->esq = u->dir;
    u->dir = p;
    p->bal = 0;
    u->bal = 0;
    return u;
}

// Rotação simples à direita
No* rotacaoR(No* p) {
    No* u = p->dir;
    if (u->bal == 1) { // Rotação RL
        cout << "Rotação RL Necessária" << endl;
        No* v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->bal == 1) 
            p->bal = -1;
        else 
            p->bal = 0;

        if (v->bal == -1) 
            u->bal = 1;
        else 
            u->bal = 0;

        v->bal = 0;

        return v;
    }
    // Rotação RR
    cout << "Rotação RR necessária" << endl;
    p->dir = u->esq;
    u->esq = p;
    p->bal = 0;
    u->bal = 0;
    return u;
}

// Função para inserir um nó na árvore AVL
No* inserir(No* raiz, int chave, bool& cresceu) {
    // Verifica se a árvore está vazia
    // Se estiver, cria um novo nó e retorna
    if (raiz == nullptr) {
        cresceu = true;
        return criarNo(chave);
    }

    // Se a chave for menor que a chave do nó atual, insere na subárvore esquerda
    if (chave < raiz->chave) {
        // Chama a função recursivamente para inserir na subárvore esquerda
        raiz->esq = inserir(raiz->esq, chave, cresceu);
        // Verifica se houve crescimento na subárvore esquerda
        if (cresceu) {
            // Atualiza o fator de balanceamento do nó atual
            // Se o fator de balanceamento for 1, faz uma rotação à esquerda
            if (raiz->bal == 1) {
                raiz = rotacaoL(raiz);
                cresceu = false;
            } else if (raiz->bal == 0) {
                raiz->bal = 1;
            } else if (raiz->bal == -1){
                raiz->bal = 0;
            }
        }
    } 
    // Se a chave for menor que a chave do nó atual, insere na subárvore direita
    else if (chave > raiz->chave) {
        // Chama a função recursivamente para inserir na subárvore direita
        raiz->dir = inserir(raiz->dir, chave, cresceu);
        // Verifica se houve crescimento na subárvore direita
        if (cresceu) {
            // Atualiza o fator de balanceamento do nó atual
            // Se o fator de balanceamento for -1, faz uma rotação à direita
            if (raiz->bal == -1) {
                raiz = rotacaoR(raiz);
                cresceu = false;
            } else if (raiz->bal == 0) {
                raiz->bal = -1;
            } else if (raiz->bal == 1){
                raiz->bal = 0;
            }
        }
    }
    return raiz;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        imprimirEmOrdem(raiz->esq);
        cout << raiz->chave << " ";
        imprimirEmOrdem(raiz->dir);
    }
}

int main(void){
    //2
    NoBST* root = start();
    No* raiz = nullptr;
    bool cresceu = false;


    inserir_mes(root, "janeiro");
    inserir_mes(root, "maio");
    inserir_mes(root, "abril");
    inserir_mes(root, "novembro");
    
    //exibe em ordem ALFABETICA
    exibir_em_ordem(root);

    cout << endl;
    cout << endl;
    cout << endl;

    //
    exibir_pre_ordem(root);

//-----------------------------------------------------
    //3
    
    inserir(raiz, 30, cresceu);
    inserir(raiz, 29, cresceu);
    inserir(raiz, 33, cresceu);
    inserir(raiz, 6, cresceu);
    inserir(raiz, 24, cresceu);
    inserir(raiz, 11, cresceu);
    inserir(raiz, 20, cresceu);
    inserir(raiz, 05, cresceu);

    // 30, 29, 33, 6, 24, 11, 20, 05 já foram inseridos
    //CJ3029336
    //24/11/2005

    //inserindo +3 numeros inteiros
    inserir(raiz, 12, cresceu); 
    inserir(raiz, 50, cresceu);
    inserir(raiz, 47, cresceu);
    imprimirEmOrdem(raiz);
    return 0;
}

//nao da tempo de fazer mais nada, não sei porque o 3 nao esta funcionando, nao consegui fazer o 1;
//não esta sendo a coisa mais facil do mundo acompanhar essa materia afinal tem que estar muito focado nisso para nao se embaralhar com esses algoritmos de arvores;
//atualmente eu trabalho em 6x1 fora da área também (não que justifique alguma coisa, mas por esse motivo eu ja esperava ter dificuldade nessa avaliação pratica)
//tenho esperança de me sair melhor amanha na acaliação teorica