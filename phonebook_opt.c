#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    unsigned int hashnum;
    entry *temp;
    hashnum = bkdr_hash(lastName);
    temp = hashhead[hashnum]->pNext;
    while (temp != NULL) {
        if (strcasecmp(lastName, temp->lastName) == 0) {
            return temp;
        }
        temp = temp->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    unsigned int hashnum;
    hashnum = bkdr_hash(lastName);

    hashtail[hashnum]->pNext = (entry *) malloc(sizeof(entry));
    hashtail[hashnum] = hashtail[hashnum]->pNext;
    strcpy(hashtail[hashnum]->lastName, lastName);
    hashtail[hashnum]->pNext = NULL;

    return e;
}

unsigned int bkdr_hash(char lastName[])
{
    unsigned int seed = 31;
    unsigned int hashnum = 0;
    while (*lastName) {
        hashnum = hashnum * seed + (*lastName++);
    }
    hashnum %= 1024;
    return hashnum;

}
