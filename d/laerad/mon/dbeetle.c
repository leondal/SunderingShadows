//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"beetle","death beetle","Death Watch Beetle","animal"}));
    set_name("Death Watch Beetle");
    set_short("A Death Watch Beetle");
    set_long(
	"This horrible beetle is the most feared of its kind. "+
	"The large creature is 5 feet in length and is jet black "+
	"in color except for a single patch of white on the back "+
	"of its carapace in the shape of a human skull."
    );
    set_body_type("insectoid");
    set_race("beetle");
    set_gender("male");
    set_size(2);
    set_hd(22,18);
    set_hp(225);
    set_alignment(5);
    set_overall_ac(2);
    set("aggressive",19);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(3,4);
    set_funcs(({"rattle"}));
    set_func_chance(102);
}
void rattle(){
    object *vars;
    int i;
    vars = all_living(ETO);
    for(i=0;i<sizeof(vars);i++){
    if(vars[i] == TO) continue;
    	tell_object(vars[i],"%^BOLD%^RED%^The Death Beetle vibrates its carapace emitting a screeching noise!");
        if(!vars[i]->will_save(10) && !FEATS_D->usable_feats(vars[i], "death watch")){
	    tell_object(vars[i],"%^BOLD%^RED%^\nYour heart stops.");
       set_property("magic",1);
      vars[i]->do_damage("torso",200);
       remove_property("magic");
	    set_func_chance(0);
	}
   else {
     	tell_object(vars[i],"%^BOLD%^RED%^\nYour heart skips a beat.");
	vars[i]->do_damage("torso",roll_dice(5,4));
	set_func_chance(0);
    }
}
            call_out("reset_rattle",250);
}
void reset_rattle(){set_func_chance(102);}
