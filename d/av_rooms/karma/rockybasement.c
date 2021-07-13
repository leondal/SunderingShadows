// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("rockybasement");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A rocky cellar");

    set_long("%^BOLD%^%^BLACK%^The %^WHITE%^light %^BLACK%^of a single f%^WHITE%^l%^BLACK%^ick%^WHITE%^e%^BLACK%^ring la%^WHITE%^n%^BLACK%^te%^WHITE%^r%^BLACK%^n ref%^WHITE%^l%^BLACK%^ect%^WHITE%^s %^BLACK%^the m%^"
	"ORANGE%^u%^BLACK%^l%^ORANGE%^t%^BLACK%^i%^CYAN%^c%^BLACK%^ol%^MAGENTA%^o%^CYAN%^r%^BLACK%^e%^GREEN%^d %^CYAN%^geodes %^BLACK%^lining the walls, bathing the room in a distracting dance of color and sha"
	"dow. Crystal %^RESET%^stalactites %^BOLD%^%^BLACK%^protrude from the ground along the room's perimeter, making it hard to gauge its exact size. As your eyes adjust, you find what looks like a %^RESET%"
	"^%^ORANGE%^storage area %^BOLD%^%^BLACK%^of sorts. Several crates are scattered about the floor, most of which have been emptied and turned on their sides. A %^RESET%^%^ORANGE%^space %^BOLD%^%^BLACK%^"
	"has been cleared in the middle of the room, for a %^RESET%^%^ORANGE%^blanket %^BOLD%^%^BLACK%^and several worn pillows. The %^ORANGE%^lantern %^BLACK%^stands on the blanket, and just next to it sits a"
	"n %^WHITE%^innocent%^BLACK%^, %^RESET%^%^MAGENTA%^old w%^BOLD%^oode%^RESET%^%^MAGENTA%^n box%^BOLD%^%^BLACK%^. %^RESET%^"
	);

    set_smell("default","
It smells of potatoes and damp minerals.");
    set_listen("default","It is eerily quiet.");

    set_search("crates","You search one of the crates and find that you can push it away to reveal a small chute, barely big enough for a child to squeeze through.");
    
set_items(([ 
	"crates" : "Most of the crates have been emptied. Some are turned on their sides and used as beds, tables and chairs.",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/karma/rockytemple",
		"chute" : "/d/av_rooms/karma/rockyalcove",
	]));



    set_invis_exits(({ "chute" }));

}