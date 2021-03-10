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
	set_id(({ "tattoo", " stars", " star tattoo", " stars tattoo" }));
	set_short("Seven %^BLUE%^stars%^RESET%^ are in this tattoo.  They are on this elf's wrist, hand and arm.  They go upward in a %^BLUE%^swirling pattern.");
	set_long(
@MYLONG
Seven %^BLUE%^stars%^RESET%^ are in this tattoo.  They are on this elf's wrist, hand and arm.  They go upward in a %^BLUE%^swirling pattern.

MYLONG
	);
	set_limbs(({"left arm"}));
	set_wear((:TO,"wear_me":));
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

