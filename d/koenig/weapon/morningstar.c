inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "morningstar","morning star" }));
   set_name("morning_star");
   set_short("A morning star");
   set_long(
	"This is a pole with a spiked ball, attached to a chain, "
	"attached to the pole. "
   );
   set_weight(12);
   set_size(2);
   set("value", 10);
   set_wc(2,4);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("mace");
}
