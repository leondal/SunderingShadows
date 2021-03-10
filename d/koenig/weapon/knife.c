inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "knife"}));
   set_name("knife");
   set_short("A knife");
   set_long(
	"This is a shiny, well kept knife. "
   );
   set_weight(1);
   set_size(1);
   set("value", 5);
   set_cointype("silver");
   set_wc(1,3);
   set_large_wc(1,2);
   set_type("magepierce");
}
