#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("ratty robe");
   set_id(({"robe","robes","ratty robes","ratty robe"}));
   set_short("%^BOLD%^%^BLACK%^A ratty robe%^RESET%^");
   set_long("This robe was once long and flowing but now ends raggedly well above where the hem once was.  "
"The sleeves have been cut off jaggedly, and it is difficult to tell what color the robe is supposed to be, "
"though it seems to be a muted gray.  The fabric is coated with a thin layer of muck and dirt, and a musty "
"smell has permeated it through.");
   set_ac(1);
   set_weight(5);
   set_value(25);
   set_size(1);
   set_type("clothing");
   set_limbs(({"torso"}));
}
