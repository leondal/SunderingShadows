// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ruined_base2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("A room in shambles");

    set_long("This room appears slightly in better shape then the other. It has only one exit leading south and at the north is a long table with %^BOLD%^%^WHITE%^papers%^RESET%^ thrown about it. To the west is a d"
	"ented and bent over %^BOLD%^%^CYAN%^regal%^RESET%^ statue of a knight. The walls of this room are made of sturdy looking steel and lack the bluish tint of the room before. "
	);

    set_smell("default","
The scent of sulfur is quite strong in the air");
    set_listen("default","A eeire and deadly silence lingers");

    set_search("papers","This piece of paper looks interesting!");
    
set_items(([ 
	"paper" : "The following piece of paper has the following written on it: If one must die, one should die for a cause!",
	"statue" : "The statue was quite beautifully in another age of time. However, now it lacks the awe that it once held as it's is cracked and appears to be bent over. The right side of it's face has been %^BOLD%^%^RED%^blasted %^RESET%^off.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/anhur/ruined_base",
	]));

}