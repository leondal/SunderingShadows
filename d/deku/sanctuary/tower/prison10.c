#include <std.h>
#include "../dragon.h";

inherit BPRISON;

int items;

void create () {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This small cell does not consist of very much."+
      " There is a small cot and a barrel full of waste. Other than that,"+
      " there is nothing here."
   );
   set_items( ([
      "cot" : "This is a small bed that prisoners slept on. There is nothing on top of this one. Perhaps you can try searching under the cot?",
      "barrel" : "This barrel is full of human waste.",
      "under cot" : "There looks like there is something attatched to the bottom of the cot.",
   ]) );
   set_exits( ([
      "west" : TOWER+"prison06",
   ]) );
   set_search("under cot", (: TO, "searching" :) );
   items = 1;
}

void searching() {
   object ob;
   if(!items) {
      write("You find nothing.");
      return;
   }
   switch(random(2)){
      case 0:
      write("%^BOLD%^%^BLACK%^You find a dark dagger.");
      tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" finds a dark dagger.",TP);
      ob = new(OBJ+"ghoulblade")->move(TO);
      break;
      case 1:
      write("%^BOLD%^%^BLUE%^You find a katar.");
      tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+" finds a katar.",TP);
      ob = new(OBJ+"nightsveil")->move(TO);
      break;
      }
   items = 0;
   return;
}
