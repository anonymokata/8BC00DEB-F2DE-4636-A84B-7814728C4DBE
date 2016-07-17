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
    int bDone = 1;
    char* p;
    
    sum[0] = '\0';
    
    if (strncmp(aval, "ix", 2) == 0)
    {
        aval = "viiii";
    }
    
    if (strncmp(bval, "ix", 2) == 0)
    {
        bval = "viiii";
    }
    
    
    if (*aval == 'v')
    {
        strcat(sum, "v");
        ++aval;
    }
    
    if (*bval == 'v')
    {
        strcat(sum, "v");
        ++bval;
    }
    
    strcat(sum, aval);
    strcat(sum, bval);
    
    do
    {
        bDone = 1;
        
        if ((p = strstr(sum, "vv")) != NULL)
        {
            *(p++) = 'x';
            strcpy(p, p+1);
            bDone = 0;
        }
        
        if (((p = strstr(sum, "viv")) != NULL) ||
            ((p = strstr(sum, "ivv")) != NULL))
        {
            *(p++) = 'i';
            *(p++) = 'x';
            strcpy(p, p+1);
            bDone = 0;
        }
        
        if (((p = strstr(sum, "iiv")) != NULL) ||
            ((p = strstr(sum, "ivi")) != NULL))
        {
            *(p++) = 'v';
            strcpy(p, p+3);
            bDone = 0;
        }
        
        if ((p = strstr(sum, "iiiii")) != NULL)
        {
            *(p++) = 'v';
            strcpy(p, p+4);
            bDone = 0;
        }
        else if ((p = strstr(sum, "iiii")) != NULL)
        {
            *(p++) = 'i';
            *(p++) = 'v';
            strcpy(p, p+2);
            bDone = 0;
        }

    } while(!bDone);
    
    return 1;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return 1;
}

