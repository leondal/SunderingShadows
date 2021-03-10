//entry. Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;
//void pick_critters();



void create() {
    //pick_critters();
    set_repop(30);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("entry");
    set_short("entrance to a dirty and smelly camp site ");
    set_long("%^ORANGE%^This seem to be the entrance to a large %^MAGENTA%^military camp%^ORANGE%^."+
	" On each side of the road two %^MAGENTA%^towers %^ORANGE%^have been build of rough wood."+
	" It looks like a temporary setup which over time has been built into a more permanent settlement."+
	" %^BOLD%^T%^WHITE%^o%^ORANGE%^rches %^RESET%^%^ORANGE%^on each tower keep the road lit at %^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^ght%^RESET%^%^ORANGE%^.%^RESET%^\n");
    set_smell("default","%^MAGENTA%^The air is thick with %^ORANGE%^animal musk%^RESET%^");
    set_listen("default","%^ORANGE%^You hear movements from within the %^MAGENTA%^towers %^ORANGE%^together with the occasional l%^RED%^a%^ORANGE%^u%^RED%^g%^ORANGE%^ht%^RED%^e%^ORANGE%^r of a %^BOLD%^%^BLACK%^.%^RESET%^.%^BOLD%^%^BLACK%^. hyena%^RESET%^%^ORANGE%^?%^RESET%^");
	set_exits((["south":ROOMS"5","west":ROOMS"12","east":ROOMS"7","guardroom":ROOMS"20"]));
    set_items
    (([	
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The road is filled with rubble and large rocks.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls of the towers are made from all sorts of wood hammered together.",
        ({"torches", "torch"}) : "%^ORANGE%^The torches is little more than cloth fastened to the top of a stick with animal grease for fuel.",
    ]));
}



//void pick_critters(){
//   switch(random(6)){
//         case 0:   set_monsters(
//({MOBS" ",MOBS" "}),({random(2),random(2)}) );
//                   break;
//         case 1:   set_monsters(
//({MOBS"",MOBS""}),({random(2),random(1)}) );
//                   break;
//         case 2:   set_monsters(
//({MOBS"",MOBS""}),({1,random(1)+1,random(2)}) );
//                   break;
//         case 3:   set_monsters(
//({MOBS"",MOBS"",MOBS""}),({random(3),1,1}) );
//                   break;
//         case 4..5: break;
//   }
//}

