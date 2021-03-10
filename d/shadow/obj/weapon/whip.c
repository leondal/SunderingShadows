inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "whip"}));
   set_name("whip");
   set_short("A whip");
   set_long(
   "This ordinary bullwhip really doesn't look like it'd be of much use, unless you were going to herd cattle."
  "  Against an armored opponent its use would be laughable."
   );
   set_weight(2);
   set_size(2);
   set("value", 1);
   set_cointype("silver");
   set_wc(1,2);
   set_large_wc(1,2);
   set_type("lash");
   set_prof_type("whip");
   set_weapon_speed(8);
}
