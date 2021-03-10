// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_hidden");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel's Hidden Chamber%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^This room looks very different than the others. It is clean and tidy, despite a layer of dust that seems to have settled. Bookshelves line the walls full of Chapel records of birth"
	", deaths, marriages, land purchases, disputes, and settlements. A table and chair sit in the middle of the room, and a metal spiral staircase leads up into further quarters, most likely for the Chapel"
	" vicar. Light glimmers from an enchanted glowstone above the table.%^RESET%^"
	);

    set_smell("default","
It smells slightly dusty and of old books.");
    set_listen("default","It is silent");

    set_search("dust","You see footprints of a human in the dust, and they seem recent.");
    
set_items(([ 
	"table" : "The table has a writing quill and some blank paper next to a stoppered ink well.",
	"chair" : "The chair is just a wooden chair with four legs and a sturdy back.",
	"staircase" : "It looks sturdy enough, and in reasonable repair.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/location_chapel_vicar",
		"out" : "/d/av_rooms/myrkul/location_chapel_altar",
	]));

}