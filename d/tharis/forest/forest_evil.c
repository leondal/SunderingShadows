//forest180.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

//object *trees, *ogres, harpy, imp;
// changing to use CROOM for mob control & to handle clean up of the mobs it spawns over longer uptimes *Styx*  3/17/05

void pick_mobs();

void create(){
//    trees = allocate(2);
//    ogres = allocate(3);
   pick_mobs();
   ::create();
   set_repop(30);
   if(base_name(TO) == "/d/tharis/forest/forest_evil"){
      set_property("no teleport",1);
   }
//added by Circe to stop people teleporting in.  12/20/04

}

void reset(){
   ::reset();
}

void pick_mobs() {
   if(base_name(TO) == "/d/tharis/forest/forest_evil")    
	return;
   switch(random(6)) {
      case 0:   set_monsters( ({MONS"hangman_tree", MONS"wogre_mage"}),({1, 2}));
		break;
      case 1:   set_monsters( ({MONS"hangman_tree", MONS"wogre_mage"}),({2, 2}));
		break;
      case 2:   set_monsters( ({MONS"hangman_tree", MONS"wogre_mage"}),({2, 3}));
		break;
      case 3..4:   
		set_monsters( ({MONS"hangman_tree", MONS"wogre_mage", MONS"wharpy"}),
		              ({2, 3, 1}) );
		break;
      case 5:   set_monsters( ({MONS"hangman_tree", MONS"wogre_mage", MONS"wimp"}),
		              ({1, 2, 1}) );
		break;
   }
}


/*  was this
   if(random(3))  return;  // slow down repops for longer uptimes *Styx*  4/17/03
    for(i=0;i<sizeof(trees);i++) {
        if(!objectp(trees[i]) && random(10) < 7){
            trees[i] = new(MONS"hangman_tree");
            trees[i]->move(TO);
        }
    }
    for(i=0;i<sizeof(ogres);i++) {
        if(!objectp(ogres[i]) && random(10) < 7){
            ogres[i] = new(MONS"wogre_mage");
            ogres[i]->move(TO);
        }
    }
    if(!objectp(harpy))
        if(random(10) < 5){
            harpy = new(MONS"wharpy");
            harpy->move(TO);
        }

    if(!objectp(imp))
        if(random(10) < 3){
            imp = new(MONS"wimp");
            imp->move(TO);
        }

}
*/