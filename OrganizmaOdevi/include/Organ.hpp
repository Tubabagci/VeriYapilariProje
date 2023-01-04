#if !defined(ORGAN)
#define ORGAN
#include "Doku.hpp"
#include "BST.hpp"
class Organ
{
public:
    BST *bst;
    Doku **postorder_dokular;
    Organ();
    void mutasyona_ugrat();
    ~Organ();
};

#endif // ORGAN
