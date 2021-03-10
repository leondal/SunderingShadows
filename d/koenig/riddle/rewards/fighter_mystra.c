//fighter_mystra.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("mystra hide");
	set_id(({"hide","pale studded leather armor","touch","mystery's touch","studded","armor","studded leather"}));
	set_short("%^BOLD%^%^CYAN%^Mystery's %^WHITE%^To%^CYAN%^u%^WHITE%^ch%^RESET%^");
	set_obvious_short("Pale studded leather armor");
	set_long(
@CIRCE
Made of the pale hide of some unknown beast, this armor has been dyed a subtle %^BOLD%^%^CYAN%^blue %^RESET%^shade and fitted with metal rivets that look to be made of %^BOLD%^platinum%^RESET%^.  The rivets are worked into a gently swirling pattern across the chest, with a hint of %^BOLD%^%^RED%^red %^RESET%^flowing from their center.  The knees and elbows on this suit of armor have been reinforced with %^BOLD%^%^BLUE%^deep blue %^RESET%^leather pads that look to provide extra protection for those areas.
CIRCE
	);
	set_lore(
@CIRCE
Those warriors who follow the way of the Lady of Mysteries tend to be protectors and enforcers of her clergy.  They provide muscle for the missions of the church as well as protection for those magi and clerics who venture outside the hallowed halls of her libraries and temples.  Armor such as this is given to a special group of warriors known simply as Lady Mystery's Hand.  This group is charged with protecting the church in any manner it deems necessary, especially on those missions that her paladins might baulk at.
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^The platinum rivets %^CYAN%^glitter %^WHITE%^and fade as you remove the armor.");
	return 1;
}
