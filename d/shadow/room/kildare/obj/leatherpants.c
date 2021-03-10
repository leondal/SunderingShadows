#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("leatherpants");
   set_id(({"pants","breeches","leather pants","leather breeches"}));
   set_short("Brown leather breeches");
   set_long(
      "%^RESET%^%^ORANGE%^This sturdy pair of breeches has been crafted "+
      "of sheep hide and tanned to a deep brown.  The seams are reinforced "+
      "to extend the life of the pants, and they seem well-suited for most "+
      "any task, from mucking out stables to crawling through the most "+
      "fearsome dragon's lair.%^RESET%^"
   );
   set_lore("This is a finely-tailored pair of breeches made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(6);
   set_value(30);
   set_type("clothing");
   set_limbs(({"left leg","right leg"}));
}
