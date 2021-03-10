// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("Lab");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("A %^BOLD%^%^WHITE%^Lab%^RESET%^");

    set_long("This room is oval in shape and quite large with four different levels. Each level has a walkway with row after row of bookcases.and beakers sitting on %^BOLD%^%^RED%^chestnut%^RESET%^ shelves. The flo"
	"or of the lab contains numerous tables with books and beakers scattered about.  The floor is made of %^BOLD%^%^CYAN%^polished%^RESET%^ marble with a mixture of granite below the surface. The center of"
	" the room has a large cage made of %^BOLD%^%^WHITE%^steel%^RESET%^. The steel cage is quite unique and is surround by a flowing pool of %^BOLD%^%^RED%^boiling%^RESET%^ water. "
	);

    set_smell("default","
The smell of burned components and magical spells clog the air");
    set_listen("default","The rush of flowing water and the movement of air can be heard across the room");

    
set_items(([ 
	"cage" : " The cage is quite interesting to gaze apon. It is made out of steel and the steel appears to be constantly on fire, but never moving. The door of the cage is made of pure %^BOLD%^%^WHITE%^mithril%^RESET%^ with small streaks of %^CYAN%^electricity%^RESET%^ flowing through it.",
	"books" : " The books spines are variety of colors and they range from demon summoning to crafting artifacts",
	"bookcases" : "The bookcases all appear to be made of chestnut wood and contain hundreds of books",
	"beakers" : "The beakers appear to contain different liquids and powdery substances within them",
	]));
}