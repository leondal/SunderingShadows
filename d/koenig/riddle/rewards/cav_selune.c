//cav_selune.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("selune lance");
	set_id(({ "lance", "alabaster lance" }));
	set_short("%^BOLD%^%^WHITE%^Lance of the Shooting Stars%^RESET%^");
	set_obvious_short("An alabaster short lance");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This short lance is made up of alabaster, polished to a white sheen. The short lance is inlaid with crystal star shaped images that are filled with a silver liquid. The liquid seems to never harden, always retaining it's mutable quality. The tip of the lance is fashioned out of pure silver, further adding to the brilliant luster of the lance.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Selune used by her cavaliers and knights in battles against the enemies of her church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^WHITE%^The liquid in the crystal stars seems to "+
          "further push your attack along, allowing you to sunder into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" sunders into you with "+
          ""+ETO->QP+" brilliant white lance!");
       tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" sunders into "+targ->QCN+" with "+
          ""+ETO->QP+" brilliant white lance!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
