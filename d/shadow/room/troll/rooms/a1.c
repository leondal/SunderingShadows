#include <std.h>
#include "/d/shadow/room/troll/short.h"
inherit ROOM;

inherit "/d/shadow/room/troll/cavern1.c";
inherit "/d/shadow/room/troll/actions1.c";

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_property("no scry",1);
    set_property("no wipe",1);
    set_property("carving here",1);
    set_short("%^BOLD%^%^ORANGE%^Mine Entrance%^RESET%^");
    set_long("%^BOLD%^%^RED%^"
             "The entrance to the %^WHITE%^abandoned mine%^RED%^ shows signs "
             "of recent use. "
             "%^CYAN%^Tracks%^RED%^ lead back and forth from the entrance of "
             "the %^WHITE%^mine%^RED%^ and the passageway leading south. "
             "%^ORANGE%^Old rickety wooden support beams%^RED%^ line the "
             "ceiling and the walls of the mine. "
             "Quite a bit of %^MAGENTA%^rock and rubble%^RED%^ lay scattered "
             "about the passageway. "
             "A couple of %^YELLOW%^smouldering firelogs%^RED%^ lay in a small pit."
             "%^RESET%^");
  
     set_items ( ([

	       ]) );	

     set_mine1_items(({ "mine", "mines", "moss", "glow", "light",
			    "area", "here", "wall", "walls", "floor",
			    "ground", "ceiling", "rock",  
			    "dirt", "room","pit","firelogs","beam","beams",
			    "tracks","rubble","entrance"	
		
                       }));
   
     add_item ( "carving", 
		"%^BOLD%^%^ORANGE%^Etched into the wall are some words "
		"of wisdom left by some ancient explorer. The carving "
		"looks to be very old indeed. It reads:%^RESET%^\n"
		"%^BOLD%^%^YELLOW%^"
		"Welcome to the Grazzt Troll Mines!%^RESET%^\n"
		"%^BOLD%^%^ORANGE%^"
		"Many have come to explore these mines, yet few "
		"have returned alive, and those that have, lived "
		"their remaining days in madness. There is a dark "
		"secret hidden here and it will take brains beyond "
		"what most mortals have. Be sure to try to do everything.\n"
		"%^BOLD%^%^RED%^Muahhahahahhha,\nGrazzt, Lord of the Drow"
		"%^RESET%^"); 

     set_exits(([
		"south": RPATH "a2",
		  "out": "/realms/grazzt/workroom",
	       ]));
    set_pre_exit_functions(({ "out" }),({ "leave" }));
}

int leave() {
    object me = this_player();
    message("inf",
	"%^BOLD%^%^YELLOW%^"
	"You step forth into the light of day and "
	"are overwhelmed that you made it out of the mines alive!"
	"%^RESET%^"
    ,me);
    message("inf",
	"%^BOLD%^%^YELLOW%^"
	+me->query_cap_name()+
	" leaves the mines breathing a sigh of relief!"
	"%^RESET%^"
    ,environment(me),me);
    return 1;		  
}

void init() {
    ::init();
    set_mine1_actions(({ "carving", "touch", "mine" }));
}

void reset() {
    ::reset();
    if(!present("troll")) {
	new(MPATH "grunt")->move(this_object());
    }
}
    