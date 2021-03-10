// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("vault");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^An %^WHITE%^A%^BLACK%^ncient V%^WHITE%^a%^BLACK%^ult%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in an %^WHITE%^ancient vault%^BLACK%^. It has a door that doubtless is sealed by solid rock. However there is a %^CYAN%^rent%^BLACK%^ in the ceiling. The vault is cube-shape"
	"d without any markings on walls, floors or ceilings. On the ground however lies two %^YELLOW%^coffins%^BLACK%^ and a %^YELLOW%^cage%^BLACK%^. One of the coffins seems to have been burst open through t"
	"he inside with some kind of cutting implement. A second appears to be completely sealed.%^RESET%^"
	);

    set_smell("default","
It smells like antiquity.");
    set_listen("default","It is oddly silent here.");

    set_search("coffins","You find ancient runes marked on the coffins.");
    set_search("cage","You find ancient runes marked on the cage.");
    
set_items(([ 
	"cage" : "Somehow this cage was tampered with. The hinges were slightly weakened by a very sharp object. The door lies on the ground with some impact marks on it. ",
	"coffin one" : "This coffin has been slashed through entirely by a razor sharp implement. The damage was done entirely from the inside, and then forced open.",
	"coffin two" : "This coffin is wrapped in chains and seems completely sealed. A bit of rust appears to have chewed a small hole in the corner.",
	"runes" : "Many runes lie on the coffins and the cage. What can be made out are, -Illithid Reaper- on the sliced coffin, and -Weave Eater- is marked on the cage. The sealed coffin has the words -Sin Eater- marked on it as well. Many markings of control, sealing, binding, and magic lie all over the coffins and cage.",
	]));

    set_exits(([ 
		"hole" : "/d/av_rooms/myrkul/fissure2",
	]));

}