inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "spear","medium spear" }));
   set_name("medium spear");
   set_short("A medium spear");
  set_long(
   "This is a short, one-handed stabbing spear."
   "  It's not so long as to be to hard to use while still retaining the use of a shield, or a leash for hunting dogs."
  );
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(1,6);
   set_large_wc(1,8);
   set_type("piercing");
   set_prof_type("medium spear");
   set_weapon_speed(6);
}
