//cav_loviatar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit NLANCE;

void create(){
	::create();
//	set_name("loviatar lance");
	set_id(({ "lance", "palladium lance" }));
	set_short("%^BOLD%^%^BLACK%^Pain's%^RED%^ B%^RESET%^%^RED%^l"+
         "%^BOLD%^iss%^RESET%^%^RED%^f%^BOLD%^ul %^BLACK%^B%^RESET%^"+
         "a%^BOLD%^%^BLACK%^rb%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A%^RED%^ barbed%^WHITE%^ "+
         "palladium %^BLACK%^lance%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Forged from tempered %^WHITE%^palladium%^BLACK%^ is this impressive lance.  Carved from %^RED%^garnet%^BLACK%^ is the impressive ornate hilt.  Faces of men, women, and children look to be pressed together, their mouths open to cry out some unheard screams.  Most of the faces look to be in pure anguish, but a few look as if they are enjoying the torment. The %^WHITE%^palladium%^BLACK%^ lance is mounted over the hilt, creating a protective sleeve for the wielder's hand.  The slender lance is light in weight all the way to it's deadly tip.  Ritualistic symbols scared into the metal, looking akin to exotic tattoos. The tip of the lance is inlaid with %^RED%^garnet%^BLACK%^ and %^WHITE%^snow-flake obsidian%^BLACK%^ triangular shapes.%^RESET%^
AVATAR
	);
	set_lore(
@AVATAR
This is a Holy Weapon of Loviatar used by her cavaliers and knights in battles against the enemies of her church and faith. Only the most dedicated warriors can ever hope to wield such a fine weapon, and those that do are proclaimed as heroes of the faith.
AVATAR
	);
}

int check(object targ) {
   ::check(targ);
    if(!objectp(ETO)) return 0;
    if(!objectp(targ)) return 0;
    if(!random(6)) {
       tell_object(ETO,"%^BOLD%^%^BLACK%^The hilt of the lance begins "+
          "to %^RED%^burn%^BLACK%^ and %^WHITE%^freeze%^BLACK%^ your "+
          "hand at the same time.  The %^WHITE%^tip%^BLACK%^ of the "+
          "lance springs open, the %^RED%^nine new barbs%^BLACK%^ "+
          "tearing into "+targ->QCN+", before it snaps shut to the "+
          "single point deep within "+targ->QO+"!%^RESET%^");
       tell_object(targ,"%^BOLD%^%^BLACK%^The tip of "+ETOQCN+"'s "+
          "lance springs open, just before it pierces your flesh.  "+
          "The single point becomes nine serrated barbs that sink "+
          "into your skin with a burning feeling.  A loud SNAP is "+
          "heard, as you can feel the lance close to a single point "+
          "again.... Was that your spleen?!");
       tell_room(EETO,"%^BOLD%^%^BLACK%^The tip of "+ETOQCN+"'s lance "+
          "springs open, creating %^RED%^nine new points %^BLACK%^"+
          "instead of one just before it pierces "+targ->QCN+".  A "+
          "swift %^WHITE%^SNAP%^BLACK%^ is heard, before "+ETOQCN+" "+
          "pulls the lance out of "+targ->QCN+"'s %^RED%^bloody wound"+
          "%^BLACK%^!%^RESET%^",({ETO,targ}));
       return random(10)+10;
    }
    return 0;
}
