inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "trident" }));
   set_name("trident");
   set_short("A mithril trident");
   set_long("This three pronged spear forged from mithril looks very vicious.  The center tine is longer than the side two which are horribly barbed.");
	set_property("enchantment", 1);
   set_weight(6);
   set_size(2);
   set("value", 215);
   set_wc(1,8);
   set_large_wc(3,4);
   set_type("pierce");
   set_prof_type("fork");
   set_weapon_speed(7);
   set_weapon_prof("martial");
}
