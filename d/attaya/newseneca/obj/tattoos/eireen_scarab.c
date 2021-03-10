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
	set_value(10000);
	set_id(({ "tattoo", "scarab tattoo", "scarab", "tiny tattoo" }));
	set_short("%^BOLD%^%^WHITE%^ a tiny %^RESET%^%^ORANGE%^s%^GREEN%^c%^CYAN%^a%^ORANGE%^r%^GREEN%^a%^ORANGE%^b%^BOLD%^%^WHITE%^ tattoo%^RESET%^");
	set_long(
@MYLONG
%^BOLD%^%^WHITE%^a tiny, yet finely detailed tattoo of a %^RESET%^%^ORANGE%^s%^GREEN%^c%^CYAN%^a%^ORANGE%^r%^GREEN%^a%^ORANGE%^b %^GREEN%^b%^CYAN%^e%^ORANGE%^e%^CYAN%^t%^ORANGE%^l%^GREEN%^e %^BOLD%^%^WHITE%^with its %^RESET%^%^ORANGE%^golden wings%^BOLD%^%^WHITE%^ outstretched%^RESET%^

MYLONG
	);
	set_limbs(({"head"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "tiny"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

