//fighter_beshaba.c - Reward for the Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit "/d/common/obj/weapon/mspear";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("doombringer's spear");
   set_id(({"doombringer's spear","spear","ebony wood spear","doom spear"}));
   set_obvious_short("%^BOLD%^%^BLACK%^An ebony wood spear%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^D%^RESET%^oo%^BOLD%^%^BLACK%^mbr%^RESET%^i"+
	"%^BOLD%^%^BLACK%^nger's S%^BOLD%^%^MAGENTA%^p%^BOLD%^%^BLACK%^e"+
	"%^BOLD%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^");
   set_long(
@CYTHERA
Rough and uneven %^BOLD%^%^BLACK%^ebony%^RESET%^ wood has been used to create the shaft of this spear.  The warped %^BOLD%^%^BLACK%^ebony%^RESET%^ wood bows and bends in various ways, giving the appearance that this spear is not very stable.  The raised grain of the %^BOLD%^%^BLACK%^ebony%^RESET%^ wood adds texture to the spear shaft.  Mounted onto the top of the shaft is a thin and narrow %^BOLD%^%^WHITE%^titanium%^RESET%^ blade.  The tapered spear head bears an uncanny resemblance to a rapier blade than any common spear head.  The surface of the %^BOLD%^%^WHITE%^titanium%^RESET%^ metal is crackled with %^BOLD%^%^MAGENTA%^mauve%^RESET%^ lines which resemble a broken egg shell.  
CYTHERA
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CYTHERA
The Doombringer's Spear was once seen as a very special weapon in the church of Beshaba.  The spear head is said to have been made from rapiers taken from followers of Tymora after bloody battles.  The rapiers are cursed numerous times with the misfortunes of Beshaba, erasing any  good fortunes that they might have once had.  The process is particularly harsh on the blade and creates the crackled mauve lines.  The spear head is then mounted onto a piece of ebony wood.  Only special fighters within Beshaba's church ever got the chance to use such a special weapon.
CYTHERA
   );
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Beshaba leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The spear refuses your hand!  You are not its master!");
                tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" screams"+
                " in pain as "+ETO->query_subjective()+" tries wield the whip dagger.",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(20)+10);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        tell_object(ETO,"%^BOLD%^You feel the blessings of Beshaba as you wield the whip.");
        return 1;
}

int hit_me(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
      if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You drive the tip of your "+
		"spear deep into "+targ->QCN+"'s gut!");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" drive the tip of"+
		" "+ETO->QP+" spear deep into your gut!");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" drives the tip of "+
		""+ETO->QP+"'s spear deep "+targ->QCN+"'s gut!",({ETO,targ}));
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
