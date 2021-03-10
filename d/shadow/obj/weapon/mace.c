inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "mace" }));
   set_name("mace");
   set_short("A mace");
   set_long(
@GARRETT
This is a blunt striking weapon, suitable for fighting on foot or from
horseback.  The head of the mace is a single piece of cast iron, and the
handle is made from the heartwood of an oak tree.
GARRETT
   );
   set_weight(10);
   set_size(2);
   set("value", 8);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_weapon_speed(6);
}
