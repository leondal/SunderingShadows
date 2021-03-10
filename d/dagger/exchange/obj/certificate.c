//Exchange commodity cerfiticate - Merchanct Exchange - LoKi - 18-02-2008

#include <std.h>
#include "../exchange.h"
inherit OBJECT;

int quantity;
string cert_type;
string cert_type_friendly;

void init() {
   ::init();
   add_action("how_much","examine");
}


void create(){
    ::create();
    set_name("certificate");
    set_id(({"cert","paper","certificate"}));
    set_short("%^RESET%^%^ORANGE%^A certificate%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This certificate is written carefully"+
" on a fine paper in a flowing script. In large bold print at the top "+
"it declares that it is a certificate of commodity under the %^RESET%^"+
"%^YELLOW%^Free Merchant's Exchange%^RESET%^%^ORANGE%^. What follows is"+
" a large description in barely understandable script concerning the "+
"legalities of the certificate. You can %^RESET%^%^BOLD%^%^WHITE%^'examine certificate'"+
" %^RESET%^%^ORANGE%^the certificate to know what commodity and what value "+
"the certificate is for. The bottom of the certificate is dominated by the"+
" flowing signature of %^RESET%^%^WHITE%^Randolph Spatch, Clerk of the "+
"Exchange%^RESET%^%^ORANGE%^. A %^RESET%^%^BOLD%^%^RED%^small red wax "+
"seal %^RESET%^%^ORANGE%^finishes the document%^RESET%^\n\n");
    set_weight(1);
    set_value(1);
}

void set_value(int quantity_asked){
    quantity = quantity_asked;
}

void set_type(string type, string type_asked){
    cert_type = type;
    cert_type_friendly = type_asked;
}

int check_value(){
    return quantity;
}

string check_type(){
    return cert_type;
}

int how_much(string str){
    if(str != "certificate"){
        return 0;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^After reviewing the certificate, you see it is worth "+quantity+" lots of "+cert_type_friendly+".");
    return 1;
}
