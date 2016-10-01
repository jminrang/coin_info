#ifndef __JSON_PARSING_H__
#define __JSON_PARSING_H__
/*
    poloniex format
   "USDT_ETC": {
   "id": 173,
   "last": "1.26396573",
   "lowestAsk": "1.27393670",
   "highestBid": "1.25913144",
   "percentChange": "0.01230639",
   "baseVolume": "14698.22885464",
   "quoteVolume": "11751.99437738",
   "isFrozen": "0",
   "high24hr": "1.28158919",
   "low24hr": "1.22902405"
   }
*/

typedef struct  exchange_matching   {
    int     id;
    double  last;
    double  lowest_ask;
    double  highest_bid;
    double  percent_change;
    double  base_volume;
    double  quote_volume;
    double  is_frozen;
    double  high_24hr;
    double  low_24hr;
} exchange_matching_t;

typedef struct  exchange    {
    const char                  *exchange;
    struct exchange_matching    matching; 
    struct exchange             *prev;
    struct exchange             *next;
} exchange_t;

#define ENUM_TO_STRING(x)   #x

struct exchange coin_exchange_data;

typedef enum {false, true} bool;

void json_parsing (void);
void json_parsing_mem_debug_front(void);
void json_parsing_mem_debug(void);

#endif
