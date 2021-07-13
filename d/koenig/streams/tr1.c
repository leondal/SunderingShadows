//tr1.c
#include <std.h>
#include "../koenig.h"
inherit ROOM;
int searched;

void create(){

::create();
  set_property("indoors",1);
  set_property("light",1);
  set_travel(SLICK_FLOOR);
  set_terrain(BUILT_CAVE);
  set_name("Gretlexsh's room");
  set_short("%^BOLD%^%^BLACK%^A very dark cavern%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This is a very dark room with hardly any light at all, despite the immensely high ceiling. Various %^RESET%^%^ORANGE%^leathers %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^furs %^BOLD%^%^BLACK%^are thrown against the rocky sides of the cave, and weapons litter the floor. A single massive chair sits in the center of the room, atop a small stone platform.%^RESET%^\n");
  set_smell("default","It smells foul.%^RESET%^");
  set_listen("default","You can hear some strange noises coming from somewhere withen the room.");
  set_items(([
     ({"floor","cave floor"}):"%^BOLD%^%^BLACK%^The floor here is a little more even than the other rooms of this cave, it looks as though there is a darker spot in the rear corner of the room though.%^RESET%^",
     ({"blood","dried blood"}):"%^RESET%^%^RED%^Dried blood can be seen lining the walls, floor and even the ceiling of this cave. The way that it is splattered lends you to believe that something or someone met a horrible end here.%^RESET%^",
      "rocks":"%^RESET%^Rocks and large boulders of various sizes lay carelessly around the room, most of them covered with %^ORANGE%^furs %^RESET%^or %^ORANGE%^leathers.",
      ({"walls","cave walls"}):"%^RESET%^%^BLUE%^The cave walls look as though they were crudely dug, claw marks can still be seen deep withen the jagged rock walls, and tufts of fur can even be seen stuck to some of the sharper edges.",
      "ceiling":"%^BOLD%^%^BLACK%^It is difficult to see the ceiling from here, but wherever the %^RESET%^light %^BOLD%^%^BLACK%^hits, you notice %^RESET%^%^RED%^dried blood.%^RESET%^",
      ({"fur","furs","leather","leathers"}):"RESET%^%^ORANGE%^Crude and smelly furs, leathers and skins line the floor and few rocks in this room.%^RESET%^",
      "hole":"%^BOLD%^%^BLACK%^This is an extremely dark hole leading to who knows where. Do you really dare to try to descend into the darkness?%^RESET%^",
      "chair":"%^RED%^This is a massive chair that sits in the middle of this room. Deep claw marks are dug into the armrests, and a few tufts of hair hang off of the wooden frame.%^RESET%^",
      "weapons":"%^RESET%^%^ORANGE%^Old weapons are scattered across the floor and even make small piles in the corners. Most of them look badly broken and abused though.%^RESET%^",
      "platform":"%^RESET%^This stone platform looks more like a slab of rock that has been tossed on the floor, scraped to a nearly flat surface, and then had a chair placed on it.",
]));
   set_search("weapons",(:TO,"search_pile":));
   set_search("furs",(:TO,"search_furs":));
   set_search("fur",(:TO,"search_furs":));
   set_search("leather",(:TO,"search_furs":));
   set_search("leathers",(:TO,"search_furs":));
   set_climb_exits(([
"descend":({INRMS+"sr1",10,4,100})
]));
   set_exits(([
"south":INRMS+"cr5",
]));
  set_search("default","%^BOLD%^%^BLACK%^You notice a very large hole hidden withen the shadows in the rear corner of the room.%^RESET%^");
}

void reset() {
   object ob;
   ::reset();
   searched = 1;
   if(!present("ogre-mage")){
       new(TMONDIR+"ogremage.c")->move(TO);
   }
}
void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"It looks like this area has been searched already.");
   return ;
   }
   if (searched == 1) {  
      write("You pull something out of the pile of weapons!\n");
      tell_room(TO,""+TPQCN+" searches around and finally digs something out of the pile of weapons.",TP);
      RANDGEAR->arm_me(TO,"edgedm",100,0,0);
      searched = 0;
      return 1;
   }
}

void search_furs() {
   if(searched <= 0) {               
   tell_object(TP,"%^RESET%^%^CYAN%^It looks like there is nothing interesting here.%^RESET%^");
   return 1;
   }
   if (searched == 1) {  
   write("%^BOLD%^%^BLUE%^%^You found some loose gems!\n");
   tell_room(TO,"%^RESET%^%^BLUE%^%^"+TPQCN+" searches through the furs and pulls out some hidden gems.%^RESET%^",TP);
      switch(random(10)){
         case 0:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
	 case 1:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
	 case 2:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
	 case 3:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
         case 4..6:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
         case 7..9:
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            new("/d/antioch/valley/obj/gem.c")->move(TO);
            break;     
      }
      searched = 0;
      return 1;
   }
}


