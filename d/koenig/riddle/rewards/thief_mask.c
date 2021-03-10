//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("black velvet mask");
	set_id(({ "mask", "black velvet mask", "velvet mask", "mask of shadows" }));
	set_short("%^BOLD%^%^BLACK%^Mask of Shadows%^RESET%^");
	set_obvious_short("A black velvet mask");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^A mask made of plush soft black velvet.  The fabric hangs in a way where the entire face is hidden behind the fold of the fabric.  The mask seems as if it ties behind the back of one's head, similar to a headband, and the fabric is allowed to drape freely.  The eyes of the mask have been cut out to allow one to see, though a fine gauze has been sewn over the eyes, to conceal the wearer's identiy.

AVATAR
	);
	set_lore(
@AVATAR
The Mask of Shadows is attributed to the god Mask.  The mask does not appear to be actually made of shadows, as the name suggests, but of fine black velvet.  The mask is common among the followers of the Lord of Thieves, for they like to keep their identiy hidden.  Even from other followers.  It's hard to say who this masked belonged to as there is such a large number of them circulating.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the black velvet mask, allowing you to get a look at the face behind the mask.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the mask and can't help but feel naked and exposed");
	return 1;
}
