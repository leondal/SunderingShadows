//up.c room with hidden spy
#include <std.h>
#include "deep_echo.h"

inherit ROOM;


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
      "This deep areas is the bottom of a %^BOLD%^chasm.%^RESET%^  "+
      "A makeshift %^BOLD%^camp%^RESET%^ is set up here.  "+
      "If any dwarves made it down here there is no trace left. "+
      "The %^BOLD%^walls%^RESET%^ are wet and"+
      " jagged likely hollowed out by lava "+
      "ages ago and forming this cave.  "+
      "Crumbled rocks from the ceiling form a uneven surface to walk "+
      "on. "+
      "\n");
set_climb_exits((["climb":({ROOMS"enter.c",20,roll_dice(10,8),100})]));
    set_items(([(({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^.  "+
         "They were not created by anything but natural events.  "+
         "If this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks.  "+
         "They are nothing like the dwarven work above. "+
         "\n",
   (({"chasm","Chasm","ceiling"})) : "Above is only blackness.  "+
         "The top of the chasm cannot be seen.  Climbing "+
         "up would be very difficult.",
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture.  "+
         "They are cold to the touch. "+
         "Several parts of the walls have been broken leaving "+
         "jagged outcropping.  They would be difficult to climb.",
     (({"camp","Camp"})) : "Seems like some creatures are "+
         "staying down here.  The items in the camp looks fresh.",
   
        ]));
   set_listen("default","wind blows slowly.");
   set_smell("default","The air here chills ones nose.");

    set_exits(([
        "southeast" : ROOMS"01"    
        ]));
}
void reset() {
    ::reset();
    
    if(!random(2))
    if(!present("drow spy")) {
      object drow = new(MOBS"drowspy"); 
      drow->move(TO);  
    }
    if(!present("ogre")){
     new(MOBS"ogre")->move(TO);
     new(MOBS"ogre")->move(TO);
     new(MOBS"ogre")->move(TO);
    }
}
