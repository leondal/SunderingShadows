// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("farm");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("meadows");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Farmland%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This farm is a field of %^YELLOW%^wheat%^RESET%^%^ORANGE%^ and %^YELLOW%^barley%^RESET%^%^ORANGE%^ with a wooden fence to keep out %^RED%^varmints%^ORANGE%^. A %^BOLD%^%^GREEN%^shac"
	"k%^RESET%^%^ORANGE%^ where the farmer lives lies at the back end of the field, and a slow moving %^BOLD%^%^CYAN%^stream winds%^RESET%^%^ORANGE%^ its way from a spring on the other side. The lands look"
	" to be in %^BLUE%^good shape%^ORANGE%^, and well kept despite the rickety old shack.%^RESET%^"
	);

    set_smell("default","
%^YELLOW%^It smells of %^RESET%^%^ORANGE%^manure.%^RESET%^");
    set_listen("default","You hear the birds and the wind blowing through the fields.");

    
set_items(([ 
	"stream" : "The stream doubtless provides much needed irrigation and water for the farmer to drink.",
	"shack" : "The shack looks rather poor. It looks abandoned with the door ajar, creaking in the wind.",
	"field" : "The land looks to be rather rich and with deep dark soil and well tilled ruts.",
	]));

    set_exits(([ 
		"south" : "/d/newbie/rooms/road/road52",
	]));

}