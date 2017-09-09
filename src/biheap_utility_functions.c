

/************************************************************************************
    Implementation of Binary Heap Data Structure Utility functions
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#include "biheap.h"
#include <string.h>
#include <stdlib.h>







int biheap_init(BiHeap *heap, void *pArray, unsigned int nCount,
            unsigned int nWidth, int (*fpCompare) (const void *arg1, const void *arg2))
{
    
    /* Check for invalid function arguments */
    if (heap == 0 || pArray == 0 || nWidth == 0 || fpCompare == 0)
        return -1;
    
    heap->pArrayElem = pArray;
    heap->elemCount = nCount;
    heap->elemWidth = nWidth;
    heap->fpCompare = fpCompare;
    heap->pSwapMemory = (void *) malloc(nWidth);
    
    return 0;
}



void biheap_destroy(BiHeap *heap) {
    
    
    /* Check for invalid algorithm arguments */
    if (heap == 0)
        return;
    
    free((void *) heap->pSwapMemory);
    memset((void *) heap, 0, sizeof(BiHeap));
    
    return;
}



int biheap_swapElements(unsigned int index1, unsigned int index2, BiHeap *heap) {
    
    unsigned char *pElem1, *pElem2;
    
    pElem1 = ((unsigned char *) biheap_array(heap)) + (biheap_width(heap) * index1);
    pElem2 = ((unsigned char *) biheap_array(heap)) + (biheap_width(heap) * index2);
    
    memcpy((void *) heap->pSwapMemory, (const void *) pElem1,            biheap_width(heap));
    memcpy((void *) pElem1,            (const void *) pElem2,            biheap_width(heap));
    memcpy((void *) pElem2,            (const void *) heap->pSwapMemory, biheap_width(heap));
    
    return 0;
}


