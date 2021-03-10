//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("leather helm");
	set_id(({ "helm", "leather helm", "helm of guardians" }));
	set_short("%^RESET%^%^WHITE%^Helm of %^BLUE%^Guardians%^RESET%^");
	set_obvious_short("A steel grey leather helm");
	set_long(
@AVATAR
%^RESET%^Made of steel grey leather, this open face helm takes the shape of rounded helmet.  The leather has been treated and made to resemble leather, even down to the dusting of steel powder bound to the leather that gives it a slight shimmer.  Tooled into the leather and set off with dyes is the image of a %^BLUE%^blue eye%^RESET%^, the watchful eye of Helm.  The helm is padded on the inside with quilted %^BLUE%^cobalt%^RESET%^ cotton, to give some comfort.

AVATAR
	);
	set_lore(
@AVATAR
The Helm of the Watcher is used by a band of scouts of Helm who have dedicated their life to protecting women and childern how ever they can.  Few get the chance to wear such a helm, and those that do are considered blessed and lucky.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" removes the steel grey helm.",ETO);
	tell_object(ETO,"%^BLUE%^You remove the helm, but know the watchful eyes of Helm are always on you.");
	return 1;
}
