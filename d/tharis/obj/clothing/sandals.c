//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

void create(){
   ::create(); 
   set_name("sandals");
   set_id(({"sandals",}));
   set_short("a pair of sandals");
   set_long("This pair of sandals is made of a wide %^ORANGE%^tan "+
      "leather %^RESET%^strap that covers most of the top of the "+
      "wearer's foot.  The sole of the sandal is made of layers of "+
      "thickened leather that protect the foot from small pebbles "+
      "and the like, though the open nature of the shoe would do "+
      "do little to combat the elements.");
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_weight(1);
   set_size(random(3)+1);
   set_value(5);
}
