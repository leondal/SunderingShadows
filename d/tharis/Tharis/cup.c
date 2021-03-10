//cup.c

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
The Merchant's Cup
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^YELLOW%^The Merchant's Cup%^RESET%^
This busy pub serves a definite upper level crowd.  You note
that even the rich here in Tharis are just as loud when drunk.
The well clothed patrons shout back and forth at each other.
The place is clean and the walls are fairly nicely decorated.  
You notice as you stand and watch that the occasional patron 
comes in and disappears into the crowd toward the west end of
the common room.
JAVAMAKER
   );

   set_smell("default","The room smells of the perfumes of the partons mixed with ample ale.");
   set_listen("default","Around you gossip happens.  Various languages can be heard, most seem jolly enough.");
   set_items(([
      "walls":"The walls here are hung with signs and drawings. A particularly large drawing of a thick bearded man to the west catches your eye.",
      "patrons":"For the most part these people come from a merchant class, trying to spend today's earnings on the perfect pint.",
      "drawing":"This drawing seems to touch the floor at the bottom and be about 6 1/2 feet tall. You could almost swear it was a door.",
   ]));

   set_exits(([
      "drawing":ROOMS"safe",
      "east":ROOMS"main4",
   ]));

   set_invis_exits(({"drawing",}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));

   set_door("cup door",ROOMS"main4","east",0);
}


void reset(){
   ::reset();
   if(!present("rakath")){
      find_object_or_load(MON"rakath")->move(TO);
   }

}

void init(){
   ::init();
   add_action("read","read");
}


int drawing_postExit(){
   ROOMS"cup"->set_open("drawing",0);
   ROOMS"cup"->set_locked("drawing",1);
}

int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("Rakath");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("The following great foods are served here at the Merchant's cup Tavern.");

    write("--------------------------------------------------------------------");
    write("Tharisian ale\t\t\t\t\t"+ (int)ob->get_price("tharisian ale") + " silver");
    write("Tsarven wine\t\t\t\t\t"+(int)ob->get_price("tsarven wine")+" silver");
    write("Forest water\t\t\t\t\t"+(int)ob->get_price("forest water")+" silver");
    write("Bread\t\t\t\t\t\t"+ (int)ob->get_price("bread")+" silver");
    write("Squirrel stew\t\t\t\t\t"+ (int)ob->get_price("squirrel stew")+" silver");
    write("Side of meat\t\t\t\t\t"+ (int)ob->get_price("side of meat")+" silver");
    write("Rakath's special blend\t\t\t\t"+ (int)ob->get_price("rakath's special blend")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}