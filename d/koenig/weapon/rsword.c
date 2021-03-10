inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "short sword", "a short sword", "short" }));
   set_name("short");
   set_short("A short sword");
   set_long(
	"This is a shiny, well kept short sword. "
   );
   set_weight(3);
   set_size(1);
   set("value", 10);
   set_wc(1,6);
   set_large_wc(1,8);
   set_type("thiefslash");
}
