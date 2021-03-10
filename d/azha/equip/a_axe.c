inherit "/d/common/obj/weapon/large_battle_axe";

create() {
    ::create();
   set_id(({ "axe", "battle","battle axe", "skullsplitter" }));
   set_name("battle axe");
   set_short("A %^BOLD%^large%^RESET%^ battle axe");
   set_property("enchantment", 1);
   set_long(
@AZHA
  This is a large, very deadly looking, two-headed battleaxe.
Although it appears to be well-worn, it also appears to be 
regularly sharpened and cared for by its owner.  No doubt this
axe has cracked open a few skulls in its time.
AZHA
   );
   set("read", "Skullsplitter");
   set_weight(10);
   set_size(2);
   set("value", 8);
   set_wc(1,9);
   set_large_wc(1,8);
   set_type("slash");
   set_prof_type("medium axe");
}
