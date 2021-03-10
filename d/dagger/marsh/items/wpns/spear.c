inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "trident" }));
   set_name("trident");
   set_short("A trident");
   set_long(
	"This is a shiney, well kept trident. "
   );
   set_weight(6);
   set_size(2);
   set("value", 15);
   set_wc(1,6);
   set_large_wc(3,4);
   set_type("pierce");
   set_prof_type("medium spear");
}
