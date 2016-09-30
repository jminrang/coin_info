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

#define ENUM_TO_STRING(x)   #x

typedef enum {false, true} bool;

void json_parsing (void);

#endif
