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
	set_id(({ "tats", "toe tats", "right foot tattoo", "tattoos", "foot tat" }));
	set_short("tiny toe tattoos (on right foot)");
	set_long(
@MYLONG
looking down at his right foot, you can see four tiny tattos on each of his toes (starting on his pinkie-toe and ending on the fore-toe next to the big-toe). The tiny tattoos are three letters and a number. They are BOLD AND BLACK, they are...S-K-C-4.

MYLONG
	);
	set_limbs(({"right foot"}));
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

