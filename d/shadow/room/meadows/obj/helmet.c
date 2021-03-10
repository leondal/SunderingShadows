#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("antler helmet");
   set_short("Antler helmet");
   set_id(({"helmet","helm","antler helmet"}));
   set_long("This is an intriguing helm. The base"+
   " is made from bronzewood with cloth inside to cushion one's head,"+
   " and there is a nice set of antlers protruding from the top.");
   set_weight(3);
   set_value(20);
   set_type("armour");
   set_limbs(({"head"}));
   set_ac(1);
   set_size(random(3)+1);
}
