inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "axe","bardiche","bardiche axe" }));
   set_name("bardiche");
   set_short("A bardiche axe");
   set_long(
	"A fancy axe with an 8 foot shaft."
   );
   set_weight(12);
set_size(2);
   set("value", 7);
   set_wc(2,4);
   set_large_wc(2,6);
     set_type("pierce");
   set_prof_type("medium axe");
}
