#include <std.h>

inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",2);
        set_property("no sticks",1);
	set_property("ooc room", 1);
        set_short("%^MAGENTA%^Character info. room");
        set_long(
@STYX
This room is designed to help players learn how to make their characters more memorable and also comply with the role-playing aspects of Sundering Shadows.  There are several posters on the walls here to help you with syntax and information about useful commands and how to play here.  Type %^BOLD%^<look posters>%^RESET%^ to see the topics they cover and how to read them. 
STYX
        );
        set_smell("default","The room smells like vanilla-scented candles.");
        set_listen("default","The room is quiet except for the conversations about how to play in Sundering Shadows.");
        set_items(([
        ]));
        set_exits(([
        "out" : "/d/newbie/ooc/hub_room2",
        ]));
}

void reset() {
	::reset();
	if(!present("posters"))
	new("/d/newbie/ooc/char_poster")->move(TO);
//	if(!present("riley"))
//	new("/d/newbie/ooc/character.c")->move(TO);
}
