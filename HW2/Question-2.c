#include<stdio.h>
#include<stdlib.h>


//Deleting the main root will raise core dumped!

struct Node{
    int Key;
    struct Node *Left, *Right;
};

struct Node* btree_search(struct Node *Root, int key){
    if(Root == NULL || Root->Key == key)
        return Root;
    if(key < Root->Key)
        return btree_search(Root->Left, key);
    else
        return btree_search(Root->Right, key);

}

struct Node *NewNode(int key){
    struct Node *Created = (struct Node *)malloc(sizeof(struct Node));
    Created->Key = key;
    Created->Left = NULL;
    Created->Right = NULL;

    return Created;
}

struct Node* btree_add_node(struct Node* Parent, int key){
    if(Parent == NULL)
        return NewNode(key);
    else 
        if(key < Parent->Key)
            Parent->Left = btree_add_node(Parent->Left, key);
        else
            Parent->Right =  btree_add_node(Parent->Right, key);


}

struct Node* MinValue(struct Node* root){
    struct Node* Current = root;

    while(Current && Current->Left != NULL){
        Current = Current->Left;
    }
    return Current;
}

struct Node* btree_remove_node(struct Node *root, int key){
    if(root == NULL)
        return root;
     if(key < root->Key)
            root->Left = btree_remove_node(root->Left, key);
    else if(key > root->Key)
            root->Right =  btree_remove_node(root->Right, key);
        //when this is the node we want to btree_remove_node
    else{
        if(root->Left == NULL)
            {
                struct Node* temp = root->Right;
                free(root);
                return temp;
            }
            else if (root->Right == NULL){
                struct Node* temp = root->Left;
                free(root);
                return temp;
            }

            struct Node* Temp = MinValue(root->Right);
            root->Key = Temp->Key;

            //btree_remove_node the node which is subsituated (Minvalue)

            root->Right = btree_remove_node(root->Right, Temp->Key);


        }
        return root;
}

//This is just for checking the anwers and the order of the nodes which we add to the Binary btree_search Tree
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->Left);
        printf("%d \n", root->Key);
        inorder(root->Right);
    }
}




int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct Node *root = NULL;
    root = btree_add_node(root, 50);
    btree_add_node(root, 30);
    btree_add_node(root, 20);
    btree_add_node(root, 40);
    btree_add_node(root, 70);
    btree_add_node(root, 60);
    btree_add_node(root, 80);
  
    root = btree_remove_node(root, 20); 
    root = btree_remove_node(root, 30); 
  
    inorder(root); 
  
    return 0;
}