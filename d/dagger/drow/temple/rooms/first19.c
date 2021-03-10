#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit ROOM;
int LIT1,LIT2,BURNER1,BURNER2;

void init() {
    ::init();
    BURNER1 = 0;
    BURNER2 = 0;
    LIT1 = 0;
    LIT2 = 0;
    add_action("place_func","place");
    add_action("ignite_func","ignite");
    add_action("chant_func","chant");
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
	"It smells of pure evil."
    );
    set_listen("default",
	"Evil chanting fills your ears."
    );
    set_items(([
	"stone":"The whole hallway is constructed from black stone slabs.",
	"walls":"The walls are made of black stone.",
	"ceiling":"The ceiling is made of black stone.",
	"floor":"The floor is made of black stone.",
	"black stone":"The black stone absorbs light the way a leech absorbs "
	"blood.",
	"brazier":"%^RED%^A %^MAGENTA%^copper brazier%^RED%^ filled with "
	    "%^YELLOW%^glowing coals%^RESET%^%^RED%^ stands in the center "
	    "of the chamber. Beside the %^YELLOW%^brazier%^RESET%^%^RED%^ "
	    ", on both sides, are %^RESET%^insence burners%^RED%^.%^RESET%^",
	"burner":"There are insence burners located to the left and the "
	"right of the brazier.",
	"burners":"%^RED%^The burners are for burning insence.%^RESET%^",
	"mural":"%^RED%^The entire floor is painted in an elaborate mosaic "
	    "%^GREEN%^mural%^RED%^ depicting hundreds of different "
	    "spiders.%^RESET%^",
	"cobwebs":"The cobwebs appear to be very large and sway in an "
	"unseen breeze. They are likely not spider webs, but drider webs.",
	"coals":"The coals are burning in the brazier.",
	"pentagram":"%^BOLD%^%^RED%^The blood red pentagram is painted on "
	"the north wall.%^RESET%^"
    ]));
    set_exits(([
	"west" : RPATH "first21",
	"east": RPATH "first20",
	"south" : RPATH "first6"
    ]));
    set_pre_exit_functions(({"east"}),({"exit_fun"}));
    set_pre_exit_functions(({"west"}),({"exit_fun"}));
}
string lng_fun(string str) {
    if((int)TP->query_alignment() != 1 &&
       (int)TP->query_alignment() != 4 &&
       (int)TP->query_alignment() != 7 &&
       (int)TP->query_level() < 15) {
	str = 
            "%^RED%^The walls, ceiling "
	    "and floor here are made of blackened stone slabs. The "
	    "surface of the slabs seems to absorb all forms of light. "
	    "The eerie macabe scene which lays before you causes paranoid "
	    "curiousity to fill your soul. The chamber you stand within "
	    "appears to be either a shrine to an evil god or a place "
	    "of demon summoning. A large %^BOLD%^%^RED%^blood red "
	    "pentagram%^RESET%^%^RED%^ has been painted upon the north "
	    "wall. A %^MAGENTA%^copper brazier%^RED%^ filled with "
	    "%^YELLOW%^glowing coals%^RESET%^%^RED%^ stands in the center "
	    "of the chamber. Beside the %^YELLOW%^brazier%^RESET%^%^RED%^ "
	    ", on both sides, are %^RESET%^insence burners%^RED%^. "
	    "The entire floor is painted in an elaborate mosaic "
	    "%^GREEN%^mural%^RED%^ depicting hundreds of different "
	    "spiders. %^MAGENTA%^Cobwebs%^RED%^ adorn the ceiling and seem "
	    "to sway in an unseen breeze. The movement of the %^MAGENTA%^"
	    "cobwebs%^RED%^ is faintly hypnotic." 
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
            "%^RED%^Temple Chamber.%^RESET%^";
    } else {
	str =
            "%^RED%^Your vision is clouded.%^RESET%^";
    }
    return str;
}

