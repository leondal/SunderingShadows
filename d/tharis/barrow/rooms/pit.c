#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
int FLAG;

void init() {
    ::init();
    add_action("climb_func","climb");
    add_action("lever_thing","pull");
}

void create() {
    ::create();
   set_terrain(BUILT_CAVE);
   set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_property("indoors",1);
//    set_short( (:TO,"shrt_fun" :) );  was buggy
    set_short("%^BLUE%^A Cramped Stone Pit%^RESET%^");
    set_long( (:TO,"lng_fun" :) );
    set_property("no teleport",1);
    set_smell("default",
	"A raw stench fills the chamber."
    );
    set_listen("default","A whisper seems to come to your ears from the "
	"pit floor.");

    set_items(([
	"stone":"The whole chamber is constructed from black stone slabs.",
	"torches":"The torches flicker and provide little light.",
	"walls":"The walls are made of black stone and have a few flickering "
	"torches in them.",
	"ceiling":"You can see the ceiling of the room above the pit from "
	"where you stand. You also notice many cracks in the walls of the "
	"pit, perhaps making it possible to climb out.",
	"floor":"The floor is made of black stone and bears a painted "
	"pentagram.",
	"lever":"A small lever...looks usable somehow.",
	"pentagram":"A large blood coloured pentagram is located painted "
	"on the floor of the pit."
    ]));
}

string lng_fun(string str) {
/* TP isn't always defined, for instance when a daemon like the high quest one calls it
besides, alignment 0 isn't valid anyway  *Styx* 
    if((int)TP->query_alignment() == 0) {
	str = 
            "%^ORANGE%^The pit is made from "
	    "blackened stone. On the floor is a large %^RED%^blood "
	    "red pentagram%^ORANGE%^ has been painted. The walls of "
	    "of the pit are as black as death incarnate, a small "
	    "lever juts from one of them. \nMuch evil of your demonic "
	    "master resides within the walls of the pit"
	    ".%^ORANGE%^ ";
    } else {
*/
	str =
	    "%^BLUE%^The chamber is merely a "
	    "%^ORANGE%^stone%^BLUE%^ pit. "
	    "The floor and walls are bare except for a small lever. You "
	    "sense incredible evil within the air around you.%^BLUE%^ ";
//    }
    if(present("krykoth")) {
	str += "\n%^GREEN%^A large demonic creature stands glaring at "
	"you. ";
    }
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt."
	       "%^RESET%^";
    }
    return str;
}

/* using TP in query_short was bugging the high quests daemon because TP isn't defined when called by a daemon - 0 isn't a valid alignment anyway, so, zap this *Styx* 8/9/05
string shrt_fun(string str) {
    if((int)TP->query_alignment() == 0) {
	str = 
            "%^ORANGE%^The pit of evil.%^RESET%^";
    } else {
	str =
            "%^BLUE%^A Cramped Stone Pit%^RESET%^";
    }
    return str;
}
*/

int climb_func(string str) {
    if(!str) {
      tell_object(TP,"Climb what?");
	return 1;
    }
    if(str != "pit") {
      tell_object(TP,"Climb what?");
	return 1;
    }
   if(TP->query_paralyzed()){
      tell_object(TP,TP->query_paralyze_message());
      return 1;
   }
    write(
	"%^BOLD%^%^RED%^You clamber out of the stone pit.%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" clambers up out of the pit.%^RESET%^"
    ,TP);
    TP->move_player( RPATH "chamber1" );
    return 1;
}    
void lever_thing(string str){
    if(!str) return notify_fail("Pull what?\n");
    if(str != "lever") return 0;
    write("As you pull the lever a trapdoor opens up underneath you and you fall in!");
    tell_room(TO,TPQCN+" pulls a lever and disappears into a trap door.");
    TP->move(RPATH "trap");
    TP->describe_current_room(1);
    return 1;
}
void reset() {
    ::reset();
    if(present("krykoth")) {
        tell_room(TO,
            "%^BOLD%^%^RED%^The Krykoth lets out an eerie howl!"
        );
    } else {
        new( MPATH "krykoth")->move(TO);
        tell_room(TO,
            "%^BOLD%^%^RED%^A large demon suddenly appears within "
	    "the pentagram "

            "painted on the floor."
            "%^RESET%^"
);
    }
}
