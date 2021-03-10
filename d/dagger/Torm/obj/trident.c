inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "trident" }));
   set_name("trident");
  set_short("%^GREEN%^Seaweed wrapped trident%^RESET%^");
   set_long(
  "%^GREEN%^"
   "  This long viscious looking weapon has seaweed wrapped around its shaft and wound through its tines."
  "  Its triple barbed points are razor sharp and the edges of the outer tines appear to have been sharped to enable the trident to slash as well as impale."
  "  Slime coats its handle and the only thing that enables you to keep it in your hand is the checkered pattern ground into the metal shaft."
   );
   set_weight(6);
   set_size(2);
   set("value", 15);
  set_wc(1,8);
   set_large_wc(3,4);
   set_type("pierce");
   set_prof_type("fork");
   set_weapon_speed(7);
}
