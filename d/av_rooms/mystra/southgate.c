// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("southgate");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^ORANGE%^So%^BOLD%^%^BLACK%^uth Ga%^RESET%^%^ORANGE%^te%^RESET%^");

    set_long("%^MAGENTA%^Two large %^BOLD%^%^WHITE%^pillars %^RESET%^%^MAGENTA%^sit on either side of a cobble-stone path before you.  The %^BOLD%^%^WHITE%^pillars %^RESET%^%^MAGENTA%^stand near three stories in he"
	"ighth and are made of solid %^BOLD%^%^BLACK%^gn%^RESET%^e%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^blocks expertly cut into squares and pieced together for a perfect"
	" fit.  In front of each pillar, and smaller guard station made of the same stones is placed to provide a bit of shelter to guards on duty.  Heavy doors made from large planks of %^ORANGE%^stout oak %^"
	"MAGENTA%^stand wide open for ease of travel.  During times of war these would be shut and reinforced.  Flags fly atop the pillars depicting the image of a %^RED%^R%^BOLD%^%^YELLOW%^o%^RED%^c %^RESET%^"
	"%^MAGENTA%^carrying a large %^BOLD%^%^BLUE%^tr%^RESET%^i%^BLUE%^d%^BOLD%^e%^CYAN%^n%^BLUE%^t %^RESET%^%^MAGENTA%^in it's claws.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^Many smells blend together for one strange aroma%^RESET%^");
    set_listen("default","%^BOLD%^%^ORANGE%^The city is alive with the bustle of it's inhabitants.%^RESET%^");

    
set_items(([ 
	({ "pillars", "pillar" }) : "%^BOLD%^%^WHITE%^30 ft. high and expertly constructed of high quality gneiss blocks%^RESET%^",
	"flag" : "%^WHITE%^%^BOLD%^A white background, with an embroidered image of a %^RED%^R%^BOLD%^%^YELLOW%^o%^RED%^c %^WHITE%^carrying in it's talons a %^BOLD%^%^BLUE%^tr%^RESET%^i%^BLUE%^d%^BOLD%^e%^CYAN%^n%^BLUE%^t%^RESET%^",
	"gate" : "%^ORANGE%^It is made of sturdy oak doors, both swung inward towards the city.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/mystra/teel1",
		"south" : "/d/av_rooms/mystra/workroom",
	]));

}