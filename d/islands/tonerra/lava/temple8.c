#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

int searched;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_short("A hidden passageway");
  set_long(
@DESC
   %^BOLD%^%^RED%^A hidden passageway%^RESET%^
This is a small corridor, leading away from the main 
temple chamber.  The dust of ages lines the floor, 
covering the remains of a few bodies that are slumped 
alongside the walls.  At the end of the hall is a 
glowing portal.
DESC
  );
  set_listen("default","Silence");
  set_smell("default","Nothing, your senses are strangly dead");
  set_exits(([
    "back":LAVA+"temple7",
    "portal":I_VILLAGE+"hut7",
  ]));
  set_items(([
   "portal":"At the end of the hall is a glowing portal. Looking through it, you can see a tree-shrouded village beyond.",
   "bodies":"Several bodies lie slumped along the sides of the hallway, looking as though they had been cut down as they fled from the altar chamber.  Somehow they are still preserved, as if some magic held them in stasis.  Perhaps you could search them and see if they had anything of value?",
   ]));
   set_search("default",(:TO,"search_room":));
   set_search("bodies",(:TO,"search_room":));
   searched = 0;
}

void init() {
   ::init();
   add_action("quit_func","quit");
}

int quit_func(string str) {
   TP->move(I_VILLAGE+"hut7");
   tell_object(TP,"%^ORANGE%^Feeling unsafe in this cursed place, you step through the portal before finding a place to "
"rest.%^RESET%^");
   TP->force_me("quit");
}

int search_room(string str) {
    string *myarray, chosen;
    int iterations, i;

    if(!str) {
      tell_object(TP,"The only thing of interest in this corridor is the bodies strewn along the floor.  Perhaps you "
"could search them?");
      return 1;
    }
    if(str != "bodies") {
      tell_object(TP,"You find nothing odd.");
      return 0;
    }
    if(searched) {
      tell_object(TP,"It seems someone has already taken anything of value from their bodies.");
      return 0;
    }
    iterations = random(2)+2;
    myarray = ({"lance","mace","collar","chain","star"});

    for(i = 0; i< iterations;i++){
      chosen = myarray[random(sizeof(myarray))];
      myarray -= ({chosen});
      switch(chosen) {
        case "lance": new(OBJ+"lance")->move(TO); break;
        case "mace": new(OBJ+"mace")->move(TO); break;
        case "collar": new(OBJ+"collar")->move(TO); break;
        case "chain": new(OBJ+"chain")->move(TO); break;
        case "star": new(OBJ+"mephistar")->move(TO); break;
        default: tell_room(TO,"Something is broken, please tell a coder you got this message."); break;
      }
    }
    tell_object(TP,"You search the bodies and find a few items that look like they might be valuable!");
    tell_room(TO,""+TP->QCN+" searches the bodies and finds a few items that look like they might be valuable!",TP);
    searched = 1;
    return 1;
}

void reset_corpses() {
   searched = 0;
}