#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    char c;
    Node* left;
    Node* right;
};

class MyComparator {
public:
      bool operator()(Node* x, Node* y) {
          return x->data > y->data;
      }
};

void printCode(Node* root, string s) {
    if (root->left == NULL && root->right == NULL && isalpha(root->c)) {
        cout << root->c << ":" << s << endl;
        return;
    }
    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}

int main() {
    int n = 6;
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int  charfreq[]  =  {5, 9, 12, 13, 16, 45};
    priority_queue<Node*, vector<Node*>, MyComparator> q;
    for (int i = 0; i < n; i++) {
        Node* hn = new Node();
        hn->c = charArray[i];
        hn->data = charfreq[i];
        hn->left = NULL;
        hn->right = NULL;
        q.push(hn);
    }

    Node* root = NULL;
    while (q.size() > 1) {
        Node* x = q.top();
        q.pop();
        Node* y = q.top();
        q.pop();

        Node* f = new Node();
        f->data = x->data + y->data;
        f->c = '-';
        f->left = x;
        f->right = y;
        root = f;
        q.push(f);
    }
    printCode(root, "");
    return 0;
}
