#ifndef __JSON_PARSING_H__
#define __JSON_PARSING_H__
/*
   "tag": "ETH",
   "algorithm": "Ethash",
   "block_time": "13.6025",
   "block_reward": 5.000000,
   "block_reward24": 5.000000,
   "last_block": 2293093,
   "difficulty": 68498882700885.500000,
   "difficulty24": 63441880821047.898438,
   "nethash": "5035756860936.261716596213931262635544936592538136",
   "exchange_rate": 0.022067,
   "exchange_rate24": 0.021427,
   "exchange_rate_vol": 14153.215720,
   "exchange_rate_curr": "BTC",
   "market_cap": "$1,130,900,929.35",
   "estimated_rewards": "0.1072",
   "estimated_rewards24": "0.1158",
   "btc_revenue": "0.00237",
   "btc_revenue24": "0.00255",
   "profitability": 100,
   "profitability24": 100,
   "lagging": false,
   "timestamp": 1474360026
*/
struct coin {
    json_object *data;
    json_object *tag;
    const char *tag_data;
};

void json_parsing (void);

#endif
