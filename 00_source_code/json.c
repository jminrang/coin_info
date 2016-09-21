#include "curl_struct.h"
#include "json_parsing.h"

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

void json_parsing (void)
{
    struct json_object *all_data;
    struct json_object *coins, *ethereum, *ethereum_tag;
    int coins_len, ethereum_len, ethereum_tag_len;

    all_data = json_tokener_parse(target_data.memory);

//    json_parsing_print(all_data);

    coins   = json_object_object_get(all_data, "coins");
    coins_len  = json_object_array_length(coins);

    struct  coin    ethereum_data;

    ethereum_data.data  = json_object_object_get(coins, "Ethereum");
    ethereum_data.tag   = json_object_object_get(ethereum_data.data, "tag");
    ethereum_data.tag_data  = malloc(json_object_get_string_len(ethereum_data.tag));
    ethereum_data.tag_data  = json_object_get_string(ethereum_data.tag);

    printf("ethereum tag len  = %d\n", json_object_get_string_len(ethereum_data.tag));
    printf("ethereum tag data = %s\n", ethereum_data.tag_data);
/*
    ethereum    = json_object_object_get(coins, "Ethereum");
    ethereum_len    = json_object_array_length(ethereum);

    ethereum_tag    = json_object_object_get(ethereum, "tag");
    ethereum_tag_len    = json_object_get_string_len(ethereum_tag);

    const char *string;

    string  = malloc(json_object_get_string_len(ethereum_tag));
    string = json_object_get_string(ethereum_tag);

    printf("coins len = %d\n", coins_len);
    printf("ethereum len = %d\n", ethereum_len);
    printf("ethereum tag len = %d\n", ethereum_tag_len);
    printf("etheruem tag = %s\n", string);
    json_parsing_print(ethereum);
*/
}
