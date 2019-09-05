#include "library.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Brief: Allocate dynamic storage long enough to store
 *      [meta data] + [original string]
 * This will copy passed string into dynamically allocated storage
 * and store length of a string in meta-data
 *
 * Args: constant pointer to character string
 *
 * Returns: NCS string containing meta-data + original string. Pointer is
 * pointing to starting of a string. So, that normal C string functions
 * works just fine out of box.
 */
char* ncs_new(const char *str)
{
    size_t len = strlen(str);
    char *new_str = (char *)malloc(sizeof(size_t) + len + 1);
    size_t *lptr = (size_t *)new_str;
    *lptr = len;
    new_str = (char *)++lptr;
    strcpy(new_str, str);
    return new_str;
}


/*
 * Brief: Find length of a NCS string from the meta-data.
 * Args: NCS string [Caution: passing normal string might result in an incorrect data or a crash]
 * Returns: Length of a string
 */
size_t ncs_len(const char *str)
{
    size_t *lptr = (size_t *)str;
    --lptr;
    return *lptr;
}


/*
 * Brief: Concatenate C string into NCS string
 * Arg1: NCS string [Caution: passing normal string might result in an incorrect data or a crash]
 * Arg2: C string [You can also pass NCS string]
 * Returns: New concatenated NCS string
 */
char* ncs_cat(const char *nstr, const char *str)
{
    size_t *ncs_lptr = (size_t *)nstr;
    --ncs_lptr;
    size_t new_len = *ncs_lptr + strlen(str);
    char *ncs_cat_str = (char *)malloc(sizeof(size_t) + new_len + 1);

    size_t *lptr = (size_t *)ncs_cat_str;
    *lptr = new_len;
    ncs_cat_str = (char *)++lptr;
    strcpy(ncs_cat_str, nstr);
    strcat(ncs_cat_str, str);

    return ncs_cat_str;
}


/*
 * Brief: Deallocate NCS string by calling system free() call
 * Args: Pointer to NCS string [Caution: Passing normal string might result in a crash]
 * Returns: Nothing
 */
void ncs_free(const char *str)
{
    size_t *lptr = (size_t *)str;
    lptr--;
    free(lptr);
    return;
}
