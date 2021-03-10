#include <std.h>
#include "/realms/dinji/sanctuary/dragon.h";

inherit ROOM;
int items;

void create() {
items = 1;
   ::create();
   set_property("light", 0);
   set_property("indoors", 0);
   set_terrain(RUINS);
   set_travel(RUBBLE);
   set_short("Ruined road of Sanctuary");
   set("long",
      "%^BOLD%^%^BLACK%^The roads of %^RED%^Sanctuary%^BLACK%^ are beaten and battered."+
      " All around you buildings lay in rubble and you are not too sure how long they"+
      " will remain standing. The streets are littered with corpses, skeletons and broken"+
      " cobblestones that once made up the paved roads. Something terrible has swept through"+
      " this town and nothing has remained untouched by the desctruction."
   );
   set_smell("default","The stench of decay and sulfur is strong in the air.");
   set_listen("default","%^RESET%^%^CYAN%^It is eerily silent all around you.");
   set_items(([
      "corpses" : "The corpses of men, women, and even children are scattered around the now empty town.",
      "buildings" : "The buildings are nothing, but heaps of rubble that are barely still standing. None look very stable",
      "streets" : "The streets are dented with large craters as if something smashed into them.",
      "craters" : "Some are larger than others. Some look like large rocks created them while others look like large footprints."
   ]) );
   set_search("default","There is little else other than the reminders of the destruction and corpses.");
   set_search("corpses", (: TO, "searching" :) );
}

void searching() {
   object ob;
   if(!items) {
      write("%^BOLD%^%^BLACK%^You find nothing.");
      return;
   }
   switch(random(20)){
      case 0..9:
         write("%^BOLD%^%^BLACK%^You find nothing.");
         tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" searches the corpses and finds nothing.",TP);
         break;
      case 10..15:
         write("%^BOLD%^%^YELLOW%^You find some coins scattered about the corpses!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds some coins scattered about the corpses.",TP);
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(1000)+1000);
         ob->move(TO);
         break;
      case 16..17:
         write("%^BOLD%^%^YELLOW%^You find some coins scattered about the corpses!");
         tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds some coins scattered about the corpses.",TP);
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(5000)+1000);
         ob->move(TO);
      case 18..19:
         write("%^BOLD%^%^BLUE%^Your searching causes two of the corpses to rise up to their feet!");
         tell_room(TO,"%^BOLD%^%^BLUE%^"+TPQCN+"'s searching causes two corpses to rise up to their feet!",TP);
         ob = new(MON+"zombie")->move(TO);
         ob = new(MON+"zombie")->move(TO);
         break;
      }
      items = 0;
      return;
}

void reset(){
   ::reset();
   if(random(10) < 2)
   if(!present("skeleton")) {
   new(MON+"skeleton")->move(TO);
   new(MON+"skeleton")->move(TO);
   }
   if(random(10) < 2)
   if(!present("zombie")) {
   new(MON+"zombie")->move(TO);
   new(MON+"zombie")->move(TO);
   }
   if(random(10) < 2)
   if(!present("skeleton")) {
   new(MON+"skeleton")->move(TO);
   new(MON+"mage")->move(TO);
   }
   if(random(10) < 2)
   if(!present("zombie")) {
   new(MON+"zombie")->move(TO);
   new(MON+"priest")->move(TO);
   }
   if(random(10) < 1)
   if(!present("construct")) {
   new(MON+"steel_construct")->move(TO);
   }
   if(random(10) < 1)
   if(!present("bodak")) {
   new(MON+"bodak")->move(TO);
   }
}
