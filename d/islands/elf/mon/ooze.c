#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;
//todo, make it break into two oozes when using slashing weapons.
void create(){
        ::create();
        
        set_name("gray ooze");
        set_id(({"monster","ooze","gray ooze"}));
        set_short("%^BOLD%^%^BLACK%^A large gray ooze%^RESET%^");
        set_long(" This is a gray ooze.  It is an extremely"+
		" slow blob that seeks to dissolve anything in its path."+
		"  It is quite large and capable of enveloping a person.");
        set_hd(9,3);
        set_hp(300+random(200));
        set_funcs(({"my_hit"}));
        set_func_chance(102);
        set_overall_ac(3);
        set_property("strength","electricity");
        set("aggressive",25);
        set_race("ooze");
        add_limb("body","body",80,0,3);
		new("/d/antioch/valley/obj/gem")->move(TO);
		set_new_exp(30,"very low");
        set_max_level(35);
		set_base_damage_type("acid");
 
}

void my_hit(object targ){
 object ooze;       
    if(!objectp(targ)) return;
	if(!objectp(TO))   return;
                tell_room(ETO,"%^BOLD%^The gray ooze touches "
				+targ->QCN+"!",targ);
                tell_object(targ,"%^BOLD%^The ooze touches you!"+
				" Its acids eats at you!\n");
				targ->cause_typed_damage(targ,0,roll_dice(5,10),"acid");
                //trying to cut back on chain stun some more
                if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-30) && targ->query_paralyzed() == 0){//easier because perma stun
                        targ->set_paralyzed(40+random(30),"You are paralyzed in the gray ooze.");
                        tell_object(targ,"%^BOLD%^You are paralyzed by the ooze's touch!\n");
                        tell_object(targ,"%^BOLD%^Its acid eats at you.\n");
                        tell_room(ETO,"%^BOLD%^"+targ->QCN+
						" is overwhelmed by the ooze.",targ);
				if(!present("oozeobj",targ)) {
				          ooze = new(OBJ"oozeobj");
                          ooze->move(targ);
						  call_other(ooze, "hurt",targ);

				          }	

                }
         else {
                tell_room(ETO,"The ooze misses "
				+targ->QCN+"!",targ);
                tell_object(targ,"The ooze misses you.\n");
        }
 return;
}



