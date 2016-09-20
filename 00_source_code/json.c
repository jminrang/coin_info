#include "curl_struct.h"
#include "json_parsing.h"

void json_parsing_print(json_object *obj)
{
    printf("json data\n%s\n", json_object_to_json_string_ext(obj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY));

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
