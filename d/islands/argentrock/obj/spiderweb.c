#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit OBJECT;

void create() {
   ::create();
   set_name("spider web");
   set_id( ({"web","spider web"}) );
   set("short","Spider web");
    set("long","This is a giant white spider web. The giant black widow "+
      "spider uses this kind of web to trap any living creatures who "+
       "unfortunately enter into her hunting zone. The oval outlook "+
      "indicates that it might have trapped a victim inside it.");
   set_weight(5);
   set_value(500);
}

void init() {
   ::init();
   add_action("break_web","break");
}

int break_web(string str) {
   int luck;
   if(!str) {
      notify_fail("Break what?\n");
      return 0;
   }
   if(str != "web") {
      notify_fail("You cannot break that!\n");
      return 0;
   }
   luck = random(30);
   switch(luck) {
      case 28..30:
         new(OBJ+"obsidian_ring")->move(TP);
         write("You find a beautiful ring within the web!");
         say(TPQCN+" finds something within the spider web.");
         break;
      case 1..10:
         write("You find a black pearl within the web.");
         say(TPQCN+" finds something within the spider web.");
         new(OBJ+"blackpearl")->move(TP);
         break;
      default:
         write("Possibly the victim has died and the corpse decayed.\n"+
            "You found nothing left in the spider web.");
   }
   TO->remove();
   return 1;
}
