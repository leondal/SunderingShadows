#include <std.h>
#include "/d/darkwood/yntala/yntala.h"
inherit ROOM;
int searched;

void create()
{
        ::create();
        set_property("outdoors",0);
        set_property("light",2);
        set_terrain(LIGHT_FOREST);
        set_travel(DIRT_ROAD);
        set_name("%^RESET%^%^GREEN%^High in a tree%^RESET%^");
        set_short("%^BOLD%^%^GREEN%^High in a tree%^RESET%^%^");
   set_long((:TO,"ldesc":));
        set_smell("default","%^BOLD%^%^GREEN%^It smells fresh and clean up here.%^RESET%^");
        set_listen("default","You hear the chatter of several birds around you.");
        set_items(([
"vines":"%^BOLD%^%^GREEN%^The vines hang down to the %^RESET%^%^GREEN%^forest floor %^BOLD%^%^GREEN%^beneath you.%^RESET%^",
({"nest","birdsnest"}):"%^RESET%^%^ORANGE%^The birds nest looks like it is made of leaves, straw and old scraps of paper, and appears to have been abandoned for some time.%^RESET%^",
"leaves":"%^BOLD%^%^GREEN%^The leaves flutter around you, rustling softly in the %^RESET%^breeze.",
"branches":"%^RESET%^%^ORANGE%^The branches here are quite sturdy and very comfortable to sit on.%^RESET%^",
"ivy":"%^BOLD%^%^GREEN%^The ivy and other vines hang down from here to the forest floor below.%^RESET%^",
]));
         set_search("nest", (: TO, "search_pile" :) );
         set_search("birdsnest", (: TO, "search_pile" :) );
        set_exits(([
"down":INRMS"forest171"
]));
}
void reset() {
   ::reset();
   if(!random(2))
   searched = 1 ;
}
void search_pile() {
   object ob;
   if(searched <= 0) {             
       tell_object(TP,"It looks like the nest has been searched already.");
       return ;
   }
   if (searched == 1) { 
      switch(random(10)){
         case 0..3:
            write("%^RESET%^%^ORANGE%^You found a few old pieces of parchment in the nest.\n");
             tell_room(TO,""+TPQCN+" pulls out a few pieces of paper from the nest.", TP);
             new(OBJD+"parchment1")->move(TO);
             ob = new("/d/magic/scroll");
             ob->set_spell(random(3)+1);
             ob->move(TO);
             searched = 0;
             break ;
         case 4..9:
             write("%^RESET%^%^ORANGE%^You found an old piece of parchment in the nest.\n");
             tell_room(TO,""+TPQCN+" pulls out a piece of paper from the nest.", TP);
             new(OBJD+"parchment1")->move(TO);
             searched = 0;
             break ;
       }
   return ;
   }
}
string ldesc(string str){
   return("%^RESET%^%^GREEN%^You find yourself high in a"
" tree amongst the leaves, branches and other things one would"
" expect to find up here.  Vines hang down to the forest floor"
" beneath you, and an old %^ORANGE%^birds nest %^GREEN%^sits out on"
" one of the branches.%^RESET%^\n");
} 
