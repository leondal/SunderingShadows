inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "mace" }));
   set_name("mace");
   set_short("A mace");
   set_long(
	"This is a mace. "
   );
   set_weight(10);
   set_size(2);
   set("value", 8);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("mace");
}
