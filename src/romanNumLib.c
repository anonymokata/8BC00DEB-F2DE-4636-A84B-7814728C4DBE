#include "romanNumLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/****************************************************************************************/
//  Private Functions
/****************************************************************************************/



/****************************************************************************************/
//  Public Functions
/****************************************************************************************/
int romanNumbersAdd(const char *aval, const char *bval, char *sum)
{
    char buf[80];
    char* pBuf;
    
    buf[0] = '\0';
    
    if(*aval == 'v')
    {
        strcat(buf, "v");
        ++aval;
    }

    if(*bval == 'v')
    {
        strcat(buf, "v");
        ++bval;
    }
    
    strcat(buf, aval);
    strcat(buf, bval);
    if ((pBuf = strstr(buf, "iiiii")) != NULL)
    {
        int idx;
        int count = pBuf - buf;
        strncpy(sum, pBuf, count);
        strcat(sum, "v");
        idx = count + 5;
        strcat(sum, &buf[idx]);
    }
    else if ((pBuf = strstr(buf, "iiii")) != NULL)
    {
        int idx;
        int count = pBuf - buf;
        strncpy(sum, pBuf, count);
        strcat(sum, "iv");
        idx = count + 4;
        strcat(sum, &buf[idx]);
    }
    else
    {
        strcpy(sum, buf);
    }
    
    
    return 1;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return 1;
}

