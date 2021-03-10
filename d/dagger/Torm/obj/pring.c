#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("pearl ring");
   set_short("%^BOLD%^%^WHITE%^Pearl Ring%^RESET%^");
   set_id(({"pearl ring","ring"}));
   set_long("%^BOLD%^This ring is made out of platinum and has a cluster"+
   " of five nice sized white pearls, four on the bottom and one on the"+
   " top in the very center, giving it a flowery appearance. It is quite"+
   " beautiful.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"right hand"}));
   set_value(1000);
   set_size(random(3)+1);
}
