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
	set_id(({ "tiny tat", " tiny tattoo", "tat", "tattoo", "coin tattoo", "silver tattoo" }));
	set_short("a tiny SILVER tattoo on the palm of his right hand");
	set_long(
@MYLONG
This small tattoo is inked on the palm of his real hand. Its a detailed tat of a SILVER coin featuring the likeness of Tymora's beautiful face.

MYLONG
	);
	set_limbs(({"right hand"}));
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

