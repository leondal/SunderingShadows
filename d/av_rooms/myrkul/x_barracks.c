// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_barracks");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^Barracks%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This spartan room is full of footlockers and bunkbeds which line the north wall. %^RED%^Weapons%^BLACK%^ racks line the opposite, south wall where %^BLUE%^d%^RESET%^%^BLUE%^r%^BOLD%^o"
	"w s%^RESET%^%^BLUE%^o%^BOLD%^ldiers%^BLACK%^ hang their weapons and armor. The center of the room has a large open %^RESET%^%^ORANGE%^sand pit%^BOLD%^%^BLACK%^ where the soldiers test their skill. The"
	" barracks are kept meticulously clean.%^RESET%^"
	);

    set_smell("default","
The funk of dirty socks fills the air.");
    set_listen("default","You hear snoring drow soldiers.");

    set_search("sand","There is a lot of blood evidently in the sand.");
    set_search("bunkbeds","You find nothing in the bunks.");
    set_search("bunks","You find nothing in the bunks.");
    set_search("beds","You find nothing in the bunks.");
    set_search("footlockers","The footlockers have many personal items of only nominal value.");
    set_search("bed","You find nothing in the bunks.");
    
set_items(([ 
	({ "sand", "sand pit", "pit" }) : "The sand pit is where the drow train for battle. ",
	({ "beds", "bunks", "bunkbeds" }) : "The bunkbeds are unremarkable wooden frames with soft matresses. The beds have been made with precision and attention to detail.",
	"weapons" : "The weapons include bows, longswords, and daggers. Mesh armor is also kept in the racks. ",
	"armor" : "There are some suits of mesh armor.",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/myrkul/x_whall",
	]));

}