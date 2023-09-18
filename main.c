#include <stdio.h>
#include <stdlib.h>

void qsort ( void* base, size_t num, size_t size, int ( *compara ) ( const void*, const void* ) );
int compara ( const void* a, const void* b );
int* topKFrequent( int* nums, int numsSize, int k, int* returnSize );
void tryChange( int* vals, int* freqs, int currentNum, int countFreq, int k );


int main()
{
    int *num, aux[1] = {1}, k = 1, *freqs, returnSize;

    num = ( int * ) calloc ( 1,  sizeof( int ) );
    
    for( int i = 0; i < 1; i++ ) {
        num[i] = aux[i];
    }

    for( int i = 0; i < 1; i++ ) {
        printf( "%d\n", num[i] );
    }

    qsort ( num, 1, sizeof( int ), compara );
    printf( "Ordenado:\n" );
    
    for( int i = 0; i < 1; i++ ) {
        printf( "%d\n", num[i] );
    }

    freqs = topKFrequent( num, 1, k, &returnSize );
    printf( "K mais frequentes: \n" );
    for( int i = 0; i < k; i++ ) {
        printf( "%d\n", freqs[i] );
    }

    

    return 0;
}

int compara ( const void* a, const void* b ) {
    if ( *( int * ) a == *( int * ) b ) {
        return 0;
    } else {
        if ( *( int * ) a < *( int * ) b ) {
            return -1;
        } else {
            return 1;
        }
    }
        
}

int* topKFrequent( int* nums, int numsSize, int k, int* returnSize ) {
    int *vals, *freqs, currentNum, countFreq, j = 0;
    *returnSize = k;

    vals = ( int * ) calloc ( k, sizeof( int ) );
    freqs = ( int * ) calloc ( k, sizeof( int ) );
    

    qsort ( nums, numsSize, sizeof( int ), compara );

    currentNum = nums[0];
    countFreq = 1;

    for( int i = 0; i < numsSize - 1; i++ ) {
        if ( currentNum == nums[i + 1] ) {
            countFreq++;
        } else {
            if ( j == k ) {
                tryChange( vals, freqs, currentNum, countFreq, k );
            } else {
                vals[j] = currentNum;
                freqs[j] = countFreq;
                j++;
            }
            currentNum = nums[i + 1];
            countFreq = 1;
        }
    }

    tryChange( vals, freqs, currentNum, countFreq, k );

    free( freqs );

    return vals;
}

void tryChange( int* vals, int* freqs, int currentNum, int countFreq, int k ) {
    int leastFreq, leastFreqIndex, i;
    leastFreq = freqs[0];
    leastFreqIndex = 0;

    for( int j = 1; j < k; j++ ) {
        if( freqs[j] < leastFreq ) {
            leastFreq = freqs[j];
            leastFreqIndex = j;
        }
    }
    i = leastFreqIndex;
    if( countFreq > freqs[i] ) {
        vals[i] = currentNum;
        freqs[i] = countFreq;
    }
}

        
 
