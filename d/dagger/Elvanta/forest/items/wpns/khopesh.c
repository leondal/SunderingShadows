inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "khopesh sword", "khopesh" }));
   set_name("khopesh");
   set_short("A khopesh sword");
   set_long(
	"This is an egyption sword, with a long curved blade."
   );
   set_weight(7);
   set_size(2);
   set("value", 10);
   set_wc(2,4);
   set_large_wc(1,6);
   set_type("slash");
}
