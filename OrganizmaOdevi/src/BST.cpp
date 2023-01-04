#include "../include/BST.hpp"
/**
 * @file BST.cpp
 * @description Bağıl ikili arama ağacına ait işlemler tanımlanmıştır. (ekle, sil, dolaş, yükseklik bul, ara vb.)

 */

void BST::SearchAndAdd(Doku *&subNode, Doku &newItem)
{
    if (subNode == NULL)
        subNode = new Doku(newItem);
    else if (newItem.orta_hucre.dna_uzunlugu < subNode->orta_hucre.dna_uzunlugu)
        SearchAndAdd(subNode->sol, newItem);
    else if (newItem.orta_hucre.dna_uzunlugu > subNode->orta_hucre.dna_uzunlugu)
        SearchAndAdd(subNode->sag, newItem);
    else
        SearchAndAdd(subNode->sol, newItem);
}

bool BST::SearchAndDelete(Doku *&subNode, const Doku &data)
{
    if (subNode == NULL)
        return false;
    if (subNode->orta_hucre.dna_uzunlugu == data.orta_hucre.dna_uzunlugu)
        return DeleteNode(subNode);
    else if (data.orta_hucre.dna_uzunlugu < subNode->orta_hucre.dna_uzunlugu)
        return SearchAndDelete(subNode->sol, data);
    else
        return SearchAndDelete(subNode->sag, data);
}

bool BST::DeleteNode(Doku *&subNode)
{
    Doku *DelNode = subNode;

    if (subNode->sag == NULL)
        subNode = subNode->sol;
    else if (subNode->sol == NULL)
        subNode = subNode->sag;
    else
    {
        DelNode = subNode->sol;
        Doku *parent = subNode;
        while (DelNode->sag != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->sag;
        }
        subNode->orta_hucre.dna_uzunlugu = DelNode->orta_hucre.dna_uzunlugu;
        if (parent == subNode)
            subNode->sol = DelNode->sol;
        else
            parent->sag = DelNode->sol;
    }
    delete DelNode;
    return true;
}

void BST::inorder(Doku *subNode)
{
    if (subNode != NULL)
    {
        inorder(subNode->sol);
        cout << subNode->orta_hucre.dna_uzunlugu << " ";
        inorder(subNode->sag);
    }
}

void BST::postorder(Doku *subNode)
{
    if (subNode != NULL)
    {
        postorder(subNode->sol);
        postorder(subNode->sag);
    }
}

void BST::postorder2(Doku *altdoku, Doku **dizi)
{
    if (altdoku != NULL)
    {

        postorder2(altdoku->sol, dizi);
        postorder2(altdoku->sag, dizi);
        dizi[sayac] = altdoku;
        sayac++;
    }
}

int BST::Height(Doku *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->sol), Height(subNode->sag));
}

void BST::PrintLevel(Doku *subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->orta_hucre.dna_uzunlugu << " ";
    else
    {
        PrintLevel(subNode->sol, level - 1);
        PrintLevel(subNode->sag, level - 1);
    }
}

bool BST::Search(Doku *subNode, const Doku &item)
{
    if (subNode == NULL)
        return false;
    if (subNode->orta_hucre.dna_uzunlugu == item.orta_hucre.dna_uzunlugu)
        return true;
    if (item.orta_hucre.dna_uzunlugu < subNode->orta_hucre.dna_uzunlugu)
        return Search(subNode->sol, item);
    else
        return Search(subNode->sag, item);
}

BST::BST()
{
    root = NULL;
}

bool BST::isEmpty() const
{
    return root == NULL;
}

void BST::Add(Doku &newItem)
{
    SearchAndAdd(root, newItem);
}

void BST::Delete(const Doku &data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}

void BST::inorder()
{
    inorder(root);
}

int BST::Height()
{
    return Height(root);
}

bool BST::Search(const Doku &item)
{
    return Search(root, item);
}

void BST::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}

bool BST::agac_dengeli_mi(Doku *dal)
{
    while (dal != NULL)
    {
        if (abs(Height(dal->sol) - Height(dal->sag)) > 1)
            return false;
        else
        {
            agac_dengeli_mi(dal->sol);
            agac_dengeli_mi(dal->sag);
            break;
        }
    }
    return true;
}

void BST::postorder(Doku **dizi)
{
    sayac = 0;
    postorder2(root, dizi);
}

BST::~BST()
{
    Clear();
}