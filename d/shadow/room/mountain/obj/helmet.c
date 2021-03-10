#include <std.h>
inherit "/d/common/obj/armour/helm";

void create() {
   ::create();
   set_name("helm");
   set_id(({"helm","horned helm","helmet","horned helmet"}));
   set_short("%^BOLD%^%^BLACK%^A horned helmet%^RESET%^");
   set_long(
      "This is a large blackened metal helmet that covers the entire head and neck. "
      " There is a small metal divider that comes down between the eyes and protects the nose ."
      " There is an opening for the mouth, so that the wearer can be heard clearly when speaking.  "
      " On the top of the helmet, there are two large black horns pointing upward.  "
      "It looks like it is extremely well made and would protect quite well."

   );
   set_property("enchantment",1);
}
