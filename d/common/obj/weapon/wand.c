inherit "/std/weapon";

create() {
    ::create();

   set_id(({"wand","small wand"}));
   set_name("small wand");
   set_short("A small wand");
   set_long("This small wand has been roughly carved from a piece "+
      "of wood. It has a slender handle and gradually thins along "+
      "its length."
   );
   set_weight(1);
   set_size(1);
   set_prof_type("wand");
   set_weapon_prof("simple");
   set_value(15);
   set_cointype("silver");
   set_wc(1,2);
   set_large_wc(1,2);
   set_type("bludgeoning");
   set_weapon_speed(4);
   set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("bludgeoning");
}
