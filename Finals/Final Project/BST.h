#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
        //create a key
        T key;

        //pointers for left and right
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public:
        //constructor
        BinarySearchTree(T value);

        //destructor
        ~BinarySearchTree();

        //insert left and right
        void insert(T value);

        //traversing
        void preOrder();
        void inOrder();
        void postOrder();

        //searching
        bool search(T value);

};
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    delete left;
    delete right;
}
template <typename T>
void BinarySearchTree<T>::insert(T value){
    //left or right

    //go left if value is < key insert to left
    if(value < key){
        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        }else{
            left->insert(value);
        }
    //go right if value > key insert to right
    }else if(value > key){
        if(right == nullptr){
            right = new BinarySearchTree<T>(value);
        }else{
            right->insert(value);
        }
    }

}

template <typename T>
bool BinarySearchTree<T>::search(T value){
    if (value == key){
        return true;
    }

    if (value < key){
        if (left != nullptr){
            return left->search(value);
        }
    }
    else{
        if (right != nullptr){
            return right->search(value);
        }
    }

    return false;
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << " ";
    if(left != nullptr){
        left->preOrder();
    }

    if(right != nullptr){
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        left->inOrder();
    }
    std::cout << key << " ";
    if(right != nullptr){
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
    if(left != nullptr){
        left->postOrder();
    }
    if(right != nullptr){
        right->postOrder();
    }
    std::cout << key << " ";
}
#endif