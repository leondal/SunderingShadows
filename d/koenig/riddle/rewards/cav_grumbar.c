//cav_grumbar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("grumbar lance");
	set_id(({ "lance", "adamantium lance" }));
	set_short("%^RESET%^%^ORANGE%^Lance of the Fissure%^RESET%^");
	set_obvious_short("An adamantium lance");
	set_long(
@AVATAR
%^ORANGE%^Adamantium has been fashioned and forged into this large lance. The lance has an almost conical shape, wide at one end and narrowing down to a fine tapered point. Inbeded in the metal along the shaft of the lance are various %^YELLOW%^g%^RED%^e%^BLUE%^m%^WHITE%^s%^RESET%^%^ORANGE%^, precious and semi precious, giving the lance a rich glimmer. The hilt of the lance is made from solid gray granite.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Grumbar used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);

    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^ORANGE%^The gems on the lance seem to glimmer adding "+
          "the strength of the earth to your attack!");
       tell_object(targ,"%^ORANGE%^ "+ETOQCN+"'s lance sparkles with a dim "+
          "light as "+ETO->QS+" tears into you.");
       tell_room(EETO,"%^ORANGE%^"+ETOQCN+"'s lance sparkles with a "+
          "dim light as "+ETO->QS+" tears into "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
