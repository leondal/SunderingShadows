//mage_lathander.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robes of renewal");
	set_id(({ "robe", "robe of renewal" }));
	set_short("%^YELLOW%^R%^MAGENTA%^o%^RED%^b%^RESET%^%^ORANGE%^e%^RED%^s %^MAGENTA%^o%^YELLOW%^f%^MAGENTA%^ R%^RED%^e%^RESET%^%^ORANGE%^n%^RED%^e%^MAGENTA%^w%^YELLOW%^a%^MAGENTA%^l%^RESET%^");
	set_obvious_short("A golden orange robe with a crimson sash");
	set_long(
@AVATAR
%^ORANGE%^The main color of these robes is golden orange.  The robes are cut in a slim silhouette, looking to fit snug to the body.  On a closer inspection, one notices that the outer layer of the robe is actually made of an almost sheer silk  that is the golden orange shade.  A pattern of %^BOLD%^%^MAGENTA%^rose-red%^RESET%^%^ORANGE%^,%^BOLD%^%^RED%^ scarlet%^RESET%^%^ORANGE%^, and%^YELLOW%^ yellow%^RESET%^%^ORANGE%^ is woven into the semi-sheer silk.  An underrobe of %^RED%^crimson%^RESET%^%^ORANGE%^ is fitted tight against the body.  The long tapered snug sleeves of the underrobe come to a point over each knuckle.  Around the waist a %^RED%^crimson %^ORANGE%^sash has been tied, keeping the garments together.

AVATAR
	);
	set_lore(
@AVATAR
The Robes of Renewal are mirrored after the vestments of Lathander's faith.  The Lathanderites see nothing wrong with elaborate dispalys of wealth that push some people's opinion of good taste.  Because Lathander is also the god of youth, athletics and self-perfection, it is not uncommon to see comely males and females displaying their eye-pleasing bodies.  Though they avoid anything that would be seen as tacky or immoral!

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You slip off the robes and almost wish to put them on again.  You've never looked better before!");
	return 1;
}
