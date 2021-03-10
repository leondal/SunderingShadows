//Coded by Bane//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"ghoul","disfigured","disfigured ghoul"}));
    set_name("ghoul");
    set_short("A disfigured Ghoul");
    set_long(
	"This creature is vaguely recognizable as once having been "+
	"human, but has become horribly disfigured by its "+
	"change to a ghoul.  Its tongue is long and thick, "+
	"its teeth are long and sharp, and its nails are strong "+
	"and look like claws."
    );
    set_body_type("human");
    set_race("ghoul");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_class("fighter");
    set_mlevel("fighter",6);
    set_hd(5,5);
    set_hp(65);
    set_exp(450);
    set_overall_ac(4);
    set("aggressive",19);
    set_stats("strength",16);
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("slashing");
    set_attacks_num(3);
    set_damage(1,6);
    set_attack_bonus(5);
    set_hit_funcs( (["right hand":(:TO,"paralyze":),"left hand":(:TO,"paralyze":)]) );
}
void paralyze(object targ){
    if(targ->query_paralyzed()) return 1;
    if(!SAVING_D->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Ghouls touch paralyzes you!");
	tell_room(ETO,"%^BOLD%^BLUE%^"+targ->query_cap_name()+" stiffens at the touch of the Ghoul!",targ);
	targ->set_paralyzed(random(40)+20,"You are frozen stiff.");
	return 1;
    }
}
