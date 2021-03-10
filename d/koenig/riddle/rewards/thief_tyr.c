//thief_tyr.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("turban");
	set_id(({ "turban", "turban of the wolfjaws" }));
	set_short("%^BOLD%^%^BLUE%^Turban of the Blue Wolf%^RESET%^");
	set_obvious_short("An azure blue turban");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Fine smooth cotton in azure blue has been used to form this turban.  This turban though is not like most that you have seen, where the mass of fabric is woven about the head.  Instead this turban features a cloth hat in circular shape that covers the head.  The cloth hat is low and slightly wide, but never sticking more than two fingers away from one's head.  Azure blue cotton printed with an image of a wolf is wrapped around the cloth base with %^WHITE%^silver cording%^BLUE%^.  The excess wolf print fabric is pulled to the back where it is allowed to hang down to the middle of one's back.

AVATAR
	);
	set_lore(
@AVATAR
The Turban of the Wolfjaws was rumored to have once belonged to Al'Radzan the Second, a secret spy of the church of Tyr in the underworld of Azha.  Al'Radzan was able to use his connections as a rogue to keep tabs on the workings of the thief guild and smugglers that thrived in Azha.  With the information he had the Blue Wolf, as he was nicknamed, was able to keep the church of Tyr one step ahead of the thieves guild and eventually ended their reign in Azha.  Though the Blue Wolf's efforts were discovered by the thieves, and for that betrayl to the rogues the Blue Wolf met with a bloody end when he was crushed by a stone block in the markets of Azha.  How the rope that was supporting managed to snap is a mystery still to this day, for the ends of the rope looks as if they had been burnt, not by fire but some other means.  The Blue Wolf though became a martyr of the faith and a sign to Tyrans that sometimes a rogue can be helpful.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" removes their turban and takes a moment to carefully fold the fabric, as to avoid wrinkling it.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You remove the turban and fold it carefully as not to wrinkle the fabric.");
	return 1;
}
