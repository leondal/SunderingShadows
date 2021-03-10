//cav_shar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("shar lance");
	set_id(({ "lance", "black lance" }));
	set_short("%^BOLD%^%^BLACK%^Lance of the Night's Shadow%^RESET%^");
	set_obvious_short("A slender black lance");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This slender lance looks more like a pole-arm of sorts, or maybe a spear. The lance is made of actually solidified darkness, harden by some unknown means. A faint %^RESET%^%^MAGENTA%^amethyst%^BOLD%^%^BLACK%^ glow is shed from the lance, though not bright enough to cast any light. The slender lance tapers to a sharp point that looks as if it could pierce the daylight itself with its inky black darkness.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Shar used by her cavaliers and knights in battles against the enemies of her church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^BLACK%^A burst of black negative energy bursts "+
          "forth from the lance, piercing through "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^BLACK%^A burst of black negative energy issues "+
          "forth from "+ETOQCN+"'s lance, tearing into your soul!");
       tell_room(EETO,"%^BOLD%^%^BLACK%^A burst of black energy bursts forth from "+
          ""+ETOQCN+"'s lance, piercing through "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
