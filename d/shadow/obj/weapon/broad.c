inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "broad sword", "broad" }));
  set_name("broad sword");
   set_short("A broad sword");
   set_long(
   "This sword has a thick, heavy blade and looks like it would stand up to combat for a long time."
   );
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(2,4);
   set_large_wc(1,6);
set_type("slashing");
   set_weapon_speed(7);
}
