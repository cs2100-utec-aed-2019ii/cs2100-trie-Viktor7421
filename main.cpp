#include <iostream>

#define CHAR_SIZE 128

class TrieNode
{
public:
    bool is_node;
    TrieNode* children[CHAR_SIZE];

    TrieNode()
    {
        this->is_node = false;

        for (int i = 0; i < CHAR_SIZE; i++)
            this->children[i] = nullptr;
    }

    void insert(std::string palabra)
    {
        TrieNode* curr = this;
        for (int i = 0; i < palabra.length(); i++)
        {
            if (curr->children[palabra[i]] == nullptr)
                curr->children[palabra[i]] = new TrieNode();

            curr = curr->children[palabra[i]];
        }

        curr->is_node = true;
    }
    bool deletion(TrieNode*& curr, std::string key)
    {
        if (curr == nullptr)
            return false;

        if (key.length())
        {

            if (curr != nullptr &&
                curr->children[key[0]] != nullptr &&
                deletion(curr->children[key[0]], key.substr(1)) &&
                curr->is_node == false)
            {
                if (!haveChildren(curr))
                {
                    delete curr;
                    curr = nullptr;
                    return true;
                }
                else {
                    return false;
                }
            }
        }

        if (key.length() == 0 && curr->is_node)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;

                return true;
            }

            else
            {
                curr->is_node = false;

                return false;
            }
        }

        return false;
    }
    bool search(std::string key)
    {
        if (this == nullptr)
            return false;

        TrieNode* curr = this;
        for (int i = 0; i < key.length(); i++)
        {
            curr = curr->children[key[i]];

            if (curr == nullptr)
                return false;
        }

        return curr->is_node;
    }
    bool haveChildren(TrieNode const* curr)
    {
        for (int i = 0; i < CHAR_SIZE; i++)
            if (curr->children[i])
                return true;

        return false;
    }
};

int main()
{
    TrieNode tries;
    tries.insert("hola");
    std::cout << tries.search("hols");
    std::cout << tries.search("hola");

    return 0;
}