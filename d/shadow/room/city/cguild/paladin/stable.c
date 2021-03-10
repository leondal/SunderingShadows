#include <std.h>

inherit STABLE;

void create(){
    ::create();
    set_id("stables");
//    set_property("no teleport", 1);
    set_short("%^BOLD%^%^BLUE%^Stable of the Paladins%^RESET%^");
    set("long",
@OLI
    %^BOLD%^%^BLUE%^ Stable of the Paladins %^RESET%^
%^CYAN%^This is the Paladin's stable. Here you can buy a war horse to carry you on your adventures. As you look around you notice how wonderfully clean it is...surprisingly so. Sturdy looking war horses stand in their stalls and they look at you as you enter the room.
You may purchase a war horse for a price. <buy war horse>
OLI
);

    set_exits(([
        "southwest" : "/d/shadow/room/city/cguild/paladin/sanctum",
    ]));
    set_items(([
    ]));
    set_smell("default","You smell horses here.");
    set_listen("default","An occasional shifting of horses' hooves can be heard here.");
    set_animal(({"war horse", "barded war horse"}),({"/d/shadow/room/city/cguild/paladin/war_horse","/d/shadow/room/city/cguild/paladin/barded_war_horse"}));
    set_animal_price(({"war horse","barded war horse"}),({500, 2500}));
    set_stalls(15);
    ::fill_stalls();
}
