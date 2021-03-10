#include <std.h>
#include "../../elfisland1.h"
inherit "/std/room";

int items;
int item;

void create() {
items = 1;
item = 1;
   ::create();
   set_property("indoors", 0);
   set_property("light", 2);
   set_property("night light",1);
   set("short", "%^BOLD%^%^YELLOW%^Lookout%^RESET%^");
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set("long",
      "%^RESET%^%^GREEN%^The spiral stairs along the side of the tree lead to this platform."+
      " This platform is high up in the trees. The vastness of the land"+
      " around you can be observed from here. The platform is made up of the intricate bindings"+
      " of the tree branches. There is a small waist high border, to keep people from accidentally"+
      " falling off. There is a large deposit of arrows set in one corner and several long bows"+
      " hanging from a hook grown from the tree."
   );
   set_smell("default", "%^RESET%^%^ORANGE%^You can smell the fresh scent of the forest.%^RESET%^");
   set_listen("default", "%^RESET%^%^CYAN%^You can hear the sound of wind passing through the branches.%^RESET%^");
   set_items( ([ 
      "forest": "You can observe a vast part of the forest from here. You see several paths and a few of them come to this village.", 
      "arrows":"There are several arrows decorated with feathers in the corner.",
      "bows":"A few bows of elven craftsmanship hang from a hook for easy access." 
   ]) );
   set_exits( ([
      "down" : TOWN+"road02"
   ]) );

   set_search("default", "There is not much here other than the arrows and the bows.");
   set_search("arrows", (: TO, "searchinga" :) );
   set_search("bows", (: TO, "searchingb" :) );
}

void searchinga() {
   object ob;
   if(!items) {
      write("Looks like all the useful stuff is being armed at the moment");
      return;
   }
   switch(random(4)){
      case 0..2:
   ob = new("/d/common/obj/lrweapon/larrows");
   ob->move(TO);
   write("You find a quiver of arrows among the equipment.");
   tell_room(TO,TPQCN+" finds a quiver arrows among the equipment.", TP);
   break;
      case 3:
   write("%^BOLD%^%^BLUE%^You find a quiver of colorful arrows!%^RESET%^");
   tell_room(TO,TPQCN+" finds a quiver of colorful arrows among the equipment.", TP);
   ob = new(OBJ+"carrows");
   ob->move(TO);
   break;
   }
   items = 0;
   return;

}

void searchingb() {
   object ob;
   if(!item) {
      write("Looks like all the useful stuff is being armed at the moment");
   return;
   }
   switch(random(4)){
      case 0..2:
   ob = new("/d/common/obj/lrweapon/longbow");
   ob->move(TO);
   write("You find a longbow among the equipment.");
   tell_room(TO,TPQCN+" finds a longbow among the equipment.", TP);
   break;
      case 3:
   write("%^BOLD%^%^GREEN%^You find an exquisite longbow among the equipment!%^RESET%^");
   tell_room(TO,TPQCN+" finds a finely crafted longbow among the equipment.", TP);
   ob = new(OBJ+"elbow");
   ob->move(TO);
   break;
   }
   item = 0;
   return;

}

void reset()
{
   ::reset();
   if(random(10) < 4)
      items = 1;
   if(random(10) < 4)
      item = 1;
   if(!present("guard")) {
    new(MON+"elguard")->move(TO);
    new(MON+"elguard")->move(TO);
    new(MON+"elguard")->move(TO);
}
}

