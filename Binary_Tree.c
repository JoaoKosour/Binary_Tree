//B TREE IMPLEMENTATION BY JOAO KOSOUR, FEEL FREE TO USE AS WILL :)

#include <stdlib.h>
#include <stdio.h>

//some defines for error and success so if i need to change values
//i dont need to do it in the whole code
#define ERROR 0
#define SUCCESS 1   


//here im using a int called id, but you can use anything you want,
//however we will need find out if this node is >, < or = 
//than other nodes, for insertion, deletion and search, 
//so it would "harder" to do with strings or structs for example, 
//however you can put an id for comparing, but keep in mind
//having a extra int just for this will take 4 bytes per node createad
typedef struct NODE {
    int id;
    struct NODE *left, *right;  //left is <, right is >
} NODE;


typedef struct root {
    NODE *root;
    int size;
}ROOT;



/*******************************************************
*                                                      *
*                   S E A R C H                        *
*                                                      *
********************************************************/
//call for the binary search, we need this so we can have a recursive
//binary search. There are 2 different structs, one for root
//and one for node, by doing a call function we can pass the root
//node as a NODE struct, and depending if it is > or < pass node->right
//or node->left as the new node pointers in the recursive call
// since they are also a NODE struct and not ROOT struct
//TL;DR We call this function to get root in NODE struct type
void binary_search_call(ROOT *root, int key) {
    if(!root) return ERROR;
    return binary_search(root->root, key);
}

//one of the fastests searches, because in each search call we reduce 
//the area we need to look in by half, so logarithmic complexity
int binary_search(NODE *node, int key) {
    if(!node) return ERROR;

    if(node->key == key) return SUCCESS;
    else if(key > node->key)
            return binary_search(node->right, key);
    else if(key < node->key)
            return binary_search(node->left, key);
    return ERROR;
}


/*******************************************************
*                                                      *
*               I N S E R T I O N                      *
*                                                      *
********************************************************/
//this is just a subroutine (auxiliary to the main code/function) 
//to create a new node for insertion.
NODE *create_new_binary_tree_node(int key){
    NODE *new_node = calloc(1, sizeof(NODE));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}

//we are creating a new node with key, finding its location on the tree and inserting it
//here key can be anything, you can use a struct, a string, or anything you want to store
void binary_tree_insertion(ROOT *root, int key){
    if(!root){
        printf("Missing root, no node inserted");
        return NULL;
    } 

//1. creating a node:
    NODE *new_node = create_new_binary_tree_node(key); //creating a new node with the key given

//2. finding the locantion and inserting a node:
    //here we create an auxiliary pointer to help us treverse 
    //the tree to find where the new node will be inserted
    NODE *aux = root->root;
    //this while treverses the tree 
    while(aux){
        if(aux == NULL){ // position found, just insert
            aux = new_node;
            break;
        }
        if(key == aux->key) break; //no duplicate entrys in the tree
        if(key > aux->key) aux = aux->right; //goes right
        else if(key < aux->key) aux = aux->right; //goes left
    }
}


/*******************************************************
*                                                      *
*                 D E L E T I O N                      *
*                                                      *
********************************************************/
void binary_tree_deletion_call(ROOT *root, int key) {
    if(!root){
        printf("No root found, no node deleted.");
        return;
    }
    binary_tree_deletion(root->root, int key);
}

NODE *find_min_value_child(NODE* node) { 
    NODE *aux = node; 
    while (aux && aux->left) 
        aux = aux->left; 
    return aux; 
} 
  
NODE *binary_tree_deletion(NODE *node, int key) { 
    if (root == NULL){
        printf("Node not found, no node deleted.");
        return;
    } 
  
    if(key < root->key) 
        root->left = binary_tree_deletion(root->left, key); 
  

    else if(key > root->key) 
        root->right = binary_tree_deletion(root->right, key); 
  
    else { 
        if (!root->left) { 
            NODE *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (!root->right) { 
            NODE *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        NODE *temp = find_min_value_child(root->right); 
        root->key = temp->key; 
        root->right = binary_tree_deletion(root->right, temp->key); 
    } 
    return root; 
} 