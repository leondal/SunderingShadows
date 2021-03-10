//pathway25.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  This seems to be the main pathway through the town.  "+
      "The path runs straight here for awhile, and a new path branches off, leading "+
      "south.  The southern path has been carefully fitted with flagstone, unlike "+
      "the wooden path through much of the village.  The village green "+
      "opens up to the north.\n");
   add_item("path","The southern path has been fitted with flagstone and carefully "+
      "laid, unlike the wooden pathway through the village.  The deep slate stone "+
      "must have been imported from somewhere as it does not match the stone of the "+
      "mountainside.");
   add_item("flagstone","The southern path has been fitted with flagstone and carefully "+
      "laid, unlike the wooden pathway through the village.  The deep slate stone "+
      "must have been imported from somewhere as it does not match the stone of the "+
      "mountainside.");
   add_item(({"green","village green"}),"The village green to the north "+
      "is a large open area where outdoor festivals are held.  In the "+
      "northwestern corner, you can make out what looks to be a pole, "+
      "but otherwise, the green is open.");
   set_exits(([
      "west" : PATHEXIT"pathway24",
      "east" : PATHEXIT"pathway26",
      "south" : PATHEXIT"chapel1",
      "north" : PATHEXIT"green2",
   ]));
}
