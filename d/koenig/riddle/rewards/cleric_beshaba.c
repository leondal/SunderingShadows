//cleric_beshaba.c - Reward for the Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit CLERICWEAPON;

int OWNED;
string owner;

void create(){
   ::create();
   set_name("whip of woe");
   set_id(({"beshaba weapon","whip of woe","red leather whip","whip","woe whip"}));
   set_obvious_short("%^BOLD%^%^RED%^A bright red leather whip%^RESET%^");
   set_short("%^BOLD%^%^RED%^Whip of %^BOLD%^%^BLACK%^W%^BOLD%^"+
	"%^MAGENTA%^o%^BOLD%^%^BLACK%^e%^RESET%^");
   set_long(
@CYTHERA
Strips of %^BOLD%^%^RED%^bright red%^RESET%^ leather have been braided tightly to form this whip.  Interwoven into the leather strips are %^BOLD%^%^WHITE%^metallic %^BOLD%^%^BLACK%^black%^RESET%^ and %^BOLD%^%^MAGENTA%^mauve%^RESET%^ threads, adding strength to the leather.  The tip of the whip has been closed off with a %^BLUE%^cold iron%^RESET%^ cap.  Stylized to look like the tail of a rat, the steel cap provides added weight to the whip.  A motley array of%^BOLD%^%^MAGENTA%^ mauve%^RESET%^, %^BOLD%^%^BLACK%^black%^RESET%^, and %^BOLD%^%^RED%^bright red%^RESET%^ linen strips cover the handle of the whip.
CYTHERA
   );
    if(TO->query_property("enchantment")< 2){
       set_property("enchantment",2);
    }
   set_lore(
@CYTHERA
The Whip of Woe is a special weapon reserved only for the priests of Beshaba.  Stylized in a chaotic motley of colors, the brightly colored whip is on that tends to strike fear into the heart of folks, for they claim that the whip itself is cursed with the misfortunes of Lady Doom.  Priests of Beshaba typically train in how to use the whip in order to strike misfortune into the lives of any they meet.
CYTHERA
   );
   set_property("lore difficulty",12);
   set_weight(2);
   set_size(2);
   set_value(0);
   set_wc(1,2);
   set_large_wc(1,2);
   set_type("lash");
   set_prof_type("whip");
   set_weapon_speed(8);
   set_wield((:TO,"wield_me":));
   set_unwield("You feel the strength of Beshaba leave you as you sheath your weapon.");
   set_hit((:TO,"hit_me":));
}

int wield_me(string str){
        if((string)TPQN != owner) {
                tell_object(ETO,"%^BOLD%^%^RED%^The whip refuses your hand!  You are not its master!");
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
   tell_object(ETO,"%^BOLD%^%^MAGENTA%^You snap the tip of your whip"+
	" across "+targ->QCN+"'s flesh!");
   tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" snaps the tip of"+
		" "+ETO->QP+" whip across your flesh!");
   tell_room(EETO,""+ETOQCN+" snaps the tip of "+ETO->QP+" whip across"+
		" "+targ->QCN+"'s flesh!",({ETO,targ}));
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You snap the rat tail shaped"+
		" cap of the whip into one of "+targ->QCN+"'s tender spots!");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+" snaps the rat tail"+
		" shaped cap of "+ETO->QP+" whip into one of your tender spots!");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" snaps the rat tail shaped"+
		" cap of "+ETO->QP+" whip into one of "+targ->QCN+"'s tender"+
		" spots!",({ETO,targ}));
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
