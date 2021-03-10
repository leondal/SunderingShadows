//thief_sune.c - reward for Riddle Quest. Cythera 8/05
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("ioun stone");
	set_id(({"stone","ioun stone","ruby ioun stone","ruby","ruby ioun","ruby ioun of passion's embrace"}));
	set_short("%^RESET%^%^RED%^Ruby Ioun of Passion's Embrace%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^A ruby ioun stone%^RESET%^");
	set_long(
@CYTHERA
%^RED%^This oval ioun stone has been crafted out of a ruby gem.  The ruby shines with a deep crimson red clarity and is free of any flaws.  The oval stone is about one inch in diameter.  Set deep within the ioun stone is a three dimensional face of an %^BOLD%^%^WHITE%^ivory%^RESET%^%^RED%^ skinned woman's face.  Long flowing crimson tresses wrap around the flawless face of the woman as her %^BOLD%^%^GREEN%^emerald green%^RESET%^%^RED%^ eyes seem to twinkle.  When released the ruby ioun stone circles around the owner's head with a slight fiery trail.%^RESET%^
CYTHERA
	);
	set_lore(
@CYTHERA
The Ruby Ioun of Passion's Embrace is a rare treasured gift given to the rogues of Sune Firehair's faith.  Within the faith of Sune, a special band of temple rogues were created to help protect precious treasures of the faith.  It was not uncommon for these rogues to be sent on mission to retrieve precious heirlooms that had been stolen from the temples by greedy and selfish individuals.  In time the rogues also became protectors of star-crossed lovers, helping them to escape their rigid and sometimes cruel families to find a happier life together.  The rogue of Lady Firehair in time grew to become a rather influential group, touching the lives of many across the lands. 
CYTHERA
	);
	set_remove((:TO,"remove_func":));
	set_wear((:TO,"wear_func":));
}
int wear_fun(){
	tell_object(ETO,"%^RED%^You release the ruby ioun stone into the air."+
		"  The ruby starts to circle around your head leaving a faint"+
		" fiery trail in its wake.");
	tell_room(environment(ETO),"%^RED%^A ruby ioun stone starts to circle "+
		"around "+ETOQCN+"'s head, leaving a fiery trail in its wake.",ETO);
     	return 1;
}
int remove_func(){
	tell_object(ETO,"%^RED%^Catch the ruby ioun stone in the air, and tuck"+
		" it away in a safe spot.");
	return 1;
}
