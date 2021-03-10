// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_lab");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^M%^GREEN%^a%^BLUE%^k%^YELLOW%^e%^BLACK%^s%^RED%^h%^MAGENTA%^i%^CYAN%^f%^BLACK%^t La%^YELLOW%^b%^BLACK%^or%^GREEN%^a%^BLACK%^to%^BLUE%^r%^BLACK%^y%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in a widening passageway that has had many %^RESET%^%^ORANGE%^tables%^BOLD%^%^BLACK%^ leaned against the walls. Even coffins have been used to prop up pieces of wood to crea"
	"te greater workspace. Across these haphazard planks, a great assortment of %^BLUE%^v%^WHITE%^i%^RED%^a%^GREEN%^l%^YELLOW%^s%^BLACK%^, tubing, crystals, and powders have been spread. %^WHITE%^Manuscrip"
	"ts%^BLACK%^ and %^RESET%^%^ORANGE%^notebooks%^BOLD%^%^BLACK%^ are piled high. And everywhere you look are the trappings of various %^GREEN%^al%^BLACK%^c%^GREEN%^h%^BLACK%^y%^GREEN%^mi%^BLACK%^c%^GREEN"
	"%^al%^BLACK%^ experiments. Lanterns cast a light off into the %^RESET%^%^MAGENTA%^gloom%^BOLD%^%^BLACK%^, illuminating little but the workbenches. Passageways extend off to the east and west, but to t"
	"he south a great excavation has been underway, possibly related to the laboratory in this area.%^RESET%^"
	);

    set_smell("default","
%^YELLOW%^It stinks of sulfur and other caustic materials.%^RESET%^");
    set_listen("default","%^BOLD%^%^CYAN%^You hear the bubbling of potions and the whir of stirring.%^RESET%^");

    
set_items(([ 
	"experiments" : "There seems to be an emphasis on conjuring, summoning, undeath, and planar portals.",
	({ "tables", "coffins", "planks" }) : "On top of every inch of space are magical contraptions, magical supplies, vials, tubes, powders, crystals. You could find any kind of magical component imaginable -- if you knew on which bench to look!",
	({ "manuscripts", "notebooks" }) : "The notebooks, manuscripts, and papers contain many recipes for the brewing of potions, extracting elemental essences, and purifying ingredients. ",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/myrkul/crypt_archeology_dig",
		"west" : "/d/av_rooms/myrkul/crypt_hall_west3",
		"east" : "/d/av_rooms/myrkul/crypt_hall_east3",
	]));

}