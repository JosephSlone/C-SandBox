#include <iostream>
#include "trie.h"

int main()
{
    std::cout << "<< Begin Run >>" << std::endl;
    trie Tree;
    std::string word;

    while(std::cin >> word) {
        Tree.add(word);
    }

    Tree.traverse();

    return 0;
}
