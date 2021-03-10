#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"axe", "battle axe", "battleaxe", "iron axe", "iron battle axe"}));
   set_name("iron battle axe");
   set_short("iron battle axe");
   set_long("This is a heavy, long-handled battle axe with a large, straight-edged, iron blade.");
   set_size(3);
   set_weight(13);
   set_value(10);
   set_type("slashing");
   set_prof_type("large axe");
   set_weapon_speed(7);
   set_wc(1,8);
   set_large_wc(1,8);
}

