#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("bearskin jacket");
   set_short("%^RESET%^%^ORANGE%^Bearskin jacket%^RESET%^");
   set_id(({"jacket","bear jacket","bearskin jacket","bear skin jacket"}));
   set_long("%^ORANGE%^This jacket has been expertly tailored from one large piece"+
   " of bear hide. The outside is covered in the thick brown fur of the"+
   " bear, while the inside is supple bearskin. The jacket has been"+
   " tailored to fit closely around the body and will keep you warm.%^RESET%^");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(4);
   set_value(25);
   set_size(random(3)+1);
}
