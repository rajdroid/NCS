#ifndef NCS_STRING_LIBRARY_H
#define NCS_STRING_LIBRARY_H

#include <stddef.h>

char *ncs_new(const char *str);
size_t ncs_len(const char *str);
char* ncs_cat(const char *nstr, const char *str);
void ncs_free(const char *str);

#endif
