#include <std.h>
inherit WEAPON;

void create()
{
   ::create();
   set_name("staff");
   set_short("A fine wooden staff");
   set_id(({"staff","fine staff","wooden staff","fine wooden staff"}));
   set_long(
   "This is a fine wooden staff made out of mahogany wood. It is highly polished"+
   " with a dragon's claw holding a ball on the top of the staff.");
   set_weight(2);
   set_wc(1,6);
   set_large_wc(1,6);
   set_size(2);
   set_value(10);
   set_type("bludgeoning");
   set_prof_type("staff");
   set_weapon_speed(3);
}
