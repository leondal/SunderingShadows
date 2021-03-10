//updated by Circe with new lore from Shar 6/7/04
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("antlers");
   set_short("A rack of antlers");
   set_id(({"antlers","rack of antlers"}));
   set_long("This is a nice rack of antlers off of a young antelope. It"+
   " might sell for a bit of gold if you could find someone to buy it.");
   set_lore(
@CIRCE
Antelope antlers have long been used as weapons with many cultures.  Many folk find the twisting spirals of the horns pleasing and lightweight.  Its only been in the past 40 years or so that people have began to use them in decorative arts.
CIRCE
   );
   set_property("lore difficulty",5);
   set_weight(2);
   set_value(random(20)+80);
}
