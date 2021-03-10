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
	set_value(15000);
	set_id(({ "blue-white star with eight points " }));
	set_short(" %^BOLD%^%^BLUE%^A sm%^RESET%^%^BLUE%^a%^BOLD%^ll blue%^WHITE%^-white %^BLUE%^star with eight points radiating in all directions.%^RESET%^");
	set_long(
@MYLONG
 %^BOLD%^%^BLUE%^A small blue-%^WHITE%^white %^BLUE%^star with eight points radiating in all directions. Placed on her ankle, it is a reminder of times not so long ago when her fanily was lost to her. %^RESET%^

MYLONG
	);
	set_limbs(({"right leg"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

