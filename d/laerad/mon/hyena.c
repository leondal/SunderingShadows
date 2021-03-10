//Updated description and mechanics - Octothorpe 11/4/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"hyena","dire hyena","dire","laeradmon"}));
    set_name("dire hyena");
    set_short("%^RESET%^%^ORANGE%^v%^BOLD%^%^BLACK%^i%^RESET%^"+
	   "%^ORANGE%^c%^BOLD%^%^BLACK%^iou%^RESET%^%^ORANGE%^s d%^BOLD%^"+
	   "%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e %^RESET%^"+
	   "%^ORANGE%^h%^BOLD%^%^BLACK%^ye%^RESET%^%^ORANGE%^n%^BOLD%^"+
	   "%^BLACK%^a%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This specimen is nearly twice the "+
	   "size of a normal hyena.  Reaching nearly four feet high at "+
	   "the shoulder, this desert scavenger is certainly a threat.  "+
	   "It is covered in tan hair, which is sp%^BOLD%^%^BLACK%^o%^RESET%^"+
	   "%^ORANGE%^tt%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d a "+
	   "light %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^ck"+
	   "%^RESET%^%^ORANGE%^.  An exposed, %^BOLD%^%^WHITE%^bony "+
	   "%^RESET%^%^ORANGE%^ridge runs down the back of the hyena, "+
	   "which adds to its grotesque appearance.%^RESET%^");
    set_body_type("quadruped");
    set_race("hyena");
    set_gender("male");
    set_size(3);
    set_alignment(6);   // was 5
    set_hd(15,10);	// was 5,10
    set_max_level(20);  // was 15
    set_hp(150);       // was 50
    set_exp(9000);
    set_overall_ac(-3);
	set_stats("strength",21);
	set_stats("dexterity",15);
	set_stats("constitution",19);
	set_stats("intelligence",2);
	set_stats("wisdom",13);
	set_stats("charisma",5);
    set("aggressive",19);
    add_limb("teeth","head", 0, 0, 0);
    set_attack_limbs(({ "teeth" }));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(3,6);
    set_moving(1);
	set_speed(75);
	set_nogo(({"/d/laerad/wasteland/waste1"}));		
}
