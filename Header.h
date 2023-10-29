#pragma once
using namespace std;

struct tnode
{
    int info;
    tnode* next;
    tnode* prev;
};
using pnode = tnode*;

void CreateList(pnode& head, pnode& tail);
void DisplayList(pnode head);
void DisplayReverseList(pnode tail);
int InsertBefore(pnode& head, int info, int new_info);
int InsertAfter(pnode& head, pnode& tail, int info, int new_info);
int DeleteByValue(pnode& head, pnode& tail, int info);
bool CheckSymmetry(pnode head, pnode tail);

