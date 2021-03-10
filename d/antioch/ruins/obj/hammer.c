//Added lore -Cythera 4/05
#include <std.h>
#include <spell.h>
#include <magic.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/warhammer";

void dest_effect(object targ);
void more_burn(object targ);
int num;
object targ;

void create() {
	::create();
	set_name("%^BOLD%^%^RED%^Crimson Hammer%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Hammer of the %^RED%^Crimson Bl%^YELLOW%^a%^RED%^ze%^RESET%^");
   set_obvious_short("%^BOLD%^%^RED%^A ruby adorned warhammer%^RESET%^");
	set_id(({"hammer","crimson hammer","hammer of the crimson blaze","ruby hammer","Crimson Hammer","Hammer of the Crimson Blaze"}));
	set_long(
	"%^BOLD%^The head of the hammer is made of one of the largest %^RED%^rubies%^WHITE%^"+
	" that you've ever seen. It has been smoothly polished and cut to fit"+
	" this hammer. The handle joins to the bottom of the %^RED%^ruby%^WHITE%^ seamlessly. It"+
	" is made out of the purest mithril, with a braided piece that wraps"+
	" in cork-screw fashion around it. The tiniest of %^RED%^rubies%^WHITE%^"+
	" are embedded into the braid, making the handle sparkle. It is a marvelous"+
	" piece of work."
	);
	set_lore("The Hammer of the Crimson Blaze was first crafted by the "+
		"Hammer Maiden, Brunhelda Silvermine, a dwarven female"+
		" warrior.   Brunhelda was a skilled blacksmith, as most dwarves "+
		"are.  She crafted the hammer herself from the finest rubies and "+
		"mithril she could find.  Taking over a decade to shape the hammer,"+
		" Brunhelda's labor of love offered her the power to bash down anyone"+
		" or thing that got in her way.  Slain in a battle against a red "+
		"dragon, Brunhelda's hammer was added to the red wyrm's horde.  That"+
               " is until almost half a century later when the wyrm was slain.  As "+
		"the seven adventures sorted through the trinkets, artifacts, and "+
		"treasures of Fezlegarath's horde, The Hammer of Crimson Blaze was "+
		"discovered.  One of the adventures, a human cleric by the "+
		"name of Jezzim, was so impressed with the workmanship of the hammer "+
		"that he claimed it as his own.  Spending nearly all of his portion "+
		"of the treasure, Jezzim enlisted the aid of an elven mage, he had "+
		"the hammer enchanted with the properties of the fire. - The Hammer "+
		"Maiden: The Life and Creations of Brunelda Silvermine - Rathor "+
		"Mithrilbeard");
	set_property("lore",14);  
	set_value(1500);
	set_property("enchantment",3);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

int wieldme() {
	if(ETO->query_lowest_level() < 15) {
		tell_object(ETO,"You are simply not powerful enough to master a weapon"+
		" such as this one.");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^RED%^ruby hammer%^WHITE%^ seems"+
	" to brighten for a moment as you wield it.");
	tell_room(environment(ETO),"%^BOLD%^%^RED%^A ruby light reflects in"+
	" "+ETO->QCN+"'s eyes as "+ETO->QP+" wields"+
	" the hammer.",ETO);
	return 1;
}

int removeme() {
	tell_object(ETO,"%^BOLD%^%^WHITE%^The %^B_RED%^%^YELLOW%^blazing%^RESET%^"+
	" %^BOLD%^hammer cools as you set it aside.");
	tell_room(environment(ETO),"%^BOLD%^The %^RED%^fire%^WHITE%^ in "+ETO->QCN+"'s"+
	" eyes slowly fades as "+ETO->QS+" sets the hammer aside.",ETO);
	return 1;
}

int hitme(object targ) {
    if(!living(ETO) || !living(targ)) return 0;
        if(!random(8)) {
		tell_object(ETO,"%^BOLD%^You slam your hammer with tremendous force into "+targ->QCN+"!");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+" slams "+ETO->QP+""+
		" hammer into you with tremendous force!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" slams "+ETO->QP+""+
		" hammer into "+targ->QCN+" with tremendous force!",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(3)+4);
		remove_property("magic");
		return 1;
	}
        if(!random(15)) {
		tell_object(ETO,"%^MAGENTA%^You swing your hammer in a full circle,"+
		" solidly connecting with "+targ->QCN+".");
		tell_object(targ,"%^MAGENTA%^"+ETO->QCN+" swings "+ETO->QP+""+
		" hammer in a full circle, solidly connecting with your chest.\n"+
		"It almost feels like something broke!");
		tell_room(environment(ETO),"%^MAGENTA%^There is a sickening crunching"+
		" sound as "+ETO->QCN+" swings "+ETO->QP+""+
		" hammer into "+targ->QCN+".",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(5)+6);
		remove_property("magic");
		targ->set_paralyzed(7,"You got the wind knocked out of you.");
		return 1;
	}
	if(!random(20)) {
		tell_object(ETO,"Your hammer %^B_RED%^%^YELLOW%^blazes%^RESET%^ with"+
		" a %^RED%^%^BOLD%^ruby%^RESET%^ light, you can feel the fury of battle"+
		" strengthen you.\n"+
		"%^BOLD%^You release that fury on "+targ->QCN+"!");
		tell_room(environment(ETO),""+ETO->QCN+" gets a %^RED%^mad%^RESET%^"+
		" look in "+ETO->QP+" eyes as "+ETO->QP+""+
		" hammer %^B_RED%^%^YELLOW%^blazes%^RESET%^ to life!",ETO);
		tell_object(targ,"%^BOLD%^That hammer slams forcefully into you!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" slams"+
		" "+ETO->QP+" hammer forcefully into "+targ->QCN+"!",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(5)+10);
		remove_property("magic");
		targ->set_paralyzed(8,"You are recovering from that last hit.");
		ETO->do_damage("torso",(-1)*(random(5)+3));
		return 1;
	}
	if(!random(30)) {
		tell_object(ETO,"%^YELLOW%^You feel a power swell within your hammer.");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^Crimson fire engulfs"+
		" "+targ->QCN+", who screams in absolute agony!",targ);
		tell_object(targ,"%^BOLD%^%^RED%^Crimson fire leaps into life around"+
		" you, the painful burning causes you to scream in agony!");
		set_property("magic",1);
		targ->do_damage("torso",random(10)+15);
		remove_property("magic");
		if(!"daemon/saving_d"->saving_throw(targ,"spell",-10)) {
			tell_object(targ,"%^RED%^Instead of dying down, the flames continue"+
			" to burn around you!");
			num = 3+random(3);
			call_out("more_burn",ROUND_LENGTH,targ);
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^MAGENTA%^Thankfully the flames die down"+
			" and disappear.");
			tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^The flames quickly die down"+
			" around "+targ->QCN+".",targ);
			return 1;
		}
		return 1;
	}
	return 3;
}

void more_burn(object targ) {
      if(!objectp(TO)) return;
	if(!objectp(ETO) || !objectp(targ)) {
		call_out("dest_effect",ROUND_LENGTH);
		return ;
	}
	tell_object(targ,"%^BOLD%^%^RED%^The crimson blaze continues to suround"+
	" you, filling your body with pain!");
	tell_room(environment(targ),"%^BOLD%^%^RED%^The crimson blaze continues"+
	" to surround "+targ->QCN+" with its deadly embrace.",targ);
	targ->do_damage("torso",random(4)+5);
	if(num-- > 0) {
		call_out("more_burn", ROUND_LENGTH);
		return 1;
	}
	else {
		call_out("dest_effect",ROUND_LENGTH);
		return ;
	}
	return ;
}

void dest_effect(object targ) {
	if(!objectp(targ)) return;
	if(find_call_out("more_burn") != -1) {
		remove_call_out("more_burn");
		return ;
	}
	if(targ) {
		tell_object(targ,"%^RED%^The crimson blaze at last subsides.");
		tell_room(environment(targ),"%^RED%^The crimson blaze dies down around"+
		" "+targ->QCN+".",targ);
		return ;
	}
	return ;
}
