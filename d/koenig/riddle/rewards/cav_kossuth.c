//cav_kossuth.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("kossuth lance");
	set_id(({ "lance", "gold lance" }));
	set_short("%^YELLOW%^Lance of the %^RESET%^%^RED%^Blazing %^ORANGE%^Inferno%^RESET%^");
	set_obvious_short("A gold medium lance");
	set_long(
@AVATAR
%^YELLOW%^This medium lance is made of gold. The thick lance is slightly bigger than most lances you have seen, perhaps due to the gold? A combination of %^RED%^reddish gold%^YELLOW%^ and yellow gold are used to make this lance, set into a flame like pattern. Rich flame dance gems and fire opal are set in yellow gold setting along the length of the lance.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Kossuth used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^RED%^The gems of the lance erupt in a fiery burst as "+
          "you pierce "+targ->QCN+"!");
       tell_object(targ,"%^RED%^You feel yourself on the receiving end of a "+
          "fiery blaze from "+ETOQCN+"'s lance!");
       tell_room(EETO,"%^RED%^The lance wielded by "+ETOQCN+" bursts in a fiery "+
          "blaze at it pierces "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
