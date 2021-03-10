inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "hammer", "lucern", "lucern hammer" }));
   set_name("lucern_hammer");
   set_short("A lucern hammer");
   set_long(
	"This is a shiney, well kept lucern hammer. "
   );
   set_weight(15);
set_size(2);
   set("value", 7);
   set_wc(2,4);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("medium hammer");
}
