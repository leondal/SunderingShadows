//thief_cyric.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("silver rune");
	set_id(({ "rune", "rune of the dark sun" }));
	set_short("%^BOLD%^%^WHITE%^Rune of the %^BOLD%^%^BLACK%^Dark%^RESET%^%^MAGENTA%^ Sun%^RESET%^");
	set_obvious_short("A silver rune");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^A silver rune is before you.  The rune's shape features many twists and curves in a circular pattern.  What the rune spells out is it hard to say, as it seems to be written in some ancient language that few, if any know anymore.  The rune casts a dim silver glow.

AVATAR
	);
	set("read",
@AVATAR
The rune's language is hard to make out.

AVATAR
	);
     set("langage","common");	set_weight(3);
	set_lore(
@AVATAR
The silver rune looks like a relic from the past.  The language is not like anything you have seen before.  Unlike other runes, this one seems almost tangible and solid, which is curious in itself.  Perhaps if you could fine someone who knew one of the dead languages you could figure out what the rune means.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The silver rune dislodges itself from "+ETOQCN+"",ETO);
	tell_object(ETO,"%^MAGENTA%^You will the rune to remove itself from you, but know that Cyric's gift to you will come in need very soon.");
	return 1;
}
