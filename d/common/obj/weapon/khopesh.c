//updated base damage - Circe 4/29/04
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword","khopesh sword","khopesh"}));
   set_name("khopesh");
   set_short("A khopesh sword");
   set_long("This sword has a long, curved, sickle like blade.  "+
      "It looks like the perfect weapon for severing unarmored "+
      "limbs like a gardener would prune a hedge.");
   set_weight(7);
   set_size(2);
   set_value(10);
   set_wc(2,4);
//   set_large_wc(1,6);
   set_large_wc(2,4);
   set_type("slashing");
   set_weapon_speed(6);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
