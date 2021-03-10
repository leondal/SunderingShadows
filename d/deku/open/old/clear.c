#include <std.h>

inherit ROOM;

int searched;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_short("Shadowlord forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_long( (: TO, "long_descr" :) );
    set_listen("default","The thick trees muffle most sounds.");
    set_smell("default","A putrid smell comes from the cauldron.");
    set_items(([
       "clearing" : "The dirt and turf is mossy, dark, and strewn with small "
          "piles of bones.",
       ({"tree", "limbs", "tree limbs"}) : "They seem to be a blackish color "
          "and deformed, as though they are in the throes of death.",
       "cauldron":"It is large blackened iron pot about 5 ft. tall and "
          "just as wide at the mouth with something vile boiling in it.",
       "haze" : "The haze seems to hang over the clearing like a dirty cloud "
          "and probably came from the cauldron."
    ] ));
    set_search("cauldron", (: TO, "search_it" :) );
    set_exits(([
       "south" : "/d/deku/open/skull4"
    ] ));
}

void reset() {
    ::reset();
    if(!present("vexia") && !random(3)) 
      find_object_or_load("/d/deku/monster/vexia")->move(TO);
    if(!present("babu") && !random(3))
      new("/d/deku/monster/babu")->move(TO);
	if(!random(2)) searched = 0;
}

string long_descr(string str) {
   if(!present("vexia")) {
     return("The narrow path opens up before you to become a large clearing in "
     "the midst of the thick forest.  The circular clearing is surrounded by "
     "arching tree limbs that entwine so solidly you cannot pass beyond them.  "
     "A strange charcoal-colored haze fills the air above the clearing.  "
     "A large black iron cauldron sits in the center of the clearing.  It "
     "is boiling as if someone was recently here or planning to return.");
	} else {
	return("The narrow path opens up before you to become a large clearing in "
     "the midst of the thick forest.  The circular clearing is surrounded by "
     "arching tree limbs that entwine so solidly you cannot pass beyond them.  "
     "A strange charcoal-colored haze fills the air above the clearing.  "
     "A large black iron cauldron sits in the center of the clearing with one "
     "of the ugliest creatures you've ever seen hovering over it.");
   }
}

void search_it() {
   object ob;
   if(present("vexia")) {
     write("Vexia isn't about to let you do that!");
     tell_room(ETP,"Vexia seems to be guarding the cauldron.",TP);
     return;
   }
   if(searched) {
     write("It appears the cauldron has already been searched.");
     return;
   }
   switch(random(7)) {
     case 0..2:
       write("You burn your hand badly trying to search the cauldron.");
       tell_room(ETP,""+TPQCN+" flinches and pulls back a badly burned hand "
         "from trying to search the cauldron.", TP);
       TP->do_damage("right hand",random(8)+8);
       break;
     case 3..4:
       write("The vile liquid boils over onto you as you try to search.  "
         "It splashes on your face barely missing your eyes but still "
         "burning badly.");
       tell_room(ETP,""+TPQCN+" jumps backward but is still burned as the "
         "vile liquid boils over.", TP);
       TP->do_damage("torso",random(12)+8);
       break;
     case 5:
       write("%^GREEN%^As you search, the cauldron tips over and the vile "
         "liquid splashes everywhere!");
       if(TP->query_dexterity() > random(20)) {
         write("%^BOLD%^You manage to jump out of the way and barely avoid "
           "getting burned or worse by it.");
         tell_room(ETP,"%^GREEN%^"+TPQCN+" tips the cauldron over but manages "
           "to jump out of the way, barely avoiding being hit by the vile, "
           "boiling liquid!");
       }
       write("%^GREEN%^You are severely scalded as the boiling liquid splashes "
           "all over you.");
       tell_room(ETP,"%^GREEN%^"+TPQCN+" is badly scalded from the splashing "
           "liquid.", TP);
       TP->do_damage("torso",random(12)+15);
       break;
     case 6:
       tell_room(ETP,"An odd stone rolls out from under the cauldron.");
       if(!random(3))  ob = new("/d/deku/misc/red.c");
       else ob = new("/d/deku/misc/purple.c");
       ob->move(TO);
       break;
   }
   searched = 1;
   return;
} 
