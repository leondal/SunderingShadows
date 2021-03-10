//Village green for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_indoors(0);
   set_light(2);
   set_name("Village Green");
   set_short("Village Green");
   set_long("%^GREEN%^This open grassy area lies just north of "+
      "the main road through town.  The %^BOLD%^grass %^RESET%^"+
      "%^GREEN%^here is lush but kept short, providing a comfortable "+
      "place for the villagers to sit during outdoor %^MAGENTA%^"+
      "festivals%^GREEN%^, of which they seem quite fond.  Most "+
      "of the green is kept open and clear, allowing ample space "+
      "for gatherings of any size.  All around you rise up the "+
      "%^RESET%^homes %^GREEN%^and %^ORANGE%^shops %^GREEN%^of "+
      "Lothwaite.");
   set_items(([
      ({"ground","grass","green"}) : "%^GREEN%^The village green is "+
         "covered in short, soft grass that provides a comfortable "+
         "place to sit or lay.",
      ({"pole","wooden pole"}) : "%^ORANGE%^The wooden pole in "+
         "the northwestern corner of the green stands upon a "+
         "low mound.  It seems to be a focal point of the green.",
      ({"homes","shops","buildings"}) : "The wooden and stone "+
         "buildings of Lothwaite surround you, making this a "+
         "sheltered area that seems quite safe."
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
}