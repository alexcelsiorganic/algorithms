#include <iostream>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

class Node {
public:
    explicit Node(long long key) {
        this->key = key;
        right = nullptr;
        left = nullptr;
        height = 0;
    }

    Node(long long key, int height) {
        this->key = key;
        right = nullptr;
        left = nullptr;
        this->height = height;
    }

    long long get_key() const {
        return this->key;
    }

    void set_key(long long _key) {
        this->key = _key;
    }

    void set_height(int _height) {
        this->height = _height;
    }

    long long key;
    int height;
    Node *left;
    Node *right;

};


class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(long long key) {
        int counter = 0;
        if (root == nullptr) {
            root = new Node(key);
            root->set_height(0);
            return;
        } else {
            add_node(root, key, counter);
        }
    }


    void add_node(Node *&node, long long key, int counter) {
        if (node == nullptr) {
            node = new Node(key);
            node->set_height(counter);
            return;
        } else if (key < node->get_key()) {
            add_node(node->left, key, counter += 1);
        } else if (key > node->get_key()) {
            add_node(node->right, key, counter += 1);
        }
    }

    Node *find_node(long long key, Node *node_root) {
        if (node_root == nullptr) {
            return nullptr;
        }
        if (node_root->get_key() > key) {
            return find_node(key, node_root->left);
        } else if (node_root->get_key() < key) {
            return find_node(key, node_root->right);
        } else if (node_root->get_key() == key) {
            return node_root;
        }
        return nullptr;
    }

    long long right_remove(Node *node) {
        if (node->left == nullptr) {
            return node->get_key();
        } else {
            return right_remove(node->left);
        }
    }

    Node *remove_node(long long key, Node *node_root) {
        if (node_root == nullptr) {
            return nullptr;
        }
        if (node_root->get_key() < key) {
            if (node_root->right == nullptr) {
                    return node_root;
            }
            node_root->right = remove_node(key, node_root->right);
            return node_root;
        } else if (node_root->get_key() > key) {
            if (node_root->get_key() < key) {
                return node_root;
            }
            node_root->left = remove_node(key, node_root->left);
            return node_root;
        } else if (node_root->key == key) {
            if (node_root->left == nullptr && node_root->right == nullptr) {
                return nullptr;
            }
            if (node_root->left == nullptr) {
                return node_root->right;
            }
            if (node_root->right == nullptr) {
                return node_root->left;
            } else {
                node_root->set_key(right_remove(node_root->right));
                node_root->right = remove_node(node_root->get_key(), node_root->right);
                return node_root;
            }
        }
        return nullptr;
    }

    void pre_order_traversal(Node *node, std::vector<long long> &v) {
        if (node != nullptr) {
            v.push_back(node->get_key());
            pre_order_traversal(node->left,  v);
            pre_order_traversal(node->right, v);
        }
    }


    ~BinaryTree() {
        destroy_node(root);
    }

    Node *root;
private:
    void destroy_node(Node *node) {
        if (node != nullptr) {
            destroy_node(node->right);
            destroy_node(node->left);
            delete node;
        }
    }
};


int main() {
    FILE* f = fopen("input.txt", "r");
    FILE* f1 = fopen("output.txt", "w");
    long long  n = 0;
    int counter = 0;
    long long key =  0;
    fscanf(f, "%lld", &key);
    BinaryTree tree;
    while (fscanf(f, "%lld", &n) != EOF) {
        tree.insert(n);
    }
    std::vector<long long> vec;
    tree.root = tree.remove_node(key, tree.root);
    tree.pre_order_traversal(tree.root, vec);
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            fprintf(f1, "%lld", vec[i]);
        }
        else {
            fprintf(f1, "%lld\n", vec[i]);
        }
    }
    fclose(f);
    fclose(f1);
    return 0;
}