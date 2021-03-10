// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c5");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^A room in an underwater structure%^RESET%^");

    set_long("%^RESET%^%^CYAN%^There is little left to this once plushly appointed room.  Any %^ORANGE%^furniture%^CYAN%^ or %^WHITE%^adornments %^CYAN%^have long since fallen to the remains of the floor, ruined be"
	"yond recognition into a pile of %^GREEN%^algae %^CYAN%^coated rubble.  A few small %^WHITE%^fish%^CYAN%^ have made their home amongst the remains, and you see at least one%^RED%^ crustacean %^CYAN%^va"
	"nish into a hole when you approach. %^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    set_search("rubble","%^RED%^All you manage to do is annoy a few crabs who quickly scuttle away into a deeper hole.%^RESET%^");
    
set_items(([ 
	({ "algae", "fish" }) : "%^RESET%^%^GREEN%^Tiny fish dart in and out of the many hideaways that have been created by the room's rubble.  They flit about, nibbling on the algae that grows thickly on almost everything in the room.%^RESET%^",
	({ "furniture", "adornments" }) : "%^RESET%^%^ORANGE%^There is not much left of the furniture or personal items that once made up this room's decorations.  Most has been destroyed by water and time, though there are a few instances where you see the hand of man having interfered, including the lack of anything valuable.%^RESET%^",
	"crustacean" : "%^RED%^Little crabs and lobsters make their homes in the small niches that can be found throughout the rubble.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/seawreck_c4",
	]));

}