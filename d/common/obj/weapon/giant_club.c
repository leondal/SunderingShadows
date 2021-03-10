inherit "/std/weapon";

create() {
    ::create();

   set_id(({ "club", "mclub", "giant club" }));
   set_name("giant club");
   set_short("A giant club");
   set_long(
   "This is a huge wooden club, so large that a normal humanoid would "+
"have no hope of carrying it.  It is rather plain and ordinary,"+
" roughly carved from a large tree limb.  It is thicker at the ends and"+
" narrows down to a slender handle that you can grip it with.  It is"+
" generally used to hit someone with, and is a rather crude weapon."
   );
   set_weight(18);
   set_size(4);
   set("value", 1);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("bludgeoning");
         set_prof_type("giant clublike");
   set_weapon_speed(6);
   set_weapon_prof("simple");
   set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_damage_type("bludgeoning");
}
