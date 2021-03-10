inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "bastard sword", "a bastard sword", "bastard" }));
     set_name("bastard");
   set_short("A bastard sword");
   set_long(
   "This is a long, heavy sword.  Its handle is almost big enough for two hands for a normal sized human, but more effectivly wielded with one."
    "  It's not so much pointed as made for heavy blows with its edge."
   );
   set_weight(10);
   set_size(2);
   set("value", 10);
   set_wc(1,8);
   set_large_wc(1,12);
   set_type("slash");
   set_weapon_speed(6);
}
