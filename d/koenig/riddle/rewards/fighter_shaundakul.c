//fighter_shaundakul.c - Reward for the Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/scimitar";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("windwalker's scimitar");
   set_id(({"windwalker's scimitar","scimitar","sword","steel scimitar"}));
   set_obvious_short("%^RESET%^%^CYAN%^A blue-gray tinted steel scimitar%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Wi%^MAGENTA%^n%^CYAN%^dwal%^MAGENTA%^k%^CYAN%^er"+
		"'s Sc%^MAGENTA%^i%^CYAN%^m%^MAGENTA%^i%^CYAN%^tar%^RESET%^");
   set_long(
@CYTHERA
%^RESET%^Forged from %^CYAN%^blue-gray%^RESET%^ tinted steel, this curved sword is known as a scimitar.  The thin but wide blade of the sword has been sharpened to a fine point, making it quite deadly.  Up the length of the blade, rippling lines have been etched into the steel and painted a %^MAGENTA%^deep purple%^RESET%^ color.  The hiltless scimitar is set on a heavy %^CYAN%^steel%^RESET%^ pommel, to counter balance the weight of the blade.  A resting%^BOLD%^%^BLACK%^ hawk's %^RESET%^claws is placed on a sphere of %^MAGENTA%^purple jasper%^RESET%^ to give the scimitar a final touch of ornamentation.
CYTHERA
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CYTHERA
The Windwalker Scimitar was often used by a small group of mercenaries devoted to Shaundakul.  The Windwalker Warriors hired themselves out to protect caravans, merchants and to accompany adventures to dangerous locations.  Well known for their exotic style of fighting the Windwalker Warriors were known as 'Whirling Dervishes' when they engaged in battle.  Their fighting style focused more on speed than brute strength.  To find one of their scimitars is a rare and priceless treasure for any follower of Sha
CYTHERA
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Shaundakul leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The scimitar refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the scimitar.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
       tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the blessings of Shaundakul as you wield the scimitar.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
      if(!random(8)) {
      tell_object(ETO,"%^CYAN%^With a burst of speed, you quickly slash "+
		"your scimitar through "+targ->QCN+"!");
      tell_object(targ,"%^CYAN%^With a burst of speed "+ETOQCN+" quickly"+
		" slashes "+ETO->QP+" scimitar through you!");
     tell_room(EETO,"%^CYAN%^With a burst of speed "+ETOQCN+" quickly"+
		" slashes "+ETO->QP+" scimitar through "+targ->QCN+"!",({ETO,targ}));
      targ->do_damage("torso",random(5)+6);
      return 1;
   }
}

void init(){
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}
