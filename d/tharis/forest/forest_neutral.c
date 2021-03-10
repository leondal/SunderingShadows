//forest85.c

#include <std.h>
#include "./forest.h"

#define EVILS ({ MONS"hangman_tree", MONS"wogre_mage", MONS"wharpy", MONS"wimp" })

#define GOODS ({  MONS"treant", MONS"we_archer", MONS"wunicorn", MONS"wpsdragon" })


// object *trees, *htrees, *ogres, *elves, dragon, unicorn, imp, harpy;
// changing to use CROOM for mob control & to handle clean up of the mobs it spawns over longer uptimes *Styx*  3/17/05

void pick_mobs();

inherit BFOREST;

void create() {
/* not using this now
    trees = allocate(2);
    htrees = allocate(2);
    ogres = allocate(3);
    elves = allocate(3);
*/
   pick_mobs();
   ::create();
   set_repop(30);
   if(base_name(TO) == "/d/tharis/forest/forest_neutral"){
      set_property("no teleport",1);
   }
//added by Circe to stop people teleporting in.  12/20/04
}

void reset() {
    ::reset();
}

void pick_mobs() {
   int evil, good;
   evil = sizeof(EVILS);
   good = sizeof(GOODS);
   if(base_name(TO) == "/d/tharis/forest/forest_neutral")    
	return;
   switch(random(12)) {
      case 0:   set_monsters( ({EVILS[random(evil)], EVILS[random(evil)]}),({1, 2}));
		break;
      case 1:   set_monsters( ({EVILS[random(evil)], EVILS[random(evil)]}),({2, 2}));
		break;
      case 2:   set_monsters( ({EVILS[random(evil)], GOODS[random(good)]}),({2, 2}));
		break;
      case 3:   set_monsters( ({EVILS[random(evil)], GOODS[random(good)]}),({2, 3}));
		break;
      case 4:   set_monsters( ({EVILS[random(evil)], GOODS[random(good)]}),({3, 3}));
		break;
      case 5:   set_monsters( ({GOODS[random(good)], GOODS[random(good)]}),({1, 2}));
		break;
      case 6:   set_monsters( ({GOODS[random(good)], GOODS[random(good)]}),({2, 2}));
		break;
      case 7:   set_monsters( ({MONS"hangman_tree", MONS"wogre_mage", EVILS[random(evil)] }),({random(2)+1, random(2)+1, 2}));
		break;
      case 8:   set_monsters( ({MONS"treant", MONS"we_archer", EVILS[random(evil)] }),({random(2)+1, random(2)+1, 2}));
		break;
   }
}


/*  was before
    int i;
    ::reset();

    //Evil
   if(random(3))  return;  // slow down repops for longer uptimes *Styx*  4/17/03
    for(i=0;i<sizeof(htrees);i++) {
        if(!objectp(htrees[i]) && random(10) < 7) {
            htrees[i] = new(MONS"hangman_tree");
            htrees[i]->move(TO);
        }
    }
    for(i=0;i<sizeof(ogres);i++) {
        if(!objectp(ogres[i]) && random(10) < 7) {
            ogres[i] = new(MONS"wogre_mage");
            ogres[i]->move(TO);
        }
    }
    if(!objectp(harpy))
        if(random(10) < 5) {
            harpy = new(MONS"wharpy");
            harpy->move(TO);
        }

    if(!objectp(imp))
        if(random(10) < 3) {
            imp = new(MONS"wimp");
            imp->move(TO);
        }

        //Good

    for(i=0;i<sizeof(trees);i++) {
        if(!objectp(trees[i]) && random(10) < 7) {
            trees[i] = new(MONS"treant");
            trees[i]->move(TO);
        }
    }
    for(i=0;i<sizeof(elves);i++) {
        if(!objectp(elves[i]) && random(10) < 7) {
            elves[i] = new(MONS"we_archer");
            elves[i]->move(TO);
        }
    }
    if(!objectp(unicorn))
        if(random(10) < 5) {
            unicorn = new(MONS"we_archer");
            unicorn->move(TO);
        }

    if(!objectp(dragon))
        if(random(10) < 3) {
            dragon = new(MONS"wpsdragon");
            dragon->move(TO);
        }
}
*/
