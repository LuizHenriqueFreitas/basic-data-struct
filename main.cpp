#include<iostream>
#include<stack> // Para a exibição reversa
#include<queue> // Para a exibição em largura
using namespace std;

struct NODE 
{
    int value;
    NODE* right;
    NODE* left;
};

// Inicializa a árvore
NODE* Start()
{
    return nullptr;
}

// Adiciona um nó recursivamente
void AddItem(NODE*& root, int NewValue)
{
    if(root == nullptr){
        root = new NODE;
        root->value = NewValue;
        root->right = nullptr;
        root->left = nullptr;
        cout << root->value << " adicionado!" << endl;
    }
    else if(root->value > NewValue)
    {
        AddItem(root->left, NewValue);
    }
    else if(root->value < NewValue)
    {
        AddItem(root->right, NewValue);
    }
}

// Adiciona um nó interativamente
void InterativeSearch(NODE* root, int WhereValue)
{
    while (root != nullptr && root->value != WhereValue)
    {
        if(root->value > WhereValue)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if(root == nullptr)
    {
        cout << "Valor NAO encontrado!" << endl;  
        return;  
    }
    else
    {
        cout << "Valor encontrado!" << endl;
    }
}

// Conta o número de nós na árvore
int CountThree(NODE* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        return CountThree(root->left) + CountThree(root->right) + 1;
    }
}

// Exibe a árvore em ordem (esquerda, raiz, direita)
void ShowInOrder(NODE* root)
{
    if(root == nullptr)
    {
        return;
    }
    ShowInOrder(root->left);
    cout << root->value << " ";
    ShowInOrder(root->right);
}

// Exibe a árvore em ordem reversa (direita, raiz, esquerda) de forma iterativa
void ShowReverseOrder(NODE* root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<NODE*> nodeStack;
    NODE* current = root;

    while (!nodeStack.empty() || current != nullptr)
    {
        while (current != nullptr)
        {
            nodeStack.push(current);
            current = current->right;
        }

        current = nodeStack.top();
        nodeStack.pop();
        cout << current->value << " ";
        current = current->left;
    }
}

// Exibe a árvore em pré-ordem (raiz, esquerda, direita)
void ShowPreOrder(NODE* root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root->value << " ";
    ShowPreOrder(root->left);
    ShowPreOrder(root->right);
}

// Exibe a árvore em pós-ordem (esquerda, direita, raiz)
void ShowPostOrder(NODE* root)
{
    if(root == nullptr)
    {
        return;
    }
    ShowPostOrder(root->left);
    ShowPostOrder(root->right);
    cout << root->value << " ";
}

// Exibe a árvore em largura, de cima para baixo e da esquerda para a direita
void ShowLevelOrder(NODE* root)
{
    if(root == nullptr)
    {
        return;
    }

    queue<NODE*> nodeQueue;
    nodeQueue.push(root);

    while(!nodeQueue.empty())
    {
        NODE* current = nodeQueue.front();
        nodeQueue.pop();
        cout << current->value << " ";

        if(current->left != nullptr)
        {
            nodeQueue.push(current->left);
        }
        if(current->right != nullptr)
        {
            nodeQueue.push(current->right);
        }
    }
}

// Remove nós recursivamente
void RecursiveRemoveItem(NODE*& root, int value)
{
    if(root == nullptr)
    {
        return;
    }
    else if(value < root->value)
    {
        RecursiveRemoveItem(root->left, value);
    }
    else if(value > root->value)
    {
        RecursiveRemoveItem(root->right, value);
    }
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr)
        {
            NODE* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            NODE* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            NODE* temp = root->right;
            while(temp->left != nullptr)
            {
                temp = temp->left;
            }
            root->value = temp->value;
            RecursiveRemoveItem(root->right, temp->value);
        }
    }
}

// Remove nós iterativamente
void InterativeRemoveItem(NODE*& root, int value)
{
    NODE* parent = nullptr;
    NODE* current = root;

    while (current != nullptr && current->value != value)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == nullptr)
    {
        cout << "Valor nao encontrado!" << endl;
        return;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (current == root)
        {
            root = nullptr;
        }
        else if (parent->left == current)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete current;
    }
    
    else if (current->left == nullptr || current->right == nullptr)
    {
        NODE* child = (current->left != nullptr) ? current->left : current->right;

        if (current == root)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete current;
    }
    
    else
    {
        NODE* successorParent = current;
        NODE* successor = current->right;

        while (successor->left != nullptr)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->value = successor->value;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }
        delete successor;
    }
}

int main()
{
    NODE* root = Start();

    AddItem(root, 25);
    AddItem(root, 15);
    AddItem(root, 35);
    AddItem(root, 30);
    AddItem(root, 5);
    AddItem(root, 40);
    AddItem(root, 55);
    AddItem(root, 60);

    InterativeSearch(root, 40);
    InterativeSearch(root, 27);

    CountThree(root);
    cout << endl;

    cout << "Em-ordem: ";
    ShowInOrder(root);
    cout << endl;
    cout << "Ordem-Reversa: ";
    ShowReverseOrder(root);
    cout << endl;
    cout << "Pre-Ordem: ";
    ShowPreOrder(root);
    cout << endl;
    cout << "Pos-Ordem: ";
    ShowPostOrder(root);
    cout << endl;
    cout << "Exibicao em Largura: ";
    ShowLevelOrder(root);
    cout << endl;
    cout << endl;

    cout << endl << "Removendo 25 recursivamente:  ";
    RecursiveRemoveItem(root, 25);
    ShowPreOrder(root);
    cout << endl << endl << "Removendo 55 iterativamente:  ";
    InterativeRemoveItem(root, 55);
    ShowPreOrder(root);
    cout << endl << endl;

    return 0;
}