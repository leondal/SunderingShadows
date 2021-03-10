//Updated description and mechanics - Octothorpe 10/31/09
//Coded by the one and only master of monsters...BANE//

#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"rhino","dire rhino","dire","laeradmon"}));
    set_name("dire rhino");
    set_short("%^RESET%^st%^BOLD%^ou%^RESET%^t d%^BOLD%^i%^RESET%^"+
	   "r%^BOLD%^e %^RESET%^rh%^BOLD%^i%^RESET%^n%^BOLD%^o%^RESET%^");
    set_long("%^RESET%^This beast is an exceptional representative of a "+
	   "rhinoceros.  It reaches a height of eight feet at its "+
	   "shoulders, and a length of nearly twenty feet.  The rh%^BOLD%^"+
	   "i%^RESET%^n%^BOLD%^o%^RESET%^'s tough, gr%^BOLD%^e%^RESET%^y "+
	   "skin is complemented by a series of protruding %^BOLD%^bony "+
	   "%^RESET%^plates that serve as a nearly impenetrable armor.  "+
	   "Three large, serrated horns are found on the beast's snout "+
	   "and are capable of goring a giant.  Its mouth is perpetually "+
	   "locked into an enraged snarl, and leers with its dull %^RED%^"+
	   "red %^RESET%^eyes.");
    set_race("dire rhino");
    set_body_type("equine");  // changed from quadruped
    set_gender("male");
    set_size(3);
    set_hd(15,14);
    set_max_level(20); // was 15
    set_hp(194);
    set_attack_bonus(1);
    set_alignment(6);
    set_exp(12500);
    set_overall_ac(-4);  // was 4
    set("aggressive",22);
    set_attack_limbs(({"head", "right fore hoof", "left fore hoof"}));
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_damage(3,6);
    set_funcs(({"charge"}));
    set_func_chance(20);
    set_monster_feats(({"damage resistance","improved damage resistance"}));
    set_stats("strength",25);
    set_stats("dexterity",10);
    set_stats("intelligence",2);
    set_stats("wisdom",6);
    set_stats("constitution",21);
    set_stats("charisma",2);
	set_moving(1);
	set_speed(40);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
}
void charge(object targ){
    //int ac, roll;
    //ac=targ->query_ac();
    //roll=random(20);
    if(!random(3)){   //was roll > 9-ac
	   tell_object(targ,"%^BOLD%^RED%^The dire rhino charges at you "+
	      "and impales you on its horn!%^RESET%^");
	   tell_room(ETO,"%^BOLD%^RED%^The dire rhino charges at "+
	      ""+targ->QCN+" and impales "+targ->QO+" on its horn!"+
		  "%^RESET%^",targ);
	   add_attack_bonus(query_attack_bonus()+1);
	   targ->do_damage("torso",roll_dice(4,6));
	return;
    }
    tell_object(targ,"%^BOLD%^RED%^The dire rhino charges at you and "+
	   "runs right past!%^RESET%^");
    tell_room(ETO,"%^BOLD%^RED%^The dire rhino charges at "+
	   ""+targ->QCN+", but it runs right past!%^RESET%^",targ);
    return;
}
