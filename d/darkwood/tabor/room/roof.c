//updated by Circe 5/31/04 with color, etc.
#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light",2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
   set_property("indoors",0);
   set_name("%^BOLD%^%^CYAN%^Rooftop of the Tower of the Arcane, Tabor%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Rooftop of the Tower of the Arcane, Tabor%^RESET%^");
   set_long(
   "%^BOLD%^Rooftop of the Tower of the %^CYAN%^A%^YELLOW%^r%^CYAN%^c"+
   "%^YELLOW%^a%^CYAN%^n%^YELLOW%^e%^WHITE%^, Tabor%^RESET%^\n"+
   "%^CYAN%^This is the rooftop of the %^BOLD%^Tower of the Arcane"+
   "%^RESET%^%^CYAN%^.  The %^WHITE%^floor %^CYAN%^here is"+
   " made of stone blocks and is in the shape of a circle, with the"+
   " %^BOLD%^%^BLACK%^staircase %^RESET%^%^CYAN%^that leads down to "+
   "the fourth floor directly in the center.  There are no railings "+
   "here, just a small set of ornately %^WHITE%^carved stones %^CYAN%^"+
   "that ring the edges.  There is almost always a"+
   " %^BOLD%^breeze %^RESET%^%^CYAN%^blowing, and occasionally mages "+
   "will come out here to practice %^YELLOW%^spells %^RESET%^%^CYAN%^"+
   "that might be dangerous if cast within the tower."+
   "  From here you can see over the city of Tabor.\n"
   );
   set_smell("default","The breeze is sweet and refreshing.");
   set_listen("default","You can hear the wind rush about the tower.");
   set_items(([
   "staircase" : "There is a staircase in the center of the roof that"+
   " leads back down to the fourth level.",
   ({"stones","carved stones","ornately carved stones"}) : "There are"+
   " several ornately carved stones that ring the edges of the roof."+
   " They are perhaps half a foot tall and appear to be purely for"+
   " decoration.",
   ]));
   set_exits(([
   "down" : ROOMDIR+"tfloor4",
   ]));
}
