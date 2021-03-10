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
	set_id(({ "swan", "tat", "tattoo", "smudge", "ink" }));
	set_short("a tinyBLACK smudge on his big nosed mug");
	set_long(
@MYLONG
This aint nare smudge...its a tiny tattoo. Its a tiny detailed BLACK swan with a RED feather setting just under the out-side corner of his left eye.

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

