//System permission
#define READ 4
#define WRITE 2
#define EXECUTE 1

//Common permissions
#define PERM_RW 6
#define PERM_RX 5
#define PERM_WX 3
#define PERM_RWX 7

#include<stdio.h>

//Add permission function
void add_perm(unsigned int *perm, unsigned int p){
    *perm |= p;
}

//Remove permission function
void remove_perm(unsigned int *perm, unsigned int p){
    *perm &= ~p;
}

//Check user permission
int has_perm(unsigned int perm, unsigned int p){
    return (perm & p) == p;
}

void print_status(unsigned int perm){
    if (has_perm(perm, READ)) printf("R\n"); else printf("-\n");
    if (has_perm(perm, WRITE)) printf("W\n"); else printf("-\n");
    if (has_perm(perm, EXECUTE)) printf("X\n"); else printf("-\n");
}

int main(){
    unsigned int user_perm = WRITE | EXECUTE; //No permission
    add_perm(&user_perm,READ); //Add READ permission
    print_status(user_perm); //Print active permissions
}
