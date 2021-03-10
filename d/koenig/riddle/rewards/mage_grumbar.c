//mage_grumbar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("quilted robe of the hills");
	set_id(({ "robe", "quilted robe of the hills" }));
	set_short("%^RESET%^%^ORANGE%^Quilted Robe of the Hills%^RESET%^");
	set_obvious_short("A bulky quilted brown robe");
	set_long(
@AVATAR
%^ORANGE%^This robe is bulky and massive!  The earth-colored brown cotton has been heavily quilted to add bulk and size to the robes.  The shoulders of the robe feature thick padding underneath the outer fabric giving the image of one having massive shoulders.  The cut of the robe is simple and timeless.  The sleeves of the robe have a two inch cuff on them, which only adds to the appearance of bulk the robe gives.  Looking closer you notice that %^YELLOW%^copper%^RESET%^%^ORANGE%^ metallic thread is used to quilt the earthy cotton.

AVATAR
	);
	set_lore(
@AVATAR
The Quilted Robe of the Hills has always remainded the same since the first of their kind was made over 200 years ago.  A Grumbarian mage, Olestarn Nethural, first made these robes to help hide his puny body and to give him the appearnce of a hulking muscular mage.  The faith of Grumbar seems to favor those who look hardy, muscled, and strong, like the earth itself.  Olestarn was mocked for his short stature and his slim body.  With the aid of these robes he was able to give the appearance that he was like his fellow Grumbarians, whom he so wanted to impress.  Since his time, others who lack the body type that the Grumbarian priests favor have found the robes useful.  Though, much like the Earthlord, their design has never changed, and never should.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^ORANGE%^You slip off the robe, suddenly feeling rather thin and puny!");
	return 1;
}
