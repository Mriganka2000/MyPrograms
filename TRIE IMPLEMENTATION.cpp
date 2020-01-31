#include <iostream>
#define SIZE 58

class Trie;

class Node
{
private:
    bool endOfWord;
    Node *charecter[SIZE];
    friend Trie;
};

class Trie
{
    bool isEmpty(Node *root)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(root->charecter[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
public:
    Node *create()
    {
        Node *newnode = new Node();
        for(int i = 0; i < SIZE; i++)
        {
            newnode->charecter[i] = NULL;
        }
        newnode->endOfWord = false;
        return newnode;
    }
    void insert(Node *root, std::string key)
    {
        Node *ptr = root;
        for(int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'A';
            if(ptr->charecter[index] == NULL)
            {
                ptr->charecter[index] = create();
            }
            ptr = ptr->charecter[index];
        }
        ptr->endOfWord = true;
    }
    bool search(Node *root, std::string key)
    {
        Node *ptr = root;
        for(int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'A';
            if(ptr->charecter[index] == NULL)
            {
                return false;
            }
            ptr = ptr->charecter[index];
        }
        return (ptr != NULL && ptr->endOfWord);
    }
    Node * deleteNode(Node *root, std::string key, int depth = 0)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(depth == key.size())
        {
            if(root->endOfWord == true)
            {
                root->endOfWord = false;
            }
            if(isEmpty(root))
            {
                delete(root);
                root = NULL;
            }
            return root;
        }
        int index = key[depth] - 'A';
        root->charecter[index] = deleteNode(root->charecter[index], key, depth+1);
        if(isEmpty(root) && root->endOfWord == false)
        {
            delete(root);
            root = NULL;
        }
        return root;
    }
};

int main()
{
    Trie obj;
    std::string name;
    std::string deleteName;
    char option;
    std::string key[] = {"Mriganka", "Mriganavhi", "Mrinal", "Souvik", "Sourav", "z"};
    int n = sizeof(key) / sizeof(key[0]);
    Node *root = obj.create();
    for(int i = 0; i < n; i++)
    {
        obj.insert(root, key[i]);
    }
    do
    {
        std::cout << "Enter the name to delete :- ";
        std::cin >> deleteName;
        obj.deleteNode(root,deleteName);
        std::cout << "Do you wish to continue y or n ? ";
        std::cin >> option;
    }while(option != 'n');

    do
    {
        std::cout << "Enter the name to search :- ";
        std::cin >> name;
        obj.search(root, name)? std::cout << "Yes present\n" : std::cout << "Not present \n";
        std::cout << "Do you wish to continue y or n ? ";
        std::cin >> option;
    }while(option != 'n');
}
