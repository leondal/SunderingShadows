// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn4");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Castwater Inn Stairwell");

    set_long("%^WHITE%^%^BOLD%^A grand circular stairwell leads upward towards the balcony that stands guard over the entry hall.  Beautiful %^RED%^red cedar %^WHITE%^steps and rails stand out in their naturally st"
	"ained beauty.  Hand carved balusters uniquely designed for the inn stand out as they accompany the flow of the risers and handrails winding into a curve going up into the second level.  %^YELLOW%^Ligh"
	"t %^WHITE%^from the chandelier in the entry hall shines onto the stairs casting shadows only in small doses on your feet.   Further up against the walls behind the balcony, you can see some more %^RES"
	"ET%^%^MAGENTA%^paintings %^BOLD%^%^WHITE%^coming into view.%^RESET%^ "
	);

    set_smell("default","
%^CYAN%^The smells of food is faint here%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Light chatter and quiet laughter bounces off the walls%^RESET%^");


    set_exits(([ 
		"up" : "/d/av_rooms/mystra/inn5",
		"east" : "/d/av_rooms/mystra/inn1",
	]));

}