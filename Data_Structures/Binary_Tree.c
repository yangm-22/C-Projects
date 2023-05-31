#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/******************The binary tree***********************
 * The following is an illustration of the binary tree
 * I *highly* recommend you test your algorithm on.
 ********************************************************
 *                        Nicholas
 *                        /      \
 *                     Mark      Parker
 *                    /          /     \
 *                Swaleh     Soroush   Other Mark
 *                                 \
 *                                 Ana
 *                                 /
 *                             Bassel
 *
 *
 * (where "/" indicates a left branch, 
 *    and "\" indicates a right branch)
 *
 */ 


//defining a node
typedef struct node {
    //string used for storing the name
    char* name;
    //string used for storing the tea
    char* tea;
    //pointer to left branch of tree
    struct node* left;
    //pointer to right branch of tree
    struct node* right;
} Node;
//means you can call it by "Node" or "struct node"



//returning the depth of the tree
int depth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    else {
        //finding depth of left and right branches of tree
        int left = depth(root -> left);
        int right = depth(root -> right);

        //return the longer branch of the tree
        if (left > right) {
            return left + 1;
        }
        else {
            return right + 1;
        }
    }
}

//finding the name in a tree
void dfs_child(Node* node, char* name, int *count, int *flag) {
    //checking if there is a branch further down the root
    if (node == NULL) {
      return;
    }

    *count +=1;
    if (strcmp(node->name, name) == 0) {
        *flag = 1;
        return;
    }

    if (node->left != NULL) {
        dfs_child(node->left, name,count,flag);
    }
    if (*flag == 1) {
        return;
    }
    if (node->right != NULL) {
        dfs_child(node->right, name, count, flag);
    }
} 

int dfs(Node *root, char* name){
    int counter = 0;
    int exist = 0;
    dfs_child(root, name, &counter, &exist);
    if (exist == 0) {
        return -1;
    }

    return counter;
}

int main() {
    //Testing code ^_^
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
 
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1

    printf("Depth First Search for : Ana\n");
    printf("result: %d\n", dfs(root, "Ana"));
    // expected result is -1

    printf("Depth First Search for : HELLO\n");
    printf("result: %d\n", dfs(root, "HELLO"));
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);


}
