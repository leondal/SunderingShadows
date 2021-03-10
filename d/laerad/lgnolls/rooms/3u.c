//gtowers1 Template  - Essyllis - May - 2014


#include <std.h>
#include "../lgnoll.h"

inherit CROOM;

object ob;
void pick_critters();



void create() {
    pick_critters();
    set_repop(50);
    ::create();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("guard tower top");
    set_short("%^ORANGE%^top of a crude guard tower.%^RESET%^");
    set_long("%^ORANGE%^Staying up here may be dangerous on its own. A %^CYAN%^slight breeze %^ORANGE%^is enough to make the whole tower "+
	"sway and creak dangerously and there is no protection from the elements up here. The %^BOLD%^sun %^RESET%^%^ORANGE%^bakes down on you "+
	"mercilessly and strong winds could knock you off the tower. The view from up here is quite good and you can see all the way to the desert "+
	"from here. Besides the unstable floor there are very few things up here. Only a %^BOLD%^%^BLACK%^crate %^RESET%^%^ORANGE%^with "+
	"%^BOLD%^%^BLACK%^crossbow bolts %^RESET%^%^ORANGE%^and a few wooden chairs.\n%^RESET%^");
	
    set_smell("default","%^ORANGE%^You can smell the crisp %^WHITE%^de%^BOLD%^%^BLACK%^s%^RESET%^ert a%^BOLD%^%^BLACK%^i%^RESET%^r %^ORANGE%^up here.%^RESET%^");
    set_listen("default","%^ORANGE%^You hear the sounds of a busy %^BOLD%^%^BLACK%^gnoll camp %^RESET%^%^ORANGE%^to the north.%^RESET%^");
	set_exits((["down":ROOMS"3"]));
    set_items
    (([	
        ({"floor", "ground"}) : "%^ORANGE%^The floor is dried and cracked from the sun. Several holes make walking up here dangerous",
        ({"crate", "crates"}) : "%^ORANGE%^Much the same as the ones below. These have already been emptied however.",
		({"barrel", "bolts", "crossbow bolts"})		  : "%^ORANGE%^This barrel has been filled with crossbow bolts for the gnolls to use.",
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
	  "gnolls' victims can he hear from somewhere in the camp.");
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
