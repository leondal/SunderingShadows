//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/armour/coif_leather.c";

void create(){
	::create();
	set_name("skullcap");
	set_id(({ "skullcap", "mithril skullcap", "cap", "mithril studded skullcap" }));
	set_short("%^BOLD%^%^WHITE%^Mithril %^RED%^Studded Skullcap%^RESET%^");
	set_obvious_short("A studded red leather skullcap");
	set_long(
@AVATAR
%^BOLD%^%^RED%^Made of a soft leather, this skullcap looks as if it would offer some protection to one's head.  The skullcap is shaped in a way where it rests on one's head, just covering the top of the skull.  There is nothing that covers the ear, which many find to be a great asset.  The soft red leather has been tooled with a geometrical pattern.  %^WHITE%^Mithril%^RED%^ studs give added strength to the skullcap.  The inside of the skullcap seems to be lined with a lightly quilted red cotton.
AVATAR
	);
	set_weight(4);
	set_value(250);
	set_lore(
@AVATAR
Skullcaps are favored by many who need a helm, but don't want to wear anything to binding.  This skullcap seems to be made from the hide of a hell hound, that has been bleached and then dyed a bright shade of red.  The geometrical pattern tooled into the leather looks akin to something one might see from a nomadic culture.

AVATAR
	);
	set_property("lore",10);
	set_size(2);
        set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" places a red leather skullcap on their head.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You place the leather skullcap on your head.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" removes the red leather skullcap",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You remove the skullcap");
	return 1;
}