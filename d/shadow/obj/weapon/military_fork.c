inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "military fork","military_fork","military","fork"}));
    set_name("military fork");
   set_short("A military fork");
   set_long(
  "  This is an evolved form of the hay fork."  
   "  Its two tines have been lengthened and supported to make it an effective weapon for keeping an opponent at bay, although it lacks penetration power against heavily armored targets."
   );
   set_weight(7);
   set_size(3);
   set("value", 5);
   set_wc(1,8);
   set_large_wc(2,4);
   set_type("pierce");
   set_prof_type("fork");
   set_weapon_speed(7);
}
