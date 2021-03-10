#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("sunstone rod");
   set_short("%^YELLOW%^A sunstone rod%^RESET%^");
   set_id(({"rod","sunstone rod","sun stone rod","feldspar rod"}));
   set_long("%^YELLOW%^This is a slender rod approximately two and a"+
   " half feet long and not quite an inch thick, made of one piece of"+
   " polished sunstone. The sunstone is slightly opaque and is yellow"+
   " in color, it glows brightly when held up to the light.");
   set_weight(7);
   set_value(1750);
   set_property("brazier sacrifice",1);
}
