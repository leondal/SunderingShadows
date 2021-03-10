#include <daemons.h>

float currency_rate(string type) { 
    return (float)ECONOMY_D->__Query(type, "rate");
}

float currency_inflation(string type) {
    return (float)ECONOMY_D->__Query(type, "inflation");
}

int currency_weight(string type, int x) {
    return to_int((float)ECONOMY_D->__Query(type, "weight") * x);
}

string *mud_currencies() { return (string *)ECONOMY_D->__QueryCurrencies(); }
