#include <std.h>
inherit "/std/room";

void create() {
     ::create();
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
     set_light(3);
     set_indoors(1);
     set_short("You stand within the crystal tower of the Kinnesaruda");
     set_long("
    You stand atop a clear crystal platform that is floating high above the ground in an incredibly vast chamber with glass walls.  All around you are similar such platforms hovering in this chamber, but they are too far away to jump to.  All the platforms are clear like ice and you can see all the way to the ceiling and the floor through them.  
    In the very center of the gigantic chamber is a large black cube the size of a multi-story building!  It is quite far away, though.
");
    set_exits(([
       "southwest" : "/d/attaya/tower/tower33",
       "northeast" : "/d/attaya/tower/tower31",
   ] ));
   set_items(([
         "cube" : "It is enormous and black.  It is suspended by four massive cables that attach to the four corners of the ceiling.  It is enormous and could easily contain a small city.",
         "walls" : "They are made of hundreds of glass panels.  You can look outside to see the entire island of Attaya and the surrounding ocean!",
         "platforms" : "They are transparent and appear to be made of quartz.  On some of them, you can see knights walking around.",
         "platform" : "The platform is transparent and appears to be made of quartz.",
    ] ));
}

