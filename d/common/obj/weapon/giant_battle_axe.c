//giant weapon by Circe 12/3/04
inherit "/std/weapon";

void create() {
   ::create();
   set_id(({"axe","battle","battle axe","giant axe","giant battle axe"}));
   set_name("giant battle axe");
   set_short("giant battle axe");
   set_long(
      "This immense weapon features twin blades balanced across a "+
      "wooden haft the size of a small tree.  The half-moon blades "+
      "are honed to sharp edges, despite a few nicks that have been "+
      "smoothed again.  The base of the haft has been wrapped with "+
      "thin leather strips to provide a strong grip."
   );
   set_weight(15);
   set_size(4);
   set_value(25);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("slash");
  set_prof_type("giant axe");
   set_weapon_speed(7);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
