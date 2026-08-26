//System permission
#define READ 4 //0b100 ou 0x04
#define WRITE 2 //0b010 ou 0x02
#define EXECUTE 1 //0b001 ou 0x01

#include<stdio.h>

//Add permission function
void add_perm(unsigned int *perm, unsigned int p){
    *perm |= p; //Example: perm = 0b011 OR 0b100 = 0b111
}

//Remove permission function
void remove_perm(unsigned int *perm, unsigned int p){
    *perm &= ~p; //perm = 0b111 AND ~(WRITE) => 0b111 AND ~(010) => 0b111 AND 101 = 0b101
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
    unsigned int user_perm = WRITE | EXECUTE; //WRITE OR EXECUTE = 0b010 OR 0b001 = 0b011
    add_perm(&user_perm,READ); //Add READ permission
    remove_perm(&user_perm,WRITE); //Remove WRITE permission
    print_status(user_perm); //Print active permissions
}
