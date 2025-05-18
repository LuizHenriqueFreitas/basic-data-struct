#include<iostream>
using namespace std;

//atividade 1

//declarando estrutura simples duplamente encadeada usada no exercício 1
struct Lista2Encadeada
{
    int value;
    Lista2Encadeada* previus;
    Lista2Encadeada* next;
};

//função para inserir elementos em uma FILA de elementos
void QueueAddItem(Lista2Encadeada*& head, int value)
{
    Lista2Encadeada* newData = new Lista2Encadeada{value, nullptr, nullptr};

    if(head == nullptr)
    {
        head = newData;
    } else {
        Lista2Encadeada* temp = head;
        while (temp->next != nullptr)
        {
            temp->previus = temp;
            temp = temp->next;
        }
        temp->next = newData;
    }
}
//função para exclusão de uma FILA de elementos | Pela forma que esta escrito na pergunta eu entendi que é pra limpar a fila inteira
void QueueDelete(Lista2Encadeada* head)
{
    while(head != nullptr)
    {
        head = head->next;
    }
    cout << "Fila vazia!";
}

//adicionando elementos a uma PILHA
void StackAddItem(Lista2Encadeada*& top, int value)
{
    Lista2Encadeada* temp = new Lista2Encadeada;
    temp->value = value;
    temp->previus = top;
    temp->next = nullptr;

    if(top != nullptr)
    {
        top->next = temp;
    }

    top = temp;
}
//Excluindo completamente uma PILHA
void StackDelete(Lista2Encadeada*& top)
{
    Lista2Encadeada* temp = top;
    while(top != nullptr)
    {
        top = top->previus;
        top->next = nullptr;
    }
    delete temp;
}

//----------------------------------------------------------------------------------

//atividade 2
//declarando nó de árvore binária
struct BinaryNODE 
{
    int value;
    BinaryNODE* right;
    BinaryNODE* left;
};

//declarando nó de árvore N-área
struct NareaNODE
{
    int value;
    NareaNODE* son;
    NareaNODE* next;
};

//declarando nó de árvore AVL
struct AVL_NODE
{
    int key;
    int balance;
    AVL_NODE* left;
    AVL_NODE* right;
};

//----------------------------------------------------------------------------------

//exercício 3 -> apenas verifica o TIPO de rotação necessária em determinada situação
void Verefy_AVL_Rotation()
{
    // ao inves de um int aqui acho que seria mais correto usar o atributo "Value" nos nós da arvore AVL em questão, mas não irei me apronfundar nisso aqui pois me resta pouco tempo para entregar esta atividade
    int root, second, outher;

    if ((second > root and outher < root) or (second < root and outher > root))
    {
        cout << "Balanceado, sem rotacionamento.";
    } else if (second < root and outher < second) {
        cout << "Necessita-se de rotacionamento LL.";
    } else if (second > root and outher > second) {
        cout << "Necessita-se de rotacionamento RR.";
    } else if (second < root and (outher > second and outher < root)) {
        cout << "Necessita-se de rotacionamento LR.";
    } else if (second > root and (outher < second and outher > root)) {
        cout << "Necessita-se de rotacionamento RL.";
    } else {
        cout << "Incorreto.";
    }
}