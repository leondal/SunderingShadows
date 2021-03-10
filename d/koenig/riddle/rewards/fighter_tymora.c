//fighter_tymora.c - Reward for the Riddle Quest.  Circe 4/21/04
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/rapier";

int OWNED;
string owner;

void create(){
   ::create();
//   set_name("tymora weapon");
	set_id(({ "rapier", "lucky strike", "sword", "titanium rapier" }));
	set_short("%^BOLD%^%^WHITE%^Lu%^BLUE%^c%^WHITE%^ky %^BLUE%^St%^WHITE%^ri%^BLUE%^ke%^RESET%^");
	set_obvious_short("A titanium rapier");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This slender rapier is crafted out of pale titanium.  The metal has been treated in a way that there is an %^BLUE%^iri%^MAGENTA%^d%^BLUE%^e%^CYAN%^s%^BLUE%^c%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLUE%^nt blue%^WHITE%^ finish over the normally white titanium.   The slender rapier tapers down to a fine point, allowing for ease in piercing the target.  Engraved into the metal is a spiraling twisting geometrical pattern, circling around the blade all the way down to the tip.  Curved strips of %^BLUE%^blue%^WHITE%^ steel comes together to form the basket hilt of the rapier, allowing some protection to one's hand.  The hilt of this blade has a rippled texture to it, almost as if someone used a stack of silver coins.  At the end of the hilt of the blade, a rounded silver knob rests, with the image of a winking human female engraved into the metal.

AVATAR
	);
    if(TO->query_property("enchantment")< 2){
       remove_property("enchantment");
       set_property("enchantment",2);
    }
	set_lore(
@AVATAR
Lucky Strike is a rapier that was used by a famous swashbuckler Theredaran the Flop, a dandy of a man.  Theredaran always said his good luck was the reason for his many daring, some say insanse, chances he took.  There is a legend about Theredaran fighting a small band of Lovites on Deku with nothing but his sword and a serving tray to protect him, when they caught him in one of his numerous amorous relationships.

AVATAR
	);
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The rapier refuses your "+
                   "hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" screams"+
                " in pain as "+ETO->QS+" tries wield the rapier.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
	tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" wields the titanium "+
         "rapier and gives a roguish smirk",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You wrap your hand about the "+
         "rapier and can't help but get a feeling as if your %^WHITE%^"+
         "luck%^BLUE%^ is about to change");
        return 1;
}

int unwield_func(){
	tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" unwields the titanium "+
         "rapier with some trepidation.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You unwield the blade.  Hopefully "+
         "your good fortune will hold!");
	return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(8)) {
	tell_room(environment(query_wielded()),"%^BOLD%^%^BLUE%^"+ETOQCN+" "+
         "twists "+ETO->QP+" blade with a flourish and plants a lucky "+
         "strike onto "+targ->QCN+", causing "+targ->QO+" to cry out.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^What LUCK!  You manage to pierce "+
         ""+targ->QCN+" in a vulnerable spot!");
	tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" twists "+ETO->QP+" blade "+
         "with a flourish and plants a lucky strike into you.  OUCH, "+
         "how did "+ETO->QS+" mange to hit you there?!");
      targ->do_damage("torso",random(5)+6);
      return 1;
   }
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
