#include <stdio.h>


class TreeNode{
	public:
		char value;
		TreeNode* left;
		TreeNode* right;

		TreeNode(char v, TreeNode* l = NULL, TreeNode* r = NULL){
			this->value = v;
			this->left = l;
			this->right = r;
		}
};

void printNode(TreeNode* cur){
	printf("%c", cur->value);
}

void preorder(TreeNode* current){
	if(current !=NULL){
		printNode(current);
		preorder(current->left);
		preorder(current->right);
	}
}

void inorder(TreeNode* current){
	if(current !=NULL){
		inorder(current->left);
		printNode(current);
		inorder(current->right);
	}
}

void postorder(TreeNode* current){
	if(current !=NULL){
		postorder(current->left);
		postorder(current->right);
		printNode(current);
	}
}

TreeNode* tn[91]= {NULL};
int main(){
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i<n; i++){
		char p,l,r;
		scanf(" %c %c %c", &p, &l, &r);
		TreeNode* x = new TreeNode(p);
		if(tn[p] != NULL){
			x = tn[p];
		}
		TreeNode* y = new TreeNode(l);
		TreeNode* z = new TreeNode(r);
		if(l == '.'){
			// no left child
			y = NULL;
		}

		if(r == '.'){
			// no right child
			z = NULL;
		}

		x->left = y;
		x->right = z;
		tn[p] = x;
		tn[l] = y;
		tn[r] = z;
	}
	TreeNode* root = tn['A'];
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}
