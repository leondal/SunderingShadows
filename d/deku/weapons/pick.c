inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "pick"}));
   set_name("pick");
   set_short("A pick");
   set_long(
	"This is a pick. Similar to the garden pick. "
   );
   set_weight(6);
   set_size(2);
   set("value", 8);
   set_wc(1,6);
   set_large_wc(2,4);
   set_type("pierce");
   set_prof_type("tool");
}
