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
    strcpy(sum, aval);
    strcat(sum, bval);
    
    return 1;
}

/****************************************************************************************/
int romanNumbersSub(const char *aval, const char *bval, char *diff)
{
    return 1;
}

