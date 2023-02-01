#include <iostream>

class Node {    
private:
    Node* anterior;
    int value;
    Node* prox;
public:
    Node (int value) {
        this->anterior = NULL;
        this->value = value;
        this->prox = NULL;
    }

    int obterValor() {
        return value;
    }
     
    Node* obterProx() {
        return prox;
    }

    Node* obterAnterior() {
        return anterior;
    }

    void setAnterior(Node* a) {
        this->anterior = a;
    }

    void setProx(Node* p) {
        this->prox = p;
    }

 };

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    List(int value) {
        head = new Node(value);
        tail = head;
    }

    virtual ~List() {
        delete head;
    }

    void showElementsReverse() {
        std::cout << "\nImprimindo todos os elementos ao contrario ...\n";
        Node* t = tail;

        if (isEmpty()) {
            std::cout << "A lista não possui elementos.";
        }
        else {
            while (t) {
                std::cout << t->obterValor() << std::endl;
                t = t->obterAnterior();
            }
            std::cout << std::endl;
        }

    }

    void showElements() {
        std::cout << "\nImprimindo todos os elementos...\n";
        Node* h = head;

        if (isEmpty()) {
            std::cout << "A lista não possui elementos.";
        }
        else {
            while (h) {
                std::cout << h->obterValor() << std::endl;
                h = h->obterProx(); 
            }
            std::cout << std::endl;
        }

    }

    bool isEmpty() {
        return head == NULL;
    }

    void inserirInicio(int value) {
        Node* newNode = new Node(value);
        newNode->setProx(head);
        head = newNode;
    }

    void inserirFinal(int value) {
        Node* newNode = new Node(value);
        Node* last = this->tail;
        
        if (isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }

        while (tail->obterProx() != NULL) {
            last = this->tail->obterProx();
        }
        
        last->setProx(newNode);
        newNode->setAnterior(last);
        tail = newNode;
    }
    
    int size() {
        if (isEmpty()) {
            return 0;
        }
        Node* h = head;
        int tam = 0;
        do {
            h = h->obterProx();
            tam++;
        } while (h);
    }

    bool exists(int value) {
        Node* h = head;
        while (h) {
            if (h->obterValor() == value) {
                return true;
            }
            h = h->obterProx();
        }
    }

    void deleteElement() { // do final
        if (!isEmpty()) {
            if (head->obterProx() == NULL) {
                head = NULL;
            }
            else if (head->obterProx()->obterProx() == NULL) {
                head->setProx(NULL);
            }
            else {
                Node* antAnt = head;
                Node* ant = head->obterProx();
                Node* corrente = head->obterProx()->obterProx();

                while (corrente) {
                    Node* aux = ant;
                    ant = corrente;
                    antAnt = aux;
                    corrente = corrente->obterProx();
                }

                delete antAnt->obterProx();
                antAnt->setProx(NULL);
                tail = antAnt;
            }
        }
    }
};

int main()
{
    List l;
    l.inserirFinal(10);
    l.inserirFinal(11);
    l.inserirFinal(12);
    l.inserirFinal(13);
    l.inserirFinal(14);
    l.inserirFinal(15);

    if (l.isEmpty()) {
        std::cout << "Lista vazia";
    }
    else {
        std::cout << "Lista nao esta vazia";
        l.showElementsReverse();
    }
}
