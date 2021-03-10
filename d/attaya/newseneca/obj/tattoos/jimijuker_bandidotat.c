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
	set_id(({ "tattoo", "tat", "sombrero", "skull", "pistols", "ink", "back tattoo", "bandido" }));
	set_short("a huge skull tattoo on his back");
	set_long(
@MYLONG
This is a good sized tattoo on his little big gnome back. Its a tattoo of a grinning gnome skull wearing a strange colorful (RED and GOLD) hat (a sombrero) with two pistols with their barrels crossed under it.

MYLONG
	);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
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

