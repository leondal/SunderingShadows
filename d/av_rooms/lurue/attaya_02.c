// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";
int flu;

void init() {
    ::init();
    add_action("open_func", "open");
    flu = 0;

}

void create()
{
    ::create();
    set_name("attaya_02");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^Inside a fireplace%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Made of dark bricks and trimmed with a %^RESET%^%^ORANGE%^golden sheet%^BOLD%^%^BLACK%^ of carved marble, the fireplace is large enough that a person could stand up straight within it"
	" and be fairly comfortable.  The %^RESET%^%^CYAN%^flu %^BOLD%^%^BLACK%^is about six feet up from the floor where the chimney narrows, and the %^RESET%^%^CYAN%^metal handle%^BOLD%^%^BLACK%^ that allows"
	" it to shift open and closed is partly open.  A bit of soot and dust clings to the surface of the walls and chimney but for the most part it is surprisingly clean.%^RESET%^"
	);

    set_smell("default","
The old smell of burnt wood lingers in here.");
    set_listen("default","You can hear a bit of dust settling as your breath disturbs it.");

    
set_items(([ 
	({ "dust", "soot", "bricks", "wall", "brick" }) : "%^BOLD%^%^BLACK%^The bricks that make up this fireplace's interior are covered in a thin layer of dust and soot.  Likely from a fire several months old.  Despite this thin layer, the fireplace seems clean and tended, there's no way a fire would catch on something in here and burn the house down.%^RESET%^",
	"flu" : "%^RESET%^%^CYAN%^Made from metal you can see that the flu is only half open.  You would have to %^RESET%^open %^CYAN%^the flu fully if you wanted to have a fire or to go higher into the chimney. %^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/lurue/attaya_01",
	]));

}

int open_func(string str){

if(!str){return 0;
        }
    if((str == "flu")){
        if((flu == 1)){
            tell_object(TP,"%^RESET%^%^RED%^The flu is already open!\n%^RESET%^");
            return 1;
        }
        tell_object(TP,"%^BLACK%^%^BOLD%^As you open the flu, a great cloud of soot falls on you, coverering you head to toe!%^RESET%^\n");
        tell_room(ETP,"%^BLACK%^%^BOLD%^"+TPQCN+" %^BLACK%^%^BOLD%^opens the flu and is covered in a giant cloud of soot! \n",TP);
        flu = 1;
        return 1;
    }
    tell_object(TP,"%^RESET%^%^CYAN%^open what?\n");
    return 1;
    }