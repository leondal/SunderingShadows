#include <std.h>
inherit "/d/deku/open/dforest2i";

void create() {
    object ob;
    ::create();
	set_exits(([
       "west" : "/d/deku/open/dforest6",
       "north" : "/d/deku/open/dforest7-1",
       "east" : "/d/deku/open/dforest8"
    ] ));
	set_search("default","%^YELLOW%^You carefully inspect the area and find a crack in "+
		"the earth here that leads into %^BOLD%^%^BLACK%^darkness%^RESET%^%^YELLOW%^."+
		"%^RESET%^");
       set_climb_exits((["descend":({"/realms/saide/keep/tunnel13",20,30,100})]));
	set_fall_desc("%^RED%^You fall and slam into a rock wall!%^RESET%^");
	add_item("crack","%^YELLOW%^The earth has split open here, forming this crack.  "+
		"You see only darkness within, you could probably %^RESET%^descend%^YELLOW%^ "+
		"into it, if you were brave enough.%^RESET%^");
	add_item("earth","%^YELLOW%^The earth has split open here, forming this crack.  "+
		"You see only darkness within, you could probably %^RESET%^descend%^YELLOW%^ "+
		"into it, if you were brave enough.%^RESET%^");
}
