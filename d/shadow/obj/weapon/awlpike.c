inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "pike", "awlpike" }));
   set_name("awlpike");
   set_short("A awlpike");
   set_long(
    "A spear 12-20 feet long, with a spiked point"
	" on the end. "
   );
   set_weight(12);
   set_size(3);
   set("value", 5);
   set_wc(1,6);
   set_large_wc(1,12);
   set_type("pierce");
   set_prof_type("polearm");
   set_weapon_speed(13);
}
