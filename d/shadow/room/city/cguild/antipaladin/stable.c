#include <std.h>

inherit STABLE;

void create(){
    ::create();
set_terrain(WOOD_BUILDING);
set_travel(DIRT_ROAD);
    set_id("stables");
//    set_property("no teleport", 1);
    set_short("%^BOLD%^%^RED%^Stable of the Antipaladins%^RESET%^");
    set("long",
@OLI
    %^BOLD%^%^RED%^ Stable of the Antipaladins %^RESET%^
%^WHITE%^This is the Antipaladin's stable. Here you can buy a war horse to carry you on your adventures.  As you look around you notice how wonderfully clean it is... surprisingly so. Sturdy looking war horses stand in their stalls and they look at you as you enter the room.
You may purchase a war horse for a price, and some may be available with barding.  There is a list on the wall with the prices and what is currently available. 
OLI
);

    set_exits(([
        "out" : "/d/shadow/room/city/cguild/antipaladin/enter1",
    ]));
    set_items(([ 
    ]));
    set_smell("default","You smell horses and supplies like hay.");
    set_listen("default","An occasional shifting of horses hooves can be heard.");
    set_animal(({"war horse", "barded war horse"}),({"/d/shadow/room/city/cguild/paladin/war_horse","/d/shadow/room/city/cguild/paladin/barded_war_horse"}));
    set_animal_price(({"war horse","barded war horse"}),({500, 2500}));
    set_stalls(15);
    ::fill_stalls();
}