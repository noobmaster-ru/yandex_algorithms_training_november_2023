#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tNode *tree;
typedef char elemtype;  

typedef struct tNode{
    elemtype elem;
    int kol;
    tree left;
    tree right;
} tnode;
tree t1,t2;

tree append_elem_in_tree(tree t, elemtype n){
    if (t == NULL){
        t = (tree)malloc(sizeof(tnode));
        t->elem = n;
        t->kol = 1;
        t->left = NULL;
        t->right = NULL;
    }
    else if ( n == t->elem){
        t->kol++;
    }
    else if (n < t->elem ) {
        t->left = append_elem_in_tree(t->left,n);
    }
    else if (n > t->elem){
        t->right = append_elem_in_tree(t->right,n);
    }
    return t;
} 


void print_tree(tree t){
    if (t == NULL){
        return;
    }
    else{
        print_tree(t->left);
        printf("%c:%d ",t->elem,t->kol);
        print_tree(t->right);
    }
}

int find_kol_of_elem(tree t, elemtype n){
    if (t == NULL)
        return 0; 
    if (t->elem == n)
        return t->kol;
    if  (t->elem < n)
        return find_kol_of_elem(t->right,n);
    return find_kol_of_elem(t->left,n);
}

int main(){
    char c;
    t1 = NULL;
    t2 = NULL;
    while ((c = getchar()) != '\n' ){
        t1 = append_elem_in_tree(t1,c);
    }
    while ((c = getchar()) != '\n' ){
        t2 = append_elem_in_tree(t2,c);
    }
    // print_tree(t1);
    // printf("\n");
    // print_tree(t2);
    
    int flag = 0;
    for (c = 'a'; c <= 'z'; c++){
        if (find_kol_of_elem(t1,c) != find_kol_of_elem(t2,c)){
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}