#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
    map=(HashMap*)malloc(sizeof(HashMap));
    Pair *newpair=createPair(key,value);
    long cap=map->capacity;
    long tam=map->size;
    long pos=hash(key,cap);
    Pair **array=(Pair**)calloc(cap,sizeof(Pair*));
    array=map->buckets;
    if (array[pos]!=NULL){
      for (;pos<cap;pos++){
        if (array[pos]==NULL)
            array[pos]=newpair;
            break;
      }
      tam++;
    }
    else
      array[pos]=newpair;
      map->current=pos;
      tam++;
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
    HashMap *hash=(HashMap*)malloc(sizeof(HashMap));
    hash->buckets=(Pair**)calloc(capacity,sizeof(Pair*));
    hash->size=0;
    hash->capacity=capacity;
    hash->current=-1;
    return hash;
}

void eraseMap(HashMap * map,  char * key) {    
    

}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
