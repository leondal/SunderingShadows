//cav_mystra.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("mystra lance");
	set_id(({ "lance", "ethereal lance" }));
	set_short("%^BOLD%^%^CYAN%^Forcelance%^RESET%^");
	set_obvious_short("An ethereal lance");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This lance is actually composed of an ethereal force that sheds a soft light blue glow. Only the outline of the lance can really be seen, the rest seems to be made of an almost invisible force shaped by magic. A %^WHITE%^silver%^CYAN%^ pommel comes off the end of the lance, allowing the wielder something tangible to grasp onto. Carved into the pommel is the image of seven stars in a circle, with a red mist flowing from the center.
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Mystra used by her cavaliers and knights in battles against the enemies of her church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
    set_property("lore difficulty",12);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^CYAN%^The lance fires off three darts of pure "+
          "force, that slam into "+targ->QCN+"!");
       tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s lance fires off three darts "+
          "of pure force that tear into you!");
       tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s lance fires off three darts "+
          "of pure force, that slam into "+targ->QCN+"!",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
