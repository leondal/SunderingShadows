inherit "/std/weapon";

create() {
    ::create();

   set_id(({ "club" }));
   set_name("club");
   set_short("A small club");
   set_long(
    "This is a wooden club. It is rather plain and ordinary, made from"+
    " a small piece of wood and roughly carved. It is thicker at the ends"+
    " and narrows down to a slender handle that you can grip it with."+ 
   " It is generally used to hit someone with, and is a rather crude weapon."
   );
   set_weight(3);
   set_size( 1 );
   set("value", 5);
   set_cointype("silver"); 
   set_wc(1,6);
   set_large_wc(1,3);
   set_type("bludgeoning");
   set_weapon_speed(4);
}
