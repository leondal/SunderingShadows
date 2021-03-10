// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("trial4");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^MAGENTA%^A crystal door%^RESET%^");

    set_long("%^RESET%^%^CYAN%^The tunnel leading from the shore opens into a cave mouth hewn in %^BOLD%^%^BLUE%^glacial %^CYAN%^ice%^RESET%^%^CYAN%^.  The cave chamber is quite large, amplifying any noice into a l"
	"oud echo. Every few minutes, your movement causes a short rain of ice crystals from above.  The little light penetrating the tunnel reflects off of facets of ancient ice.  Directly opposite the tunnel"
	" mouth is a conspicuous tall door carved from %^BOLD%^ice%^RESET%^%^CYAN%^ and %^MAGENTA%^amethyst%^CYAN%^.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^It smells crisp and damp.");
    set_listen("default","%^GREEN%^You hear the slush of shifting ice.");


    set_exits(([ 
		"north" : "/d/av_rooms/tiamat/trial1",
		"tunnel" : "/d/shadow/virtual/sea/winter.dock",
	]));

    set_door("crystal door","/d/av_rooms/tiamat/trial1","north","crystal key","crystal lock");
    add_lock("crystal door","crystal key","crystal lock","A complex lock built out of diamond.");
    set_locked("crystal door",0,"crystal lock");
    lock_difficulty("crystal door",-90,"crystal lock");
    set_open("crystal door",0);
    set_string("crystal door","knock","knocks on the door");
    set_string("crystal door","open","%^BOLD%^%^BLUE%^The door swings open, releasing a rush of cool air!%^RESET%^");
    set_string("crystal door","close","You shut the door");
    set_door_description("crystal door","%^MAGENTA%^The single hinged door looks as though it were composed of amethyst quarts.  It has a single lock carved from %^BOLD%^pink diamond%^RESET%^.");
}