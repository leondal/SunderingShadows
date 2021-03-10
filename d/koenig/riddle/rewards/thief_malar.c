//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("owlbear coif");
	set_id(({ "coif", "owlbear head", "owlbear coif", "head" }));
	set_short("%^RESET%^O%^ORANGE%^wl%^RESET%^bear %^ORANGE%^H%^RESET%^ea%^ORANGE%^d%^RESET%^");
	set_obvious_short("An owlbear's head");
	set_long(
@AVATAR
%^ORANGE%^The head of an owlbear has been used to fashion this leather coif.  The %^YELLOW%^amber%^RESET%^%^ORANGE%^ eyes of the owlbear rest on top of the coif, and cast and errie gaze.  The beak of the owlbear falls forward, casting a shadow on to one's face and eyes.  The %^RESET%^feathered%^ORANGE%^ hide of the owlbear have been ruffled, gives the coif a wild and untamed feeling.  The inside lining is made from boiled leather and seems to be what gives the strange coif it's shape.  You can't help but feel the coif is rather spooky, since it seems the owlbear's eyes always follow you. 

AVATAR
	);
	set_lore(
@AVATAR
The Owlbear Head is a strange coif used by the woodland raiders of Malar.  The rogues have come to use the owlbear as their totem animal, feeling the savage creature grants them brute strength and stealthy.  Malar's Owlbears are known to perform raids against followers of Mielikki and Silvanus, though it is the peaceful followers of Eldath that they delight in preying on the most.  There are rumors that the Owlbears use the claws of the fearsome beasts as weapons to strike down savage blows in the name of the Lord of the Hunt.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^ORANGE%^"+ETOQCN+" removes the owlbear's head, you can't help but feel releaved not to have to look at those amber eyes anymore.",ETO);
	tell_object(ETO,"%^ORANGE%^You remove the coif, feeling the wild surge fade quickly from your body.");
	return 1;
}
