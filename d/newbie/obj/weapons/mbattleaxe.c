#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"axe", "battle axe", "battleaxe", "bronze battle axe", "bronze axe"}));
   set_name("bronze battle axe");
   set_short("bronze battle axe");
   set_long("This is a long-handled battle axe with a wedge-shaped blade made of bronze.");
   set_size(2);
   set_weight(10);
   set_value(10);
   set_type("slashing");
   set_prof_type("medium axe");
   set_weapon_speed(7);
   set_wc(1,8);
   set_large_wc(1,8);
}

