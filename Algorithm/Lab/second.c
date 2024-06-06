/*Author : RAJ ROY*/
/*Scholar id : 2212002*/

#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
#include<time.h>

int count = 0;               
struct Node {
    int idx;
    struct Node *left, *right;
};

struct Node* createNode(int idx) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->left = t->right = NULL;
    t->idx = idx;
    return t;
}

void traverseHeight(struct Node* root, int arr[], int* res) {
	count += 2;
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (*res > arr[root->left->idx] && root->left->idx != root->idx) {
        *res = arr[root->left->idx];
        traverseHeight(root->right, arr, res);
    }

    else if (*res > arr[root->right->idx] && root->right->idx != root->idx) {
        *res = arr[root->right->idx];
        traverseHeight(root->left, arr, res);
    }
}

void findSecondMin(int arr[], int n) {
    struct Node** li = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i += 2) {
    	count += 1;
        struct Node* t1 = createNode(i);
        struct Node* t2 = NULL;
        if (i + 1 < n) {
            t2 = createNode(i + 1);

            root = (arr[i] < arr[i + 1]) ? createNode(i) : createNode(i + 1);

            root->left = t1;
            root->right = t2;
            li[i / 2] = root;
        } 
        else
            li[i / 2] = t1;
    }

    int lsize = n / 2;
    while (lsize != 1) {
        int last = (lsize & 1) ? (lsize - 2) : (lsize - 1);
        for (int i = 0; i < last; i += 2) {
        	count += 1;
            struct Node* f1 = li[i];
            struct Node* f2 = li[i + 1];
            root = (arr[f1->idx] < arr[f2->idx]) ? createNode(f1->idx) : createNode(f2->idx);

           
            root->left = f1;
            root->right = f2;

            
            li[i / 2] = root;
        }
        count += 1;
        if (lsize & 1) {
            li[lsize / 2] = li[lsize - 1];
        }
        lsize = (lsize + 1) / 2;
    }

    
    int res = INT_MAX;
    traverseHeight(root, arr, &res);
    printf("Minimum: %d, Second minimum: %d\n", arr[root->idx], res);
}


int main() {
	srand(time(0));
	int n = 100;
	int arr[n];
	for(int i = 0; i < n; i++) {
		int x = rand() % 100;
		arr[i] = x;
	}

	for(int i = 0; i < n; i++) printf("%d " , arr[i]);
	printf("\n");
    
    findSecondMin(arr, n);

    printf("Total Number of elements = %d\n" , n);

    printf("Total Comparison = %d " , count);

    return 0;
}
