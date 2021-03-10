inherit "/std/weapon";

create() {
    ::create();

   set_id(({ "club", "mclub", "large club" }));
   set_name("club");
   set_short("A large club");
   set_long(
   "This is a large wooden club, so large it takes two hands for any normal size humanoid to wield and swing it.  It is rather plain and ordinary, roughly carved from a large tree limb.  It is thicker at the ends and narrows down to a slender handle that you can grip it with.  It is generally used to hit someone with, and is a rather crude weapon."
   );
   set_weight(5);
   set_size( 3 );
   set("value", 1);
   set_wc(1,8);
   set_large_wc(2,5);
   set_type("bludgeoning");
   set_weapon_speed(6);
}
