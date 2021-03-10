//updated base damage - Circe 5/7/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("giant scythe");
    set_id(({"scythe","tool","one-handed scythe","one handed scythe"}));
    set_short("giant scythe");
//    set_long("This is a scythe, made for cutting wheat in fields.");
    set_long("This simple weapon is made to be wielded in one "+
       "hand.  It has a three foot long oaken handle fitted into "+
       "curving, cutting blade.  Originally made for use in the "+
       "wheat fields, this version has been strengthened for use "+
       "in combat.");
    set_weight(7);
    set_value(10);
//    set_wc(1,6);
//    set_large_wc(1,8);
    set_wc(2,6);
    set_large_wc(2,6);
    set_size(4);
    set_type("slashing");
    set_prof_type("polearm");
    set_weapon_speed(4);
    set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(4);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
