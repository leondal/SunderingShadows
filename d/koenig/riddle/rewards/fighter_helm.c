//fighter_helm.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("helm hide");
	set_id(({"hide","strength","watcher's strength","studded","armor","studded leather"}));
	set_short("%^BOLD%^%^BLUE%^Watcher's %^CYAN%^Strength%^RESET%^");
	set_obvious_short("Studded leather armor");
	set_long(
@CIRCE
%^RESET%^%^ORANGE%^This unusual suit of leather armor has been fitted with %^BOLD%^%^WHITE%^mithril %^RESET%^%^ORANGE%^studs to help strengthen and reinforce it.  The armor is well-made and tapers at the waist to fit close and not hamper movement.  Set within the chest is a large, unblinking %^BOLD%^%^BLUE%^blue eye%^RESET%^%^ORANGE%^ centered on a %^BOLD%^%^WHITE%^gauntlet%^RESET%^%^ORANGE%^.  Topping the studded leather is a set of %^BOLD%^%^WHITE%^mithril shoulderplates %^RESET%^%^ORANGE%^that add extra protection. 
CIRCE
	);
	set_lore(
@CIRCE
The Watchers' faithful are among the most vigilant of worshippers in the realms.  They often take their Lord's messages to heart and follow him to the letter of his missives.  It is said that this complete devotion occasionally causes problems between members of Helm's faith and those of his closest allies.  Whether or not that be the case, this suit of armor is considered blessed by the Watcher himself - and it is only granted to the most devout of even his unfailing faith.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^CYAN%^You relax slightly as you remove the armor, but know that you are never off-duty.");
	return 1;
}
