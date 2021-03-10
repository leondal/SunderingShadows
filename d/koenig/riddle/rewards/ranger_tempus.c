//ranger_tempus.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("tempus hide");
	set_id(({"hide","leather scalemail","leather","scale","scalemail","heart","heart of battle"}));
	set_short("%^RESET%^%^ORANGE%^The Heart of %^RED%^Battle%^RESET%^");
	set_obvious_short("A suit of leather scalemail");
	set_long(
@CIRCE
%^RESET%^%^ORANGE%^This unique suit of armor is fashioned exactly like scalemail, but instead of using pieces of metal, the craftsman has pieced together bits of leather hardened nearly to the point of steel.  The armor is cut to fit close to the wearer's body, but it is so well-made as to not hamper movement.  It is incredibly silent, and it has been darkened to a blackish gray that seems to reflect no light.
CIRCE
	);
	set_lore(
@CIRCE
Many of Tempus's faithful find leather armor to be beneath them.  The rangers, however, who have given up use of metal armor for its bulk and noise, have developed this compromise between the two.  From afar, the armor looks much like darkened scalemail, but the rangers are able to retain their stealth in the woods.  Rangers of Tempus are used more as scouts than as woodland defenders as are other rangers, and their sneaky nature sometimes causes problems within the faithful of Tempus.  Because of this, many rangers of Tempus often feel alone and isolated.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^ORANGE%^You unbuckle the leather armor, feeling vulnerable again.");
}
