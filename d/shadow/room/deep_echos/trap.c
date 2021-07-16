//room with a trapped rogue
#include <std.h>
#include "deep_echo.h"
inherit ROOM;

void create(){  
    ::create();
	set_property("teleport proof",21) ;
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",0);
    set_name("Deep Echoes Mountains");
    set_short("Deep Echoes Mountains");
    set_long(
      "%^RED%^Below Echoes Mountains%^RESET%^\n"+
      "This cool cave is deep in the earth.  "+
      "Nothing ever was built here unlike the echoes above.  "+
      "If any dwarves made it down here there is no trace left. "+
      "The %^BOLD%^walls%^RESET%^ are wet and"+
      " jagged, likely hollowed out by lava "+
      "ages ago and forming this cave.  "+
      "Crumbled rocks from the ceiling form a uneven surface to walk "+
      "on. "+
      "\n"+
      "%^CYAN%^There are many glowing stones here.");

    set_items(([
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^.  "+
         "They were not created by anything but natural events.  "+
         "If this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks.  "+
         "They are nothing like the dwarven work above. "+
         "\n",
 
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture.  "+
         "They are cold to the touch. "+
         "Several parts of the walls have been broken leaving "+
         "jagged outcropping.",
      (({"stones","glowing stones"})) : "Lodged in the wall, "+
         "many glowing stones shimmer magically.",   
        ]));
   set_listen("default","A slight hum can be heard.");
   set_smell("default","The air is stale.");

    set_exits(([
        "northeast" : ROOMS"52"
        ]));


}
void init(){
  ::init();
  add_action("pull", "pull");
}
int pull(){
   int x;
   if(!present("rogue"))
     tell_object(TP, "There is no one to help");
   else{
     TP->set_mini_quest("Deep Echoes1", 1000000,
      "You helped a dwarf trapped in a cave in");
	 tell_object(TP,"You help a dwarf get out from under a rock.");	 
	 tell_room(ETP,TP->query_cap_name()+" moves a rock off the dwarf.\n",TP);
	 present("rogue")->poof();
     }
   return 1;	 
}
void reset(){
  object mon;
  ::reset();
 
  if(!present("dwarf")){
    mon =new(MOBS"rogue");
	mon->move(TO);
	}
}
