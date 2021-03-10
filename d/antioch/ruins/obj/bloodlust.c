//Added lore and changed the inherit - Cythera 4/05
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/large_battle_axe.c";

void create()
{
	::create();
   	set_obvious_short("A large axe");
   	set_name("%^BOLD%^%^RED%^Axe of the Hunter%^RESET%^");
	set_short("%^BOLD%^%^RED%^Axe of the Hunter%^RESET%^");
	set_id(({"axe","battle axe","axe of the hunter","Axe"}));
	set_long(
		"%^RED%^%^BOLD%^This is a large battle axe. It has a wooden handle that is wrapped around"+
		" by strips of leather hide. The blade of the axe is sharpest steel, and"+
		" has a%^RESET%^%^RED%^red%^BOLD%^ tinge to it. On the bottom of handle an emblem"+
   		" of a savage wolf has been engraved."
	);
	set_lore("Through divinations and research, I have found that "+
		"the Axe of the Hunter use to be referred to a The Foresters"+
		" Axe.  The Foresters Axe was a minor religious relic in the"+
		" faith of Mielikki.  Every 10 years the axe was to be passed"+
		" on to a new owner, as to spread the favors of the Forest "+
		"Maiden.  The last known wielder of the Foresters Axe was a "+
		"human by the name of Ilskan.  The former sword for hire grew"+
		" tired of his savage life and searched for a more meaning.  "+
		"By tending to the forests he found the inner peace that he "+
		"searched for. They claim that Ilskan was mauled to death by "+
		"a pack of wild wolves during the night of a full moon.  Given"+
		" the connection to the full moon, lycanthropes and the "+
		"Beastlord, I have to wonder if the transformation of the "+
		"Foresters Axe to the Axe of the Hunter has some connection "+
		"to that faith. - Libram of Greenleaves - Holy Forester "+
		"Omin Willow.");
	set_property("lore",12);
	set_value(30);
	set_wield((:TO,"wieldme":));
	set_property("enchantment",2);
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

int wieldme()
{
	if(ETO->query_lowest_level() < 10) {
		tell_object("You are too inexperienced to wield such a weapon.");
		return 0;
	}
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The axe refuses to be wielded by someone using such goodly items!");
      return 0;
   }
	tell_object(ETO,"%^GREEN%^The song of the hunt rings through your"+
   " ears, quickening your pulse, as you grip the hilt of the axe.");
	tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" grips"+
   " the axe and begins looking around for prey.",ETO);
   ETO->set_property("evil item",1);
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^RED%^You feel the andrenaline drain from your body as"+
	" you release your grip on the axe.");
	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" gets a tired"+
	" look on "+ETO->QP+" face as "+ETO->QS+""+
	" releases "+ETO->QP+" grip on the axe.",ETO);
   ETO->set_property("evil item",-1);
	return 1;
}

int hitme(object targ)
{
  if (!objectp(targ)) return 1;
	if(!random(8)) {
		tell_object(ETO,"%^RED%^You swing the axe in a fearsome chop, hitting"+
		" "+targ->QCN+" hard.");
		tell_object(targ,"%^RED%^"+ETO->QCN+" swings "+ETO->QP+""+
		" axe in a fearsome chop, hitting you very hard.");
		tell_room(environment(ETO),"%^RED%^"+ETO->QCN+" swings "+ETO->QP+""+
		" axe in a fearsome chop, hitting "+targ->QCN+" hard.",({ETO,targ}));
		targ->do_damage("torso",random(5)+3);
		return 1;
	}
	if(!random(13)) {
		if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
			tell_object(ETO,"%^BOLD%^%^RED%^You draw back and execute a full swing"+
			" at "+targ->QCN+", impacting so hard that "+targ->QS+""+
			" seems momentarily stunned.");
			tell_object(targ,"%^BOLD%^%^RED%^"+ETO->QCN+" draws"+
			" back and executes a full swing, impacting directly with your"+
			" torso. You feel the jolt throughout your entire body.");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" draws"+
			" back and executes a full swing, impacting directly with "+targ->QCN+"'s"+
			" torso.",({ETO,targ}));
			targ->set_paralyzed(random(5)+2,"You are too stunned to move.");
			targ->do_damage("torso",random(8)+6);
			return 1;
		}
		else {
			tell_object(ETO,"%^ORANGE%^You draw back and execute a full swing"+
                        " at "+targ->QCN+", impacting so hard that"+
			" you feel the jolt through the hilt of your axe.");
			tell_object(targ,"%^ORANGE%^"+ETO->QCN+" draws back and"+
			" executes a full swing, connecting hard with your torso. You"+
			" barely manage to hold your ground.");
			tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" draws back and"+
			" executes a full swing, connecting hard with "+targ->QCN+"'s"+
			" torso.",({ETO,targ}));
			targ->do_damage("torso",random(8)+6);
			return 1;
		}
	}
}
