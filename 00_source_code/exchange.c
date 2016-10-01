
#include "exchange.h"

void    get_exchange    (void)
{
    const char *url = EXCHANGE;

    set_curl_opt(url);

    get_curl_data();

    exchange_data   = json_tokener_parse(target_data.memory);

    json_parsing_print(exchange_data);
}
