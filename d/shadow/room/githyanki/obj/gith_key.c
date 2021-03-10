//Githyanki crystal key - Githyanki Fortress - LoKi - 07-02-2008

#include <std.h>
#include "../githyanki.h"
inherit OBJECT;

void create(){
    ::create();
    set_name("gith_key");
    set_id(({"key","gith key","jail key","crystal key"}));
    set_short("%^RESET%^%^ORANGE%^cr%^RESET%^%^YELLOW%^y%^RESET%^%^ORANGE%^st%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^l ke%^RESET%^%^YELLOW%^y%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^Seemingly grown from cr%^RESET%^%^YELLOW%^y%^RESET%^%^ORANGE%^st%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^l, this key is a stunning creation. It has the rough shape of a normal key, but is obviously for a lock not of human creation. A %^RESET%^%^BOLD%^%^BLACK%^bl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ck silk ribb%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^n %^RESET%^%^ORANGE%^ties to the end of it%^RESET%^");
    set_weight(1);
    set_value(2000);
}
