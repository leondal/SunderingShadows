//created by Styx 5/19/01 for Newbietown to cover large spears (made it between the Shadow mspear and the Tonerra large spear)

inherit "/std/weapon";

create() {
    ::create();
   	set_id(({ "spear","large spear" }));
   	set_name("large spear");
   	set_short("A large spear");
  	set_long("This is a long spear and will take two"+
		" hands for most to wield.  The head is "+
		"fashioned from metal into a sharp point "+
                "much like an arrow's head.  It is attached "+
		"solidly to a hard wooden shaft that is over"+
		" two inches in diameter to withstand heavy "+
		"battles.  The long shaft provides for strong "+
		"thrust and good leverage.");
   set_weight(6);
   set_size(3);
   set("value", 10);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("slashing");
   set_prof_type("spear");
   set_weapon_speed(10);
   set_weapon_prof("simple");
   set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
}
