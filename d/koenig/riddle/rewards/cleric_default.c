//cleric_default.c - Coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

void create(){
	::create();
	set_name("cleric weapon");
	set_id(({ "mace","heavy mace" }));
	set_short("A heavy mace");
	set_long(
@CIRCE
This is a blunt striking weapon, suitable for fighting on foot or from
horseback.  The head of the mace is a single piece of cast iron, and the
handle is made from the heartwood of an oak tree.  Intricate carvings 
run the length of the handle, and the mace seems finely crafted.
CIRCE
	);
	set_weight(10);
	set_type("bludgeoning");
	set_prof_type("mace");
      set_weapon_speed(6);
	set_size(2);
	set_wc(1,6);
	set_large_wc(1,6);
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func() {
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The weapon refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the weapon.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
	  ETO->add_attack_bonus(1);
   	  ETO->add_damage_bonus(1);
        tell_object(ETO,"%^BOLD%^You grasp the handle of the mace and feel ready for battle.");
        return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" lowers the mace.",ETO);
	tell_object(ETO,"%^CYAN%^You lower the mace.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" swings the mace "+
         "around, hitting "+targ->QCN+" stoutly on the head.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You swing the mace around, hitting "+targ->QCN+" "+
         "stoutly on the head.");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" swings hte mace around, hitting you "+
         "stoutly on the head.");
		return roll_dice(2,4)+3;	}
}