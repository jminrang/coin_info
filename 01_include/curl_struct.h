#ifndef __CURL_STRUCT_H__
#define __CURL_STRUCT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <json/json.h>

#define TARGET_URL  "http://www.whattomine.com/coins.json"

struct  memory  {
    char    *memory;
    size_t  size;
};

CURL        *curl_handle;

struct memory   target_data;

void    init_curl       (void);
void    set_curl_opt    (void);
int     get_curl_data   (void);
void    del_curl        (void);

size_t  write_memory_callback (void *contents, size_t size, size_t num_of_byte, void *user_p);

#endif
