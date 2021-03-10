//Added limits to the total number of mobs - *Styx* 3/3/02
// updated to use CROOM with new features for new guards *Styx* 10/9/05
#include "/d/dagger/tonovi/town/short.h"
#include <std.h>

inherit CROOM;

void pick_critters();
int get_mobs;

void create(){
   set_repop(40);
   if(!random(3))  get_mobs = 1;
   //if(get_mobs)   pick_critters();
   if(get_mobs)
       set_monsters(({ "/d/dagger/tonovi/guards/guard" }),({1+random(2)}));
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Streets of Tonovi");
   set_smell("default", "With the walls towering above, the air smells dank and oppressive.");
   set_listen("default","Beneath the bustle of the city, you "+
      "occasionally hear the wail of a child.");
}

void reset() {
   int active;
   if(get_mobs) {
     if(!active = has_mobs()) {
       if(mons) mons = ([]);
       set_monsters(({ "/d/dagger/tonovi/guards/guard" }),({1+random(2)}));
     }
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
/*
void pick_critters() {
      switch(random(6)){
         case 0:   set_monsters(({MPATH"guard1_city"}),({1}));
		   monster_party(40);
                   break;
         case 1:   set_monsters(({MPATH"guard2_city", MPATH"guard1_city"}),({1, 2}));
		   monster_party(40);
                   break;
         case 2:   set_monsters(({MPATH"guardcapt", MPATH"guard1_city"}),({1, 2}));
		   monster_party(40);
                   break;
         case 3:   set_monsters(({MPATH"guard2_city", MPATH"guard1_city"}),({2, 1}));
		   monster_party(40);
                   break;
         case 4:   set_monsters(({MPATH"guard2_city", MPATH"guard1_city"}),({1, 1}));
		   monster_party(40);
                   break;
         case 5:   set_monsters(({MPATH"citizen"}),({1}));
		   monster_party(0);
                   break;
         default:  break;
      }
}
*/
