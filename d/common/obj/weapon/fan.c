inherit "/std/weapon";

void create() {
    	::create();
   	set_id(({ "steel fan","fan"}));
   	set_name("steel fan");
   	set_short("A steel fan");
   	set_long("An unusual weapon that has been adopted by "+
		"some is the iron fan.  The fan is composed of "+
		"thick steel outer ribs that protect the fan "+
		"when closed.  When the fan is opened, sharpened"+
		" tips of thinner steel ribbing are coved with "+
		"lacquered paper.  The steel fan is a delicate weapon"+
		" to use in battle, one often reserved for monks or "+
		"females.");
   	set_type("piercing");
   	set_prof_type("fan");
    set_weapon_prof("exotic");
   	set_weight(3);
   	set_size(1);
    set_wc(1,6); //basically making this the waveblade from pathfinder - Odin
    set_weapon_speed(3);
    set_large_wc(1,6);
   	set_value(25);
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
