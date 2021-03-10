//cav_torm.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("torm lance");
	set_id(({ "lance", "adamantium lance" }));
	set_short("%^BOLD%^%^WHITE%^Lance of the %^YELLOW%^Lion's Heart%^RESET%^");
	set_obvious_short("A medium adamantium lance");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This has to be one of the oddest lances that you have seen. The medium lance is made of pure adamantium, polished to a pristine gloss. The lance itself is in the shape of a pouncing lion. The lion has been carved with great detail, giving a sense almost as if the beast is alive. Golden filigree has been used to further bring life to the lion shaped lance.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Torm used by his cavaliers and knights in battles against the enemies of his church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^YELLOW%^The lion shaped lance releases an inspiring roar that "+
          "fills you with a quick burst of strength, allowing you to spear "+targ->QCN+"!");
       tell_object(targ,"%^YELLOW%^A lion's roar rips through the area, seeming to drive "+
          ""+ETOQCN+" on as "+ETO->QS+" tears into you with brutal strength!");
       tell_room(EETO,"%^YELLOW%^A lion's roar rips through the area, seeming to drive "+
          ""+ETOQCN+" on with "+ETO->QP+" attack against "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
