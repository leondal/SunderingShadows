//Coded by the one and only master of monsters...BANE//
// added laeradmon id and made a little tougher *Styx*  12/20/03

#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"cockatrice","Cockatrice", "laeradmon"}));
    set_name("Cockatrice");
    set_short("An eerie Cockatrice");
    set_long(
	"This repulsive hybrid of lizard, cock, and bat is about "+
	"the size of a large turkey.  It has the head and body "+
	"of a cock, with two bat-like wings and the long tail of a "+
	"lizard tipped with a few feathers.  Infamous for its ability "+
	"to turn living creatures to stone, most sane beings stay clear "+
	"of them."
    );
    set_body_type("fowl");
    set_race("cockatrice");
    set_gender("male");
    set_size(1);
    set_alignment(6);   // was 5
    set_hd(15,10);	// was 5,10
    set_max_level(20);  // was 15
    set_hp(150);	// was 50
    set_attack_bonus(1);
    set_exp(1800);
    set_overall_ac(5);
    set("aggressive",12);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(1,3);
    set_hit_funcs( (["head":(:TO,"stone":)]) );
    set_stats("strength",16);
    set_stats("dexterity",13);
    set_stats("intelligence",7);
    set_stats("wisdom",6);
    set_stats("constitution",8);
    set_stats("charisma",6);
}

int stone(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^RED%^The hit from the Cockatrice begins turning your flesh to stone!");
	tell_room(ETO,"%^BOLD%^RED%^The hit from the Cockatrice appears to be turning "+targ->query_cap_name()+"'s flesh to stone!",targ);
        set_property("magic",1);
        targ->add_hp(-200);
       set_property("magic", -1);  // was remove_property which shouldn't really be used
       return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^You resist the touch of the Cockatrice!");
    tell_room(ETO,"%^BOLD%^RED%^"+targ->query_cap_name()+" resists the touch of the Cockatrice!",targ);
    return 1;
}
