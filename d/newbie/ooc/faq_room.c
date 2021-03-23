#include <std.h>

inherit ROOM;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("light",2);
        set_property("no sticks",1);
	set_property("ooc room", 1);
        set_short("%^MAGENTA%^FAQ room");
        set_long(
@STYX
This room is packed full of the answers to the questions most frequently asked by newcomers to Sundering Shadows.  There are several posters on the walls here that have the information broken down from the faq help file.  Type %^BOLD%^<look posters>%^RESET%^ to see the topics they cover and how to read them. 
STYX
        );
        set_smell("default","The room smells like ripe apples.");
        set_listen("default","The room buzzes with questions and answers about life in Sundering Shadows.");
        set_items(([
        ]));
        set_exits(([
        "out" : "/d/newbie/ooc/hub_room2",
        ]));
}

void reset() {
	::reset();
	if(!present("posters"))
	new ("/d/newbie/ooc/faq_poster.c")->move(TO);
}
