#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

int found,found2;
string x;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(NAT_CAVE);
   set_travel(RUBBLE);
   set_name("Pit");
   set_short("Pit");
   set_long("%^BOLD%^A Deep Dark Pit%^RESET%^\n"
"You have entered a deep pit.  Smashed bodies litter the ground and more stalactites hang menacingly here.  "
"You don't feel safe here.  The pit is huge and dark.  But you can see things shimmering on the floor here "
"in the soft light of a phosphorescent fungus.\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You can hear water dripping.");

   set_items(([
     "stalagmites":"These are old and large although the smaller ones on the path have been bashed down.",
     "stalactites":"These hang menacingly from the ceiling.",
     "bodies":"There are eight or so corpses here, it's hard to tell they are so beat up.",
     "fungus":"A fungus grows here and it gives off an unnatural glow.",
     "floor":"There are a few coins scattered about as well as various implements of death."
   ]));

   set_exits(([
     "up":CAVES+"cave13",
   ]));
   x=roll_dice(1,8);
}

void init(){
   ::init();
   do_random_encounters(({MON"piercer"}),70,12);
   add_action("search_fun","search");
}

int search_fun(string str){
   object equipment;
   int enchant;
   if(!str) return 0;
   if((str != "corpse "+x) && (str !="floor")) return 0;
   if((str == "corpse "+x) && (found == 0)){
     new(OBJ"whalebone")->move(TO);
     tell_object(TP,"You find a long dagger of %^BOLD%^bone%^RESET%^!");
     tell_room(ETP,TPQCN+" finds something on the corpse.",TP);
     found = 1;
     return 1;
   }
   if((str == "floor") && (found2 == 0)){
     enchant=(random(2)+1);
     tell_object(TP,"You search the floor and find a shiny longsword and some coins!");
     tell_room(ETP,TPQCN+" searches through the debris on the floor and finds some coins and a "
"longsword.",TP);
     equipment=new("/d/common/obj/weapon/longsword");
     equipment->set_property("enchantment",enchant);
     equipment->move(TO);
     equipment=new("/std/obj/coins");
     equipment->add_money("gold",random(100));
     equipment->add_money("silver",random(130));
     equipment->add_money("copper",random(11230));
     equipment->move(TO);
     found2 = 1;
     return 1;
   }
}

void reset(){
   ::reset();
   found = 0;
   found2 = 0;
   x=roll_dice(1,8);
}
