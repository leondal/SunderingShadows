//cr11
#include <std.h>;
#include "../koenig.h"
inherit IHRMS+"cave1.c";
int searched;

void create(){
::create();
   set_name("A dark mess hall");
   set_short("%^RESET%^%^BLUE%^%^A %^BOLD%^%^BLACK%^dark %^RESET%^%^BLUE%^mess hall%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This room opens up into a very"
" large area that looks as though it is where whatever lives here"
" may dine. Large %^RESET%^stones %^BLUE%^line the walls and are"
" littered with %^RESET%^skeletons %^BLUE%^and various other"
" pieces of %^ORANGE%^rotting flesh. %^BLUE%^A few corpses hang"
" from %^BOLD%^%^WHITE%^hooks %^RESET%^%^BLUE%^affixed to the"
" ceiling, the %^RED%^blood %^BLUE%^from them falling freely onto"
" the sloping floor below and pooling into a small depression in"
" the center of the room.%^RESET%^");
   set_items(([
   ({"stones","tables"}):"%^RESET%^Large, flat stones line the walls and are littered with skeletons, bones and other pieces of %^ORANGE%^rotting flesh, %^RESET%^giving you the impression that perhaps they serve as tables.%^RESET%^",
   ({"bones","skeletons"}):"%^RESET%^The skeletons and other various bones lay scattered and broken all over the place. Some of them are splintered as though they had been brutally smashed, while others have large teeth and claw marks on them, as if the flesh was savagely eaten straight from the bones.",
   "corpses":"%^RED%^The corpses of elves, humans, half-elves, gnomes, fairies, halflings, snakes, birds, reptiles, and many other victims hang from meat hooks affixed to the ceiling. Their unseeing eyes stare at you as their blood pools onto the floor below.%^RESET%^",
   "floor":"%^BOLD%^%^BLACK%^The floor here has been specially carved so that it all slopes towards a depression in the center.",
   "depression":"%^BOLD%^%^RED%^It is difficult to see just how deep this depression is, since it is completely full of the blood of the various victims that hang from the ceiling%^RESET%^",
   ({"flesh","rotting flesh"}):"%^RESET%^%^ORANGE%^Pieces of stinking, rotting, half-eaten flesh litter the tables and floor.%^RESET%^",
   "hooks":"%^BOLD%^%^WHITE%^These hooks are large and curved, designed to hold any size of creature. Their cool metal gleams in the darkness here, creating an overall, sickening feeling.%^RESET%^",
]));
   set_exits(([
"east":INRMS+"cr4",
]));
    set_search("default", "%^RED%^The insides of the corpses look interesting.%^RESET%^");
    set_search("corpse", (: TO, "search_pile" :) );
    set_search("corpses",(:TO,"search_pile":));
}
void reset() {
   ::reset();
   searched = 1 ;
}
void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"%^RESET%^%^RED%^You dig your arms deep into the belly of one of the corpses only to find that it has already been gutted%^RESET%^.");
     tell_room(TO,"%^RESET%^%^RED%^"+TPQCN+" digs deeply into the belly of one of the corpses, splattering blood all over "+TP->query_objective()+"self in the process, but finds nothing.", TP);
      return ;
   }

   if (searched == 1) {  
            tell_object(TP,"%^RESET%^%^RED%^You dig deeply into one of the corpses and pull on the first solid thing you find.\n");
            tell_room(TO,"%^RESET%^%^RED%^"+TPQCN+" digs deeply into one of the corpses and pulls out a long, %^ORANGE%^stinky %^RED%^strand of %^ORANGE%^entrails%^RESET%^.",TP);
            new("/d/koenig/obj/entrails.c")->move(TO);
            searched = 0;
            return ;
   }
}
