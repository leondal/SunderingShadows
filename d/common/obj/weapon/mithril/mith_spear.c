inherit "/d/common/obj/weapon/mspear.c";

create() {
  ::create();
  set_id(({ "spear","medium spear" }));
  set_name("medium spear");
  set_short("A medium mithril-tipped spear");
  set_long("This is a medium sized stabbing spear.  It's short enough for normal size humanoids to use while still retaining the use of a shield.  The business end is forged from mithril and looks very sharp.");
  set_property("enchantment", 1);
  set_weight(4);
  set_size(2);
  set("value", 310);
  set_wc(1,6);
  set_large_wc(1,8);
  set_type("piercing");
  set_prof_type("medium spear");
  set_weapon_speed(6);
  set_weapon_prof("simple");
}
