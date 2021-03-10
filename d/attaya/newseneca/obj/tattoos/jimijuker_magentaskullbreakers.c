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
	set_id(({ "tattoo" }));
	set_short("A small magenta colored cracked skull tattoo with the word "SKULLBREAKERS CLAN" written under it on his neck");
	set_long(
@MYLONG
This masterfully drawn tatt was inked by a steadied and skilled hand. The grinning cracked skull is magenta colored with bold-black detailling. Written under the skull are the words "SKULLBREAKERS CLAN". The magically embodied ink allows the words to be read in any language.

MYLONG
	);
	set_limbs(({"neck"}));
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

