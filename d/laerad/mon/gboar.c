//Updated description and mechanics - Octothorpe 11/1/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"boar","dire boar","dire","laeradmon","animal"}));
    set_name("dire boar");
    set_short("%^RESET%^%^ORANGE%^menancing dire boar%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This massive boar stands about "+
	   "six feet tall at the shoulder, and is covered in a coat of "+
	   "coarse, brown hair.  It is an exact likeness of a normal boar, "+
	   "except for the %^BOLD%^%^WHITE%^bony %^RESET%^%^ORANGE%^ridges "+
	   "found running up its back to its head.  Two %^RED%^blood"+
	   "%^ORANGE%^-soaked tusks erupt out of the dire boar's mouth "+
	   "in an menancing manner, and prove that this is a dangerous "+
	   "foe indeed.%^RESET%^");
    set_race("dire boar");
    set_body_type("equine");
    set_gender("male");
    set_size(3);
    set_hd(14,9);	// was 7,9
    set_hp(185);   	// was 165
    set_max_level(20);	// was 15
    set_attack_bonus(2); // was 1
    set_exp(9000);
    set_overall_ac(-5);  // was 5
    set("aggressive",19); // was 15
    set_attack_limbs(({"head", "right fore hoof","left fore hoof"}));
    set_attacks_num(3);	  // was 1
    set_base_damage_type("bludgeoning");
    set_damage(3,6);
	set_moving(1);
	set_speed(45);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
    set_funcs(({"charge"}));
    set_func_chance(20);
}

void charge(object targ){
    if(!random(3)){
	   tell_object(targ,"%^BOLD%^RED%^The dire boar charges at you "+
	      "and impales you on its tusks!%^RESET%^");
	   tell_room(ETO,"%^BOLD%^RED%^The dire boar charges at "+
	      ""+targ->QCN+" and impales "+targ->QO+" on its tusks!"+
		  "%^RESET%^",targ);
	   add_attack_bonus(query_attack_bonus()+1);
	   targ->do_damage("torso",roll_dice(4,5));
	return;
    }
    tell_object(targ,"%^BOLD%^RED%^The dire boar charges at you and "+
	   "runs right past!%^RESET%^");
    tell_room(ETO,"%^BOLD%^RED%^The dire boar charges at "+
	   ""+targ->QCN+", but it runs right past!%^RESET%^",targ);
    return;
}
