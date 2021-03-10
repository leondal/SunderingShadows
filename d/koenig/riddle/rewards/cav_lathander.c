//cav_lathander.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("lathander lance");
	set_id(({ "lance", "golden lance" }));
	set_short("%^YELLOW%^Lance of the %^MAGENTA%^Morning Light%^RESET%^");
	set_obvious_short("A golden slender lance");
	set_long(
@AVATAR
%^YELLOW%^This lance is cast with pure gold. Though it is a lance, this weapon almost seems to look more like a long spear. The golden shaft of the lance is set with an large %^MAGENTA%^rose quartz%^YELLOW%^ that has been shaped into a fine point. Small %^RED%^rubies%^YELLOW%^ are encrust the golden casing for the %^MAGENTA%^rose quartz%^YELLOW%^ tip. 
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Lathander used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^MAGENTA%^The rose quartz tip of the lance sheds a "+
          "brilliant rosy glow as you pierce "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^MAGENTA%^The rose quartz tip of "+ETOQCN+"'s "+
          "lance casts a brilliant rosy glow that burns you!");
       tell_room(EETO,"%^BOLD%^%^MAGENTA%^The rose quartz tip of "+ETOQCN+"'s lance "+
          "casts a brilliant rosy glow as it pierces "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
