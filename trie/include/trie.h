#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>

struct Node {
    bool is_EndOfWord = false;
    int counter = 0;
    std::map<char, Node*> children;
};

class trie
{
    public:
        trie();
        virtual ~trie();
        void add(std::string word);
        bool seek(std::string word);
        int occurances(std::string word);
        void traverse();

    protected:
        struct Node *newNode(void);

    private:
        Node *root;
        void _traverse(std::string const& prefix, Node const& n);
};

#endif // TRIE_H
