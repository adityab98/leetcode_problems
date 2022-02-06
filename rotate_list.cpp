#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;
		ListNode *tail = head;
		int c = 0;
		vector<int> arr;
		while (tail != NULL) {
			arr.push_back(tail->val);
			tail = tail->next;
			c++;
		}
		tail = head; 
		int i = 0;
		k %= c;
		while (i != k) {
			if (tail->next == NULL)
				tail = head;
			else tail = tail->next;
			i++;
		}
		for (i = 0; i < c; i++) {
			tail->val = arr[i];
			if (tail->next == NULL)
				tail = head;
			else tail = tail->next;
		}
		return head;
	}
};
