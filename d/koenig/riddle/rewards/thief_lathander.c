//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("golden headband");
	set_id(({ "headband", "headband of the rising sun" }));
	set_short("%^BOLD%^%^YELLOW%^Headband of the %^MAGENTA%^Rising Sun%^RESET%^");
	set_obvious_short("A golden headband");
	set_long(
@AVATAR
%^YELLOW%^Soft golden cashmere wool has been made into this slender headband.  The golden cashmere has a faint gleam to it, as if metallic threads were woven into the cashmere wool.  Etched into the center with %^RESET%^%^RED%^crimson%^YELLOW%^, %^BOLD%^%^RED%^scarlet%^YELLOW%^,%^RESET%^%^ORANGE%^golden orange%^YELLOW%^, and %^MAGENTA%^rose%^YELLOW%^ threads, a highly detailed image of a sun with a fiery burst takes shape.  You can make out bits of glass beads used to further add to the majesty of the sun.

AVATAR
	);
	set_lore(
@AVATAR
The Headband of the Rising Sun came into use around the 4th century, by a band of rogues who served as heralds to the nobles.  The heralds were followers of Lathander's clegry, who's faith is still popular with nobles to this day.  What their masters did not know though was that these rogues were part of a secret sect of the faith who tried to manipulate and shape the course of the lands to benifit all people.  Noble and peasant.  It is because of these rogues' work that cities such as Shadow and Antioch learnt to respect nature so much, and in fact worked to preserve it and live in (somewhat) harmony with the rangers and druids of the woods.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" unties the headband and slips it away into a safe place.",ETO);
	tell_object(ETO,"%^YELLOW%^You untie the headband, and slip it away into a safe place.");
	return 1;
}
