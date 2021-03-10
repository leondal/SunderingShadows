//room with a ranger that has armor
#include <std.h>
#include "deep_echo.h"

inherit ROOM;

int items = 1;

void create(){  
    ::create();
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",-1);
    set_name("Deep Echoes Mountains");
    set_short("Deep Echoes Mountains");
    set_long(
      "%^RED%^Below Echoes Mountains%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^This cool cave is deep in the earth.  "+
      "Nothing ever was built here unlike the echoes above.  "+
      "If any dwarves made it down here there is no trace left. "+
      "The %^WHITE%^walls%^BLACK%^ are wet and"+
      " jagged, likely hollowed out by lava "+
      "ages ago, forming this cave. "+
      "Crumbled rocks from the %^WHITE%^ceiling%^BLACK%^"+
	  " form a uneven surface to walk "+
      "on. %^RESET%^"+
      "\n"+
      "%^CYAN%^The cavern reaches its deepest point here.  It tapers off"+
      " into shallow water and rocks.  Up above there is a"+
      " crack that spills out a small waterfall.  Next to the water"+
      " is a camp.");

    set_items(([
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^. "+
         "They were not created by anything but natural events.  "+
         "If this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks. "+
         " They are nothing like the dwarven work above. "+
         "\n",
 
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture.  "+
         "They are cold to the touch.  "+
         "Several parts of the walls have been broken leaving "+
         "jagged outcropping.",
      (({"water","waterfall","lake","pool","crack"})) : "This area is low enough "+
         "that water stops up making a pool at the end of the tunnel. "+
         " The water is fed by a small waterfall trickling out "+
         "from above.",
      (({"camp","hunter camp"})) : "There is a small camp "+
         "set up here.  A tent made from hides sits next"+
         " to tools for food, skinning, and leatherworking. \n"+
		 "Perhaps one could search it.",
     
   
        ]));
   set_listen("default","a small stream of water splashes down.");
   set_smell("default","it smells of fresh water.");

    set_exits(([
        "northwest" : ROOMS"50"
        ]));

    set_search("default","Where do you want to search?");
    set_search("camp",(:TO,"search_camp":));
}
int search_camp(string str){
     object obj;
     if (!items) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
    if (present("hunter")) {
     tell_object(TP,"the hunter will not"+
      " let you poke around.");
      return 1;}
     obj = new(OBJ"hookhide");
     obj->set_size(TP->query_size()); 
     obj->move(TO);
     tell_object(TP,"You find an armor"+
      " that looks to be your size.");
     items=0;
      return 1;
}

void reset(){
   ::reset();
   items = 1; // search once per reset
   if(!present("hunter"))new(MOBS"hunter")->move(TO);
   switch(random(5)){



      case 0:  tell_room(TO,"%^CYAN%^Water splashes down into the pool.");
               break;
      case 1:  tell_room(TO,"%^GREEN%^You suddenly hear a clicking  "+
                  "noise nearby.");
               break;
      case 2:  tell_room(TO,"A loud %^RED%^--CLUNK--%^RESET%^"+
                  " sounds as "+
                  "another piece of stone falls to the ground.");
               break;
      case 3:  tell_room(TO,"%^BOLD%^%^BLACK%^The stale "+
                  "air makes your stomach "+
                  "turn.");
               break;
      case 4:  tell_room(TO,"Several %^RED%^bats%^RESET%^ fly "+
                  "through the cave past you, "+
                  "then out of sight.");
               break;
   }
}
