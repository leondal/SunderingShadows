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
	set_value(30000);
	set_id(({ "tattoo" }));
	set_short("^GREEN^a huge Halfling Weed Leaf^RESET^");
	set_long(
@MYLONG
This Tat is hip, its cool and its worn only by the grandest gnomes from the Halfling Weed hills.

MYLONG
	);
	set_limbs(({"torso"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

