#include "romanNumLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char*   tensSymbol;
    char*   ninesSymbol;
    char*   fivesSymbol;
    char*   foursSymbol;
    char*   onesSymbol;
} romanDecimalSymbols_t;

static const romanDecimalSymbols_t _romanSymbolSets[]  =
{
    { "",    "",  "",   "", "m" },
    { "m", "cm", "d", "cd", "c" },
    { "c", "xc", "l", "xl", "x" },
    { "x", "ix", "v", "iv", "i" }
};

#define DECIMAL_BASE    10
#define DECIMAL_NINE    9
#define DECIMAL_FIVE    5
#define DECIMAL_FOUR    4
#define DECIMAL_ONE     1


/****************************************************************************************/
//  Private Functions
/****************************************************************************************/
static const char * _convertDecimalSymbolsToCount(const char *pInp, int *pDecimalVal, const romanDecimalSymbols_t* pSymbols)
{
    if (strlen(pSymbols->ninesSymbol) != 0 && strncmp(pInp, pSymbols->ninesSymbol, strlen(pSymbols->ninesSymbol)) == 0)
    {
        (*pDecimalVal) += 9;
        pInp += strlen(pSymbols->ninesSymbol);
    }
    else if (strlen(pSymbols->foursSymbol) != 0 && strncmp(pInp, pSymbols->foursSymbol, strlen(pSymbols->foursSymbol)) == 0)
    {
        (*pDecimalVal) += 4;
        pInp += strlen(pSymbols->foursSymbol);
    }
    else
    {
        if (strlen(pSymbols->fivesSymbol) != 0 && strncmp(pInp, pSymbols->fivesSymbol, strlen(pSymbols->fivesSymbol)) == 0)
        {
            (*pDecimalVal) += 5;
            pInp += strlen(pSymbols->fivesSymbol);
        }
        
        while (strncmp(pInp, pSymbols->onesSymbol, strlen(pSymbols->onesSymbol)) == 0)
        {
            ++(*pDecimalVal);
            pInp += strlen(pSymbols->onesSymbol);
        }
    }
    
    return pInp;
}

/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
int romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
    int bValid = 1;
    int decimalVal[4];
    char decimalBuf[4][16];
    int i;
    int carry;
    const int loopCount = sizeof(_romanSymbolSets) / sizeof(_romanSymbolSets[0]);
    
    const char* pA = aval;
    const char* pB = bval;
    
    sum[0] = '\0';
    
    // printf("Accumulating %s + %s\n", aval, bval);

    for (i = 0; i < loopCount; ++i)
    {
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];
        decimalVal[i] = 0;
        
        pA = _convertDecimalSymbolsToCount(pA, &decimalVal[i], pSymbols);
        pB = _convertDecimalSymbolsToCount(pB, &decimalVal[i], pSymbols);
        
        // printf("Digit Accum [%d] %d\n", i, decimalVal[i]);
    }
    
    carry = 0;
    for (i = loopCount-1; i >= 0; --i)
    {
        int j;
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];
        int thisDecimalVal = decimalVal[i] + carry;
        
        decimalBuf[i][0] = '\0';
        carry = 0;
        
        if (thisDecimalVal >= DECIMAL_BASE)
        {
            carry = 1;
            thisDecimalVal -= DECIMAL_BASE;
        }
        
        if (strlen(pSymbols->ninesSymbol) != 0 && thisDecimalVal == DECIMAL_NINE)
        {
            strcat(decimalBuf[i], pSymbols->ninesSymbol);
        }
        else if (strlen(pSymbols->foursSymbol) != 0 && thisDecimalVal == DECIMAL_FOUR)
        {
            strcat(decimalBuf[i], pSymbols->foursSymbol);
        }
        else
        {
            if (strlen(pSymbols->fivesSymbol) != 0 && thisDecimalVal >= DECIMAL_FIVE)
            {
                strcat(decimalBuf[i], pSymbols->fivesSymbol);
                thisDecimalVal -= DECIMAL_FIVE;
            }
            
            if (thisDecimalVal > 3)
            {
                bValid = 0;
                break;
            }
            
            for (j =  0; j < thisDecimalVal; ++j)
            {
                strcat(decimalBuf[i], pSymbols->onesSymbol);
            }
        }
    }
    
    if (carry)
    {
        bValid = 0;
    }
    
    for (i = 0; i < loopCount && bValid; ++i)
    {
        strcat(sum, decimalBuf[i]);
    }
    
    // printf("result: %s\n\n", sum);
    
    return bValid;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    int bValid = 1;
    int decimalVal[4];
    char decimalBuf[4][16];
    int i;
    int borrow;
    const int loopCount = sizeof(_romanSymbolSets) / sizeof(_romanSymbolSets[0]);
    
    const char* pA = aval;
    const char* pB = bval;
    
    diff[0] = '\0';
    
    printf("Computing %s - %s\n", aval, bval);
    
    for (i = 0; i < loopCount; ++i)
    {
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];
        decimalVal[i] = 0;
        
        pB = _convertDecimalSymbolsToCount(pB, &decimalVal[i], pSymbols);
        decimalVal[i] *= -1;
        pA = _convertDecimalSymbolsToCount(pA, &decimalVal[i], pSymbols);
        
        printf("Digit Diff [%d] %d\n", i, decimalVal[i]);
    }
    
    borrow = 0;
    for (i = loopCount-1; i >= 0; --i)
    {
        int j;
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];
        int thisDecimalVal = decimalVal[i] - borrow;
        
        decimalBuf[i][0] = '\0';
        borrow = 0;
        
        if (thisDecimalVal < 0)
        {
            borrow = 1;
            thisDecimalVal += DECIMAL_BASE;
        }
        
        if (strlen(pSymbols->ninesSymbol) != 0 && thisDecimalVal == DECIMAL_NINE)
        {
            strcat(decimalBuf[i], pSymbols->ninesSymbol);
        }
        else if (strlen(pSymbols->foursSymbol) != 0 && thisDecimalVal == DECIMAL_FOUR)
        {
            strcat(decimalBuf[i], pSymbols->foursSymbol);
        }
        else
        {
            if (strlen(pSymbols->fivesSymbol) != 0 && thisDecimalVal >= DECIMAL_FIVE)
            {
                strcat(decimalBuf[i], pSymbols->fivesSymbol);
                thisDecimalVal -= DECIMAL_FIVE;
            }
            
            if (thisDecimalVal > 3)
            {
                bValid = 0;
                break;
            }
            
            for (j =  0; j < thisDecimalVal; ++j)
            {
                strcat(decimalBuf[i], pSymbols->onesSymbol);
            }
        }
    }
    
    if (borrow)
    {
        bValid = 0;
    }
    
    for (i = 0; i < loopCount && bValid; ++i)
    {
        strcat(diff, decimalBuf[i]);
    }
    
    printf("result: %s\n\n", diff);
    
    return bValid;
}

