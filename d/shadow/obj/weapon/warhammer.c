inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "warhammer","hammer","war ahmmer","war" }));
   set_name("warhammer");
   set_short("A war hammer");
   set_long(
  "  This is a heavy iron war hammer."
   "  It's got a long, thick head on one side, counterbalanced on the other by a heavy spike."
   "  It's definitely got its uses if you want to try to crack someone out of their shell."
   );
   set_weight(10);
   set_size(2);
   set("value", 2);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("bludgeoning");
  set_prof_type("medium hammer");
   set_weapon_speed(4);
}
