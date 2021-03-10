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
	set_id(({ "tattoo", " skull tattoo" }));
	set_short("A small tattoo of a ^WHITE^ grinning cracked skull ^RESET^ with the word ^MAGENTA^ SKULLBREAKERS ^reset^ written in script under it on his neck");
	set_long(
@MYLONG
This masterfully drawn ^WHITE^ grinning cracked skull ^RESET^ with ^BLACK^ detailing was drawn by a highly-skilled artist. Under the ^WHITE^ skull has the word ^MAGENTA^ SKULLBREAKERS ^RESET^ written in a flowing script. The magically embodied ink allows anyone reading it to understand it in their own native tongue.

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

