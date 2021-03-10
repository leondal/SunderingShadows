// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b10");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("an underground cell");

    set_long("%^RED%^This small niche in the larger cave curves back out of sight and toward a pile of rubbish that looks like leaves and moss.  In fact the whole back corner looks to have vegetation growing out of"
	" it.  Vegetation that moves!%^RESET%^"
	);

    set_smell("default","
The smell wet earth is heavy here.");
    set_listen("default","Your heart is beating so heavily in your ears you can't hear a thing!");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/dekumage_b9",
	]));

    set_door("cell door","/d/av_rooms/lurue/dekumage_b9","west","manor key","cell lock");
    add_lock("cell door","manor key","cell lock","A heavy chain has been fed between several of the iron bars and are held shut by a new looking padlock. ");
    set_locked("cell door",1,"cell lock");
    lock_difficulty("cell door",-35,"cell lock");
    set_open("cell door",0);
    set_string("cell door","knock","rattles the bars of the");
    set_string("cell door","open","The rusty bars groan as they are pulled open.");
    set_string("cell door","close","The clang of iron as the door slams shut echoes around the chamber.");
    set_door_description("cell door","This rusty looking hash of bars has been formed into a sort of cell door that spans a portion of the cave.  Old looking, you wonder why anyone would put such a contraptions down here.  That is till you catch the sight of eyes in the dark of the room beyond!");
}