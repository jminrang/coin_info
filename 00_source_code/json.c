#include "curl_struct.h"
#include "json_parsing.h"

#include <stdlib.h>

void json_parsing_print(json_object *obj)
{
    printf("json data\n%s\n", json_object_to_json_string_ext(obj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY));

}

void json_print_string(json_object *obj)
{
    const char  *string;
    int         string_len;

    string_len  = json_object_get_string_len(obj);
    string  = malloc(string_len);
    string  = json_object_get_string(obj);

    printf("String = %s\n", string);
}

void json_type_check(json_object *obj)
{
    switch(json_object_get_type(obj))   {
        case json_type_null:
            printf("Type : NULL\n");
            break;
        case json_type_boolean:
            printf("Type : boolearn\n");
            break;
        case json_type_double:
            printf("Type : double\n");
            break;
        case json_type_int:
            printf("Type : int\n");
            break;
        case json_type_object:
            printf("Type : object\n");
            break;
        case json_type_array:
            printf("Type : array\n");
            break;
        case json_type_string:
            printf("Type : string\n");
            break;
    }
}

int json_count_exchange(json_object *obj)
{
    struct json_object_iterator it;
    struct json_object_iterator it_end;

    int count   = 0;
    it  = json_object_iter_begin(obj);
    it_end  = json_object_iter_end(obj);

    while(!json_object_iter_equal(&it, &it_end))   {
//        printf("count : %d exchange : %s\n", count, json_object_iter_peek_name(&it));
        count++;
        json_object_iter_next(&it);
    }

    return  count;
}

#define PARSING_DATA(VALUE, TARGET) json_object_object_get_ex(tmp_obj, VALUE, &tmp_obj_1);  \
                                    str = malloc(json_object_get_string_len(tmp_obj_1));    \
                                    str = json_object_get_string(tmp_obj_1);                \
                                    coin_exchange_data.matching.TARGET  = atof(str);

void json_parsing_data(json_object *obj)
{
    struct json_object_iterator it, it_end;
    struct json_object_iterator it_match, it_end_match;
    struct json_object          *tmp_obj, *tmp_obj_1;

    const char  *str;

//    json_parsing_mem_debug_front();

    it      = json_object_iter_begin(obj);
    it_end  = json_object_iter_end(obj);
    
    while(!json_object_iter_equal(&it, &it_end))    {

        coin_exchange_data.exchange = malloc(strlen(json_object_iter_peek_name(&it)));
        coin_exchange_data.exchange = json_object_iter_peek_name(&it);

        tmp_obj = json_object_iter_peek_value(&it);

        it_match        = json_object_iter_begin(tmp_obj);
        it_end_match    = json_object_iter_end(tmp_obj);

        while(!json_object_iter_equal(&it_match, &it_end_match))    {

            PARSING_DATA("id", id);
            PARSING_DATA("last", last);
            PARSING_DATA("lowestAsk", lowest_ask);
            PARSING_DATA("highestBid", highest_bid);
            PARSING_DATA("percentChange",percent_change);
            PARSING_DATA("baseVolume", base_volume);
            PARSING_DATA("quoteVolume", quote_volume);
            PARSING_DATA("isFrozen", is_frozen);
            PARSING_DATA("high24hr", high_24hr);
            PARSING_DATA("low24hr", low_24hr);

            json_object_iter_next(&it_match);
        }

//        json_parsing_mem_debug();
        json_object_iter_next(&it);
    }
}

void json_parsing_mem_debug_front(void)
{
    printf("----------------------------------------------------------------------------------------------");
    printf("------------------------------------------------------------------------------------\n");
    printf("%*s | ", 12, "Exchange");
    printf("%*s | ", 12, "ID");
    printf("%*s | ", 12, "Last");
    printf("%*s | ", 12, "Lowest Ask");
    printf("%*s | ", 12, "Highest Bid");
    printf("%*s | ", 15, "Percent Changed");
    printf("%*s | ", 15, "Base Volume");
    printf("%*s | ", 20, "Quote Volume");
    printf("%*s | ", 12, "Is Frozen");
    printf("%*s | ", 12, "High 24HR");
    printf("%*s | ", 12, "Low  24HR");
    printf("\n");
    printf("----------------------------------------------------------------------------------------------");
    printf("------------------------------------------------------------------------------------\n");
}

void json_parsing_mem_debug(void)
{
#if 0
    printf("Memory pasing debug test\n");
    printf(" Exchange : %s\n", coin_exchange_data.exchange);
    printf(" Matching\n");
    printf("  ID            : %d\n", coin_exchange_data.matching.id);
    printf("  Last          : %0.8f\n", coin_exchange_data.matching.last);
    printf("  Lowest ask    : %0.8f\n", coin_exchange_data.matching.lowest_ask);
    printf("  Highest bid   : %0.8f\n", coin_exchange_data.matching.highest_bid);
    printf("  Percent change: %0.8f\n", coin_exchange_data.matching.percent_change);
    printf("  Base volume   : %0.8f\n", coin_exchange_data.matching.base_volume);
    printf("  Quote voluem  : %0.8f\n", coin_exchange_data.matching.quote_volume);
    printf("  Is frozen     : %0.8f\n", coin_exchange_data.matching.is_frozen);
    printf("  High 24hr     : %0.8f\n", coin_exchange_data.matching.high_24hr);
    printf("  Low  24hr     : %0.8f\n", coin_exchange_data.matching.low_24hr);
#else
    printf("%*s | ", 12, coin_exchange_data.exchange);
    printf("%*d | ", 12, coin_exchange_data.matching.id);
    printf("%*.8lf | ", 12, coin_exchange_data.matching.last);
    printf("%*.8lf | ", 12, coin_exchange_data.matching.lowest_ask);
    printf("%*.8lf | ", 12, coin_exchange_data.matching.highest_bid);
    printf("%*lf | ", 15, coin_exchange_data.matching.percent_change);
    printf("%*lf | ", 15, coin_exchange_data.matching.base_volume);
    printf("%*lf | ", 20, coin_exchange_data.matching.quote_volume);
    printf("%*lf | ", 12, coin_exchange_data.matching.is_frozen);
    printf("%*.8lf | ", 12, coin_exchange_data.matching.high_24hr);
    printf("%*.8lf | ", 12, coin_exchange_data.matching.low_24hr);


    printf("\n");
#endif
}

void json_parsing (void)
{
    struct json_object *all_data;

    int count;

    memset(&coin_exchange_data, 0, sizeof(struct exchange));
    all_data = json_tokener_parse(target_data.memory);

//    json_parsing_print(all_data);

    count   = json_count_exchange(all_data);

    json_parsing_data(all_data);

    printf("exchange count : %d\n", count);
}
