#include "curl_struct.h"
#include "json_parsing.h"

int main(int argc, char *argv[])
{
    const char  *url    = URL_POLONIEX;

    init_curl();

    set_curl_opt(url);

    get_curl_data();

    del_curl();

    json_parsing();

    return 0;
}
