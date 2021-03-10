#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("magistrates robe");
  set_id(({"robe","magistrates robe"}));
  set_short("%^RED%^Magistrates robe%^RESET%^");
    set_long(
    "  This finely made red robe is trimmed with a fine white fur along the edges of its cuffs and collar."
 "  Gold stitching runs up the back and you wonder just how much of the coffers of the city went into buying it."
    );
    set_weight(1);
  set_value(900);
    set_type("clothing");
     set_limbs(({"torso"}));
//    set_ac(1);
    set_property("enchantment",1);
}
