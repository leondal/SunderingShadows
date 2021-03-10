#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
   set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"Something rotten, something wrong..."
    );
    set_listen("default","A deceptive silence fills the room.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood."
     ]));
    set_exits(([
	"west": RPATH "first15"
    ]));
}
string lng_fun(string str) {
    if(present("swarm")) {
	str = 
            "%^RED%^Your shocked by the massive flying "
	    "swarm of spiders "
	    "which quickly surrounds you, biting at your flesh and "
	    "blocking your vision!"
	    "%^RED%^ ";
    } else {
	str =
	    "%^RED%^This chamber located at the end of the eastern "
	    "hallway is made of the same black stone and is empty. "
	    "Overall it seems quite unused. The only exit is back "
	    "the way you came."
	    "%^RED%^ ";
    }
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presence of Grazzt."
	       "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if(present("swarm")) {
	str = 
            "%^RED%^Within the Swarm.%^RESET%^";
    } else {
	str =
            "%^RED%^Temple Chamber.%^RESET%^";
    }
    return str;
}
void reset() {
    ::reset();
    if(!present("swarm")) {
	new( MPATH "swarm.c" )->move(TO);
    }
}
