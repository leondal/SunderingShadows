inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "warhammer","hammer","war ahmmer","war" }));
   set_name("warhammer");
   set_short("A war hammer");
   set_long(
	"This is a well kept war hammer. "
   );
   set_weight(6);
   set_size(2);
   set("value", 2);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("bludgeoning");
   set_prof_type("medium hammer");
}
