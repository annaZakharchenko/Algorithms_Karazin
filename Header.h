#pragma once
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};
ListNode* createLinkedList();
bool contains(const vector<int>& vals, int target);
int countConnectedComponents(ListNode* head, vector<int>& vals);
