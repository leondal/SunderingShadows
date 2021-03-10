// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castle2");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("back alley");
    set_climate("temperate");

    set_short("Castle Halls");

    set_long("%^RESET%^This is an aging castle interior.  The major walls, floor and ceiling are built from roughly cut stones, thinly mortared.  Judging from the way noises are absorbed, the walls must be very thi"
	"ck and durable indeed.  Years have left their mark on many features around you.  %^BOLD%^Cobwebs%^RESET%^ obscure many of the open spaces and drift lazily in the open air.  A %^RED%^dank%^RESET%^, %^R"
	"ED%^oily%^RESET%^ feeling suggests that organisms still thrive somewhere, making it somewhat difficult to breathe.  The occasional rusting %^BOLD%^%^BLACK%^sconce%^RESET%^ or %^ORANGE%^hanging%^RESET%"
	"^ suggests that civilized things once lived here, but not for quite some time.%^RESET%^"
	);

    set_smell("default","
%^GREEN%^It smells like age and mildew.%^RESET%^");
    set_listen("default","%^ORANGE%^You hear distant dripping.%^RESET%^");

    
set_items(([ 
	({ "webs", "cobwebs" }) : "Cobwebs riddle the castle ruins, everywhere they can.  The webbing is just a little too thick, suggesting very big spiders.",
	({ "hanging", "hangings" }) : "%^ORANGE%^The walls look like they once proudly displayed a variety of hangings, tapestries and banners.  They have long since decayed so as to be unrecognizable.%^RESET%^",
	({ "sconce", "sconces" }) : "Rusting sconces probably once held torches.  Very little light penetrates here now.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/castle1",
		"north" : "/d/av_rooms/tiamat/castle3",
		"west" : "/d/av_rooms/tiamat/castle4",
		"east" : "/d/av_rooms/tiamat/castle10",
	]));

    set_door("door","/d/av_rooms/tiamat/castle3","north","key castle","castle lock");
    add_lock("door","key castle","castle lock","A mechanical lock set into the door.");
    set_locked("door",1,"castle lock");
    lock_difficulty("door",-85,"castle lock");
    set_open("door",0);
    set_string("door","knock","knocks on the");
    set_string("door","open","The door opens with a loud creak.");
    set_string("door","close","The door closes with a loud creak.");
    set_door_description("door","This is a thick wooden double door, reinforced with iron bands.");
}