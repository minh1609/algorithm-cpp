using namespace std;

template <typename T>
class AVLTree {
    struct node {
        T data;
        node* left;
        node* right;
        int height;
    };

    void makeEmpty(node* n) {
        if (n == nullptr) return;
        makeEmpty(n->left);
        makeEmpty(n->right);
        delete n;
        n = nullptr;
    }

    node* singleRightRotate(node*& n) {
        node* u = n->left;
        n->left = u->right;
        u->right = n;
        n->height = max(height(n->left), height(n->right)) + 1;
        u->height = max(height(u->left), n->height) + 1;
        return u;
    }

    node* doubleLeftRotate(node*& n) {
        n->right = singleRightRotate(n->right);
        return singleLeftRotate(n);
    }

    node* doubleRightRotate(node*& n) {
        n->left = singleLeftRotate(n->left);
        return singleRightRotate(n);
    }

    node* singleLeftRotate(node*& n) {
        node* u = n->right;
        n->right = u->left;
        u->left = n;
        n->height = max(height(n->left), height(n->right)) + 1;
        u->height = max(height(n->right), n->height) + 1;
        return u;
    }

    int height(node* n) {
        if (n == nullptr) {
            return -1;
        } else {
            return n->height;
        }
    }

    node* insert(int value, node* n) {
        if (n == nullptr) {
            n = new node;
            n->data = value;
            n->height = 0;
            n->left = n->right = nullptr;
        } else if (value < n->data) {
            n->left = insert(value, n->left);
            if (height(n->left) - height(n->right) == 2) {
                if (value < n->left->data)
                    n = singleRightRotate(n);
                else
                    n = doubleRightRotate(n);
            }
        } else if (value > n->data) {
            n->right = insert(value, n->right);
            if (height(n->right) - height(n->left) == 2) {
                if (value > n->right->data)
                    n = singleLeftRotate(n);
                else
                    n = doubleLeftRotate(n);
            }
        }

        n->height = max(height(n->left), height(n->right)) + 1;
        return n;
    }

    void inOrder(node* n) {
        if (n == nullptr)
            return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }

    node* findMinValue(node* n) {
        if (n == nullptr)
            return nullptr;
        else if (n->left == nullptr)
            return n;
        else
            return findMinValue(n->left);
    }

    node* remove(int value, node* n) {
        node* temp;

        if (n == nullptr)
            return nullptr;
        else if (value < n->data)
            n->left = remove(value, n->left);
        else if (value > n->data)
            n->right = remove(value, n->right);
        else if (n->left && n->right) {
            temp = findMinValue(n->right);
            n->data = temp->data;
            n->right = remove(n->data, n->right);
        } else {
            temp = n;
            if (n->left == nullptr)
                n = n->right;
            else if (n->right == nullptr)
                n = n->left;
            delete temp;
        }

        if (n == nullptr)
            return n;

        n->height = max(height(n->left), height(n->right)) + 1;

        if (height(n->left) - height(n->right) == 2) {
            if (height(n->left->left) - height(n->left->right) == 1)
                return singleLeftRotate(n);
            else
                return doubleLeftRotate(n);
        } else if (height(n->right) - height(n->left) == 2) {
            if (height(n->right->right) - height(n->right->left) == 1)
                return singleRightRotate(n);
            else
                return doubleRightRotate(n);
        }
        return n;
    }

   public:
    node* root;
    AVLTree();
    void insert(T x);
    void print();
    void remove(T x);
    void empty();
    int height();
};