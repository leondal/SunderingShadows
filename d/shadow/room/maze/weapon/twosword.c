inherit "/std/weapon";

create() {
    ::create();
set_id(({ "sword", "two handed sword" }));
   set_name("two handed sword");
   set_short("A two handed sword");
set_long("This is a two handed sword, looks nice too.");
   set_weight(15);
   set_size(3);
   set("value", 50);
   set_wc(1,10);
   set_large_wc(3,6);
   set_type("slash");
}
