//Coded by Bane//
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"wisp","will","Will o' wisp"}));
    set_name("Will o' wisp");
    set_short("A Will o' wisp");
    set_long(
	"The Will o' wisp is merely a little ball of glowing light that "+
	"darts back and forth in the air.  It is only a few inches long "+
	"yet they are rumored to be fearsome opponents with powerful "+
	"abilities."
    );
    set_body_type("wisp");
    set_race("will o' wisp");
    set_gender("male");
    set_size(1);
    set_hd(15,30);
    set_hp(150);
    set_alignment(9);
    set_overall_ac(-8);
    set_exp(8000);
    set("aggressive",21);
    set_mob_magic_resistance("average");
    set_property("strength","fire");
    set_property("swarm",1);
    set_funcs(({"attack"}));
    set_func_chance(102);
}
void attack(object targ){
    int ac, roll, thac;
    ac = targ->query_ac();
    roll = random(20)+1;
    thac = "/daemon/bonus_d"->thaco(TP->query_level(),TP->query_class());
    if(thac - ac <= roll){
	tell_object(targ,"%^BOLD%^RED%^The Will o' wisp shocks you with a jolt of electricity!");
	tell_room(ETO,"%^BOLD%^RED%^The Will o' wisp shocks "+targ->query_cap_name()+" with a jolt of electricity!",targ);
    targ->cause_typed_damage(targ, targ->return_target_limb(), roll_dice(5, 10), "electricity");
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Will o' wisp misses you with a bolt of electricity!");
    tell_room(ETO,"%^BOLD%^RED%^The Will o' wisp misses "+targ->query_cap_name()+" with a bolt of electricity!",targ);
    return 1;
}
