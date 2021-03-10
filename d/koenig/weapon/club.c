inherit "/std/weapon";

create() {
    ::create();

   set_id(({ "club" }));
   set_name("club");
   set_short("A club");
   set_long(
      "This is a wooden club."
   );
   set_weight(3);
   set_size( 1 );
   set("value", 0);
   set_wc(1,6);
   set_large_wc(1,3);
   set_type("bludgeoning");
}
