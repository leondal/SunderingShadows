// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b9");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("dirt road");
    set_climate("tropical");

    set_short("an underground cave");

    set_long("%^RESET%^%^ORANGE%^The passage opens up here into what appears to be a natural cave in the swamp's soil.  Though not very high, the %^BLACK%^%^BOLD%^stone %^RESET%^%^ORANGE%^of the cave provides secur"
	"e footing and a has a sense of safety that was missing in the earlier corridor.   An %^RED%^iron grate %^ORANGE%^covers a portion of the eastern cave that curves out of the way.  Another of those dirt"
	" corridors leads off to the northeast.%^RESET%^"
	);

    set_smell("default","
The smell wet earth is heavy here.");
    set_listen("default","Did you hear something moving beyond the bars?");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/dekumage_b8",
		"north" : "/d/av_rooms/lurue/dekumage_b7",
		"east" : "/d/av_rooms/lurue/dekumage_b10",
	]));

    set_door("cell door","/d/av_rooms/lurue/dekumage_b10","east","manor key","cell lock");
    add_lock("cell door","manor key","cell lock","A heavy chain has been fed between several of the iron bars and are held shut by a new looking padlock. ");
    set_locked("cell door",1,"cell lock");
    lock_difficulty("cell door",-35,"cell lock");
    set_open("cell door",0);
    set_string("cell door","knock","rattles the bars of the");
    set_string("cell door","open","The rusty bars groan as they are pulled open.");
    set_string("cell door","close","The clang of iron as the door slams shut echoes around the chamber.");
    set_door_description("cell door","This rusty looking hash of bars has been formed into a sort of cell door that spans a portion of the cave.  Old looking, you wonder why anyone would put such a contraptions down here.  That is till you catch the sight of eyes in the dark of the room beyond!");
}