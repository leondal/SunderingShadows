#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
int FLAG;
void init() {
    ::init();
    add_action("stand_func","stand");
}
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
	"A cold musty breeze brings the smell of evil to you from within "
	"the temple."
    );
    set_listen("default","A deceptive silence fills the room.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
        "symbol":"%^MAGENTA%^The large painted symbol of Lloth appears before "
	"you on the floor. It makes you feel uneasy and you try to avoid "
	"stepping on it. The eyes of the demonqueen depicted within the "
	"symbol-like mural seem to follow your every move."
    ]));
    set_exits(([
    "south": "/d/dagger/drow/rooms/temple1",
	"north": RPATH "first2"
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
	    "is a mural like symbol depicting the Demonqueen Lloth."
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
    write("%^BLUE%^You venture forward into the temple."
	"%^RESET%^"
    );
    say("%^BLUE%^"+TPQCN+" wanders deeper into the temple."
	"%^RESET%^"
    ,TP);
    return 1;
}	
int stand_func(string str) {
    if(!str) {
	notify_fail("Stand what?\n");
	return 0;
    }
    if(str != "symbol") {
	notify_fail("Stand what?\n");
	return 0;
    }
    write(
	"%^BOLD%^%^RED%^You stand within the symbol of Lloth!%^RESET%^"
    ); 
    say(
	"%^BOLD%^%^RED%^"+TPQCN+" stands upon the symbol of Lloth!%^RESET%^"
    );
    write(
	"%^BOLD%^%^YELLOW%^A violent shock of energy fills your body!"
	"%^RESET%^"
    );
    say(
	"%^BOLD%^%^YELLOW%^"+TPQCN+" screams out in pain!%^RESET%^"
    );
    TP->do_damage( "torso",20 );
    TP->add_poisoning(10);
    write(
	"%^CYAN%^A whisper comes to your mind: %^RESET%^The fountain can "
	"harm your body, but it can cure your venomous soul..."
    );	
    say(
	"%^CYAN%^A strange whispering sound fills the room.%^RESET%^"
    );	
    return 1;
}    
