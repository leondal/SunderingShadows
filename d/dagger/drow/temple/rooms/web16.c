#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
int xy;
void create() {
    ::create();
   set_terrain(BARREN);
   set_travel(LEDGE);
    set_property("light",-1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The smell of insects and rotten flesh fill the area."
    );
    set_listen("default","Clicking and chittering sounds "
	"surround you.");

    set_items(([
	"stone":"The whole chamber is constructed from black stone slabs.",
	"walls":"The walls are made of black stone and located a hundred "
	"feet apart.",
	"ceiling":"The ceiling is made of black stone and located "
	"one hundred feet above you.",
	"floor":"The floor is made of black stone and located a hundred "
	"feet below you.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
	"web":"The large web streches across the entire chamber. It "
	"is composed of several large strands on which you currently "
	"stand. Many smaller strands spew out in all direction and "
	"you are careful not to touch them as they appear to be sticky.",
	"strands":"There are large strands and small strands",
	"strand":"You stand upon a large strand of the web which can "
	"be used to traverse the web.",
	"large strands":"The large strands are used for travelling and are two "
	"feet thick. They seem to provide the support for the web.",
	"small strands":"The small strands are sticky looking and spew "
	"out in all directions from the larger strands. You are careful "
	"not to touch them.",
    ]));
    set_exits(([
	"southeast": RPATH "web7"
    ]));
    set_pre_exit_functions(({"north"}),({"exit_fun"}));
    set_pre_exit_functions(({"south"}),({"exit_fun"}));
    set_pre_exit_functions(({"east"}),({"exit_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exit_fun"}));
    set_pre_exit_functions(({"northwest"}),({"exit_fun"}));
    set_pre_exit_functions(({"southeast"}),({"exit_fun"}));
    set_pre_exit_functions(({"southwest"}),({"exit_fun"}));
}
string lng_fun(string str) {
    if(random(20) > 2) {
	str = 
            "%^RED%^You stand within a very large, dark chamber. "
	    "It is hard to see exactly where the walls, ceiling "
	    "and floor are located. Within the chamber, located at "
	    "a height of over a hundred feet is a massive spider "
	    "web which stretches from wall to wall. The main strands "
	    "of the web are two feet thick. You are standing upon "
	    "one of these larger strands and are careful not to fall "
	    "off the strand as the fall to the chamber floor below you "
	    "would certainly be fatal. Many smaller strands stretch "
	    "out in all directions. It appears that you can use the larger "
	    "strands to travel across the web."
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
    if(random(20) > 2) {
	str = 
            "%^RED%^Within the Web.%^RESET%^";
    } else {
	str =
            "%^RED%^Your vision is clouded.%^RESET%^";
    }
    return str;
}

int exit_fun() {
    write(
	"%^CYAN%^You carefully use the large web strand to "
	"travel across the chamber."
	"%^RESET%^"
    );
    say(
	"%^BLUE%^"+TPQCN+" uses one of the larger web strands "
	"to travel within the chamber."
	"%^RESET%^"
    ,TP);
    return 1;
}	
void reset() {
    ::reset();
    if(!present("swarm") && !present("spider") && !present("drider")) {
        xy = random(10);
        if(xy == 0) {
	    new( MPATH "swarm.c" )->move(TO);
        }
        if(xy == 1) {
	    new( MPATH "webder.c" )->move(TO);
        }
        if(xy == 2) {
	     new( MPATH "pest.c" )->move(TO);
        }
        if(xy == 3) {
	    new( MPATH "spider.c" )->move(TO);
	    new( MPATH "spider.c" )->move(TO);
	    new( MPATH "spider.c" )->move(TO);
	    new( MPATH "spider.c" )->move(TO);
	    new( MPATH "spider.c" )->move(TO);
        }
        if(xy == 4) {
	    new( MPATH "lspider.c" )->move(TO);
        }
    }
}
	
