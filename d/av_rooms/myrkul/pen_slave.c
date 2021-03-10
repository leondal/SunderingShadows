// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("pen_slave");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("rocky");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^YELLOW%^Ramshackle slave pen%^RESET%^");

    set_long("%^RESET%^This pen has been hastily made out of thick %^ORANGE%^wooden%^RESET%^ stakes and heavy slats. The walls are about eight feet high and seem solid enough, if in ill repair. Heavy %^BOLD%^%^BLAC"
	"K%^iron rings%^RESET%^ adorn the walls of the pen so that people in chains may be secured there. There is no %^GREEN%^shelter%^RESET%^ from the %^CYAN%^elements%^RESET%^, and it seems this place must "
	"be some kind of temporary holding area for merchants on the way to Tonovi."
	);

    set_smell("default","
It smells of fear and excrement.");
    set_listen("default","The echos of sobs and quiet despair echo in your ears.");


    set_exits(([ 
		"camp" : "/d/av_rooms/myrkul/camp",
	]));

}