//mage_malar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("tunic of the hunt");
	set_id(({ "tunic", "tunic of the hunt" }));
	set_short("%^RESET%^%^ORANGE%^Tunic of the %^RED%^Hunt%^RESET%^");
	set_obvious_short("A matted bearskin tunic");
	set_long(
@AVATAR
%^ORANGE%^The hide of a brown bear has been used to create this tunic.  The tunic's shape is crude, and it looks to have been made quickly.  The edges of the tunic are not finished, instead left to their own means, further adding to the wild, savage look of this tunic.  The pelt of the brown bear is stained %^RED%^red-brown%^ORANGE%^ and clumped together, much like dried blood.  The paw of the bear crosses over the shoulder and is threaded through with a jagged broken %^WHITE%^bone%^ORANGE%^, serving as a makeshift button.  The smell on the tunic is a mixture of sweat and a metallic coppery scent.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Hunt is crafted from the hide of a creature that the Malaritie must kill on his or her own, without any aid.  As Malar tends to be a brutal and savage power, the condition of the hunt is the creature must die a painful death.  Of the few mages that follow Malar, they tend to be invokers, summoners, or transmutters.  The wild nature of Malar's faith holds little regard for enchanters, illusionists, or diviners.  Once the creature has been slain, it is up to the Malarite to fashion this tunic from the creature's hide.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^ORANGE%^You slip out of the tunic.");
	return 1;
}
