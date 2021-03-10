inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "halberd" }));
   set_name("halberd");
   set_short("A halberd");
   set_long(
	"This is the most popular pole arm. It has a hook on one side, "
	"and an axe blade on the other side. "
   );
   set_weight(15);
   set_size(3);
   set("value", 10);
   set_wc(1,10);
   set_large_wc(2,6);
   set_type("slash");
   set_prof_type("polearm");
}
