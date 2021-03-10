//updated base damage - Circe 5/7/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("two-handed scythe");
    set_id(({"scythe","tool","two-handed scythe","two handed scythe"}));
    set_short("A large scythe");
//    set_long("This is a scythe, made for cutting wheat in fields.");
    set_long("This strengthened version of the scythe often used "+
       "in the fields is made to be wielded in two hands.  The long, "+
       "curving haft is about five feet long and fitted with two "+
       "shorter wooden handles spaced about two and a half feet "+
       "apart.  The steel blade is about three feet long and curves "+
       "to a vicious point.");
    set_weight(11);
    set_value(15);
    set_wc(2,4);
    set_large_wc(2,4);
    set_size(3);
      set_type("slashing");
set_prof_type("polearm");
    set_weapon_speed(6);
    set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(4);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
