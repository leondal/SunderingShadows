inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "handaxe", "axe" }));
   set_name("handaxe");
   set_short("A mithril hand axe");
   set_long("This single bladed axe has a head forged from mithril atop about a two foot handle suitable for wielding in one hand.  It looks like it could chop wood or enemies equally well.");
	set_property("enchantment", 1);
   set_weight(5);
   set_size(1);
   set("value", 306);
   set_wc(1,6);
   set_large_wc(1,4);
   set_type("slashing");
   set_prof_type("small axe");
   set_weapon_speed(4);
   set_weapon_prof("martial");
}
