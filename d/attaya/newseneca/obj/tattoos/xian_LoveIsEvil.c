#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_weight(0);
        set_ac(0);
        set_type("ring");
        set_property("death keep",1);
        set_property("no animate",1);
        set_name("tattoo");
        set_value(20000);
        set_id(({ "tattoo", " Love Is Evil tattoo", " black tattoo", " medium tattoo"
}));
        set_short("%^RED%^A %^BLACK%^%^BOLD%^black %^RESET%^%^RED%^and red medium tattoo that reads '%^BLACK%^%^BOLD%^L%^RED%^o%^RESET%^%^RED%^v%^BLACK%^%^BOLD%^e %^RED%^i%^RESET%^%^RED%^s %^BLACK%^%^BOLD%^E%^RED%^v%^RESET%^%^RED%^i%^BLACK%^%^BOLD%^l%^RED%^'");
        set_long(
@MYLONG
%^BLACK%^%^BOLD%^This is a black and %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^tattoo that reads %^RESET%^%^RED%^'%^BLACK%^%^BOLD%^L%^RED%^o%^RESET%^%^RED%^v%^BLACK%^%^BOLD%^e %^RED%^i%^RESET%^%^RED%^s %^BLACK%^%^BOLD%^E%^RED%^v%^RESET%^%^RED%^i%^BLACK%^%^BOLD%^l%^RESET%^%^RED%^' %^BLACK%^%^BOLD%^it goes around his
neck.  The '%^RED%^L%^BLACK%^o%^RESET%^RED%^v%^BOLD%^e%^BLACK%^' starts on his left side on his neck, the '%^RED%^i%^RESET%^%^RED%^s %^BLACK%^%^BOLD%^' is right in the middle of his neck, and the "E%^RED%^v%^RESET%^%^RED%^i%^BLACK%^%^BOLD%^l" is on the right side.

MYLONG
        );
        set_limbs(({"neck"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "medium"; }

int is_tattoo(){ return 1; }

int wear_me(){
        "daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}
