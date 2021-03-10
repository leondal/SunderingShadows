//k_road09.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "This narrow broken roadway leads through a ransacked village "+
      "that has clearly been abandoned.  North and south small buildings "+
      "rise up in the village, but the stretch of road here is now empty.  "+
      "East and west are patches of charred ground and ruins where there "+
      "were once several houses.  Now, nothing remains but burned timbers "+
      "and fitful patches of coarse grass trying to grow up throw the desolation."
      "\n");
   add_item("ruins","To the east and west stand the ruins of several village "+
      "buildings, most likely houses.  Now, timbers stand upright, most burned in "+
      "half, and grass is finally beginning to grow there.");
   add_item("grass","The verdant grass is growing in fitful patches among the "+
      "ruins of the village.  It is coarse and quite short, but it is steadily "+
      "trying to take over the ruins.");
   set_exits(([
      "north" : VILROOMS"k_road08",
      "west" : VILROOMS"ruins1",
      "east" : VILROOMS"ruins2",
	"south" : VILROOMS"k_road10"
   ]));
}