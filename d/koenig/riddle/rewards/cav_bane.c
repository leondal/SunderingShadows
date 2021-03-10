//cav_bane.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("bane lance");
	set_id(({ "lance", "green lance" }));
	set_short("%^BOLD%^%^GREEN%^ Lance of the %^BOLD%^%^BLACK%^Black Hand%^RESET%^");
	set_obvious_short("A medium green lance");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^This lance has been colored a rich emerald green color, making the metal hard to determine exactly what it is. The slender medium lance is polished to a bright shimmer, further adding to the majesty of such a weapon. The tip of the lance is curious though, as a %^BLACK%^black hand%^GREEN%^ made of jet has been set in place of the usual point. The hand is clenched into a tight fist and looks to be wearing a spiked gauntlet.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Bane used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^GREEN%^You can't help but get grin as the black "+
          "gauntleted hand tears into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" gives you a cruel smirk as "+
          "the spiked gauntlet fist on "+ETO->QP+" lance tears into you.");
       tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" smirks to "+ETO->QO+"self as "+
          ""+ETO->QP+" lance tears into "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
