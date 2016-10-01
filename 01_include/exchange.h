#ifndef __EXCHANGE__H__
#define __EXCHANGE__H__

#include "json_parsing.h"
#include "curl_struct.h"

void get_exchange   (void);

struct json_object  *exchange_data;

#endif
