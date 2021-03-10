#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads northwest or east through "+
    "the forest or branches off to the southwest and continues "+
    "through the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"11-4",
       "east" : F_ROOMS"9-4",
       "north" : F_ROOMS"10-5",
       "south" : F_ROOMS"10-3",
       "southeast" : F_ROOMS"9-3",
       "southwest" : F_ROOMS"11-3",
       "northeast" : F_ROOMS"9-5",
       "northwest" : F_ROOMS"11-5",
    ] ));
    bandit_ambush("northwest","southwest","east",TO);
    set_search("default", "%^BOLD%^%^GREEN%^Perhaps something of interest "+
    "could have fallen to the %^RESET%^%^GREEN%^ground%^BOLD%^%^GREEN%^ and mixed with the "+
    "heavy debris?%^RESET%^");
	set_search("ground", "%^YELLOW%^You carefully inspect the debris covered ground "+
	"and find a crack in "+
	"the earth here that leads into %^BOLD%^%^BLACK%^darkness%^RESET%^%^YELLOW%^."+
	"%^RESET%^");
        set_climb_exits((["descend":({"/d/deku/keep/rooms/tunnel13",20,30,100})]));
	set_fall_desc("%^RED%^You fall and slam into a rock wall!%^RESET%^");
	add_item("crack","%^YELLOW%^The earth has split open here, forming this crack.  "+
	"You see only darkness within, you could probably %^RESET%^descend%^YELLOW%^ "+
	"into it, if you were brave enough.%^RESET%^");
	add_item("earth","%^YELLOW%^The earth has split open here, forming this crack.  "+
	"You see only darkness within, you could probably %^RESET%^descend%^YELLOW%^ "+
	"into it, if you were brave enough.%^RESET%^");
}
