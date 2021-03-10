//mage_helm.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the watchful eye");
	set_id(({ "robe", "robe of the watchful eye" }));
	set_short("%^BOLD%^%^WHITE%^Robe of the %^BLUE%^Watchful%^RESET%^%^MAGENTA%^ Eye%^RESET%^");
	set_obvious_short("A white robe");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This robe is made out of a bleached cotton that gives it its white color.  The robe looks as if one slips into it like a shirt rather than wrapping it around one's body.  Silver metallic fabric patches cover the shoulders in an attempt to try to mock shoulderplates, though they of course are just for decoration.  A decorative pattern of a stylized eye is woven into the cotton in %^BLUE%^blue%^WHITE%^ threads.  The pupil of the eye is colored %^RESET%^%^MAGENTA%^dusky purple%^BOLD%^%^WHITE%^.  The image of the eye looks exactly like that on the holy icons of the Watcher and is scattered across the robe in an organized pattern.  Wide sleeves with a three inch cuff finish off this elaborate robe.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Watchful Eye was made by a Helmite mage, Therosian Delevorsian, a famed Abjurer who dedicated his life to protecting others.  Therosian was old by human standards when he first joined the faith at the age of 53.  During his service to Helm, Therosian was able to help strengthen the fortifications of many citadels of Helm and aid the clergy in a brutal war that broke out between the Helmites and the Xvimarians.  Sadly, though, Therosian met his end during a mage duel with a Xvim sorceress that resulted in the spread of the desert east of Shadow, after the Xvimarians tried to take the city by force.

AVATAR
	);
      set_property("lore difficulty",12);
}