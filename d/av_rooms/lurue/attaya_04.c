// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_04");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Under the boardwalk%^RESET%^");

    set_long("%^RESET%^You are standing beneath a %^ORANGE%^wooden pier %^RESET%^that extends from the city of %^YELLOW%^Seneca %^RESET%^out into the %^CYAN%^ocean%^RESET%^.  The wood has been stained with a type o"
	"f %^BOLD%^%^BLACK%^tar %^RESET%^to help it withstand the constant onslaught of weather and tide.  This makes it nearly black in color and obscures the rich %^ORANGE%^amber tones%^RESET%^ of the origin"
	"al wood.  To the southwest, a beach curves away in a spill of %^YELLOW%^golden sand %^RESET%^that clings thickly at your heals and makes walking tiresome and difficult. %^RESET%^"
	);

    set_smell("default","
You can smell the salty spray of the ocean.");
    set_listen("default","The waves pound against the rocky coastline further south.");

    
set_items(([ 
	({ "sand", "beach" }) : "%^RESET%^%^ORANGE%^The beach extends down to the coastline in a southern direction.  Gold and cream mixing with the occasional stone or shell.%^RESET%^",
	({ "pier", "wood pier", "wood", "wooden pier" }) : "%^BOLD%^%^BLACK%^The pier is made out of thick round poles that have been driven deep into the earth.  Beams of equally thick wood create a framework of crossbeams and joints that support the actual surface that is walked upon.  Nearly black in color, the wood has long since absorbed the tar-like paint that was placed upon it to prevent the weather and tide from causing damage.  With all that framework in place, one could probably %^RESET%^ascend%^BOLD%^%^BLACK%^ up into the underside of the pier and find a nice hideaway to relax.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/attaya/beach18",
		"east" : "/d/attaya/beach20",
		"ascend" : "/d/av_rooms/lurue/attaya_05",
		"southwest" : "/d/attaya/senund/rooms/senbeach2",
	]));



    set_invis_exits(({ "ascend" }));

}