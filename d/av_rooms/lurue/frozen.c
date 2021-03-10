// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("frozen");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("ice");
    set_travel("rubble");
    set_climate("arctic");

    set_short("%^BOLD%^%^CYAN%^Within an Avalance%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This small crawl space ends abruptly at a massive, thick wall of ice. The deep %^BLUE%^blue%^WHITE%^ of the glassy substance distorts what is beyond it into a hazy fuzz, but you can a"
	"lmost make out something large and white beyond.  Perhaps just more %^CYAN%^ice %^WHITE%^and %^BLACK%^rock%^WHITE%^.  A small snow drift piles up at the base, looking somewhat distorted in shape.  May"
	"be there is something hidden.%^RESET%^"
	);

    set_smell("default","
The air is too cold to smell anything.");
    set_listen("default","Snow shifts all around you, threatening to seal you in forever.");

    set_search("drift","%^BOLD%^%^WHITE%^You plunge your hand down into the depths of the snowdrift, feeling around the best you can.  Your hand brushes over something cold and scaly and you wonder if you should pull it up or leave it where it is.%^RESET%^");
    set_search("ice,glass","%^BOLD%^%^BLUE%^The ice is a large, thick slab of ice that appears to have slid down with the avalanche.  You're very glad that you weren't caught in that because that much ice would have easily severed a body part or two during the tumble.  The large block distorts what is beyond, but you can make out a strange shape, just not tell what it is.  Maybe its just now and rock.%^RESET%^");
    set_search("snowdrift","%^BOLD%^%^WHITE%^You plunge your hand down into the depths of the snowdrift, feeling around the best you can.  Your hand brushes over something cold and scaly and you wonder if you should pull it up or leave it where it is.%^RESET%^");
    set_search("snow,rock","%^BOLD%^%^WHITE%^You can't quite make out what is beyond the glassy like surface of the ice slab.  It looks very large though, and white with some darker splots.  Perhaps its just snow and rock, but the way that one bit looks brings to mind the shape of a leg, and the other bit there kind of looks like the curve of a neck.  Its too bad that block is so thick that you can't see properly through it.%^RESET%^");
    
set_items(([ 
	({ "snow drift", "drift" }) : "%^BOLD%^%^WHITE%^Looking down at the base of the block of ice, you notice a large pile of snow has gathered.  Its oddly shaped though, jutting out and away from the block of ice, then curving slightly to the side.  Maybe you could search around in it and see if there is anything there.%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/underdark/upper/tonovitunnel/newtunnel12",
	]));

}