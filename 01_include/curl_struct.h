#ifndef __CURL_STRUCT_H__
#define __CURL_STRUCT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <json/json.h>

#define URL_WHAT_TO_MINE    "http://www.whattomine.com/coins.json"
#define URL_POLONIEX        "https://poloniex.com/public?command=returnTicker"
#define EXCHANGE            "http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.xchange%20where%20pair%20in%20(%22USDKRW%22)&format=json&env=store://datatables.org/alltableswithkeys&callback"

struct  memory  {
    char    *memory;
    size_t  size;
};

CURL        *curl_handle;

struct memory   target_data;

void    init_curl       (void);
void    set_curl_opt    (const char *url);
int     get_curl_data   (void);
void    del_curl        (void);

size_t  write_memory_callback (void *contents, size_t size, size_t num_of_byte, void *user_p);

#endif
