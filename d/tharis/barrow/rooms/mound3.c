//added inherit to save memory while changing it so the short description 
//doesn't change - put that message in init.  *Styx* 8/13/01

#include <std.h>
#include "/d/tharis/barrow/short1.h"

inherit "/d/tharis/barrow/mound_inherit";
int FLAG;
object here = RPATH "inner3";

void create() {
    ::create();
    set_exits(([ "out": RPATH "bd4"  ]));
}

int twist_func(string str) {
    if(!str) {
	notify_fail("Twist what?\n");
	return 0;
    }
    if(str != "statue") {
	notify_fail("Twist what?\n");
	return 0;
    }
    if(present("my_guardian")) {
	notify_fail("The guardian won't let you!\n");
	return 0;
    }
    if(FLAG == 1) {
	notify_fail("The statue does not budge.\n");
	return 0;
    }
    write(
	"%^BOLD%^%^RED%^You manage to pivot the statue a foot to the "
	"left.%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" twists the statue a foot to the left."
        "%^RESET%^"
    ,TP);
    message("info",
	"%^BOLD%^%^RED%^Suddenly, for no apparent reason, a portal appears "
	"in the floor!%^RESET%^"
    ,here);
    here->add_exit( RPATH "inner4" , "portal" ); 
    here->set_had_players(3);
    FLAG = 1;
    return 1;
}  

void reset() {
    ::reset();
    if(!(present("my_guardian"))) {
	new( MPATH "guardian")->move(TO);
    }
    message("info","%^BOLD%^%^RED%^Suddenly, for no apparent reason, the portal "
	"vanishes from the floor!%^RESET%^",here);
    FLAG = 0;
}
