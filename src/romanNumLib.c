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
    char* p;
    
    strcpy(buf, aval);
    strcat(buf, bval);
    if ((p = strstr(buf, "iiiii")) != NULL)
    {
        int idx;
        int count = p - buf;
        strncpy(sum, p, count);
        strcat(sum, "v");
        idx = count + 5;
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

