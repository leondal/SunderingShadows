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
	set_id(({ "tattoo", " circle" }));
	set_short("%^BOLD%^%^BLACK%^A tiny %^BOLD%^%^BLACK%^bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck circle%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^ORANGE%^This a very simply tattoo, of a perfect %^BOLD%^%^BLACK%^bl%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^ck circle%^RESET%^%^ORANGE%^ upon Ibn's forehead.

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

