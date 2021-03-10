// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("crypt_start");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^En%^RED%^t%^BLACK%^om%^RED%^b%^BLACK%^ed in a C%^RED%^r%^BLACK%^ypt%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^shadows%^BOLD%^%^BLACK%^ en%^WHITE%^s%^BLACK%^hr%^WHITE%^o%^BLACK%^ud you in an ever deepening gl%^WHITE%^o%^BLACK%^om. A series of heavy stone slabs line the "
	"walls of this large, oval room. %^BLACK%^An%^YELLOW%^c%^BLACK%^ient s%^YELLOW%^k%^BLACK%^eletons rest atop the slabs, arms crossed over their breasts. A crumbling %^GREEN%^staircase%^BLACK%^ at the en"
	"d of the room leads up and away. Opposite the staircase, a stone-carved mural of a grinning %^BOLD%^%^WHITE%^skeletal skull%^BLACK%^ lines the wall. A feeling of a forlorn %^RESET%^%^MAGENTA%^emptines"
	"s%^BOLD%^%^BLACK%^ of the %^RESET%^%^MAGENTA%^f%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^rgotten d%^BOLD%^%^WHITE%^e%^RESET%^%^MAGENTA%^ad%^BOLD%^%^BLACK%^ washes over you in the silence.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^A m%^YELLOW%^u%^BLACK%^sky scent of %^GREEN%^mold%^BLACK%^ and ancient st%^WHITE%^o%^BLACK%^ne pervades the room.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^Silent as a tomb.%^RESET%^");

    set_search("skeletons","%^BOLD%^%^BLACK%^Rotted fabric turns to dust at your touch.%^RESET%^");
    set_search("mural","%^BOLD%^%^BLACK%^The %^WHITE%^skull%^BLACK%^ reveals nothing but perhaps a vague sense of %^RESET%^%^MAGENTA%^irony%^RESET%^");
    set_search("staircase","%^BOLD%^%^BLACK%^The staircase shows some signs of water damage and wear from the tramp of many feet.%^RESET%^");
    set_search("stairs","%^BOLD%^%^BLACK%^The staircase shows some signs of water damage and wear from the tramp of many feet.%^RESET%^");
    set_search("skeleton","%^BOLD%^%^BLACK%^Rotted fabric turns to dust at your touch.%^RESET%^");
    set_search("skull","%^BOLD%^%^BLACK%^The %^WHITE%^skull%^BLACK%^ reveals nothing but perhaps a vague sense of %^RESET%^%^MAGENTA%^irony%^RESET%^");
    set_search("slabs","%^BOLD%^%^BLACK%^The stone slabs are completely solid.%^RESET%^");
    set_search("stair","%^BOLD%^%^BLACK%^The staircase shows some signs of water damage and wear from the tramp of many feet.%^RESET%^");
    set_search("slab","%^BOLD%^%^BLACK%^The stone slabs are completely solid.%^RESET%^");
    
set_items(([ 
	({ "rune", "runes" }) : "%^BOLD%^%^BLACK%^....Know me and fear me. My embrace is for all and is patient but sure. The dead can always find you. My hand is everywhere - there is no door I cannot pass, nor guardian who can withstand me....%^RESET%^",
	({ "skull", "mural" }) : "%^BOLD%^%^BLACK%^The skull's empty eyesockets gaze out on the hall with a kind of malignant intelligence. An %^RESET%^%^MAGENTA%^ironic%^BOLD%^%^BLACK%^ smile graces the skeletal face, as laughing at its own mortality. Chipped runes line the walls surrounding the mural.%^RESET%^",
	({ "skeleton", "skeletons" }) : "%^BOLD%^%^BLACK%^The skeletons seem to have died in violence, with many a cracked bone. They are truly ancient, and only shreds of garments remain. Rusty bits of metal are all that remain of any tools or jewelry.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/myrkul/crypt_stair",
	]));

}