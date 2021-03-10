inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "scimitar","sword","scimitar sword" }));
   set_name("scimitar");
   set_short("A scimitar sword");
   set_long(
   "This sword has a wide, heavy, curved blade on it, perfect for cutting into poorly armored targets."
   );
   set_weight(4);
   set_size(2);
   set("value", 15);
   set_wc(1,8);
   set_large_wc(1,8);
set_type("slashing");
   set_weapon_speed(5);
}
