#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("dust pouch");
   set_short("%^RESET%^%^ORANGE%^A pouch of dust%^RESET%^");
   set_id(({"dust pouch","pouch of dust","pouch"}));
   set_long("This is a rather nondescript, brown leather pouch. A"+
   " drawstring closes it tightly so that nothing escapes, but inside"+
   " is the dust of several diamonds, emeralds, rubies, and sapphires."+
   " This would certainly fetch a nice price somewhere.");
   set_weight(5);
   set_value(8000);
   set_property("brazier sacrifice",1);
}