int exit_fun() {
   if(present("drowmon")) {
	write(
	    "%^BLUE%^The priest blocks your way!%^RESET%^"
	);
	say(
	    "%^BLUE%^"+TPQCN+" is blocked by the priest!%^RESET%^"
	,TP);
        return 0;
    } else {
        write(
   	    "%^BLUE%^You move deeper into the darkness of the temple."
	    "%^RESET%^"
        );
        say(
	    "%^BLUE%^"+TPQCN+" wanders deeper into the temple."
	    "%^RESET%^"
        ,TP);
        return 1;
    }
}	
int place_func(string str) {
   object obj;
   string who,what; 
   if(!str) {
        notify_fail("Place what in what?\n");
        return 0;
    }
    if(sscanf(str,"stick in %s burner",who) != 1) {
        notify_fail("Place what in what?\n");
        return 0;
    }	
    if(who != "right" && who != "left") {
	notify_fail("Place what in what?\n");
	return 0;
    }
    if(who == "right") {
	if(BURNER1 != 0) {
	    notify_fail("There is already insence in the burner!\n");
	    return 0;
        }
        if(!(obj = present("wis_stick",TP))) {
	    notify_fail("You don't have a proper stick of insence!\n");
	    return 0;
        }
        write(
	    "%^RED%^You place the stick into the burner on the right "    
            "hand side of the room.%^RESET%^"
        );
        say(
	    "%^RED%^"+TPQCN+" places a stick of insence into the burner "
	    "on the right hand side of the room.%^RESET%^"
        ,TP);
        BURNER1 = 1;
        obj->remove();
        return 1;
    }
    if(who == "left") {
	if(BURNER2 != 0) {
	    notify_fail("There is already insence in that burner!\n");
	    return 0;
        }
        if(!(obj = present("int_stick",TP))) {
	    notify_fail("You don't have a proper stick of insence!\n");
	    return 0;
        }
        write(
	    "%^RED%^You place the stick into the burner on the left "    
            "hand side of the room.%^RESET%^"
        );
        say(
	    "%^RED%^"+TPQCN+" places a stick of insence into the burner "
	    "on the left hand side of the room.%^RESET%^"
        ,TP);
        BURNER2 = 1;
        obj->remove();
        return 1;
    }
}	
int ignite_func(string str) {
    string side;
    if(!str) {
        notify_fail("Ignite what?\n");
        return 0;
    }
    if(sscanf(str,"%s burner",side) != 1) {
        notify_fail("Ignite which? Ignite what?\n");
        return 0;
    }	
    if(side != "right" && side != "left") {
	notify_fail("Ignite which (Right or left) burner?\n");
	return 0;
    }
   if(present("drowmon")) {
	notify_fail("The drow won't let you touch the burner!\n");
	return 0;
    }
    if(side == "right") {
	if(BURNER1 == 0) {
	    notify_fail("You would need to place something into "
	    	"the burner to ignite!\n");
	    return 0;
        }
        write(
	    "%^RED%^You ignite the burner on the right "    
            "hand side of the room.\nYou feel the urge to "
	    "chant!%^RESET%^"
        );
        say(
	    "%^RED%^"+TPQCN+" ignites the burner "
	    "on the right hand side of the room.%^RESET%^"
        ,TP);
        LIT1 = 1;
        return 1;
    }
    if(side == "left") {
	if(BURNER2 == 0) {
	    notify_fail("You would need to place something into "
		"the burner to ignite!\n");
	    return 0;
        }
        write(
	    "%^RED%^You ignite the burner on the left "    
            "hand side of the room.\n"
	    "You feel the urge to chant!%^RESET%^"
        );
        say(
	    "%^RED%^"+TPQCN+" ignites the burner "
	    "on the left hand side of the room.%^RESET%^"
        ,TP);
        LIT2 = 1;
        return 1;
    }
}
int chant_func(string str) {
    if(LIT1 == 0 || LIT2 == 0) {
	notify_fail("You chant.\n");
	return 0;
    }
    write(
	"%^BOLD%^%^BLUE%^Losing yourself within the scent of the "
 	"insense you begin to chant garbled sounds in a foreign "
	"language!%^RESET%^"
    );
    say(
	"%^BOLD%^%^BLUE%^"+TPQCN+" begins chanting in a strange "
	"language while swaying slowly!%^RESET%^"
    ,TP);
    write("Normally you would now be moved to the third level of the temple...it is not in but will "
	"very soon...tell Grazzt you figured this out to speed him up coding it!");
    TP->move_player( RPATH "temple1.c" );
    return 1;
}
void reset() {
    ::reset();
    BURNER1 = 0;
    BURNER2 = 0;
    LIT1 = 0;
    LIT2 = 0;
    if(!present("drow")) {
	new( MPATH "priest1.c" )->move(TO);
	new( MPATH "priest2.c" )->move(TO);
	new( MPATH "priest3.c" )->move(TO);
    }
}   
