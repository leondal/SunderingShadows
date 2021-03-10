// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_gate");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^YELLOW%^Gates %^BLACK%^of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^BOLD%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Before you stands a gate in the deepening shadows of the caves. It is very large, and wide enough to walk two wagons abreast when opened. Torches to either side give a %^RESET%^%^MAGE"
	"NTA%^flickering%^BOLD%^%^BLACK%^ light which reveal the seal of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^BOLD%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW"
	"%^n%^BOLD%^%^BLACK%^ on the front. Clearly you stand before the ancestral home of a pillar of the Underdark.%^RESET%^"
	);

    set_smell("default","
You smell the dry air of the caves.");
    set_listen("default","You hear the sound of Drow voices and walking nearby.");

    
set_items(([ 
	"seal" : "The seal of House Xorlorrin is displayed prominently on the gate. It is a spider dripping with yellow venom.",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/myrkul/x_entrance",
		"south" : "/d/dagger/drow/rooms/city28",
	]));

    set_door("gate","/d/av_rooms/myrkul/x_entrance","north","spider key","lock");
    add_lock("gate","spider key","lock","This is a strange looking lock that has a key hole resembling a spider.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-50,"lock");
    set_open("gate",0);
    set_string("gate","knock","pounds on the");
    set_string("gate","open","The gate opens slowly.");
    set_string("gate","close","The gate swings shut.");
    set_door_description("gate","This is a wrought iron gate with ornamental spikes and bearing a symbol of a spider with dripping yellow venom.");
}