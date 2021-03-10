//cav_default.c - Coded by Circe.  For Riddle Quest
#include <std.h>
#include "../../nereid.h"
inherit "/d/common/obj/weapon/hhlance";

int OWNED;
string owner;

void create(){
	::create();
	set_long(
@CIRCE
This is a heavy horse lance. It is an effective weapon with which to charge an opponent.  This particular lance is made of decorative bronze reinforced with steel.  It has a nice, balanced weight, and seems to rest lightly in the wielder's hands.
CIRCE
	);
    set_property("enchantment",2);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
      set_value(0);
    set_lore("The origin of this lance is unknown, though some "+
       "sages speculate that the lance might be tied to the stories "+
       "of Marianna, an ancient knight who was betrothed to "+
       "the archmage Sulafelde.  The sages are sure this is not "+
       "the fabled Lance of the Noble Heart that was eventually "+
       "gifted to her, but they believe that the mage crafted "+
       "many prototypes such as this one as he was working on the "+
       "enchantment.");
    set_property("lore difficulty",12);
      set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}

int wield_func() {
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The lance refuses your hand!  You are not its master!");
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
        tell_object(ETO,"%^BOLD%^You grasp the lance and feel ready for battle.");
        return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" lowers the lance.",ETO);
	tell_object(ETO,"%^BOLD%^You lower the lance.");
	ETO->add_attack_bonus(-1);
	ETO->add_damage_bonus(-1);
	return 1;
}
int hit_func(object targ){
   ::check(targ);
	if(random(1000) < 300){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" charges with "+
         "force, driving the lance into "+targ->QCN+"!",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You charge with force, driving the lance into "+
         ""+targ->QCN+"!");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" charges with force, driving the "+
         "lance into you!");
		return roll_dice(2,4)+3;	}
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}
