#include <std.h>
inherit WEAPONLESS; 

void create() {
    :: create();
    set_name("golem");
    set_id(({
        "death golem","golem"
    }));
    set_short("%^RESET%^%^BOLD%^%^BLUE%^Death golem%^RESET%^");
    set_long(
        "The sixteen foot tall golem creature before you is made from "
	"a pure jet black stone substance. Two cold fiery blue eyes stare "
	"down at you. It's fists are clenched and it stands absolutly motionless."
    );
    set_level(27);
    set_hd(27,9);
    set_size(2);
    set_weight(50);
    set_attacks_num(4); 
    set_damage(4,6);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"})); 
set_overall_ac(-22);
    set_body_type("human");
    set_race("golem");
    set_class("fighter");
    set_guild_level("fighter",27);
    set_stats("strength",25);
    set_stats("constitution",25);
    set_stats("dexterity",25);
    set_stats("wisdom",25);
    set_stats("intelligence",25);
    set_stats("charisma",15);
    set_mob_magic_resistance("average");
    set_exp(45000);
   set_max_hp(350);
    set_max_level(36);
    set_hp(350);
    set_emotes(1,({
        "%^MAGENTA%^Death golem says: %^RESET%^None are allowed to pass!",
    }),0);	
    set_funcs(({"death"}));
    set_func_chance(30);
}
void death(object targ){
	message("environment",
	    "%^BLUE%^%^BOLD%^Death Golem chants the phrase of death!%^RESET%^"
,environment());
	tell_object(targ,
	    "%^RED%^%^BOLD%^Death golem gazes upon you!%^RESET%^"
	);
	tell_room(environment(targ),
	    "%^RED%^%^BOLD%^Death golem gazes upon "
	    +targ->query_cap_name()+"!%^RESET%^"
	,targ);
	if("/daemon/saving_d"->saving_throw(targ,"spell")) {
	    message("environment",
	        "%^RED%^%^BOLD%^For some reason the chanting is weak!%^RESET%^"
,environment());
            targ->do_damage("torso",random(100)+25);
            return 1;
	} else {
	    message("environment",
	        "%^RED%^%^BOLD%^The chant of death seizes it's foe and enforces "
	        "the calling!%^RESET%^"
,environment());
	    targ->do_damage("torso",random(200)+150);
	    return 1;
        }
} 
void set_paralyzed(int time,string message) {
    time = time/4;
      ::set_paralyzed(time,message);
    return 1;
}
