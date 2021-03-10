//Added lore and changed to inherit hide.c - Cythera -4/05\\
#include <std.h>
#include <daemons.h>
#include "../valley.h"
inherit "/d/common/obj/armour/hide.c";

string owner;

void create()
{
	::create();
	set_name("%^GREEN%^Snake Skin%^RESET%^");
	set_id(({"snake skin","Snake Skin","reptilian hide","hide","snake hide","snake skin hide","skin"}));
	set_short("%^GREEN%^Snake Skin%^RESET%^");
	set_obvious_short("%^GREEN%^snakeskin hide%^RESET%^");
	set_long(
	"%^GREEN%^The snake skin seems to be naturally shaped into a"+
	" breastplate that would fit close to the torso. The scales"+
	" are tiny but appear to be protective, and the skin looks very"+
	" supple. It would be very comfortable. %^RESET%^"
	);
	set_property("lore",18);
	set_lore("The Moonstone Valley has been under many threats in"+
		" recent times.  From the ogre and undead hordes along "+
		"the dark trials, to the wild and savage beasts that have"+
		" taken over the Dark Forest that surrounds it.  The druids"+
		" and the fey creatures have been successful for the most part"+
		" in keeping the valley fortified and safe.  Except for one "+
		"creature.. the darkfang snake.  A creature rumored to be the"+
		" creation of an ancient god of decay and rotting.  This elder"+
		" god, who's name has vanished with time, was believed to have"+
		" been a chief rival of Mielikki, the Protector of Fey and Forests"+
		" and was seeking to corrupt and twist the valley into his own "+
		"paradise of decay and rot.  The serpent was planted inside the "+
		"valley as a way for the decay to spread.  With the god's death "+
		"now though, this serpent has lost most of it's rumored powers."+
		"  Still the druids find it hard to kill the serpent and all of"+
		" its children, so they are under constant threats from it.  "+
		"The scales of the serpent are favored by druids and nature "+
		"oriented folk as a sign of pride and honor for slaying such a"+
		" corrupt beast.");
	set_property("enchantment",3);
	set_size(-1);
	set_value(190);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
/*
Removing the owner check since owner is never set and the hide is not so good 
as to need to be ownered. ~Circe~ 4/10/13
	if((string)TPQN != owner) {
		tell_object(ETO,"%^RED%^The hide twists itself into the form"+
		" of a snake and bites you as you try to wear it!");
		if(!"/daemon/saving_d"->saving_throw(ETO,"paralyzation_poison_death")) {
			ETO->add_poisoning(20);
			ETO->do_damage("torso",random(8)+2);
		}
		else {
			ETO->do_damage("torso",random(8)+6);
		}
		tell_room(environment(ETO),""+ETO->query_cap_name()+" can't"+
		" seem to get into the snake skin, then "+ETO->query_subjective()+""+
		" throws it away from "+ETO->query_objective()+"self and looks"+
		" a little paler.",ETO);
		return 0;
	}
	else {
*/
		tell_object(ETO,"%^BLUE%^The snake skin wraps itself around"+
		" your body. Its touch is pleasantly cool.");
		return 1;
//	}
}

int removeme()
{
	tell_object(ETO,"%^CYAN%^Your skin tingles from the warmth of"+
	" the air as the snake skin slips itself off of your body.");
	return 1;
}
