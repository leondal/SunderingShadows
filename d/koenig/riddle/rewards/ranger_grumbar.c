//ranger_grumbar.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("grumbar hide");
	set_id(({"hide","rigid leather armor","leather","leather armor","rigid armor","armor","strength","strength of the earth"}));
	set_short("%^RESET%^%^ORANGE%^Strength of the Earth%^RESET%^");
	set_obvious_short("Rigid leather armor");
	set_long(
@CIRCE
%^RESET%^%^ORANGE%^This suit of leather armor is rigid and unforgiving.  It has been formed and hardened to be much larger than the wearer's natural body, making the figure seem huge.  A layer of thick quilted padding fills out the shell of the armor, giving the wearer extra protection and bulk.  The armor is not very attractive, but the joints are surprisingly limber and allow the wearer a wide range of movement.
CIRCE
	);
	set_lore(
@CIRCE
Followers of the Earthlord often attempt to make themselves in his image, usually by making their armor larger than it needs to be.  Armor such as this gives the faithful a stocky, impressive stature that seems to mimic the earth itself.  While considered by many faiths to be impractical, the followers of Grumbar have long since grown accustomed to bulky armors, and they can perform incredible feats while wearing even the most cumbersome ensembles.  This particular armor has been marked by the Earthlord, and those wearing it are considered blessed among his faith.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^RESET%^%^ORANGE%^With a sigh, you let the weight of the world fall from your shoulders, longing for its feel once again.");
	return 1;
}
