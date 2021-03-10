// made the cloak drop from the hoard here more often instead - plenty of cash around the camps - to cut down on player cycling. Nienne, 09/07.
#include <std.h>
#include "../../elfisland1.h"

inherit ROOM;

int items;
int bracers;
int item;

void create() {
items = 1;
item = 1;
bracers = 1;
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set("short", "The leaders tent.");   
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD); 
   set("long",
      "%^RESET%^%^ORANGE%^This large tent is made from the hides of several large"+
      " wolves. The hides are held up by torn tree branches torn of the surrounding forest."+
      " There are many chests scattered around the tent and a couple"+
      " piles of bones stacked up sporadically around the edges. This appears to be"+
      " where the horde brings its loot after successful raids. The reasons for this"+
      " are simple; this is the most protected spot from invaders and other members"+
      " of the horde."
   );
   set_smell("default","%^RESET%^%^GREEN%^The smell of the wolf hides fill the air.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^The sounds of life in the camp surround you.%^RESET%^");
   set_items( ([
      "bones" : "The bones are stacked up in a couple of different piles. Most look like animals, some look... %^RESET%^%^RED%^elven.%^RESET%^",
      "elven bones" : " The bones of an elf that was obviously beat badly lay here. It appears most of things were taken, but there is something still there.",
      "hides" : "The hides in combination with the branches are used to build the tent. If anything, they look well skinned.",
      "chests" : "A few chests lie around here, this is obviously where the leader keeps his prized possessions.",
   ]) );

   set_exits( ([
      "out" : CAMP+"croad03",
   ]) );
   set_search("default", "There are a few chests lying around the tent.");
   set_search("bones", "You find nothing on top or among the animal bones.");
   set_search("under bones", "You find a small box hidden under the bones.");
   set_search("elven bones", (: TO, "searching" :) );
   set_search("chests", (: TO, "searchest" :) );
   set_search("box", (: TO, "searchbox" :) );

}

void searching() {
   object ob;

   if(present("gore")) {
      write("Gore is guarding over the area too closely for a search to be possible.");
      return;
   }
   if(!items) {
      write("Looks like someone beat you to whatever was there.");
      return;
   }
   switch(random(6)){
      case 0..1:
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(2000)+1000);
         ob->move(TO);
         write("%^BOLD%^%^YELLOW%^You poke around the elven bones and find a pouch full of gold!%^RESET%^");
         tell_room(TO,TPQCN+" pokes around the elven bones and finds a pouch.", TP);
         break;
      case 2..5:   
          write("%^BOLD%^%^WHITE%^You find a cloak in the pile of elven bones!%^RESET%^");
          tell_room(TO,""+TPQCN+" finds a cloak in the pile of elven bones.", TP);
         ob = new(OBJ+"lightcloak");
         ob->move(TO);
         break;
      }
      items = 0;
      return;
}

void searchbox() {
   object ob;

   if(present("gore")) {
      write("Gore is guarding over the area too closely for a search to be possible.");
      return;
   }
   if(!bracers) {
      write("Looks like someone beat you to whatever was there.");
   return;
   }
   write("%^BOLD%^%^WHITE%^You open the box and find a set of heavy bracers.%^RESET%^");
   tell_room(ETO,TPQCN+" finds a set of heavy bracers hidden in the camp.");
   ob = new("/d/islands/pirates/obj/boa.c");
   ob->move(TO);
   bracers = 0;
}          

void searchest() {
   object ob;

   if(present("gore")) {
      write("Gore is guarding over area too closely for a search to be possible.");
      return;
   }
   if(!item) {
      write("The leader must have all the good stuff now.");
      return;
   } else {
   write("%^BOLD%^%^BLUE%^You clear out the chests and find a few gems!%^RESET%^");
   tell_room(TO, TPQCN+" finds a few gems amongst the chests.", TP);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   new("/d/newbie/obj/misc/gem")->move(TO);
   item = 0;
   }
}
void reset() 
{
   ::reset();
   if(random(10) < 4)
      items = 1;
   if(random(10) < 4)
      item = 0;
   if(!present("gore")) {
      new(MON+"gore")->move(TO);
   }
}
