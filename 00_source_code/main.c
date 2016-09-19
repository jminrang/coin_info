#include "curl_struct.h"
#include "json_parsing.h"

int main()
{
    init_curl();

    set_curl_opt();

    get_curl_data();

    del_curl();

    json_parsing();

    return 0;
}
