// new inherit for katanas, nienne 05/07
#include <std.h>
inherit WEAPON;

void create() {
    ::create();
   set_id(({ "sword", "katana" }));
   set_name("katana");
   set_short("A katana");
   set_long("This finely worked sword has a very ornate hilt.  The "
        "long, ornate blade is sharpened to a fine edge.  Swords "
        "of this design and craftsmanship are known as katanas.");
   set_weight(12);
   set_size(3);
   set_value(60);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slashing");
   set_weapon_speed(8);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
