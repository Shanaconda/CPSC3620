
//  Question 3.cpp
//
//
//  Created by Shannon Abeda on 2020-02-19.
//

#include <stdio.h>


#include <iostream>
using namespace std;



//Struct of Nodes
struct BinarySearchTree
{
int data;
BinarySearchTree *left;
BinarySearchTree *right;
};



// Inserting nodes into BST
BinarySearchTree* insert( BinarySearchTree* node, int val) {
if (node == NULL) {
    BinarySearchTree *newNode = new BinarySearchTree();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
    
else if (val < node->data){
node->left = insert(node->left, val);
}
else if (val > node->data) {
node->right = insert(node->right, val);
}
return node;
}



// function to print the node of the BST with value greater than min
void PrintElements(struct BinarySearchTree *node, int min) {
if(node == NULL) // return if node is null
return;
if(node->data > min) // we go to the left subtree if and only if the node value is greater than min
PrintElements(node->left,min);
if(node->data > min) // we print the node value if it is greater than min
cout<<node->data<<" ";
PrintElements(node->right,min); // otherwise we go to the right subtree
}

int main()
{
    //Local variables
    int n, min;
    int node;
    
    //Intializing the root
    BinarySearchTree *root = NULL;
    
    
    //User input
    std::cout<<"Enter the amount of nodes you want to add to the BST: ";
    std::cin>>n;
    
    //Intializing the root of the tree
    root = insert(root, 5);
    
    
    //Inserting Values into the BST
    for(int i=0; i<n; i++)
    {
        std::cout<<"Enter the "<<i+1<<" node: ";
        cin>>node;
        insert(root, node);
    }
    
    //Finding the min
    std::cout<<"Enter the min##: ";
    std::cin>>min;
    
// printing all the nodes with value greater than 5 in the above BST
cout<<"Node values greater than "<<min<<" : ";
PrintElements(root, min);

return 0;
}
