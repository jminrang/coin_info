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

void json_parsing (void)
{
    struct json_object *all_data;

    int count;

    all_data = json_tokener_parse(target_data.memory);

//    json_parsing_print(all_data);

    count   = json_count_exchange(all_data);

    printf("exchange count : %d\n", count);
}
