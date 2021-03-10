#include <std.h>
inherit "/std/armour";
create() {
    ::create();
   set_name("%^BOLD%^%^RED%^Red silk sash%^RESET%^");
   set_id(({"sash","silk sash","red sash","red silk sash"}));
   set_short("%^BOLD%^%^RED%^Red silk sash%^RESET%^");
    set_long(
    "  This bright length of silk is stained with salt sprays as if it's been along for a great sea adventure."
  "  The wide band of red silk is worn wrapped around the waist and then knotted or tucked through itself."
    );
  set_weight(1);
  set_value(65);
set_type("ring");
  set_limbs(({"waist"}));
}
