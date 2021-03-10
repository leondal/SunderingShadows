#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;

void init() {
    ::init();
    add_action("chant_func","chant");
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
	"The damp smell of death assaults your senses."
    );
    set_listen("default","A chittering noise comes from the north.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone and has a large pentagram "
	"painted upon it.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
        "pentagram":"%^RED%^The large blood stained pentagram covers "
	"a good five foot section of the floor and have five points. "
	"There is a golden circle painted around the outside of the "
	"pentagram.%^RESET%^",
        "blood":"%^RED%^The pentagram is stained with old, dried blood."
	"%^RESET%^",
	"stains":"%^RED%^The stains are meaningless to casual observation, "
	"but you do notice that some are within the pentagram and some are "
	"outside it. Perhaps the stains do not relate to the pentagram "
	"itself.%^RESET%^",
        "circle":"%^BOLD%^%^YELLOW%^Staring at the outline you notice that "
	"it is composed of numerous runic glyphs.%^RESET%^",
	"glyphs":"%^MAGENTA%^Although you cannot understand the glyphs, "
	"you are aware that they are ancient runes of teleportation used by "
	"the Drow.%^RESET%^"
    ]));
    set_exits(([
	"north": RPATH "first4",
	"south": RPATH "first2"
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
	    "slabs seems to absorb all forms of light. Upon the floor "
	    "is a blood stained pentagram."
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
    write("%^BLUE%^You venture further into the temple."
	"%^RESET%^"
    );
    say("%^BLUE%^"+TPQCN+" wanders into the darkness of the hallway."
	"%^RESET%^"
    ,TP);
    return 1;
}	
int chant_func(string str) {
    if(!str) {
	notify_fail("Chant what?\n");
	return 0;
    }
    if(str != "zifnia" && str != "ainfiz") {
        write(
            "%^BOLD%^%^RED%^You attempt to chant an ancient "
	    "phrase!%^RESET%^"
        ); 
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" chants a phrase!%^RESET%^"
        );
        write(
	    "%^BOLD%^%^YELLOW%^A violent shock of energy fills your body!"
	    "%^RESET%^"
        );
        say(
	    "%^BOLD%^%^YELLOW%^"+TPQCN+" screams out in pain!%^RESET%^"
        );
        TP->do_damage( "torso",50 );
        TP->add_poisoning(10);
        write(
	    "%^CYAN%^A whisper comes to your mind: %^RESET%^Never attempt "
	    "to use our devices again insolent mortal!"
        );	
        say(
	    "%^CYAN%^A strange whispering sound fills the room.%^RESET%^"
        );	
        return 1;
    }
    if(str == "zifnia") {
        write(
            "%^BOLD%^%^RED%^You attempt to chant an ancient "
	    "phrase!%^RESET%^"
        ); 
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" chants a phrase!%^RESET%^"
        );
        write(
	    "%^BOLD%^%^YELLOW%^Suddenly you are moved elsewhere!"
	    "%^RESET%^"
        );
        say(
	    "%^BOLD%^%^YELLOW%^"+TPQCN+" vanishes in a flash of "
	    "light!%^RESET%^"
        );
        TP->move_player( RPATH "web19.c" );
        say(
	    "%^CYAN%^A strange moan comes to your ears!%^RESET%^"
        );	
        return 1;
    }
    if(str == "ainfiz") {
        write(
            "%^BOLD%^%^RED%^You attempt to chant an ancient "
	    "phrase!%^RESET%^"
        ); 
        say(
	    "%^BOLD%^%^RED%^"+TPQCN+" chants a phrase!%^RESET%^"
        );
        write(
	    "%^BOLD%^%^YELLOW%^Suddenly you are moved elsewhere!"
	    "%^RESET%^"
        );
        say(
	    "%^BOLD%^%^YELLOW%^"+TPQCN+" vanishes in a flash of "
	    "light!%^RESET%^"
        );
        TP->move_player( RPATH "web21" );
        say(
	    "%^CYAN%^A strange moan comes to your ears!%^RESET%^"
        );	
        return 1;
    }
}    
