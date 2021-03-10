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
	set_id(({ "tattoo", "skullcrossbones", "skull" }));
	set_short("a tiny solid-black home-grown nSKULL AND CROSSBONES tattoo on his left hand");
	set_long(
@MYLONG
This is a tiny home-grown black ink tattoo of a skull and crossbones. There's no detail to it, just the image of the shape of a skull and crossbones.

MYLONG
	);
	set_limbs(({"left hand"}));
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

