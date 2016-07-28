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
static void _catSymbol(char* pBuf, char* pSym, int count)
{
    int i;
    for (i=0; i<count; ++i)
    {
        strcat(pBuf, pSym);
    }
}


static const char * _convertDecimalSymbolsToAllOnes(const char *pInp, char *pAccum, const romanDecimalSymbols_t* pSymbols)
{
    if (strlen(pSymbols->ninesSymbol) != 0 && strncmp(pInp, pSymbols->ninesSymbol, strlen(pSymbols->ninesSymbol)) == 0)
    {
        _catSymbol(pAccum, pSymbols->onesSymbol, 9);
        pInp += strlen(pSymbols->ninesSymbol);
    }
    else if (strlen(pSymbols->foursSymbol) != 0 && strncmp(pInp, pSymbols->foursSymbol, strlen(pSymbols->foursSymbol)) == 0)
    {
        _catSymbol(pAccum, pSymbols->onesSymbol, 4);
        pInp += strlen(pSymbols->foursSymbol);
    }
    else
    {
        if (strlen(pSymbols->fivesSymbol) != 0 && strncmp(pInp, pSymbols->fivesSymbol, strlen(pSymbols->fivesSymbol)) == 0)
        {
            _catSymbol(pAccum, pSymbols->onesSymbol, 5);
            pInp += strlen(pSymbols->fivesSymbol);
        }
        
        while (strncmp(pInp, pSymbols->onesSymbol, strlen(pSymbols->onesSymbol)) == 0)
        {
            _catSymbol(pAccum, pSymbols->onesSymbol, 1);
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
    char accumBuf[4][32];
    int i;
    int carry;
    const int loopCount = sizeof(_romanSymbolSets) / sizeof(_romanSymbolSets[0]);
    
    const char* pA = aval;
    const char* pB = bval;
    
    memset(&accumBuf[0][0], '\0', sizeof(accumBuf));
    sum[0] = '\0';
    
    // printf("Accumulating %s + %s\n", aval, bval);

    for (i = 0; i < loopCount; ++i)
    {
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];
        
        pA = _convertDecimalSymbolsToAllOnes(pA, accumBuf[i], pSymbols);
        pB = _convertDecimalSymbolsToAllOnes(pB, accumBuf[i], pSymbols);
        
        // printf("Digit Accum [%d] %s\n", i, accumBuf[i]);
    }
    
    carry = 0;
    for (i = loopCount-1; i >= 0; --i)
    {
        const romanDecimalSymbols_t* pSymbols = &_romanSymbolSets[i];

        int decimalSymbolLen = strlen(accumBuf[i]) + carry;
        accumBuf[i][0] = '\0';
        carry = 0;
        
        if (strlen(pSymbols->fivesSymbol) != 0 && decimalSymbolLen >= DECIMAL_BASE)
        {
            carry = 1;
            decimalSymbolLen -= DECIMAL_BASE;
        }
        
        if (strlen(pSymbols->fivesSymbol) != 0 && decimalSymbolLen == DECIMAL_NINE)
        {
            strcat(accumBuf[i], pSymbols->ninesSymbol);
        }
        else if (strlen(pSymbols->fivesSymbol) != 0 && decimalSymbolLen == DECIMAL_FOUR)
        {
            strcat(accumBuf[i], pSymbols->foursSymbol);
        }
        else
        {
            if (strlen(pSymbols->fivesSymbol) != 0 && decimalSymbolLen >= DECIMAL_FIVE)
            {
                strcat(accumBuf[i], pSymbols->fivesSymbol);
                decimalSymbolLen -= DECIMAL_FIVE;
            }
            
            if (decimalSymbolLen > 3)
            {
                bValid = 0;
                memset(&accumBuf[0][0], '\0', sizeof(accumBuf));
                break;
            }
            _catSymbol(accumBuf[i], pSymbols->onesSymbol, decimalSymbolLen);
        }
    }
    
    for (i = 0; i < loopCount && bValid; ++i)
    {
        strcat(sum, accumBuf[i]);
    }
    
    // printf("result: %s\n\n", sum);
    
    
    return bValid;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return 1;
}

