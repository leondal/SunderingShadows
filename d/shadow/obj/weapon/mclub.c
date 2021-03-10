inherit "/std/weapon";

create() {
    ::create();

   set_id(({ "club", "mclub", "medium club" }));
   set_name("club");
   set_short("A medium club");
   set_long(
   "This is a wooden club. It is rather plain and ordinary, made from"+
   " a large piece of wood and roughly carved. It is thicker at the ends"+
   " and narrows down to a slender handle that you can grip it with."+
   " It is generally used to hit someone with, and is a rather crude weapon."
   );
   set_weight(4);
   set_size( 2 );
   set("value", 8);
   set_cointype("silver"); 
   set_wc(1,7);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_weapon_speed(4);
}
