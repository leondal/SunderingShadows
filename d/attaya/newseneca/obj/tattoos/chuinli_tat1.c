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
	set_id(({ "tattoo", "tat", "tinytattoo", "tiny tattoo", "neck tattoo" }));
	set_short("a tiny neck tattoo of a black bird");
	set_long(
@MYLONG
This little tattoo (about an inch or so big) sits on his neck, back of the neck, just peeking out from under his long INKY-BLACK hair.
It can be seen when he turns his neck just so.
Its a tiny highly detailed tattoo of a crow. Its EBONY-BLACK with a little BLUE and GRAY DETAILS.
THE BLUE and GRAY colors are its beak and eyes respectfully.
One of its detailed feathers are RED.

MYLONG
	);
	set_limbs(({"neck"}));
	set_wear((:TO,"wear_me":));
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

