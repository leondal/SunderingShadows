inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "flail" }));
   set_name("flail");
   set_short("A flail");
   set_long(
	"This is a well used flail. "
   );
   set_weight(15);
   set_size(2);
   set("value", 15);
   set_wc(1,6);
   set_large_wc(2,4);
   set_type("bludgeoning");
   set_prof_type("flail");
}
