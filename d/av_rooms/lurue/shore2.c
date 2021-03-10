// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("shore2");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^YELLOW%^A hidden part of the beach%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^A little inlet stretches back away from the nearby shore, following a thin %^BLUE%^river %^ORANGE%^that wanders around the sand dunes.  Here and there, bits of %^WHITE%^shell %^ORAN"
	"GE%^or %^BOLD%^%^BLACK%^rock %^RESET%^%^ORANGE%^can be seen, cast offs from higher tides then there is right now.  Further to the south, you can see the %^CYAN%^o%^GREEN%^c%^BLUE%^e%^CYAN%^a%^BLUE%^n "
	"%^ORANGE%^rolling in and out in its never ending dance.  Nearby, several %^WHITE%^crates%^ORANGE%^, %^CYAN%^barrels%^ORANGE%^, %^BOLD%^%^BLACK%^chests %^RESET%^%^ORANGE%^and other %^YELLOW%^goods %^RE"
	"SET%^%^ORANGE%^are neatly stacked up and hidden by one of the many dunes.  Clearly someone is stocking goods here and waiting for transport by sea.%^RESET%^"
	);

    set_smell("default","
You can smell the salt air of the open sea.");
    set_listen("default","Waves crash nearby.");

    
set_items(([ 
	({ "shell", "rock" }) : "%^RESET%^You see bits of shell and a few rocks here and there.  Nothing all that important.%^RESET%^",
	({ "crates barrels", "chests", "goods" }) : "%^RESET%^Several neatly arranged piles of goods are hidden behind some of the higher dunes, making it so that one wouldn't be able to see them except if they were standing right where you are.  A clever little operation this is.%^RESET%^",
	({ "sand", "shore", "beach", "dunes", "water", "river" }) : "%^RESET%^%^ORANGE%^The beach wanders back a little ways, following a small river inlet that wanders through the dunes.  The area provides a good amount of cover, while also allowing one to see the ocean beyond.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/shore3",
		"north" : "/d/av_rooms/lurue/shore1",
	]));

}