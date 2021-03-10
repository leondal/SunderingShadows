#include <std.h>
inherit "/d/common/obj/armour/helm";

void create() {
   ::create();
   set_name("helm");
   set_id(({"helm","helmet","shining helmet","shining helm"}));
   set_short("%^BOLD%^%^WHITE%^A shining helmet%^RESET%^");
   set_long("This is a large shining helmet that covers the entire head and neck."+
      " The helmet is made from a tough silver and has a visor that can be"+
      " slid over the eyes or lifted when needed. There is an opening for the mouth,"+
      " so that the wearer can be heard clearly when speaking.  It looks like it"
      " is extremely well made and would protect quite well."
   );
   set_property("enchantment",1);
}
