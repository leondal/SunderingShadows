#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
   ::create();
   set_name("loin cloth");
   set_id(({"loin cloth","loin"}));
   set_short("A loin cloth");
   set_long(
   "This is a loin cloth made out of some tan colored cotton. The material is rather"+
   " scraggly and it looks as though it has never been washed."
   );
   set_type("clothing");
   set_limbs(({"waist"}));
   set_weight(1);
   set_size(3);
   set_value(10);
}
