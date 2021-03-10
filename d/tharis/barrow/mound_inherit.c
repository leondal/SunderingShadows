//created to save memory and make the changes easier to get rid of the long
//short description which messed up wp command etc., put it in init. *Styx* 8/13/01

#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
int FLAG;
object here = RPATH "inner1.c";

void create() {
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_short(  "%^BLUE%^A Burial Chamber%^RESET%^" );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default", "The smell of the dead fills your nostrils." );
    set_items(([
	"dirt":"The whole chamber is made from dirt.",
	"statue":"%^BOLD%^%^CYAN%^The statue is of a regal looking knight covered "
	"from head to foot in platemail, which is oddly clean and worn in spots.",
	"marks":"The marks are somewhat circular and look like they've been made "
	"by the base of the statue somehow.",
	"coffin":"The coffin lays broken and scattered around the room,",
	"torches":"The torches flicker and provide little light.",
	"walls":"The walls are made of dirt and have a few flickering "
	"torches in them.",
	"ceiling":"The ceiling is made of dirt.",
	"floor":"The floor is made of dirt and the broken and scattered remains "
	"of a coffin litter it.  You notice odd marks around the base of the statue."
    ]));
    set_exits(([ "out": RPATH "bd2.c" ]));
    set_pre_exit_functions(({"out"}),({"exit_fun"}));
}

void init() {
    ::init();
    add_action("twist_func","twist");
    add_action("twist_func","turn");
    tell_object(TP,"%^RED%^Your mind is filled with a strange sickness and your "
	    "vision blurs. The only thing you can clearly see is the skeletal like "
	    "figure that is swinging a large glowing sword at you!%^RESET%^");
}

string lng_fun(string str) {
    if(present("my_guardian")) {
	str = 
        "%^RED%^As soon as you enter down into the chamber like burial hole "
	    "your mind is filled with a strange sickness and your vision "
	    "blurs. The only thing you can clearly see is the skeletal like "
	    "figure that is swinging a large glowing sword at you!%^RESET%^";
    } else {
	str =
	    "%^BLUE%^The burial chamber is merely a "
	    "%^ORANGE%^dirt%^BLUE%^ room. Several "
	    "flickering torches hang from the dirt walls. A large "
	    "%^RED%^statue of a knight%^BLUE%^"
	    " in full platemail stands in the center "
	    "of the room. The %^MAGENTA%^coffin%^BLUE%^"
	    " which contained the dead knight "
	    "lays scattered and broken on the floor around the statue. %^RESET%^";
    }
    return str;
}

int exit_fun() {
    write("%^BOLD%^%^BLUE%^You suddenly feel the need to escape from "
	  "the burial chamber and clamber up through the hole.%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" suddenly flees in a panic from the "
	"burial mound chamber!%^RESET%^"
    ,TP);
    return 1;
}	
int twist_func(string str) {
    if(!str) {
	notify_fail("Twist or turn what?\n");
	return 0;
    }
    if(str != "statue") {
	notify_fail("Twist or turn what?\n");
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
	"%^BOLD%^%^RED%^You manage to pivot the statue a foot to the left.%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" twists the statue a foot to the left.%^RESET%^"
    ,TP);
    message("info",
	"%^BOLD%^%^RED%^Suddenly, for no apparent reason, a portal appears "
	"in the floor!%^RESET%^",here);
    here->add_exit( RPATH "inner2.c" , "portal" ); 
    FLAG = 1;
    return 1;
}    

void reset() {
    ::reset();
    if(!(present("my_guardian"))) {
	new( MPATH "guardian.c")->move(TO);
    }
    FLAG = 0;
}
