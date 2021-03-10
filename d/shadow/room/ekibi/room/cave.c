//cave.c - entrance to Ekibi Caverns
//Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",1);
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_name("Ekibi Caverns");
   set_indoors(1);
   set_short("%^RESET%^%^MAGENTA%^Ekibi Caverns%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^You are in the Ekibi Caverns%^RESET%^\n"+
      "Dank walls of %^BOLD%^limestone %^RESET%^seem to have been "+
      "carved naturally and perhaps widened by hand.  Steady "+
      "%^CYAN%^rivulets %^RESET%^run down the curving walls to "+
      "the floor, forming small %^CYAN%^puddles %^RESET%^in "+
      "lower lying places.  There is a %^BOLD%^%^BLACK%^hole "+
      "%^RESET%^in the floor to the east, leading down into "+
      "%^BLUE%^darkness%^RESET%^.  It looks as though you "+
      "could use climbing tools and the %^YELLOW%^cracks "+
      "%^RESET%^within the %^BOLD%^limestone %^RESET%^to "+
      "%^GREEN%^descend%^RESET%^.  The cave opens back out "+
      "to the west, leading to a narrow %^ORANGE%^footpath%^RESET%^.\n");
   set_listen("default","You hear a strange sound of crickets "+
      "chirping on the wind.");
   set_smell("default","The musty fragrance of the cave reaches "+
      "your nose.");
   set_search("default","You could probably %^GREEN%^<%^RESET%^"+
      "descend%^GREEN%^> %^RESET%^through the hole to enter the "+
      "dark cavern beneath.  You may wish to have a light if you "+
      "need it.");
   set_items(([
      ({"wall","walls","limestone"}) : "%^BOLD%^The walls are "+
         "carved from damp limestone, which feels soft to the "+
         "touch.  They are far from perfect, seeming to have been "+
         "carved by water rather than by hand.  The walls curve, "+
         "narrowing toward the ceiling.",
      ({"rivulet","rivulets","water"}) : "%^CYAN%^Tiny rivulets "+
         "run down the wall, moistening the limestone and "+
         "causing small creases and crevices.",
      ({"puddle","puddles"}) : "In low-lying places throughout "+
         "the cavern, small puddles can be seen.  They do not "+
         "seem deep enough to drink from without getting a "+
         "mouthful of limestone.",
      ({"hole","floor"}) : "The floor has a large hole in the "+
         "eastern end.  You could probably %^GREEN%^descend "+
         "%^RESET%^if you had climbing tools.",
      ({"crack","cracks"}) : "Cracks riddle the limestone walls, "+
         "providing hand and footholds.  You probably cannot "+
         "climb down it safely unless you have the proper tools "+
         "or a special skill."
   ]));
   set_exits(([
      "west" : PATHEXIT"p3"
   ]));
   set_climb_exits((["descend":({ PATHEXIT"c1",10,5,100})]));
   set_fall_desc("You lose your grip and fall to the cave floor.");
}

void reset(){
   ::reset();
   if(!present("area sign")) new("/d/common/obj/areas/ekibi_sign")->move(TO);
}
