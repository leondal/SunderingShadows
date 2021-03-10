// shovel.c
// Pator@ShadowGate

inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "shovel" }));
   set_name("shovel");
   set_short("The Marleen's castle- stable-shovel");
   set_long(
@SHOVEL
This is the shovel used in the Marleen's castle stables for cleaning up the boxes.
SHOVEL
   );
   set_weight(3);
   set_size( 1 );
   set("value", 1);
   set_wc(1,3);
   set_large_wc(1,1);
   set_type("bludgeoning");
   set_prof_type("tool");
}
