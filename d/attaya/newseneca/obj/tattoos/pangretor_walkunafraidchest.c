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
	set_id(({ "tattoo", " chest tattoo", " walk unafraid", " lightning bolts", " huge tattoo" }));
	set_short("%^BOLD%^%^BLACK%^A %^BLUE%^huge %^BLACK%^che%^YELLOW%^s%^BLACK%^t tattoo%^RESET%^");
	set_long(
@MYLONG
%^YELLOW%^"%^BLACK%^Walk Unafraid%^YELLOW%^" %^BLACK%^in stylistic lettering surrounded by %^YELLOW%^lightning bolts%^BLACK%^, all in black can be seen on his chest%^RESET%^

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

