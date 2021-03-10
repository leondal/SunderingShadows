#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
int FLAG,TRAP,TRIED,j;
// string *NAMES;
void init() {
     ::init();
     add_action("lockpick_fun","pick");
     add_action("remove_fun","remove");
     FLAG = 0;
     TRAP = 0;
     TRIED = 0;
     j = 0;
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
	"There is a amipherous, yet sweet, smell in this part of "
	"the temple."
    );
    set_listen("default","A chittering sound fills the air.");

    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
	"door":"%^GREEN%^The door is made of iron and bears the symbol of "
	"Lloth upon it.%^RESET%^",
	"symbol":"%^MAGENTA%^The symbol seems to glow and the eyes of Lloth "
	"seem to follow your every movement.%^RESET%^",
	"eyes":"%^RED%^The eyes seem to be searching for something.%^RESET%^"
    ]));
    set_exits(([
	"west": RPATH "first9.c",
	"east": RPATH "first7.c",
	"door" : RPATH "first12.c"
    ]));
    set_pre_exit_functions(({"door"}),({"exita_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));

}
string lng_fun(string str) {
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7) {
	str = 
	    "%^RED%^You stand within an intersection of two hallways "
	    "which lead deeper into "
	    "the %^MAGENTA%^Drow temple of Lloth%^RED%^. The walls, ceiling "
	    "and floor are made of blackened stone slabs. The surface of the "
	    "slabs seems to absorb all forms of light. There is an "
	    "%^RESET%^%^BOLD%^"
	    "iron door%^RESET%^%^RED%^ to the south of where you stand." 
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
int remove_fun(string str) {
    int i;
    if(!str) {
	write("Remove what?");
	return 1;
    }
    if(str != "trap") {
	write("Remove what?");
	return 1;
    }
    if(TRAP != 0) {
	write("What trap?");
	return 1;
    }
if(!TP->is_class("thief")) {
	write("%^RED%^You have no knowledge of that!%^RESET%^");
	return 1;
    }
//    for(i = 0;i>sizeof(NAMES);i++) {
//	if(NAMES[i] == (string)TPQCN) {
//	    write("%^RED%^You cannot remove the trap!%^RESET%^");
//	    return 1;
//	}
//    }
    if(random(85) > 
	((int)TP->query_thief_skill("find/remove traps"))/2) {
	write("%^RED%^You try to remove the trap and fail.\n"
	    "%^GREEN%^You cut yourself on the trap!%^RESET%^");
	say("%^RED%^"+TPQCN+" fails to remove the trap on the door."
	    "%^RESET%^"
	,TP);
	TP->add_poisoning(10);
	j=j+1;
//        NAMES[j] = ""+(string)TPQCN+"";  
	return 1;
    } else {
	write("%^YELLOW%^You remove the trap on the door!%^RESET%^");
	say("%^YELLOW%^"+TPQCN+" removes the trap from the door!"
	    "%^RESET%^"
	,TP);
	TRAP = 1;
	return 1;
    }
}	
int lockpick_fun(string str) {
    if(!str) {
	write("Pick what?");
	return 1;
    }
    if(str != "door") {
	write("Pick what?");
	return 1;
    }
    if(FLAG != 0) {
	write("The door is not locked.");
	return 1;
    }
if(!TP->is_class("thief")) {
	write("%^RED%^You have no knowledge of that!%^RESET%^");
	return 1;
    }
    if(TRIED != 0) {
	    write("%^RED%^You cannot pick the door!%^RESET%^");
	    return 1;
    }
    if(TRAP == 0) {
	write("%^GREEN%^You cut yourself on a needle trap on the lock!"
	    "%^RESET%^"
	);
	say("%^GREEN%^"+TPQCN+" gets cut while trying to pick the door!"
	    "%^RESET%^"
	,TP);
	TP->add_poisoning(10);
    }
    if(random(85) > 
((int)TP->query_thief_skill("open locks"))/2) {
	write("%^RED%^You try to pick the door and fail."
	    "%^RESET%^");
	say("%^RED%^"+TPQCN+" fails to pick the door.%^RESET%^"
	,TP);
	TRIED = 1;
	return 1;
    } else {
	write("%^YELLOW%^You pick the door!%^RESET%^");
	say("%^YELLOW%^"+TPQCN+" picks the door!"
	    "%^RESET%^"
	,TP);
	FLAG = 1;
	return 1;
    }
}	

int exit_fun() {
    if(present("drider")) {
	write("%^RED%^The drider blocks your way!%^RESET%^");
	say("%^RED%^The drider blocks "+TPQCN+"'s way!%^RESET%^",TP);
	return 0;
    } else {
	write("%^BLUE%^You venture further into the temple."
	    "%^RESET%^"
	);
	say("%^BLUE%^"+TPQCN+" wanders deeper into the temple. "
	    "A strange cackle "
	    "of insanity fills the air."
	    "%^RESET%^"
	,TP);
	return 1;
    }
}	
int exita_fun() {
    if(present("drider")) {
	write("%^RED%^The drider blocks your way!%^RESET%^");
	say("%^RED%^The drider blocks "+TPQCN+"'s way!%^RESET%^",TP);
	return 0;
    } else {
    if(FLAG == 0) {
	write("%^RED%^The door is locked.%^RESET%^");
	say("%^RED%^"+TPQCN+" tries to budge the door in vain.%^RESET%^"
	,TP);
	return 0;
	} else {
	write("%^BLUE%^You swing open the door and enter the darkness "
	    "of the chamber before you."
	    "%^RESET%^"
	);
	say("%^BLUE%^"+TPQCN+" swings open the iron door and wanders in."
	    "%^RESET%^"
	,TP);
	return 1;
    }
   }
}	

void reset() {
    ::reset();
    if(!present("drider")) {
	new( MPATH "drider.c" )->move(TO);
	new( MPATH "drider.c" )->move(TO);
	FLAG = 0;
	TRIED = 0;
	TRAP = 0;
    }
}
