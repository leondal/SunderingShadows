//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("skullcap");
	set_id(({ "skullcap" }));
	set_short("%^RESET%^%^BLUE%^Skullcap of Mysteries%^RESET%^");
	set_obvious_short("A midnight blue velvet skullcap");
	set_long(
@AVATAR
%^BLUE%^Soft plush midnight blue velvet has been used to make this skullcap.  The skullcap is small in size, looking as if it rests on the back of one's head.  The velvet skullcap is rounded and has a slight convext shape to it.  %^RED%^Crimson red%^BLUE%^ thread has been used to stich the sections of the velvet together.

AVATAR
	);
	set_lore(
@AVATAR
The Skullcap of Mysteries is a item given to the faithful rogues Mystra.  Rumors say that rogues in service to Mystra have been know to steal back powerful magical items from those who would abuse the, and to keep a watchful eye on the workings of the magi across the lands.  

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BLUE%^You slip off the skullcap.");
	return 1;
}
