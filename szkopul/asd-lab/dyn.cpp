#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
    int occurrences;
	Node* left;
	Node* right;
	int height;
	int leftWeight;
	int rightWeight;
};

Node* newNode(int val, int occurrences) {
	Node* node = (Node*)calloc(1, sizeof(Node));
	node->val = val;
	node->occurrences = occurrences;
	node->height = 1;
	return node;
}

void deleteTree(Node* root) {
	if (root) {
		if (root->left) {
			deleteTree(root->left);
		}
		if (root->right) {
			deleteTree(root->right);
		}
		free(root);
	}
}

inline int height(Node* node) {
	return !node? 0 : node->height;
}

inline int weight(Node* node) {
	return !node? 0 : node->occurrences + node->leftWeight + node->rightWeight;
}

inline int leftWeight(Node* node) {
	return !node? 0 : node->leftWeight;
}

inline int balanceFactor(Node* node) {
	return !node? 0 : height(node->left) - height(node->right);
}

inline void updateHeight(Node* node) {
	!node? 0 : node->height = 1 + max(height(node->left), height(node->right));
}

inline void updateWeight(Node* node) {
	if (node) {
		node->leftWeight = weight(node->left);
		node->rightWeight = weight(node->right);
	}
}

Node* rightRotate(Node* oldRoot) {
	Node* newRoot = oldRoot->left;
	oldRoot->left = newRoot->right;
	newRoot->right = oldRoot;
	updateHeight(oldRoot);
	updateHeight(newRoot);
	updateWeight(oldRoot);
	updateWeight(newRoot);
	return newRoot;
}

Node* leftRotate(Node* oldRoot) {
	Node* newRoot = oldRoot->right;
	oldRoot->right = newRoot->left;
	newRoot->left = oldRoot;
	updateHeight(oldRoot);
	updateHeight(newRoot);
	updateWeight(oldRoot);
	updateWeight(newRoot);
	return newRoot;
}

Node* leftRightRotate(Node* oldRoot) {
	oldRoot->left = leftRotate(oldRoot->left);
	return rightRotate(oldRoot);
}

Node* rightLeftRotate(Node* oldRoot) {
	oldRoot->right = rightRotate(oldRoot->right);
	return leftRotate(oldRoot);
}

Node* balanceTree(Node* node) {
	int bf = balanceFactor(node);
    if (bf > +1) {
		int lbf = balanceFactor(node->left);
		if (lbf == +1) { 
			return rightRotate(node);
        } else if (lbf == -1) {
            return leftRightRotate(node);
		}
	}
	if (bf < -1) {
		int rbf = balanceFactor(node->right);
		if (rbf == -1) {
			return leftRotate(node);
		} else if (rbf == +1) {
			return rightLeftRotate(node);
		}
	}
	return node;
}

Node* insertNode(Node* node, int val, int pos, int occurrences) {
	if (node == nullptr) {
		return newNode(val, occurrences);
	}

	int left_weight = weight(node->left);
	int left_plus_root_weight = left_weight + node->occurrences;
	if (pos <= left_weight) {
		node->left = insertNode(node->left, val, pos, occurrences);
	} else if (pos > left_weight && pos <= left_plus_root_weight - 1) {
		if (val == node->val) {
			node->occurrences += occurrences;
		} else {
			int left_occurrences = pos - node->leftWeight;
			int right_occurrences = node->occurrences - left_occurrences;
			node->left = insertNode(node->left, node->val, node->leftWeight, left_occurrences);
			node->right = insertNode(node->right, node->val, 0, right_occurrences);
			node->val = val;
			node->occurrences = occurrences;
		}
	} else {
		node->right = insertNode(node->right, val, pos - left_plus_root_weight, occurrences);
	}
	
	updateHeight(node);
	updateWeight(node);

	return balanceTree(node);
}

Node* getNode(Node* node, int pos) {
	int left_weight = weight(node->left);
	int left_plus_root_weight = left_weight + node->occurrences;	

	if (pos < left_weight) 
		return getNode(node->left, pos);
	if (pos >= left_weight && pos <= left_plus_root_weight - 1) 
		return node;
	return getNode(node->right, pos - left_plus_root_weight);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	Node* tree = nullptr;

	int m, w = 0;
	cin >> m;
	while (m) {
		int n = weight(tree);
		int j, x, k;
		char cmd;
		cin >> cmd >> j;
		if (cmd == 'i') { // insert
			cin >> x >> k;
			j = (j + w) % (n + 1);
			tree = insertNode(tree, x, j, k);
			m--;
		} else if (cmd == 'g') { // get
			j = !n? 0 : ((j + w) % n);
			int res = getNode(tree, j)->val;
			cout << res << "\n";
			w = res;
			m--;
		}
	}
	deleteTree(tree);
	return 0;
}
