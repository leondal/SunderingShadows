inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "bastard sword", "a bastard sword", "bastard" }));
     set_name("bastard");
set_short("Bastard Sword");
   set_long(
"This is the Sword of Vengence. It appears to be a simple bastard sword."
   );
   set_weight(10);
   set_size(2);
set("value",1);
set_wc(2,10);
set_large_wc(2,12);
   set_type("slash");
set_property("enchantment",1);
}
