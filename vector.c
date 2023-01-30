#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <assert.h>

// initializing the vector
void init(Vector *vector, int memorySize){
    // returns the Vector struct with set parameters
    (*vector).array = malloc(sizeof(int) * memorySize);
    (*vector).memorySize =  memorySize;
    (*vector).size = 0;
}

// printing out the contents of the vectors
void print(Vector *vector){
    for(int i = 0; i < (*vector).size; i++){
        printf("%i\n", (*vector).array[i]);
    }
}

// resizing the vector's array
void resize(Vector *vector){
    int nMemorySize = 2 * (*vector).memorySize;
    int* narray = malloc(sizeof(int) * nMemorySize);
    for(int i = 0; i <= (*vector).size; i++){
        narray[i] = (*vector).array[i];
    }
    free((*vector).array);
    (*vector).array = narray;
    (*vector).memorySize =  nMemorySize;
}

// inserting the value at the specific location
int insert(Vector *vector, int location, int value){
    // conditions for invalid location
    if ((location > (*vector).size) || (location < 0)) {
        return 0;
    }
    // else if we can actually insert it
    else {
        // check if we need to resize
        if ((*vector).memorySize == (*vector).size){
            resize(vector);
        }
        // update the size variable
        (*vector).size++;
        // move all elements up by 1 position
        for(int i = (*vector).size; i > location; i--){
            (*vector).array[i] =  (*vector).array[i - 1];
        }
        // and insert the element
        (*vector).array[location] = value;
        return 1;
    }
}


//Obtains value at location inside the Vector
int get(Vector *vector, int location, int *value){
    if ((location >= (*vector).size) || (location < 0)) {
        return 0;
    }
    else{
        (*value) = (*vector).array[location];
        return 1;
    }
}

// Removes the array associated with the Vector.
void cleanup(Vector *vector){
    free((*vector).array);
}

// deleting the value at the specific location
int delete(Vector *vector, int location){
    // conditions for invalid location
    if ((location >= (*vector).size) || (location < 0)) {
        return 0;
    }
    // else if we can actually delete it
    else {
        // move all elements down by 1 position, deleting the element at the location
        for(int i = location; i < (*vector).size-1; i++){
            (*vector).array[i] =  (*vector).array[i + 1];
        }
        // update the size variable
        (*vector).size--;
        return 1;
    }
}


