#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",-3);
    set_property("indoors",1);
   set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"A disgusting odour drifts from the rotten corpses."
    );
    set_listen("default","A slight drone-like hum can be heard coming "
	"from within the temple walls.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
	"corpses":"There are corpses hanging from the massive web.",
	"corpse":"There are several corpses hanging from the massive "
	"web.",
	"web":"The massive web hangs from the ceiling, spanning the "
	"entire area of the chamber located ten feet and above.",
	"ceiling":"It is hard to make out the ceiling due to "
	"the massive webbing hanging above you, but it appears "
	"to be as high as one hundred feet."
    ]));
    set_exits(([
        "east": RPATH "first9"
    ]));
}
string lng_fun(string str) {
	str = 
            "%^RED%^The chamber at the end of the western hall of the temple "
	    "contains a foreboding sight. The chamber ceiling appears to be "
	    "located more than one hundred feet above you, however a massive "
	    "spider web obscures your vision. The web reaches from the ceiling "
	    "all the way down to about two feet above your head. Several "
	    "corpses hang within the webs."
	    "%^RED%^ ";

    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presence of Grazzt."
	       "%^RESET%^";
    }
    if(present("spider")) {
	str += "%^RED%^\nA small spider has clambered down from the webs to examine "
	"you.%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    	str = 
            "%^RED%^Temple Chamber.%^RESET%^";
        return str;
}
void reset() {
    ::reset();
    if(!present("spider")) {
	new ( MPATH "pest.c" )->move(TO);
    }
}

