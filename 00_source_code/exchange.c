
#include "curl_struct.h"

void    get_exchange    (void)
{
    const char *url = EXCHANGE;

    set_curl_opt(url);

    get_curl_data();
}
