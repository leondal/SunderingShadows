//mage_akadi.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("tunic of the tides");
	set_id(({ "tunic", "tunic of the tides" }));
	set_short("%^RESET%^%^CYAN%^Tunic of the %^BOLD%^%^BLUE%^Ti%^WHITE%^d%^BLUE%^es%^RESET%^");
	set_obvious_short("A teal colored tunic");
	set_long(
@AVATAR
%^CYAN%^Teal colored silk has been fashioned into this stylish tunic.  The shape of the tunic is loose and flowing, almost looking as if it melds to the wearer instead of constricting.  The silk has been treated with salt during the dying process, giving a %^BOLD%^%^WHITE%^rippling%^RESET%^%^CYAN%^ effect across the silk.  A high banded collar wraps around the neckline of the tunic and is jewelled with bits of %^BOLD%^%^MAGENTA%^coral%^RESET%^%^CYAN%^.  Slender sleeves are slit to the mid-forearms, allowing a peak at the %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^ ruffles sewn underneath.  The ruffles represent the foam on the waves, and both men and women of Istishia use them commonly in their garments.  

AVATAR
	);
	set_lore(
@AVATAR
The Tunic of the Tides came into being from a hydromancer of Istishia, Meru the White Wave, a half-elf priestess and magi of the Waterlord.  Meru felt more at home on the seas than anywhere else in the realms.  When she had managed to gain enough gold, her first purchase was that of a ship and loyal crew.  For three years she sailed the seas, in the name of her Lord, dealing with all sorts of threats against the faith of the Water Lord.  The tunic was her creation, as she was a skilled seamstress.  Her crew were likely decked out in similar garments, causing her foes to to nickname those on her ship the 'Frothing Fishes'.  Meru's fate was tied with the Prince of Antioch and his disappearance. 

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^CYAN%^You slip off the tunic, but know that like the tides, the time to wear it will soon come again.");
	return 1;
}
