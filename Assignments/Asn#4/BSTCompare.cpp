//
//
//
//  Created by Shannon Abeda on 2020-02-19.
//

#include <stdio.h>


#include <iostream>
#include <string>
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



bool isSimilar(struct BinarySearchTree *node, struct BinarySearchTree *node1)
{
    if(node==NULL && node1 == NULL)
    {
        return true;
    }
    
    else if(node!=NULL && node1!=NULL)
    {
        if(node->data == node1->data &&
           isSimilar(node->left, node1->left) && isSimilar(node->right, node1->right))
        {
            return true;
        }
    }
    
    
    return false;
    
}
    
    
    


int main() {
    //Local variables
    int n, n2, r1, r2;
    int node;
    std::string prompt;
    
    //Intializing the root
    BinarySearchTree *root = NULL;
    BinarySearchTree *root2 = NULL;
    
    
    start:

    //Intializing of the root
    std::cout<<"Intialize the root node of BST(1): ";
    std::cin>>r1;
    std::cout<<"Intialize the root node of BST(2): ";
    std::cin>>r2;
    
    //Intializing the root of the tree
    root = insert(root, r1);
    root2 = insert(root2, r2);
    
    
    //User input
    std::cout<<"Enter the amount of nodes you want to add to the first BST: ";
    std::cin>>n;
    

    //Inserting Values into the BST(1)
    for(int i=0; i<n; i++)
    {
        std::cout<<"Enter the value of the "<<i+1<<"th node: ";
        cin>>node;
        insert(root, node);
    }
    
    //User input
    std::cout<<"Enter the amount of nodes you want to add to the second BST: ";
    std::cin>>n2;
    
    
    //Inserting values into BST(2)
    for(int i=0; i<n2; i++)
    {
        std::cout<<"Enter the value of the "<<i+1<<"th node: ";
        cin>>node;
        insert(root2, node);
    }
    
    //If trees are similar
    if(isSimilar(root, root2))
    {
        std::cout<<"Binary trees are similar";
        std::cout<<endl;
    }
    
    else
    {
        std::cout<<"Binary trees ARE NOT similar";
        std::cout<<endl;
    }
    
    //Looping method to try again for further testing
    std::cout<<"Would you like to try again? Type Y to continue and ";
    std::cout<<"any other key to exit: "<<std::endl;
    std::cin>>prompt;
    
    prompt = toupper(prompt[0]);
    
    if(prompt == "Y")
    {
        goto start;
    }

    
    return 0;
}
