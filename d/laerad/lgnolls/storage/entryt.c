//entry. Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;
void pick_critters();



void create() {
    pick_critters();
    set_repop(30);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("entry");
    set_short("entrance to a dirty and smelly camp site ");
    set_long("%^ORANGE%^This seem to be the entrance to a large %^MAGENTA%^military camp%^ORANGE%^."+
	" On each side of the road two %^MAGENTA%^towers %^ORANGE%^have been build of rough wood."+
	" It looks like a temporary setup which over time has been built into a more permanent settlement."+
	" %^BOLD%^T%^WHITE%^o%^ORANGE%^rches %^RESET%^%^ORANGE%^on each tower keep the road lit at %^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^ght%^RESET%^\n");
    set_smell("default","%^MAGENTA%^The air is thick of %^ORANGE%^animal musk%^RESET%^");
    set_listen("default","%^ORANGE%^You hear movements from within the %^MAGENTA%^towers %^ORANGE%^together with the occasional l%^RED%^a%^ORANGE%^u%^RED%^g%^ORANGE%^ht%^RED%^e%^ORANGE%^r of a %^BOLD%^%^BLACK%^.%^RESET%^.%^BOLD%^%^BLACK%^. hyena%^RESET%^%^ORANGE%^?%^RESET%^");

    set_items
    (([	
        ({"floor", "ground", "outcroppings"}) : "%^RESET%^%^ORANGE%^The road is filled with rubble and large rocks.",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls of the towers are made from all sorts of wood hammered together.",
        ({"torches", "torch"}) : "%^ORANGE%^The torches are little more than cloth fastened to the top of a stick with animal grease for fuel.",
    ]));
}

void reset(){
   ::reset();
   switch(random(5)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnolls' victims can he hear from somewhere in the camp.");
               break;
         }
}


void pick_critters(){
   switch(random(6)){
        case 0:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollpriest"}),({random(2),random(1)}) );
                   break;
         case 1:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollbarb"}),({random(2),random(1)}) );
                   break;
         case 2:   set_monsters(
({MOBS"gnollpriest",MOBS"gnollbarb"}),({1,random(1)+1,random(2)}) );
                   break;
         case 3..5: break;
   }
}
