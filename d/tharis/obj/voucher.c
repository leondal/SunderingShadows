#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id( ({"paper","voucher"}) );
    set_name("voucher");
 	set_short("A voucher");
    set_weight(1);
    set("long", "This voucher needs to be sold at the exchange");
    set_value(0);
}
