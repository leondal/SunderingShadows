//created by Styx 5/19/01 from Shadow mspear.c for Newbietown to cover off size weapons for profs.

inherit "/std/weapon";

create() {
    ::create();
   	set_id(({ "spear","small spear" }));
   	set_name("small spear");
   	set_short("A small spear");
  	set_long("This is a small, one-handed stabbing "+
		"spear.  It's small enough for an off-hand "+
		"for normal size races or for small ones to "+
		"wield in one.  It almost looks as much like "+
		"an oversize crossbow bolt than a spear but the"+
		" shaft is thicker and sturdier to stand up to "+
		"repeated thrusts and being yanked back out in battle.");
   set_weight(3);
   set_size(1);
   set("value", 6);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("piercing");
   set_prof_type("spear");
   set_weapon_speed(5);
   set_weapon_prof("simple");
   set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
}
