//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit MONSTER;
object targ;
int st = targ->query_stats("strength");
void create(){
    ::create();
    set_id(({"dragonne"}));
    set_name("Dragonne");
    set_short("A vicious Dragonne");
    set_long(
   	"The Dragonne is a combination of a lion and a brass dragon. The "+
    	"beast is covered in thick brass scales and its mane is made of a "+
	"thick coarse hair. It's wings are a dull brass color and stretch "+
 	"from the creatures shoulders."
    );
    set_body_type("dragon");
    set_race("dragonne");
    set_gender("male");
    set_size(2);
    set_hd(9,18);
    set_hp(100);
    set_exp(5500);
    set_overall_ac(3);
    set("aggressive",15);
    add_money("gold",random(100)+200);
    add_money("silver",random(50)+400);
    set_funcs(({"roar"}));
    set_func_chance(25);
}
void roar(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Dragonne roars terribly draining the strength from you!");
	tell_room(ETO,"%^BOLD%^BLUE%^The Dragonne roars terribly draining the strength from "+targ->query_cap_name()+"!",targ);
	if(targ->query_stats("strength") > 5){
	    targ->add_stat_bonus("strength",-5);
	    call_out("effect_time",50,TP);
	    return 1;
	}
    }
    tell_object(targ,"%^BOLD%^BLUE%^The Dragonne roars terribly, shaking you up momentarily!");
    tell_room(ETO,"%^BOLD%^BLUE%^The Dragonne roars terribly, shaking up "+targ->query_cap_name()+" momentarily!",targ);
    return 1;
}
void effect_time(object targ){
    tell_object(targ,"You feel your strength return.");
    targ->add_stat_bonus("strength",5);
    return 1;
}
