// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("shack");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Dilapidated Shack%^RESET%^");

    set_long("This is a %^BOLD%^%^WHITE%^bare bones%^RESET%^%^ORANGE%^ shack%^RESET%^ that looks to be little more than a bed on the floor, a rickety table, and a %^RESET%^%^ORANGE%^stone fireplace%^RESET%^ and %^R"
	"ED%^hearth%^RESET%^%^ORANGE%^. The bed is hardly more than sack cloth stuffed with %^YELLOW%^straw%^RESET%^. Windows appear to be too expensive for this place, and the door %^CYAN%^hangs ajar%^RESET%^"
	" loosely in the wind. Pots of food lie knocked over on the floor, meal and flower eaten by %^GREEN%^wild animals%^RESET%^. Whoever was living here looks like they left in a hurry and didn't have much "
	"to start with."
	);

    set_smell("default","
It smells like %^BOLD%^%^BLACK%^soot%^RESET%^ and %^ORANGE%^dirty socks%^RESET%^.");
    set_listen("default","The wind whistles outside.");

    set_search("hearth","The fireplace and hearth is old and worn, and possibly predates the wood on the shack. ");
    set_search("fireplace","The fireplace is old and worn, and possibly predates the wood on the shack. ");
    set_search("bed","There's nothing to be found in the straw of this lowly matress.");
    set_search("door","A simple latch was made to keep this door shut.");
    set_search("pots","The critters didn't leave the farmer much to eat.");
    
set_items(([ 
	"table" : "There's nothing left on the table. But it once served to help make meals.",
	"floor" : "The floor is little more than dirt.",
	"bed" : "The bed is made of straw stuffed into some sacks that were sewn together.",
	"pots" : "These pots once held flower and meal, but now they are empty due to enterprising varmints.",
	"door" : "The door is made out of slats of wood.",
	"walls" : "The walls are made out of some kind of wooden planks.",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/myrkul/farm",
	]));

}