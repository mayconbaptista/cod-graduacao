#include <string>
#include <iostream>
#include <string>
#include <queue>

#ifndef ABBTreeBIN_HPP
#define ABBTreeBIN_HPP

#define OUT_NOT_MEMORY -3
#define ELEMENT_NOT_FOUND -2
#define INVALID_POINTER -1  
#define ERROR 0
#define SUCCESS 1


class Node
{
    public:
        int key;
        std::string info;
        Node *esq;
        Node *dir;

        Node (int key, std::string info);
        ~Node();
};

Node::Node (int key, std::string info)
{
    this->key = key;
    this->info = info;
    this->esq = nullptr;
    this->dir = nullptr;
}

Node::~Node()
{

}


class ABBTree
{
    private:
        Node *raiz;
        uint size;
    
    public:
        ABBTree(void);
        int insert(int key, std::string info);
        void clear();
        void in (void);
        void pre (void);
        void pos (void);
        void nivel(void);
        int sizeNodes();
        ~ABBTree();
};

void limpa (class Node *node)
{
    if(node != nullptr)
    {
        limpa(node->esq);
        limpa(node->dir);
        delete node;
        node = nullptr;
    }
}

void ABBTree::clear (void)
{
    limpa(this->raiz);
    this->size = 0;
}

// constructor e descructors

ABBTree::ABBTree()
{
    this->raiz = nullptr;
    this->size = 0;
}

ABBTree::~ABBTree()
{
    limpa(this->raiz);
    this->raiz = nullptr;
    this->size = 0;
}


int ABBTree::insert (int key, std::string info)
{
    Node *aux , *novo = new Node(key, info);

    if(novo == nullptr)
        return OUT_NOT_MEMORY;
    else if (this->raiz == nullptr)
    {
        this->raiz = novo;
    }
    else
    {
        aux = this->raiz;

        while(aux != nullptr)
        {
            if(key < aux->key)
            {
                if(aux->esq == nullptr)
                {
                    aux->esq = novo;
                    break;
                }
                else
                    aux = aux->esq;
            }
            else if(key > aux->key)
            {
                if(aux->dir == nullptr)
                {
                    aux->dir = novo;
                    break;
                }
                else
                    aux = aux->dir;
            }
            else
            {
                delete novo;
                return ERROR;
            }
        }
    }
    this->size++;
    return SUCCESS;
}

void pre_order (Node *raiz)
{
    if(raiz != nullptr)
    {
        std::cout << " " << raiz->key;
        pre_order(raiz->esq);
        pre_order(raiz->dir);
    }
}

void ABBTree::pre (void)
{
    std::cout << "Pre.:";
    pre_order(this->raiz);
    std::cout<<std::endl;
}

void in_order (Node *raiz)
{
    if(raiz != nullptr)
    {
        in_order(raiz->esq);
        std::cout << " " << raiz->key;
        in_order(raiz->dir);
    }
}

void ABBTree::in (void)
{
    std::cout << "In..:";
    in_order(this->raiz);
    std::cout << std::endl;
}

void pos_order (Node *raiz)
{
    if(raiz != nullptr)
    {
        pos_order(raiz->esq);
        pos_order(raiz->dir);
        std::cout << " " << raiz->key;
    }
}

void ABBTree::pos (void)
{
    std::cout << "Post:";
    pos_order(this->raiz);
    std::cout << std::endl;
}

void ABBTree::nivel (void)
{
    if(this->raiz == nullptr) return;

    std::queue <Node*> fila;
    Node *aux;

    fila.push(this->raiz);

    while(!fila.empty())
    {
        aux = fila.front();
        fila.pop();

        std::cout << aux->key << ' ';


        if(aux->esq != nullptr)
            fila.push(aux->esq);
        if(aux->dir != nullptr)
            fila.push(aux->dir);
    }
}// testado okay


// funções lista de exe de arvores

int contaNos (Node *raiz)
{
    if(raiz != nullptr)
    {
        contaNos(raiz->esq);
        contaNos(raiz->dir);
        return 1;
    }
    return 0;
}

int ABBTree::sizeNodes (void)
{
    return contaNos(this->raiz);
}

#endif