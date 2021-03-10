// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("speakeasyback");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("a dimly-lit back office");

    set_long("This is a small, but well-furnished back office. A soft red carpet sits on the floor. A large desk dominates most of the room, and a plush (but curiously small) chair sits behind it. Expensive looking"
	" paintings decorate the walls."
	);

    set_smell("default","
The scent of halfling pipe weed smoke hangs heavily in the air.");
    set_listen("default","You can just make out the jazz music from the other room.");


    set_exits(([ 
		"out" : "/d/av_rooms/brandobaris/brandospeakeasy",
	]));

    set_door("backroom door","/d/av_rooms/brandobaris/brandospeakeasy","out");
    set_open("backroom door",0);
    set_string("backroom door","knock","knocks cautiously on the");
    set_string("backroom door","open","The backroom door opens with a squeak of its hinges.");
    set_string("backroom door","close","The backroom door closes loudly.");
    set_door_description("backroom door","A shiny walnut door.");
}