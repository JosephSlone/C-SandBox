#include "trie.h"
#include <iostream>
#include <cctype>
#include <string>

trie::trie()
{
    //ctor

    root = new Node;
}

trie::~trie()
{
    //dtor
}

void trie::add(std::string word){
    struct Node *tNode = root;

    for(unsigned int i = 0; i < word.length(); i++) {
        if (!std::ispunct(word[i])) {
            if(!tNode->children[word[i]]) {
                tNode->children[word[i]] = newNode();
            }
            tNode = tNode->children[word[i]];
        }
    }

    tNode->is_EndOfWord = true;
    tNode->counter += 1;
    return;
}

struct Node *trie::newNode(void){
    struct Node *tNode = new Node;
    tNode->is_EndOfWord = false;

    for(unsigned int i = 0; i < tNode->children.size(); i++){
        tNode->children[i] = NULL;
    }

    return tNode;
};

bool trie::seek(std::string key) {
    struct Node *tNode = root;

    for(unsigned int i = 0; i < key.length(); i++){
        if(!tNode->children[key[i]])
            return false;
        tNode = tNode->children[key[i]];
    }

    return (tNode != NULL && tNode->is_EndOfWord);
}

int trie::occurances(std::string key){
    struct Node *tNode = root;

    for(unsigned int i = 0; i < key.length(); i++){
        if(!tNode->children[key[i]])
            return 0;
        tNode = tNode->children[key[i]];
    }

    if(tNode == NULL)
        return 0;
    else
        return tNode->counter;
}
void trie::traverse(){
    trie::_traverse("", *root);
}

void trie::_traverse(std::string const& prefix, Node const& n){
    std::string buffer;

    if(n.is_EndOfWord){
        buffer = prefix;
        buffer.resize(30,' ') ;
        std::cout << buffer << "\t\t\t" << n.counter << "\n";
    }

    for(auto val : n.children){
        char value = val.first;
        Node *tNode = val.second;
        trie::_traverse(prefix + value, *tNode);
    }
}
