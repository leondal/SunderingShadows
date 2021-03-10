//gtowers Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;
void pick_critters();



void create() {
    pick_critters();
    set_repop(70);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("guard tower");
    set_short("%^ORANGE%^Inside a %^BOLD%^%^BLACK%^crude %^RESET%^%^ORANGE%^and %^GREEN%^st%^MAGENTA%^i%^GREEN%^nk%^MAGENTA%^i%^GREEN%^ng %^ORANGE%^watch tower%^RESET%^");
    set_long("%^ORANGE%^This watch tower is just as crude inside as it looks from the outside! A few wooden boxes and make-shift chairs"+
	"have been placed around a %^MAGENTA%^table %^ORANGE%^in the middle of the room. Along the wall, multiple %^BOLD%^%^BLACK%^weapon"+
	"%^RESET%^%^ORANGE%^ r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^cks and and a few %^BOLD%^%^BLACK%^armor %^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^nds"+
	" are placed. The room is lit up by %^BOLD%^t%^WHITE%^o%^ORANGE%^rches %^RESET%^%^ORANGE%^sticking out from holders on the walls.%^RESET%^\n");
	
    set_smell("default","%^ORANGE%^It smells badly of %^RED%^r%^MAGENTA%^o%^RED%^tt%^MAGENTA%^e%^RED%^n m%^MAGENTA%^e%^RED%^at %^ORANGE%^and %^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ly m%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^sk%^RESET%^");
    set_listen("default","%^GREEN%^The tower muffles the hideous %^BOLD%^%^BLACK%^hyena %^RESET%^%^GREEN%^like %^BOLD%^%^BLACK%^laughter%^RESET%^");
	set_exits((["up":ROOMS"4u","east":ROOMS"2"]));
    set_items
    (([	
        ({"floor", "ground", "outcroppings"}) : "%^ORANGE%^The floor in here is littered with %^BOLD%^%^BLACK%^dirt %^RESET%^%^ORANGE%^and %^RED%^r%^MAGENTA%^o%^RED%^tt%^MAGENTA%^i%^RED%^ng m%^MAGENTA%^e%^RED%^at.%^RESET%^",
        ({"wall", "walls"}) : "%^RESET%^%^ORANGE%^The walls here are rough.",
        ({"torches", "torch"}) : "%^ORANGE%^The torches are little more than cloth fastened to the top of a stick with animal grease for fuel.",
		({"weapons", "weapon rack", "weapons rack"}) : "%^ORANGE%^Most of these %^BOLD%^%^BLACK%^weapons %^RESET%^%^ORANGE%^have seen very much use and very little care. There is little chance of finding anything useful.%^RESET%^",
		({"armors", "armor rack", "armor racks"}) : "%^ORANGE%^Most of these %^BOLD%^%^BLACK%^armors %^RESET%^%^ORANGE%^has seen very much use and very little care. There is little chance finding anything useful.%^RESET%^",
		({"table"}) : "%^GREEN%^The table to littered with both %^BOLD%^%^RED%^fr%^RESET%^%^RED%^e%^BOLD%^sh %^RESET%^%^GREEN%^and %^RED%^r%^MAGENTA%^o%^RED%^tt%^MAGENTA%^i%^RED%^ng m%^MAGENTA%^e%^RED%^at%^GREEN%^. %^BOLD%^%^BLACK%^Flies %^RESET%^%^GREEN%^buzz in a %^BOLD%^%^BLACK%^black cloud %^RESET%^%^GREEN%^around the table and %^MAGENTA%^fly larvae %^GREEN%^are making the table seem alive.%^RESET%^",
		({"box", "boxes"}) : "%^ORANGE%^These boxes and crates were once used to carry cargo aboard ships. Now they are reduced to crude chairs.%^RESET%^",
    ]));
}



void reset(){
   ::reset();
   switch(random(6)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^BLACK%^You hear a %^ORANGE%^li%^RED%^o%^ORANGE%^n's "+
	  "%^RED%^roar %^BLACK%^followed by the death-cry of a %^RESET%^%^ORANGE%^gnoll.");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^A %^CYAN%^gust of wind blows %^ORANGE%^through the "+
	  "camp, lifting the %^BOLD%^%^BLACK%^stink %^RESET%^%^ORANGE%^of %^MAGENTA%^death %^ORANGE%^and "+
	  "%^MAGENTA%^decay %^ORANGE%^for a precious few seconds.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A %^RED%^horrible death cry %^BLACK%^of another of the "+
	  "gnoll's victims can he hear from somewhere in the camp.");
               break;
         }
}


void pick_critters(){
   switch(random(4)){
        case 0:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollpriest"}),({random(2),random(1)+1}) );
                   break;
         case 1:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollbarb"}),({random(2),random(1)+1}) );
                   break;
         case 2:   set_monsters(
({MOBS"gnollpriest",MOBS"gnollbarb"}),({random(1)+1,random(2)}) );
                   break;
         case 3: break;
   }
}
