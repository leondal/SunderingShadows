//thief_tymora.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 4/21/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("rabbit fur boots");
	set_id(({ "boots", "rabbit boots", "lucky rabbit's feet" }));
	set_short("%^BOLD%^%^WHITE%^Lucky Rabbit's Feet%^RESET%^");
	set_obvious_short("A pair of white rabbit skin boots");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^These soft shin high boots have been crafted out leather.  The boots are soft and flexible allowing for ease of movement and they look very comfortable.  A padded leather sole gives plenty of protection from rocks or briar that one might encounter.  The boots have been covered with a soft white fur.  The fur is actually rabbit and has been well cared for, still retaining it's white color and soft luster.  

AVATAR
	);
	set_lore(
@AVATAR
The Lucky Rabbit's Feet was crafted by one travelling rogue of Lady Luck, Oquim Esquip.  Oquim heard that a rabbit's foot was a totem that brought good luck.  Needing all the good fortunes of Tymora that he could get, he decided that why just have one rabbit's foot when you can have a boot made from the fur of many rabbits!  All the more luck!

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" looks unsure "+
         "as "+ETO->QS+" slips off "+ETO->QP+" boots.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^With some reservation, you slip "+
         "off the boots.  Though you can't help pray that %^WHITE%^Tymora"+
         "%^BLUE%^ still might smile good fortune on you.");
	return 1;
}
