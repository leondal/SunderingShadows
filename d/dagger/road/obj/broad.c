inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "broad sword", "broad" }));
  set_name("broad sword");
   set_short("A broad sword");
   set_long(
	"This is a shiney, well kept broad sword. "
   );
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(2,4);
   set_large_wc(1,6);
   set_type("slash");
}
