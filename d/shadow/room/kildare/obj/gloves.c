#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("leathergloves");
   set_id(({"gloves","leather gloves","plain gloves"}));
   set_short("Plain leather gloves");
   set_long(
      "This pair of gloves is made of high quality leather and seem durable.  "+
      "They are quite plain, dyed a dark brown shade and fashioned with no "+
      "adornments or frills.  They would be good work gloves, and they are "+
      "lined with wool to keep one's hands warm in the cold."
   );
  set_lore("This is a finely-tailored pair of gloves made by Mariel "+
      "of Kildare Glen.  A small tag bearing her mark has been "+
      "sewn into it.");
   set_property("lore difficulty",3);
   set_weight(3);
   set_value(25);
   set_type("clothing");
   set_limbs(({"left arm","right arm"}));
}
