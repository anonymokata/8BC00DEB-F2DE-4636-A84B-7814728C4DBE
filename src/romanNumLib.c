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
    char* p;
    
    sum[0] = '\0';
    
    if(*aval == 'v')
    {
        strcat(sum, "v");
        ++aval;
    }

    if(*bval == 'v')
    {
        strcat(sum, "v");
        ++bval;
    }
    
    strcat(sum, aval);
    strcat(sum, bval);

    if (((p = strstr(sum, "iiv")) != NULL) ||
        ((p = strstr(sum, "ivi")) != NULL))
    {
        *(p++) = 'v';
        strcpy(p, p+3);
    }
    
    if ((p = strstr(sum, "iiiii")) != NULL)
    {
        *(p++) = 'v';
        strcpy(p, p+5);
    }
    else if ((p = strstr(sum, "iiii")) != NULL)
    {
        *(p++) = 'i';
        *(p++) = 'v';
        strcpy(p, p+5);
    }
    
    
    return 1;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return 1;
}

