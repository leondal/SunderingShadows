// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_nhall");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^North Hall%^BOLD%^%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("This hallway is markedly less pedestrian than the others. The ceiling forms an arch with entranceways into a library to the west and a shrine to the east. A %^RED%^spider symbol%^RESET%^ over the east"
	"ern archway marks it for %^BOLD%^%^RED%^Lolth%^RESET%^ and the west archway is embellished with %^GREEN%^wards%^RESET%^ and %^RESET%^%^ORANGE%^mystic symbols%^RESET%^. Further to the north the hallway"
	" opens up into a very large room. While very spare, the floors here are meticulously clean without even so much as a speck of dust - no mean feat for a cave. "
	);

    set_smell("default","
You smell musty books and incense nearby.");
    set_listen("default","You hear the sound of Drow voices and walking nearby.");

    set_search("symbols","The symbols are arcane in nature perhaps indicating a magical alarm.");
    set_search("wards","The wards do appear to be magical perhaps an alarm.");
    
set_items(([ 
	"symbols" : "The symbols appear to have some magical energy and seem to glow.",
	"spider" : "The spider symbol is artistically drawn and small gemstones serve as eyes.",
	"wards" : "The wards look quite active and glow and shimmer before your eyes.",
	"symbol" : "The spider symbol is artistically drawn and small gemstones serve as eyes.",
	"floors" : "Someone has washed these floors and scrubbed them to a polish. ",
	"moral" : "The %^RED%^eyes%^RESET%^ of Lolth are on you as you gaze at the mural. Creepy!",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/x_library",
		"north" : "/d/av_rooms/myrkul/x_ghall",
		"south" : "/d/av_rooms/myrkul/x_entrance",
		"east" : "/d/av_rooms/myrkul/x_shrine",
	]));

}