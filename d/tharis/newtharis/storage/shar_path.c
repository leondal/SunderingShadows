#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create(){
   ::create();
   set_name("Winding Path");
   set_short("Winding Path");
   set_long(
      "%^CYAN%^This narrow %^ORANGE%^path %^CYAN%^winds along the "+
      "rocky mountainside through scraggly %^GREEN%^underbrush%^CYAN%^.  "+
      "The %^GREEN%^plants %^CYAN%^look malnourished and twisted "+
      "by the winds of the %^ORANGE%^mountainside%^CYAN%^.  This "+
      "%^ORANGE%^path %^CYAN%^seems worn by the occasional "+
      "traveler's foot, though it seems to lead to nothing as it "+
      "meanders, leading southwestward toward "+
      "a sheer canyon wall.%^RESET%^\n"
   );
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(PAVED_ROAD);
   set_smell("default","Gentle breezes carry pine scents.");
   set_listen("default","The path is silent except for the faint "+
      "crackle of dying underbrush.");
   set_items(([
      ({"path","trail","ground"}) : "The path here is rocky, "+
         "worn smooth by foot travel.  It is rather narrow and "+
         "covered with a thin layer of dust.  The path snakes "+
         "along the mountainside, borded by fitful clusters of "+
         "windworn undergrowth.",
      ({"undergrowth","bushes","brush","underbrush"}) : "The "+
         "undergrowth is somewhat stunted by the wind here but "+
         "manages to make a thick covering for the ground.  "+
         "The bushes grow close enough together that they would "+
         "make travel off the path too difficult.",
      ({"wall","canyon wall"}) : "The canyon wall rises to the west, "+
         "forming an impassable ridge."
   ]));
}