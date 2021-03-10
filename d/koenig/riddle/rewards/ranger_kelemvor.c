//ranger_kelemvor.c - reward for Riddle Quest. Circe 1/25/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("kelemvor hide");
	set_id(({"hide","bone","bone armor","leather","defense","requiem's defense"}));
	set_short("%^BOLD%^Requiem's Defense%^RESET%^");
	set_obvious_short("A suit of bone armor");
	set_long(
@CIRCE
%^BOLD%^This suit of armor is much like leather armor, except it has been fitted with pieces of bone for extra protection.  The bone looks to have been taken from animals - probably those hunted for game and used as food.  The armor consists of a leather coat fitted with the bone plates that leaves the arms free to allow full range of movement.  This is worn over plain leather pants to provide some protection for the legs.  The coat ends just above the wearer's knees.
CIRCE
	);
	set_lore(
@CIRCE
Bone armor such as this is favored by rangers of Kelemvor who feel a connection to their deity while wearing such armor.  Though rangers of the Lord of the Dead are somewhat rare, several do find their calling in Kelemvor's fold.  They journey through the lands, easing pain and death for the wild denizens of the forests.  When an animal must be granted peace, the ranger may take a portion of his bone and add it to his armor.  The first suit of bone armor worn by a ranger of Kelemvor was crafted in this way.  Since that time, many rangers of the Lord of the Dead feel that his blessing resides upon such armor, and they wear it with pride, secure in their faith.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove("%^BOLD%^You feel comfort in your faith as you remove the bone armor.");
}
