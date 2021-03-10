#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("antelope jerkin");
   set_short("%^RESET%^%^ORANGE%^An antelope hide jerkin%^RESET%^");
   set_id(({"jerkin","antelope jerkin","hide jerkin","antelope hide jerkin"}));
   set_long("%^ORANGE%^This jerkin is made out of a piece of supple antelope hide."+
   " It is soft and sleeveless, covering the torso and lacing up the front."+
   " It looks like it would give the wearer a bit of protection.%^RESET%^");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_value(10);
}
