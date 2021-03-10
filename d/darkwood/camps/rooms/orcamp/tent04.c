// made the cloak drop from the hoard here more often instead - plenty of cash around the camps - to cut down on player cycling. Nienne, 09/07.
//changed some of the ids the code was looking for, to deal with a conflict with summoned monsters. Lujke 14 March 08
#include <std.h>
#include "../../elfisland1.h"

inherit BTENT;

int items;

void create() {
items = 1;
   ::create();
   set_exits( ([ 
      "west" : CAMP+"croad05",
   ]) );
   set_search("default",  "The bones are piled pretty high in one stack.");
   set_search("bones", "One pile looks pretty high.");
   set_search("pile", (: TO, "searching" :) );
}

void searching() {
   object ob;

   if(present("xxguardorcxx")) {
      write("The orcs are too close to the pile for you to search thoroughly.");
      return;
   }
   if(!items) {
      write("Looks like someone beat you to whatever was there.");
      return;
   }
   switch(random(6)){
      case 0..1:
         ob = new("/std/obj/coins");
          ob->set_money("gold", random(1000)+500);
         ob->move(TO);
         write("%^BOLD%^%^YELLOW%^You poke around the pile of bones and find a pouch full of gold!%^RESET%^");
         tell_room(TO,TPQCN+" pokes around the pile of bones and finds a pouch.", TP);
         break;
      case 2..5:   
          write("%^BOLD%^%^BLACK%^You find a cloak in the pile of bones!%^RESET%^");
          tell_room(TO,""+TPQCN+" finds a cloak in the pile of bones.", TP);
         ob = new(OBJ+"darkcloak");
          ob->move(TO);
          break;
        }       
        items = 0;
        return;
          
}
void reset()
{
   ::reset();
   if(random(10) < 4)
      items = 1;
   if(!present("xxguardorcxx")) {
      new(MON+"bandit")->move(TO);
      new(MON+"bandit")->move(TO);
      new(MON+"bandit")->move(TO);
      new(MON+"bandit")->move(TO);
   }
}

