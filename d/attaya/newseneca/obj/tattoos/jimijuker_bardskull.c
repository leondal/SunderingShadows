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
	set_id(({ "tat", "tattoo", "bardskull", "skull", "ink" }));
	set_short("A medium tat on his left bicep");
	set_long(
@MYLONG
This tat is on his right arm, up on the bicep, just below the shoulder.
Its a...
SILVER gnome skull with crossed BLUE banjolele's under it.
The top rocker, above the skull says, in BOLD BLACK letters...BARD!
And the bottom rocker, under the two banjolele's, also in BOLD BLACK, says...D4L!

MYLONG
	);
	set_limbs(({"right arm"}));
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

