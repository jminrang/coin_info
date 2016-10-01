#ifndef __EXCHANGE__H__
#define __EXCHANGE__H__

#include "json_parsing.h"
#include "curl_struct.h"

/*
{
    "query": {
        "count": 1,
            "created": "2016-10-01T11:37:48Z",
            "lang": "en-US",
            "results": {
                "rate": {
                    "id": "USDKRW",
                    "Name": "USD\/KRW",
                    "Rate": "1098.3000",
                    "Date": "9\/30\/2016",
                    "Time": "10:12pm",
                    "Ask": "1099.3000",
                    "Bid":
                        "1098.3000"
                }
            }
    }
}
*/

double  exchange_rate;

void    get_exchange        (void);
double  get_exchange_rate   (struct json_object *obj);

#endif
