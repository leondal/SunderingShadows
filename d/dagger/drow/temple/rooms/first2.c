#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
int FLAG,SKULL,FIGURINE;

void init() {
    ::init();
    SKULL = 0;
    FIGURINE = 0;
    add_action("search_func","search");
}
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
	"A cold musty breeze brings the smell of evil to you from within "
	"the temple."
    );
    set_listen("default","A deceptive silence fills this part of the "
	"hallway.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
        "alcove":"%^MAGENTA%^There are two alcoves located within the east "
	"and west walls. The west alcove has a small humanoid skull within "
	"it. The east alcove has a small figurine within it.",
        "alcoves":"%^MAGENTA%^There are two alcoves located within the east "
	"and west walls. The west alcove has a small humanoid skull within "
	"it. The east alcove has a small figurine within it.%^RESET%^",
	"skull":"%^BOLD%^The skull is made of ivory and has two glowing "
   "gems inset into its eyesockets.%^RESET%^",
        "eyesockets":"%^BLUE%^The eyesockets of the skull contain two "
	"glowing gems.%^RESET%^",
        "gems":"%^RED%^The gems are secured firmly in the skull's eyesockets.",
	"figurine":"%^BOLD%^The figurine is of a small spider carved from "
	"ivory.%^RESET%^"
    ]));
    set_exits(([
	"north" : RPATH "first3",
	"south" : RPATH "first1"
    ]));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
}
string lng_fun(string str) {
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7) {
	str = 
            "%^RED%^You stand within a hallway which leads deeper into "
	    "the %^MAGENTA%^Drow temple of Lloth%^RED%^. The walls, ceiling "
	    "and floor are made of blackened stone slabs. The surface of the "
	    "slabs seems to absorb all forms of light. Located inset within "
	    "the east and west walls are two small shelf like alcoves."
	    "%^RED%^ ";
    } else {
	str =
	    "%^RED%^All around you swirl a meaningless array of blackened "
	    "colours. You can feel the a stone floor beneath your feet but "
	    "the shadowy cloud which fills your mind and eyesight prevents you "
	    "from being able to grasp what is around you. You are faintly "
	    "to conceive where the exits are within the room, but even that "
	    "you are unsure of. It is like a being knows of your presence "
	    "within the temple and is actively clouding your vision and mind."
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
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7) {
	str = 
            "%^RED%^Temple Hallway.%^RESET%^";
    } else {
	str =
            "%^RED%^Your vision is clouded.%^RESET%^";
    }
    return str;
}

int exit_fun() {
    write("%^BLUE%^You move deeper into the darkness of the temple."
	"%^RESET%^"
    );
    say("%^BLUE%^"+TPQCN+" wanders deeper into the temple."
	"%^RESET%^"
    ,TP);
    return 1;
}	
int search_func(string str) {
    if(!str) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str != "figurine" && str != "skull") {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str == "figurine" && FIGURINE < 1) {
        write(
            "%^BOLD%^%^RED%^You search the figurine and find a small "
	    "vial!%^RESET%^"
        ); 
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" finds something in the west "
	    "alcove!%^RESET%^"
        );
        FIGURINE = 1;
        new( "/d/shadow/obj/potion/elixer_of_health.c" )->move(TP);
        return 1;
    }
    if(str == "skull" && SKULL < 1) {
        write(
            "%^BOLD%^%^RED%^You search the skull and find a small "
	    "vial!%^RESET%^"
        ); 
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" finds something in the east "
	    "alcove!%^RESET%^"
        );
        SKULL = 1;
        new( "/d/shadow/obj/potion/elixer_of_health.c" )->move(TP);
        return 1;
    }
    return 0;
}    
void reset() {
    ::reset();
    FIGURINE = 0;
    SKULL = 0;
}   

