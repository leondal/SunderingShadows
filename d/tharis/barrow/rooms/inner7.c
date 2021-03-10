#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;
int FLAG;
void init() {
    ::init();
    add_action("open_func","open");
}
void create() {
    ::create();
   set_terrain(BUILT_CAVE);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_property("no teleport",1);
    set_smell("default",
	"The smell of the dead grips your senses."
    );

    set_items(([
	"dirt":"The whole chamber is made from dirt.",
	"torches":"The torches flicker and provide little light.",
	"walls":"The walls are made of dirt and have a few flickering "
	"torches in them.",
	"ceiling":"The ceiling is made of dirt.",
	"floor":"The floor is made of dirt.",
        "sarcophagus":"%^RED%^The sarcophagus likely is the resting "
   "ground of a fallen hero. The crest of a knight is painted "
	"upon it.",
	"crest":"The crest is of the legendary House of Ty'relk."
	
    ]));
    set_exits(([
	"up": RPATH "inner6",
	"door": RPATH "chamber1"
    ]));
    set_pre_exit_functions(({"up"}),({"exit_fun"}));
    set_pre_exit_functions(({"door"}),({"exita_fun"}));
}
string lng_fun(string str) {
    if(random(1) > 0) {
	str = 
            "%^ORANGE%^The chamber is a small and cramped hole within "
	    "the mound. The dirt floor and walls are bare. There appears "
	    "to be no place to go from this small chamber but up through "
	    "ceiling. The ceiling has an opening that is filled with a "
	    "strange wispy %^CYAN%^fog%^ORANGE%^ substance. There are "
	    "a few flickering %^WHITE%^torches%^ORANGE%^ "
	    "on the walls. Laying in the center of the room lies a "
	    "a large %^MAGENTA%^jeweled sarcophagus%^ORANGE%^ ";
    } else {
	str =
	    "%^BLUE%^The chamber is merely a "
	    "%^ORANGE%^dirt%^BLUE%^ room. Several "
	    "flickering %^WHITE%^torches%^BLUE%^ hang from the walls. "
	    "The dirt floor and walls are bare. There appears "
	    "to be no place to go from this small chamber but up through "
	    "ceiling. The ceiling has an opening that is filled with a "
	    "strange wispy %^CYAN%^fog%^BLUE%^ substance."
	    " Laying in the center of the room is a large %^MAGENTA%^"
	    "jeweled sarcophagus%^BLUE%^ ";
    }
    if(FLAG == 0) {
	str += "with a closed lid. ";
    } else {
	str += "with an open lid. ";
    }
    if(present("my_knight")) {
	str += "A skeletal knight stands before the coffin glaring at you!"
	       "%^RESET%^";
    } else {
	str += "%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    if(random(1) > 0) {
	str = 
            "%^ORANGE%^A Small Dirt Chamber%^RESET%^";
    } else {
	str =
            "%^BLUE%^A Cramped Dirt Chamber%^RESET%^";
    }
    return str;
}

int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("%^CYAN%^You suddenly feel the need to leave "
	  "the cramped dirt chamber and climb up through the "
	  "ceiling.%^RESET%^"
    );
    tell_room(TO,"%^CYAN%^"+TPQCN+" suddenly disappears through the fog!%^RESET%^"
    ,TP);
    return 1;
}	
int exita_fun() {
    if(TP->query_true_invis()) return 1;
    if(present("my_knight")) {
	write("The knight blocks the way!");
	return 0;
    } else {
	return 1;
    }
}
int open_func(string str) {
    if(!str) {
	notify_fail("Open what?\n");
	return 0;
    }
    if(str != "sarcophagus") {
	notify_fail("Open what?\n");
	return 0;
    }
    if(FLAG == 1) {
	notify_fail("It is already open!\n");
	return 0;
    }
    write(
	"%^BOLD%^%^RED%^You open the lid of the sarcophagus and a "
	"skeletal knight "
	"climbs out!%^RESET%^"
    ); 
    tell_room(TO,
	"%^BOLD%^%^RED%^"+TPQCN+" opens the lid of the sarcophagus "
	"and a skeletal knight climbs out!%^RESET%^"
   ,TP);
    FLAG = 1;
    new( MPATH "knight" )->move(TO);
    return 1;
}    
void reset() {
    ::reset();
    if(FLAG == 1) {
        tell_room(TO,
            "%^BOLD%^%^RED%^The lid of the sarcophagus slides shut."
	    "%^RESET%^"
        );
    }
    FLAG = 0;
}
