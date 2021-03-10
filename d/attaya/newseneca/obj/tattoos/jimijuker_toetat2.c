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
	set_id(({ "tat", "left foot tattoo", "foot tat", " foot tattoo", "toe tatoo", "toes tat" }));
	set_short("tiny toe-tattoos (on left foot)");
	set_long(
@MYLONG
Looking down at his left foot, you can see four tiny toe tattos (starting on his fore-toe and ending on his pinkie-toe. They are four BOLD BLACK tiny letters...E-V-E-R.

MYLONG
	);
	set_limbs(({"left foot"}));
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

