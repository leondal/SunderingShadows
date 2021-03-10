//caves2.c - inherit for deeper Koenig caves.  Updated 11/28/03 by Circe.
#include <std.h>
#include "../koenig.h"

inherit CROOM;

void pick_critters();

void create() {
      pick_critters();
      set_repop(60);
    	::create();
      set_terrain(NAT_CAVE);
      set_travel(FOOT_PATH);
    	set_property("light",1);
    	set_indoors(1);
     	set_listen("default","You hear a faint drip of water in the cave.");
      set_smell("default","The stench of decay is in the air.");
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
   switch(random(4)){
      case 0:  tell_room(TO,"%^BOLD%^The sound of rats scurrying through the cave reaches your ears.");
               break;
      case 1:  tell_room(TO,"%^ORANGE%^The musty smell of molded food and dried excrement rises in the air.");
               break;
      case 2:  tell_room(TO,"%^BOLD%^%^CYAN%^A chilling gust of air moves through the caves.");
               break;
      case 3:  tell_room(TO,"%^RED%^A strange howl fills the air.");
               break;
      default: break;
   }
}

void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters( ({KMON"orc",KMON"orcguard"}),({random(2)+1,random(1)+1}) );
                   break;
         case 1:   set_monsters( ({KMON"orccaptain",KMON"k_goblin"}),({random(2)+1,random(1)}) );
                   break;
         case 2:   set_monsters( ({KMON"orcadept",KMON"zombie",KMON"skeleton"}),({1,random(1)+1,random(2)}) );
                   break;
         case 3:   set_monsters( ({KMON"k_goblin",KMON"orcguard"}),({random(2)+1,1}) );
                   break;
         case 4..6: break;
   }
}