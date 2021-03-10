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
	set_id(({ "tattoo", "tat" }));
	set_short("a medium sized tattoo of a BOLD-BLACK music-note on his left fore-arm");
	set_long(
@MYLONG
This is A bold-black inked tattoo of a standard music-note which covers his left fore-arm.

MYLONG
	);
	set_limbs(({"left hand"}));
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

