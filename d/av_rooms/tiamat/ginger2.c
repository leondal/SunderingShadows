// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ginger2");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^ORANGE%^Gingerbread bedroom%^RESET%^");

    set_long("%^RESET%^This is a tiny bedroom in a %^ORANGE%^gingerbread house%^RESET%^.  All of the major furnishing has a rather %^ORANGE%^cookie-like%^RESET%^ appearance.  An impressive %^ORANGE%^wardrobe%^RESET"
	"%^ rests ominously opposite the %^BOLD%^d%^RED%^o%^WHITE%^o%^RED%^r%^RESET%^ and set to the east is the %^ORANGE%^bed%^RESET%^.  The bed has a %^ORANGE%^gingerbread%^RESET%^ frame and a comfortable lo"
	"oking %^MAGENTA%^mattress%^RESET%^ made of some sort of %^BOLD%^%^MAGENTA%^gummy candy%^RESET%^.  The bright %^BOLD%^%^MAGENTA%^rose colored%^RESET%^ bedding shines like saltwater %^BOLD%^t%^YELLOW%^a"
	"%^MAGENTA%^f%^WHITE%^f%^CYAN%^y%^RESET%^.  There are no other embellishments in the room, except for a simple %^ORANGE%^painting%^RESET%^."
	);

    set_smell("default","
%^ORANGE%^Mmm, smells like cookies!");
    set_listen("default","%^GREEN%^You hear very little here.");

    
set_items(([ 
	"painting" : "%^ORANGE%^The painting is in a gingerbread frame.  It depicts a rather enthusiast %^BOLD%^%^WHITE%^white bunny%^RESET%^%^ORANGE%^ prancing through a field of %^YELLOW%^daffodils%^RESET%^%^ORANGE%^.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/tiamat/ginger1",
	]));

    set_door("side door","/d/av_rooms/tiamat/ginger1","west");
    set_open("side door",0);
    set_string("side door","knock","knocks on the");
    set_string("side door","open","You open the door.");
    set_string("side door","close","You close the door.");
    set_door_description("side door","A door in a candy frame.");
}