inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "bec de corbin" }));
  set_name("bec de corbin");
   set_short("A bec de corbin");
   set_long(
	"This is a pole arm with a hook on one side and an axe on the other. "
   );
   set_weight(10);
set_size(2);
   set("value", 8);
   set_wc(1,8);
   set_large_wc(1,6);
   set_type("slash");
   set_prof_type("polearm");
}
