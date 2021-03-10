#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
int FLAG;
void init() {
    ::init();
    add_action("climb_func","climb");
    add_action("enter_func","enter");
}
void create() {
    ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_property("no teleport",1);
    set_smell("default",
	"A raw stench fills the chamber."
    );
    set_listen("default","A strange howl echoes through the chamber.");

    set_items(([
	"stone":"The whole chamber is constructed from stone slabs.",
	"torches":"The torches flicker and provide little light.",
	"walls":"The walls are made of stone and have a few flickering "
	"torches in them.",
	"ceiling":"The ceiling is made of stone.",
	"floor":"The floor is made of stone and a dark open pit is "
	"located in the center of the floor.",
	"pentagram":"A large blood coloured pentagram is located on the "
	"wall facing the entrance to the chamber. You feel as though "
	"you are being drawn into it.",
	"pit":"The pit in the floor is dark and black. Perhaps you could "
	"climb down into it."
    ]));
    set_exits(([
	"out": RPATH "inner7"
    ]));
    set_pre_exit_functions(({"out"}),({"exit_fun"}));
}
string lng_fun(string str) {
    if((int)TP->query_alignment() == 9) {
	str = 
            "%^ORANGE%^The chamber you have entered is made from "
	    "blackened stone. Several torches flicker an eerie light "
	    "throughout the room. Facing you is a large %^RED%^blood "
	    "red pentagram%^ORANGE%^ painted on the wall.\nIn the center "
	    "of the floor is a large open pit.\n"
	    "%^RED%^Written in blazing red runes within the "
	    "center of the room is the word: %^MAGENTA%^Lemure%^RED%^"
	    ".%^ORANGE%^ ";
    } else {
	str =
	    "%^BLUE%^The chamber is merely a "
	    "%^ORANGE%^dirt%^BLUE%^ room. Several "
	    "flickering %^WHITE%^torches%^BLUE%^ hang from the walls. "
	    "The dirt floor and walls are bare. There appears "
	    "to be no place to go from this small chamber but out the way "
	    "you came.%^BLUE%^ ";
    }
    if(present("lemure")) {
	str += "\n%^GREEN%^A strange demonic creature stands grinning at "
	"you. ";
    }
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt."
	       "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if((int)TP->query_alignment() == 9) {
	str = 
            "%^ORANGE%^The chamber of the gating.%^RESET%^";
    } else {
	str =
            "%^BLUE%^A Cramped Dirt Chamber%^RESET%^";
    }
    return str;
}

int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^CYAN%^You leave the chamber and hear hollow laughter"
	".%^RESET%^"
    );
    tell_room(TO,"%^CYAN%^"+TPQCN+" screams and runs out of the room in a panic!"
	"%^RESET%^"
    ,TP);
    return 1;
}	
int climb_func(string str) {
    if(!str) {
	notify_fail("Climb what?\n");
	return 0;
    }
    if(str != "pit") {
	notify_fail("Climb what?\n");
	return 0;
    }
    write(
	"%^BOLD%^%^RED%^You clamber down into the pit.%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" clambers down into the pit.%^RESET%^"
    );
    TP->move_player( RPATH "pit" );
    return 1;
}    
int enter_func(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str != "pentagram") {
	notify_fail("Enter what?\n");
	return 0;
    }
    write(
    "%^RED%^You step through the pentagram.%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" sighs deeply.%^RESET%^"
    );
    TP->move_player( RPATH "fog" );
    return 1;
}    

void reset() {
    ::reset();
    if(present("lemure")) {
        tell_room(TO,
            "%^BOLD%^%^RED%^The lemre looks around and cackles evilly."
	    "%^RESET%^"
        );
    } else {
        new( MPATH "lemure")->move(TO);
        tell_room(TO,
            "%^BOLD%^%^RED%^A lemure suddenly enters through the pentagram "
	    "painted on the wall."
            "%^RESET%^"
        );
    }
}
