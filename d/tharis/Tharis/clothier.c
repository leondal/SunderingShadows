//clothier.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Clothier of Tharis
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^YELLOW%^Clothier of Tharis%^RESET%^
This is a dark shop, full of bright colors. The walls are covered with
brightly colored bolts of cloth. There is a table with a pair of hose
laid out trying to match a fairly gaudy jerkin.
JAVAMAKER
   );

   set_smell("default","The smells of the city outside have made it in here.");
   set_listen("default","The bustle of the city outside can be heard here.");
   set_items(([
      "hose":"This is some brown hose or possibly leggings, it really doesn't go with the jerkin.",
      "bolts":"The bolts of cloth are colored %^RED%^red, %^YELLOW%^yellow, %^GREEN%^green, %^BLUE%^blue, %^BLACK%^black, %^RESET%^ and many other colors.",
      "jerkin":"This jerkin is made of a thin leather, and some color blind fool died it orange.",
   ]));

   set_exits(([
      "east":ROOMS"main5",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));

   set_door("clothier door",ROOMS"main5","east",0);
}


void reset(){
   ::reset();
   if(!present("peppy")){
       find_object_or_load(MON"peppy")->move(TO);
   }

}

void init(){
   ::init();

}







