//giant weapon by Circe 12/3/04

inherit "/std/weapon";

create() {
    ::create();
   set_id(({"warhammer","hammer","giant hammer","giant war hammer","giant warhammer"}));
   set_name("giant warhammer");
   set_short("giant warhammer");
   set_long(
      "This massive hammer features a wide iron head balanced by a "+
      "wicked counterspike.  The haft is made of thick oak tied with "+
      "thick leather dyed black to match the iron head.  The solid "+
      "hammer feels as though it would certainly crack open anything..."+
      "assuming you are able to lift it, of course."
   );
   set_weight(18);
   set_size(4);
   set_value(50);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("bludgeoning");
   set_prof_type("giant hammer");
   set_weapon_speed(8);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("bludgeoning");
   set_property("repairtype",({"weaponsmith"}));
}
