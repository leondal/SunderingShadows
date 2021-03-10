inherit "/std/weapon";

create() {
   ::create();
   set_id(({ "warhammer","hammer","war hammer" }));
   set_name("warhammer");
   set_short("A mithril war hammer");
   set_long("This is a heavy iron war hammer forged of solid mithril.  It has a long, thick head on one side, counterbalanced on the other by a heavy spike.  It's definitely got its uses if you want to try to crack someone out of their shell.");
	set_property("enchantment", 1);
   set_weight(6);
   set_size(2);
   set("value", 302);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("bludgeoning");
   set_prof_type("medium hammer");
   set_weapon_speed(4);
   set_weapon_prof("martial");
}
