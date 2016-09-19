#include "curl_struct.h"
#include "json_parsing.h"

void json_parsing (void)
{
    json_object *new_obj;

    new_obj = json_tokener_parse(target_data.memory);
//  all data print
    printf("new_obj.to_string()=%s\n", json_object_to_json_string(new_obj));
}
