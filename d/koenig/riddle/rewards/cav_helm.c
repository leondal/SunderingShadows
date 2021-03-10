//cav_helm.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("helm lance");
	set_id(({ "lance", "steel lance" }));
	set_short("%^RESET%^Lance of the %^BLUE%^Watchful Eye%^RESET%^");
	set_obvious_short("A large steel lance");
	set_long(
@AVATAR
This large lance is forged from cold steel, giving it a slight blue cast. The steel has been etched with a a spiral pattern all the way to its tip. The spiral pattern has thus been further engraved with graceful swirls in a rich decorative pattern. Painted with enamel onto the metal in regular intervals along the length of the spiral is the image of an %^BLUE%^piercing blue eye%^RESET%^.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Helm used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^You sunder the lance into "+targ->QCN+" as the lance "+
          "provides you a quick extra burst of strength to the attack");
       tell_object(targ,"%^BOLD%^"+ETOQCN+" sunders "+ETO->QP+" lance into you for "+
          "a brutal blow that almost knocks you flat.");
       tell_room(EETO,"%^BOLD%^"+ETOQCN+" sunders "+ETO->QP+" lance into "+targ->QCN+""+
          " for a brutal blow.!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
