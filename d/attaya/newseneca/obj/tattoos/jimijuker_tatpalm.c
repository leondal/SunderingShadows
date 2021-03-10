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
	set_id(({ "tattoo", "skulltat" }));
	set_short("a small sized black-and-white tattoo of a GNOME-SKULL AND CROSSBONES on the palm of his right hand");
	set_long(
@MYLONG
This is a small tattoo of a gnome-skull and crossbones. Its done with black and white ink and it sets in the center of the palm of his right hand.

MYLONG
	);
	set_limbs(({"right hand"}));
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

