inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "dagger" }));
   set_name("dagger");
   set_short("A dagger");
   set_long(
   "A gleam catches your eye from the blade of this finely made weapon."
   "  Its small size and good point make it a perfect weapon for people who don't want to have to worry about space for carrying a larger weapon."
   );
   set_weight(2);
   set_size(1);
   set("value", 2);
   set_wc(1,4);
   set_large_wc(1,3);
   set_type("piercing");
   set_weapon_speed(2);
}
