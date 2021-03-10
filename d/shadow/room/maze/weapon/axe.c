inherit "/std/weapon";

create() {
    ::create();
set_id(({ "axe" }));
set_name("ace");
set_short("An axe");
   set_long(
"It's an old rusty axe, that hasn't been taken care of well");
   set_weight(7);
   set_size(2);
   set("value", 25);
   set_wc(1,8);
  set_large_wc(1,8);
   set_type("slash");
   set_prof_type("medium axe");
  set_property("enchantment",1);
}
