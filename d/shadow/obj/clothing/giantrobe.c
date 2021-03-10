#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("robe of the giant");
   set_id( ({"robe","giant robe","robe of the giant","black robe","fur robe","black fur robe"}) );
   set_short("%^BOLD%^%^BLACK%^robe of the giant%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^black fur robe%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This black colored fur robe is made up entirely of the hide of a giant black "
"bear. Its furry outer surface provides you with a great amount of protection from any physical attacks.");
   set_weight(8);
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_value(400);
   set_size(3);
   set_property("enchantment",1);
   set_wear("%^BOLD%^%^MAGENTA%^You put on the robe and feel a little more protected.");
   set_remove("%^BOLD%^%^MAGENTA%^You feel less protected as you remove the robe.");
}
