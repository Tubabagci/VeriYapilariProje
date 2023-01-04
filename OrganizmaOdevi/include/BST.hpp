#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cmath>
#include "Doku.hpp"
using namespace std;

class BST
{
private:
    void SearchAndAdd(Doku *&subNode, Doku &newItem);
    bool SearchAndDelete(Doku *&subNode, const Doku &data);
    bool DeleteNode(Doku *&subNode);
    void inorder(Doku *subNode);
    void preorder(Doku *subNode);
    void postorder(Doku *subNode);
    void postorder2(Doku *altdoku, Doku **);
    int Height(Doku *subNode);
    void PrintLevel(Doku *subNode, int level);
    bool Search(Doku *subNode, const Doku &item);

public:
    Doku *root;
    int sayac;
    BST();
    bool agac_dengeli_mi(Doku *);
    bool isEmpty() const;
    void Add(Doku &newItem);
    void Delete(const Doku &data);
    void inorder();
    void preorder();
    void postorder(Doku **);
    void levelorder();
    int Height();
    bool Search(const Doku &item);
    void Clear();
    ~BST();
};

#endif