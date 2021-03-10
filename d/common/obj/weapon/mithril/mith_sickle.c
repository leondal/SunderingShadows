inherit "/std/weapon";

create() {
   ::create();
   set_id(({ "sickle" }));
   set_name("sickle");
   set_short("A mithril-bladed sickle");
   set_long("This short, heavy tool has a curved, almost semicircular, blade with the inside of the curve used most often to cut.  It doesn't look like a very effective weapon compared to things like a sword or even a scythe, but surprise is often the key.  The blade appears to be forged from mithril and looks quite sharp.");
	set_property("enchantment", 1);
   set_weight(3);
   set_size(1);
   set("value", 156);
   set_cointype("silver"); 
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("slash");
   set_prof_type("tool");
   set_weapon_speed(4);
   set_weapon_prof("simple");
}
