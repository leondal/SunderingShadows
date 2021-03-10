#include <std.h>
#include "../dragon.h";

inherit TVAULT;

void create() {
   ::create();
   set_long(
      "%^RESET%^This is another eerily empty area. There is little that"+
      " occupies the space except numerous arcane drawings decorating the"+
      " floor and walls. One is obviously much larger than the others and"+
      " dominates the middle of the floor."
   );
   set_items( ([
       ({"walls","floor","drawings"}) : "There are numerous arcane drawings on the floor and walls. One is obviously much bigger than the rest, and it might warrant a closer look.",
       "large drawing" : "This drawing dominates the majority of the floor and looks like what is commonly used for summonings.",
   ]) );
   set_exits( ([
      "west" : TOWER+"hall01",
   ]) );
   set_door("steel door",TOWER+"hall01","west","tower key");
   set_search("wall", "You find an odd panel. Perhaps you can push it?");
}

void init() {
   ::init();
   add_action("push_panel","push");
}

int push_panel(string str) {
object ob;
 if(!str) {
      write("What do you want to push?");
      return 1;
   }
   if(str == "panel") {
      tell_room(ETP,""+TPQCN+" pushes the panel and it opens up briefly to drop a red stone.",TP);
      tell_object(TP,"You push the panel and it opens up briefly to drop a red stone.");
      ob = new(OBJ+"redstone")->move(TO);
      return 1;

   }
}
