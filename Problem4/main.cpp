#include <iostream>
#include <vector>

class Node {
public:
    explicit Node(long long key) {
        this->key = key;
        right = nullptr;
        left = nullptr;
        height = 0;
        heirs = 0;
        depth = 0;
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
    int heirs;
    int depth;

};


class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(long long key) {
        if (root == nullptr) {
            root = new Node(key);
            root->set_height(0);
            return;
        } else {
            add_node(root, key);
        }
    }


    void add_node(Node *&node, long long key) {
        if (node == nullptr) {
            node = new Node(key);
            return;
        } else if (key < node->get_key()) {
            add_node(node->left, key);
        } else if (key > node->get_key()) {
            add_node(node->right, key);
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

    void pre_order_traversal(Node *node,std::vector<long long> &vec) {
        if (node != nullptr) {
            vec.push_back(node->get_key());
            pre_order_traversal(node->left,  vec);
            pre_order_traversal(node->right, vec);
        }
    }


    void in_order_traversal(Node *node, int &counter, int& k, long long &deleted_key) {
        if (node != nullptr) {
            in_order_traversal(node->right, counter, k, deleted_key);
            if (counter == k / 2 + 1 && k % 2 != 0) {
                deleted_key = node->get_key();
                counter += 1;
            }
            else {
                counter += 1;
            }
            in_order_traversal(node->left, counter, k, deleted_key);
        }
    }


    void describe_nodes(Node *&root_node) {
        if (root_node->right != nullptr && root_node->left != nullptr) {
            root_node->right->depth = root_node->depth + 1;
            root_node->left->depth = root_node->depth + 1;
            describe_nodes(root_node->right);
            describe_nodes(root_node->left);
            if (root_node->right->height > root_node->left->height) {
                root_node->height = root_node->right->height + 1;
            }
            else {
                root_node->height = root_node->left->height + 1;
            }
            root_node->heirs = root_node->left->heirs + root_node->right->heirs + 2;
        }
        if (root_node->right == nullptr && root_node->left == nullptr) {
            root_node->height = 0;
            root_node->heirs = 0;
        }
        else if (root_node->right != nullptr && root_node->left == nullptr) {
            root_node->right->depth = root_node->depth + 1;
            describe_nodes(root_node->right);
            root_node->heirs = root_node->right->heirs + 1;
            root_node->height = root_node->right->height + 1;
        }
        else if (root_node->left != nullptr && root_node->right == nullptr) {
            root_node->left->depth = root_node->depth + 1;
            describe_nodes(root_node->left);
            root_node->heirs = root_node->left->heirs + 1;
            root_node->height = root_node->left->height + 1;
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

void MakeTree(BinaryTree &new_tree, Node *& old_root, int &counter, int height, int root_height) {
    if (old_root != nullptr) {
        if (old_root->left != nullptr && old_root->right != nullptr) {
            if (root_height - old_root->depth == height && old_root->left->heirs > old_root->right->heirs) {
                new_tree.insert(old_root->key);
                counter += 1;
            } else {
                MakeTree(new_tree, old_root->right, counter, height, root_height);
                MakeTree(new_tree, old_root->left, counter, height, root_height);
            }
        }
        else if (old_root->left != nullptr && old_root->right == nullptr) {
            if (root_height - old_root->depth == height) {
                new_tree.insert(old_root->key);
                counter += 1;
            }
            else {
                MakeTree(new_tree, old_root->left, counter, height, root_height);
            }
        }
        else if (old_root->left == nullptr && old_root->right != nullptr) {
            MakeTree(new_tree, old_root->right, counter, height, root_height);
        }
    }
}

int main() {
    FILE *f = fopen("in.txt", "r");
    FILE *f1 = fopen("out.txt", "w");
    long long n = 0;
    std::vector<long long> vec;
    BinaryTree tree;
    while (fscanf(f, "%lld", &n) != EOF) {
        tree.insert(n);
    }
    long long deleted_key = 0;
    tree.describe_nodes(tree.root);
    int need_height = 0;
    need_height = tree.root->height / 2;
    int amount_of_nodes = 0;
    int counter = 1;
    BinaryTree new_tree;
    MakeTree(new_tree, tree.root, amount_of_nodes, need_height, tree.root->height);
    new_tree.in_order_traversal(new_tree.root, counter, amount_of_nodes, deleted_key);
    tree.root = tree.remove_node(deleted_key, tree.root);
    tree.pre_order_traversal(tree.root, vec);
    for (unsigned int i = 0; i < vec.size(); i++) {
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