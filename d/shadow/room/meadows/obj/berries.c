#include <std.h>
inherit "/std/food";

void create()
{
   ::create();
   set_name("berries");
   set_short("A handful of berries");
   set_id(({"berries","handful of berries","food"}));
   set_long("This is a handful of ripe and juicy looking blackberries."+
   " They are dark black and their juices are a deep purple that are"+
   " staining your hands as you hold them.");
   set_destroy();
   set_strength(3);
   set_weight(1);
   set_my_mess("The berries are sweet and juicy.");
   set_your_mess("eats a handful of juicy berries.");
}
