// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b5");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^RED%^an underground laboratory%^RESET%^");

    set_long("%^RESET%^%^MAGENTA%^The first impression of this chamber is that of vastness.  A wide swath of pale %^RESET%^gray mist%^MAGENTA%^ swirls about, cutting off your view of anything beyond this cleared ar"
	"ea.  Here a large %^BOLD%^%^BLACK%^stone table%^RESET%^%^MAGENTA%^ and a %^ORANGE%^writing desk %^MAGENTA%^sit.  Over there, shelves that hold several types of %^GREEN%^plants %^MAGENTA%^and %^WHITE%^"
	"skeletal systems %^MAGENTA%^from small animals.  There is even a small %^BLUE%^wash basin%^MAGENTA%^ to be found, making you cringe at what might be done in this strange space.  The only way out appea"
	"rs to be the glowing %^BOLD%^portal%^RESET%^%^MAGENTA%^ behind you.%^RESET%^"
	);

    set_smell("default","
The fragrant scent of components and melted wax fills the air.");
    set_listen("default","There is a crackle of candle flame as the candles flicker.");

    
set_items(([ 
	({ "basin", "wash basin" }) : "%^BLUE%^The basin is empty at the moment, but you can see a ring around the edge and it appears to be stained %^RED%^red%^BLUE%^!%^RESET%^",
	({ "desk", "writing desk", "papers" }) : "%^RESET%^%^ORANGE%^Looking the writing desk over you notice that almost all the books and papers refer to plants or to anatomy.  There are several distrubing drawings of animals blended with plants, making you wonder just what is being experimented on here.%^RESET%^",
	({ "table", "stone table" }) : "%^BOLD%^%^BLACK%^This large stone table is covered with a number of objects.  Mostly plants and diagrams.  However you do see that there are straps at each end, suggesting that at times it's used to restrain something, or someone.%^RESET%^",
	"mist" : "%^BOLD%^%^WHITE%^The faint mist swirls around you, blocking your view of the remaining room, if indeed there is any.%^RESET%^",
	"furniture" : "%^ORANGE%^There are several pieces of well made furniture arranged around this strange space.  Most of which look to be in good repair.%^RESET%^",
	"shelves" : "%^GREEN%^The shelves are filled with what appear to be experiments and reference pieces.  Someone seems to be blending plants and animals to try and create a cross breed!%^RESET%^",
	]));

    set_exits(([ 
		"portal" : "/d/av_rooms/lurue/dekumage_b8",
	]));

}