#include "exchange.h"

void    get_exchange    (void)
{
    const char *url = EXCHANGE;

    struct json_object  *exchange_data;


    set_curl_opt(url);

    get_curl_data();

    exchange_data   = json_tokener_parse(target_data.memory);

    exchange_rate   = get_exchange_rate(exchange_data);

//    printf("Exchange Rate : %.8f\n", exchange_rate);
}

double  get_exchange_rate   (struct json_object *obj)
{
    struct json_object  *tmp_obj;
    const char          *str;

    //  query -> results -> rate -> Rate
    json_object_object_get_ex(obj, "query", &tmp_obj);
    json_object_object_get_ex(tmp_obj, "results", &tmp_obj);
    json_object_object_get_ex(tmp_obj, "rate", &tmp_obj);
    json_object_object_get_ex(tmp_obj, "Rate", &tmp_obj);

    str = malloc(json_object_get_string_len(tmp_obj));
    str = json_object_get_string(tmp_obj);

    return  atof(str);
}
