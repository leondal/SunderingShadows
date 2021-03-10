#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",-1);
    set_property("indoors",1);
   set_property("no teleport",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The smell of burning flesh surrounds you."
    );
    set_listen("default","Decrepit clicking noises fills the "
	"chamber.");

    set_items(([
	"stone":"The whole chamber is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"shadows":"%^RED%^The shadows seem to reach towards you. You try "
	"your best to avoid touching them.%^RESET%^",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood."
    ]));
    set_exits(([
	"south": RPATH "first15"
    ]));
}
string lng_fun(string str) {
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7) {
	str = 
            "%^RED%^You stand in a chamber "
	    "within "
	    "the %^MAGENTA%^Drow temple of Lloth%^RED%^. The walls, ceiling "
	    "and floor are made of blackened stone slabs. The surface of the "
	    "slabs seems to absorb all forms of light. The shadows here seem to reach out "
	    "towards you as if they are searching for something."
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
void reset() {
    ::reset();
    if(!present("drider")) {
	new( MPATH "drider.c" )->move(TO);
	new( MPATH "drider.c" )->move(TO);
	new( MPATH "drider.c" )->move(TO);
    }
}
