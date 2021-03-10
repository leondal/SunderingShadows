//cav_tyr.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("tyr lance");
	set_id(({ "lance", "blue steel lance" }));
	set_short("%^BOLD%^%^BLUE%^Lance of %^RESET%^%^MAGENTA%^Vengeance%^RESET%^");
	set_obvious_short("A blue steel large lance");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This blue steel large lance takes the shape of a typical lance of it's size. The conical shaped lance tapers off to a fine point that looks very sharp. %^RESET%^%^MAGENTA%^Dusky purple%^BOLD%^%^BLUE%^ enamel has been used to paint a horizontal stripe pattern around the lance. The pommel of the lance takes the shape of a war hammer, a symbolic image of the war hammer that Tyr uses in battle.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Tyr used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the strength of vengeance call "+
          "out to you as you tear into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" gives you a stern look, as if "+
          "able to judge your deeds as "+ETO->QS+" tears into you!");
       tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" gets a fierce determination in "+
          ""+ETO->QP+" eyes as "+ETO->QS+" tears into "+targ->QCN+" with "+
          ""+ETO->QP+" lance!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
