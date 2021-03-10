//picnic plate for new Seneca
//~Circe~ 12/13/07
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("picnic plate");
   set_id(({"plate","wooden plate","picnic plate","wooden picnic plate"}));
   set_short("%^RESET%^%^ORANGE%^a carved wooden plate%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This plate has been carved from lightweight "+
      "wood chosen for its resilience.  It has a shallow bowl designed "+
      "to hold many different types of foods, and a decorative border of "+
      "flowers has been carved around the edges.  The plate has been "+
      "crafted to be easy to carry and durable, making it a perfect "+
      "addition to any picnic.%^RESET%^");
   set_weight(1);
   set_value(0);
}