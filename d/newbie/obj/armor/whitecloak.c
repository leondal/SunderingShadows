#include <std.h>
inherit "/std/armour";
void create(){
   ::create();
   set_name("white cloak");
   set_id(({"cloak","white cloak"}));
   set_short("White cloak");
   set_long("This is a suit of simple cloak made of pure white clothe.");
   set_weight(3);
   set_value(20);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
}
