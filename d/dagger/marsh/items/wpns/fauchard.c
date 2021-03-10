inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "fauchard" }));
   set_name("fauchard");
   set_short("A fauchard");
   set_long(
	"It has a long curved blade on the end of an 8 foot shaft."
   );
   set_weight(7);
   set_size(3);
   set("value", 7);
   set_wc(1,6);
   set_large_wc(1,8);
   set_type("slash");
   set_prof_type("polearm");
}
