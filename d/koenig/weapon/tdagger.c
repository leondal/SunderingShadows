inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "dagger" }));
   set_name("dagger");
   set_short("A dagger");
   set_long(
	"This is a shiny, well kept dagger. "
   );
   set_weight(1);
   set_size(1);
   set("value", 2);
   set_wc(1,4);
   set_large_wc(1,3);
  set_type("slashing");
}
