inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "axe", "battle","battle axe" }));
   set_name("battle_axe");
   set_short("A battle axe");
   set_long(
  "  This is a long heavy axe, with double blades opposing each other."
   "  Doesn't look very effective for cutting trees, but that gnoll over there..."
   );
   set_weight(7);
   set_size(2);
   set("value", 5);
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("slash");
  set_prof_type("medium axe");
   set_weapon_speed(7);
}
