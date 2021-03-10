//fighter_auppenser.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NHIDE;

void create(){
   ::create();
//   	set_name("auppenser breastplate");
   	set_id(({"breastplate","plate","crystals","crystal breastplate","Crystals of Force"}));
   	set_obvious_short("%^BOLD%^%^WHITE%^A collection of floating crystals%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^C%^CYAN%^r%^RESET%^%^CYAN%^y%^BOLD%^"+
		"%^BLUE%^s%^RESET%^%^CYAN%^t%^BOLD%^a%^WHITE%^l%^BLACK%^s "+
		"%^RESET%^%^CYAN%^of %^BOLD%^%^BLUE%^F%^CYAN%^o%^BLUE%^r%^CYAN%^"+
		"c%^BLUE%^e%^RESET%^");
   	set_long(
@CYTHERA
%^BOLD%^%^WHITE%^This collection of %^BOLD%^%^CYAN%^crystals%^WHITE%^ float in the air.  The various crystals come in a variety of shades of %^BOLD%^%^BLUE%^blue%^WHITE%^, %^RESET%^%^CYAN%^c%^BOLD%^y%^RESET%^%^CYAN%^a%^BOLD%^n%^WHITE%^, and %^BLACK%^black%^WHITE%^.  Each crystal has been polished and shaped into spheres.  When attuned to the owner's mind, the crystals resonate a field of protective force around the owner's torso, creating an odd but useful protective breastplate.%^RESET%^
CYTHERA
   );
   	set_lore(
@CYTHERA
The Crystals of Force where gifted to the warriors of Auppenser from yesteryears.  The crystals were each attuned by a psion to the mind of the owner, allowing her to be able to raise and lower the field of force about her body.  Even though some might look down upon a warrior in Auppenser's faith, they were deeply cherished and well respected.  For the warriors served as the bodyguards and protectors of Auppenser's clerics and psions.  Of all the other warriors in the lands, those of Auppenser were known to have a calm mind that some say allowed them to react better to the chaos of battle.  
CYTHERA
   );
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
	set_wear((:TO,"wear_func":));
}
int wear_fun(){
	tell_object(ETO,"%^CYAN%^The crystals sense your need for protection"+
		" and form an invisible field of force around your body!");
	tell_room(environment(ETO),"%^CYAN%^The crystals that float around"+
		" "+ETOQCN+"'s glow for a brief moment.",ETO);
     	return 1;
}
int remove_func(){
	tell_object(ETO,"%^CYAN%^The crystals sense your need to remove the"+
		" protective force and you can feel the invisible field about you vanish.");
	return 1;
}
