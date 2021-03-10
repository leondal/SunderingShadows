inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "two handed sword", "a two handed sword", "two handed" }));
   set_name("two_handed");
   set_short("A two handed sword");
   set_long(
	"This is a shiny, well kept two handed sword. "
   );
   set_weight(15);
   set_size(3);
   set("value", 50);
   set_wc(1,10);
   set_large_wc(3,6);
   set_type("slash");
}
