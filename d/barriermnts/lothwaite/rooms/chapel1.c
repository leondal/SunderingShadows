//chapel1.c - Path to the chapel.  Circe 8/16/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("A well-made flagstone path");
   set_short("A well-made flagstone path");
   set_long("%^GREEN%^This %^BOLD%^%^BLACK%^flagstone path %^RESET%^"+
      "%^GREEN%^is made of %^BOLD%^%^BLACK%^deep gray slate "+
      "%^RESET%^%^GREEN%^that has been painstakingly shaped and "+
      "fitted.  The pathway differs greatly from the rest of the "+
      "%^BOLD%^valley %^RESET%^%^GREEN%^and creates a solemn "+
      "atmosphere as it approaches the impressive %^ORANGE%^"+
      "wooden chapel %^GREEN%^in the southern part of the village.  "+
      "A narrow border of %^YELLOW%^daffodils %^RESET%^%^GREEN%^"+
      "lines the path no matter the season, apparently blessed by "+
      "the firbolg shaman's affinity to nature.%^RESET%^\n");
   set_items(([
      ({"path","pathway"}) : "%^BOLD%^%^BLACK%^The flagstone pathway "+
         "is made of fantastic slate the color of a moonlit night sky.  "+
         "The stones have been perfectly fitted together and not a single "+
         "blade of grass peeks through.  Unlike the rustic feel of the "+
         "rest of the village, this pathway seems to convey a feeling "+
         "of solemnity.%^RESET%^",
      ({"daffodils","daffodil","border","flowers"}) : "%^YELLOW%^Sunny "+
         "daffodils line the pathway leading to the chapel, forming "+
         "a narrow border no matter the season.  In the winter, the "+
         "daffodils peek their bright faces through the snow, while they "+
         "wave proudly on the breeze in the summer.%^RESET%^",
      ({"chapel","wooden chapel"}) : "%^ORANGE%^The stunning chapel "+
         "rises high above the valley floor, a single-story masterpiece.  "+
         "%^YELLOW%^S%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
         "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
         "%^YELLOW%^s%^GREEN%^s %^RESET%^%^ORANGE%^windows with pointed "+
         "archways march along the wooden walls with a spectacular "+
         "window in the front depicting a gathering of the deities the "+
         "firbolgs revere.%^RESET%^"
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
   set_exits(([
      "north" : PATHEXIT"pathway25",
      "south" : PATHEXIT"chapel2",
   ]));
}