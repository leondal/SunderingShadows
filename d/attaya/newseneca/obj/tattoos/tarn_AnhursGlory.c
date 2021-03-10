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
	set_id(({ "tattoo", "circle tattoo", "small tattoo" }));
	set_short("A small tattoo showing %^CYAN%^three %^BOLD%^%^BLUE%^blue %^BLACK%^circles%^RESET%^");
	set_long(
@MYLONG
This small tattoo shows three blue circles, one on top and the other, two side by side under the first circle. They have been inked into the forehead of the firbolg.

MYLONG
	);
	set_limbs(({"head"}));
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

