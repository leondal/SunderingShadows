inherit "/d/common/obj/weapon/shortsword.c";

create() {
   ::create();
   set_id(({ "sword", "short sword", "shortsword" }));
   set_name("shortsword");
   set_short("A mithril short sword");
   set_long("This short sword is a perfect weapon for some, a good backup weapon for others.  It's shorter than the average sword but that just makes it more manageable, while its sharp edge and point could never be counted completely out by an opponent.  This one is forged from mithril and looks very sharp.");
	set_property("enchantment", 1);
   set_weight(5);
   set_size(1);
   set("value", 310);
   set_wc(1,6);
   set_large_wc(1,8);
   set_type("slashing");
   set_weapon_speed(3);
   set_weapon_prof("martial");
}
