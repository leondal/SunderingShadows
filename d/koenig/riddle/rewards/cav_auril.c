//cav_auril.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("auril lance");
	set_id(({ "lance", "ice lance" }));
	set_short("%^BOLD%^%^CYAN%^Lance of the Winter's Piercing Chill%^RESET%^");
	set_obvious_short("A lance made of ice");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This medium-sized lance is actually made of pure ice!  The ice has been shaped into a fine point, with jagged ice crystals that look as sharp as steel. A cold haze always issues forth from this lance.  Though it is ice, it never seems to melt or change its size, always remaining a chilling cold.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Auril used by her cavaliers and knights in battles against the enemies of her church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^CYAN%^A blast of cold air hits your face from "+
          "the lance as it seems to get even colder before you pierce into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^CYAN%^A blast of cold air chills your very soul, "+
          "as "+ETOQCN+" pierces into you!");
       tell_room(EETO,"%^BOLD%^%^CYAN%^A blast of cold air hits your face as "+ETO->QCN+" "+
          "pierces into "+targ->QCN+", freezing "+targ->QP+" blood!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
