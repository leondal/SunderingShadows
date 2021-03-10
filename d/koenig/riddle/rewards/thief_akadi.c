//thief_akadi.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("sky blue shoes");
	set_id(({ "shoes", "cloud shoes" }));
	set_short("%^BOLD%^%^WHITE%^C%^RESET%^l%^BOLD%^o%^RESET%^u%^BOLD%^d %^BLUE%^Shoes%^RESET%^");
	set_obvious_short("A pair of sky blue shoes");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^Sky blue cotton has been used in the crafting of these fine shoes.  The shoes are made where one can slip them one and seem to be tailored in a fashion where they mold to the wearer's foot, allowing the shoes to be free of buckles, laces and anything binding.  Looking closer at the fabric you notice what looks to be %^WHITE%^clouds%^BLUE%^ that travel across the fabric!  Watching the shoes for sometime will show all sorts of clouds from %^BOLD%^thick fluffy%^BLUE%^ ones, to %^BLACK%^storm clouds%^BLUE%^ to %^RESET%^whispy thin%^BOLD%^%^BLUE%^ clouds.

AVATAR
	);
	set_lore(
@AVATAR
The Cloud Shoes are an item that comes to us from the faith of Akadi. There are legends of followers of Akadi who have worn shoes made from the sky themselves.  The legends say that the shoes bear an enchantment that allows the wearer to float on the air, free of the earth's hold, for a short time.

The shoes seem to be attributed to one man, Alradana, a thief from the southern lands who used the shoes to pilfer rare treasures and gold from his targets and escape with ease.  The legend goes on to say that Alradana once loved a woman, Sheveralaza, though she was betrothed to another man.  The night before her wedding Alradana planned to do his most
daring theft, and most personal, to steal Sheveralaza away.  With the aid of the shoes it is said that he was indeed able to resuce the bride before the wedding, though what happened to them is a mystery.  The Akadians will say that sometimes you can look out at the sky and see the faint image of a male carrying a woman as they float through the air.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" looks sad as they take off their shoes.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You remove your shoes and feel the pull of the earth once again.");
	return 1;
}
