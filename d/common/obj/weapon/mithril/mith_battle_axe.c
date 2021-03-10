inherit "/std/weapon";

create() {
   ::create();
   set_id(({ "axe", "battle","battle axe" }));
   set_name("battle_axe");
   set_short("A mithril battle axe");
   set_long("This is a long heavy axe forged from mithril.  It has double blades opposing each other at the end of a sturdy oak handle that is also laced with mithril.");
	set_property("enchantment", 1);
   set_weight(7);
   set_size(2);
   set("value", 305);
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("slash");
	set_prof_type("medium axe");
   set_weapon_speed(7);
   set_weapon_prof("martial");
}
