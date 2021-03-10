#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("weasel pelt");
   set_short("A weasel pelt");
   set_id(({"pelt","weasel pelt","weasel_pelt"}));
   set_long("This is the pelt of a small brown weasel. It is quite soft"+
   " to touch, and might fetch a nice price if you could find a tailor or"+
   " someone willing to buy it.");
   set_value(50);
   set_weight(2);
}
