#include "/d/dagger/tonovi/town/short.h"

inherit CROOM;

void pick_critters();

void create(){
   set_repop(40);
   pick_critters();
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Bazaar of Tonovi");
   set_smell("default", "You smell several strange smells, "+
       "especially strong is the sweet smell of fruits.");
   set_listen("default","You can hear the merchants peddling "+
       "their wares from all around.");
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();
   switch(random(6)){
      case 0..1:  break;
      case 2:  tell_room(TO,"%^ORANGE%^Several beggar children "+
                  "rush past you in the streets, slipping into the shadows.");
                  break;
      case 3:  tell_room(TO,"%^BOLD%^%^BLACK%^Several guards push past, "+
                  "leading a line of elven slaves to the bazaar.");
               break;
      case 4:  tell_room(TO,"%^BOLD%^%^GREEN%^An aging man in a "+
                  "%^BLACK%^black brocade robe %^GREEN%^marches "+
                  "by on his way to the temple.");
               break;
      case 5:  tell_room(TO,"%^CYAN%^A merchant walks by, accompanied by "+
                  "several armed guards.");
               break;
   }
}

void pick_critters() {
      switch(random(5)){
         case 0:   set_monsters(({MPATH"tobacco_merchant"}),({1}));
                   break;
         case 1:   set_monsters(({MPATH"clothing_merchant"}),({1}));
                   break;
         case 2:   set_monsters(({MPATH"jeweler_merchant"}),({1}));
                   break;
         case 3:   set_monsters(({MPATH"candle_merchant"}),({1}));
                   break;
         case 4:   set_monsters(({MPATH"perfume_merchant"}),({1}));
                   break;
         default:  break;
      }
}