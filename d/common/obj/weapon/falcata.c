//Coded by odin
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "falcata" }));
     set_name("falcata");
   set_short("A falcata");
   set_long(
   "The falcata has a single-edged blade that pitches forward towards the point, the edge being concave near the hilt, but convex near the point. This shape distributes the weight in such a way that the falcata is capable of delivering a blow with the momentum of an axe, while maintaining the longer cutting edge of a sword and some facility to execute a thrust. The grip is typically hook-shaped, the end often stylized in the shape of a horse or a bird. There is often a thin chain connecting the hooked butt with the hilt. Although usually a single-edged weapon, double-edged falcatas have been found."
   );
   set_weight(4);
   set_size(2);
   set("value", 35);
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("slashing");
   set_weapon_speed(6);
   set_weapon_prof("exotic");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
