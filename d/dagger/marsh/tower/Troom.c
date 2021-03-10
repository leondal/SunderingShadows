//Modified to inherit CROOM and added requisite switches for mobs.  
//Scrap paper and mist key spawns offloaded to mob objects themselves.
//To help control the reaver population, keep your demons spayed or 
//neutered. Octothorpe 5/25/09

#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit CROOM;

object ob, ob2;
int i,j,active;

void create(){
   if(!random(7)){
      j = random(4)+1;
      for(i=0;i<j;i++){
         switch(random(15)){
            case 0: set_monsters(({MPATH"reaver1"}),({1+random(2)})); break;
            case 1: set_monsters(({MPATH"reaver2"}),({1+random(2)})); break;
            case 2: set_monsters(({MPATH"reaver3"}),({1+random(2)})); break;
            case 3: set_monsters(({MPATH"reaver4"}),({1+random(2)})); break;
            case 4: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
            case 5: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
            case 6: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
            case 7: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
            case 8: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
            case 9: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
            case 10: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
            case 11: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
            case 12: set_monsters(({MPATH"krykoth"}),({1+random(2)})); break;
            case 13: set_monsters(({MPATH"shadows"}),({1+random(2)})); break;
            case 14: set_monsters(({MPATH"shadows"}),({1+random(2)})); break;
            default: break;
         }
      }
   }
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("used sticks",1);
   set_property("no teleport",0); //There are 1 or 2 rooms without TP proof.
   set_repop(66);
}

void reset(){
   active = has_mobs();
   if(!active){
     if(mons) mons = ([]);
      switch(random(15)){
         case 0: set_monsters(({MPATH"reaver1"}),({1+random(2)})); break;
         case 1: set_monsters(({MPATH"reaver2"}),({1+random(2)})); break;
         case 2: set_monsters(({MPATH"reaver3"}),({1+random(2)})); break;
         case 3: set_monsters(({MPATH"reaver4"}),({1+random(2)})); break;
         case 4: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
         case 5: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
         case 6: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
         case 7: set_monsters(({MPATH"shadow"}),({1+random(2)})); break;
         case 8: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
         case 9: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
         case 10: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
         case 11: set_monsters(({MPATH"wraith"}),({1+random(2)})); break;
         case 12: set_monsters(({MPATH"krykoth"}),({1+random(2)})); break;
         case 13: set_monsters(({MPATH"shadows"}),({1+random(2)})); break;
         case 14: set_monsters(({MPATH"shadows"}),({1+random(2)})); break;
         default: break;
      }
   }
   ::reset();
}
