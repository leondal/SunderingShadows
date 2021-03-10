#include "abolition.h"

inherit ROOM;
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("noattack",1);
    set_short("Sandy Armory");
     set_long("%^BOLD%^WHITE%^Welcome to Sandy's armor shop!%^RESET%^"
"You are in a large room with many different types of armor hanging on"
" the wall.  A large man sits behind a desk watching your every move.  "
"He looks up at you in a confused way, probly trying to figure out what "
"type of armor would be best for you."
""
);
    set_smell("default","You smell the send of hot ashesh smoldering.");
    set_listen("default","You hear the sound of gold coins.");
    set_exits( ([
    "out" : "/d/mine2/sandy/room/sandy19",
        ]) );
    set_items( ([
"desk" : "The desk is made out of old rotting wood.",
"armor" : "You see large piece of armor hanging around the room.",
		]));
}
void init(){
    ::init();
	if(!present("tony"))
	    new("/d/mine2/sandy/mon/tony.c")->move(TO);
}
