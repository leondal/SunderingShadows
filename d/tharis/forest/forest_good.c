//forest_good.c
#include "./forest.h"

#include <std.h>

inherit BFOREST;

// object *trees, *elves, unicorn, dragon;
// changing to use CROOM for mob control & to handle clean up of the mobs it spawns over longer uptimes *Styx*  3/17/05

void pick_mobs();

void create(){
//    trees = allocate(2);
//    elves = allocate(3);
   pick_mobs();
   ::create();
   set_repop(30);
   if(base_name(TO) == "/d/tharis/forest/forest_good"){
      set_property("no teleport",1);
   }
//added by Circe to stop people teleporting in.  12/20/04
}

void reset(){
   ::reset();
}

void pick_mobs() {
   if(base_name(TO) == "/d/tharis/forest/forest_good")    
	return;
   switch(random(6)) {
      case 0:   set_monsters( ({MONS"treant", MONS"we_archer"}),({1, 2}));
		break;
      case 1:   set_monsters( ({MONS"treant", MONS"we_archer"}),({2, 2}));
		break;
      case 2:   set_monsters( ({MONS"treant", MONS"we_archer"}),({2, 3}));
		break;
      case 3..4:   
		set_monsters( ({MONS"treant", MONS"we_archer", MONS"wunicorn"}),
		              ({2, 3, 1}) );
		break;
      case 5:   set_monsters( ({MONS"treant", MONS"we_archer", MONS"wpsdragon"}),
		              ({1, 2, 1}) );
		break;
   }
}


/* was this in reset()
    int i;
    ::reset();
   if(random(3))  return;  // slow down repops for longer uptimes *Styx*  4/17/03

    for(i=0;i<sizeof(trees);i++) {
        if(!objectp(trees[i]) && random(10) < 7){
            trees[i] = new(MONS"treant");
            trees[i]->move(TO);
        }
    }
    for(i=0;i<sizeof(elves);i++) {
        if(!objectp(elves[i]) && random(10) < 7){
            elves[i] = new(MONS"we_archer");
            elves[i]->move(TO);
        }
    }
    if(!objectp(unicorn))
        if(random(10) < 5){
            unicorn = new(MONS"wunicorn");
            unicorn->move(TO);
        }

    if(!objectp(dragon))
        if(random(10) < 3){
            dragon = new(MONS"wpsdragon");
            dragon->move(TO);
        }
}
*/
