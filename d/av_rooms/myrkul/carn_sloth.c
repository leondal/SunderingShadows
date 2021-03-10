// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_sloth");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A %^BLACK%^h%^WHITE%^a%^BLACK%^zy%^WHITE%^ tent%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This tent is very %^RESET%^%^ORANGE%^mellow%^BOLD%^%^CYAN%^. In the center of the tent, a tobacconist stands behind a circular table, selling his wares. The table has a great variety o"
	"f different smoking pipes, tobacco, and many rare %^YELLOW%^alch%^BLACK%^y%^YELLOW%^mical %^RESET%^%^ORANGE%^herbs.%^BOLD%^%^CYAN%^ Very %^MAGENTA%^comfy pillows%^CYAN%^ line the walls, and many visit"
	"ors can be seen relaxing, smoking, and chatting. Fresh %^BLUE%^air%^CYAN%^ comes in from the open flaps on the tent, and the %^RESET%^%^ORANGE%^laid back atmosphere%^BOLD%^%^CYAN%^ is a welcome relief"
	" from the hustle and bustle of the rest of the carnival.%^RESET%^"
	);

    set_smell("default","
A heavy odor of herbs and tobacco floats through the air.");
    set_listen("default","You hear the murmur of quiet chatting.");

    
set_items(([ 
	"tobacco" : "Demand for tobacco is great, so some varieties are available and others are snapped up very quickly.",
	"pipes" : "There are many pipes for sale of all shapes and sizes.",
	"herbs" : "He's got everything from simple remedies to strong narcotics that only a healer would use, to crazy weed that only berserkers take. Doubtless the merchant is not in Tabor because this stuff would probably be banned. ",
	"pillows" : "There are some unoccupied, and they look very clean and comfy.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/carn_main_e",
	]));

}