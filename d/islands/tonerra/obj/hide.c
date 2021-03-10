//updated by Circe 6/13/04 with new desc, lore, etc.
//hide

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit "/d/common/obj/armour/hide.c";

void create(){
	::create();
	set_name("woven armour");
	set_id(({"armour","armor","woven","woven armour","woven armor","hide","aurumvorax hide"}));
      set_obvious_short("golden hide armor");
	set_short("%^YELLOW%^Woven Armor%^RESET%^");
	set_long(
         "%^RESET%^%^ORANGE%^Made from the carefully tanned hide "+
         "of the strange eight-legged creature known as the "+
         "%^YELLOW%^aurumvorax%^RESET%^%^ORANGE%^, this armor "+
         "is crafted for mobility and stealth.  The prickly "+
         "fur of the aurumvorax has been turned inward and "+
         "woven into itself, strengthening the armor against "+
         "slashing blows.  The hide gives the armor a %^YELLOW%^"+
         "golden sheen %^RESET%^%^ORANGE%^that might give one "+
         "away in the wilds, but it does seem to offer a good "+
         "amount of protection.  The joints of the armor are "+
         "amazingly well-made, causing the armor to make little "+
         "noise, which is unusual for hide armors.  Burned into "+
         "the shoulders and chest of the armor are strange tribal "+
         "markings.%^RESET%^");
      set_lore("Crafted by the tanners of Tonerra, this armor is "+
         "considered sacred.  Warriors receive a suit of such "+
         "armor crafted from aurumvorax hide...only after they "+
         "have killed one of the creatures with no armor and "+
         "armed with only a spear.  Then, they are welcomed into "+
         "the brotherhood of warriors, and the hide of the "+
         "felled beast is used to create the young man's first "+
         "suit of armor.  Working with aurumvorax hide is "+
         "extremely challenging, as it gives very little until "+
         "it is tanned properly.  To disguise the gold sheen, "+
         "the natives of Tonerra often apply a thin layer of a "+
         "paste made of crushed leaves and mud.");
	set_property("enchantment",4);
      set_value(145);
}
	
