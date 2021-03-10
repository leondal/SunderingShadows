//Added lore - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/weapon/mace.c";

int FLAG;

void create()
{
	::create();
   set_obvious_short("A white marble mace");
	set_name("Mace of the Heavens");
	set_short("%^YELLOW%^Mace of the Heavens%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A %^YELLOW%^gilded%^WHITE%^ white marble mace%^RESET%^");
	set_id(({"mace","mace of the heavens","Mace of the Heavens","heavens mace","heaven's mace"}));
	set_long(
	"The shaft of this mace is carved from %^BOLD%^white marble%^RESET%^ that has"+
	" spectacular swirls of %^YELLOW%^gold%^RESET%^ running through it. The pommel"+
	" is gilded with %^YELLOW%^gold%^RESET%^ and has strange symbols carved into"+
	" it. The head of the mace is also made out of %^YELLOW%^gold%^RESET%^ that has"+
	" obviously been enchanted. The spikes on the mace look incredibly sharp, and"+
	" unlike regular gold you doubt this stuff will be easily bent or dulled."
	);
	set_lore("The Mace of the Heavens is a blessed weapon that was first"+
		" given to a devoted cleric of Torm by the name of Kaliam.  The"+
		" half-elf cleric was heralded for his devotion to Torm the True"+
		" during his time.  Kaliam always leapt to the aid of those who "+
		"could not fight or protect themselves from the forces of darkness."+
		"  During the night of the 17th of Autumnstime in the year of 525,"+
		" Kaliam had returned to Torm's temple in hopes of starting his "+
		"fasting and mediation.  Purifying himself and ready to enter one"+
		" of the private alcoves reserved for these types of rituals, Kaliam's"+
		" plans were ruined.  An attack upon the temple by a small army of ogres,"+
		" orcs, goblins, and kobolds swarmed through the temple gates.  Kaliam"+
		" leapt into action, rushing to defend his temple and faith from the "+
		"attack lead by the Dark Knight of Xvim, Paldirem.  Dressed only in "+
		"his white vestments, Kaliam helped rally the priests and guards of "+
		"the temple to push back the army.  During the confusion of the battle"+
		" though, Kaliam found himself separated from his fellow Tormtar and "+
		"before the Dark Knight Paldirem.  Before Kaliam knew it he heard the"+
		" roar of a lion, a typical sign of Torm's favor, and in his hand a "+
		"gilded white marble mace appeared.  Now armed with this blessed "+
		"weapon, Kaliam was able to defeat and slay the Dark Knight and end"+
		" the attack upon the temple.  To this day still, many Tormtar use "+
		"Kaliam's devotion and pious nature as an example to the acolytes of"+
		" what it means to be a priest of Torm the True.");
	set_property("lore",13); 
   	set_value(2000);
        set_property("enchantment",4);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

void init()
{
	::init();
	add_action("readme","read");
}

void readme(string str)
{
	if(!ETO->is_class("cleric") && str == "mace" || str == "handle" || str == "symbols") {
		tell_object(ETO,"You can't seem to understand the symbols.");
		return 1;
	}
	if(ETO->is_class("cleric") && str == "mace" || str == "handle" || str == "symbols") {
		tell_object(ETO,"You look over the symbols and seem to understand them. They read:\n"+
		"%^YELLOW%^The Path of the Light is through the Heart, follow your Heart and"+
		" you follow the Path to the Heavens.\n");
		return 1;
	}
}

int wieldme()
{
	if(TP->query_level() < 20) {
//adjusted to 20 to match the Nightbringer ~Circe~ 4/19/13
		tell_object(ETO,"You are not powerful enough to use this fine weapon.");
		return 0;
	}
	if(ALIGN->is_evil(ETO)) {
		tell_object(ETO,"%^BOLD%^The %^YELLOW%^Mace of the Heavens%^WHITE%^ will not"+
		" let someone with your corrupted soul wield its might!");
		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" screams in agony as "+ETO->query_possessive()+""+
		" hand is burned by the mace!",TP);
		tell_object(ETO,"%^RED%^A raging fire burns through your body, tearing at your soul!");
		set_property("magic",1);
		ETO->do_damage("torso",random(20)+30);
		ETO->add_attacker(TO);
		ETO->continue_attack();
		ETO->remove_attacker(TO);
		ETO->set_paralyzed(8,"You are in absolute agony!");
		remove_property("magic");
		return 0;
	}
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The mace of the heavens refuses to be wielded while you're using such evil items!");
      return 0;
   }
	if(ETO->is_class("cleric")) {
		FLAG = 1;
		tell_object(ETO,"%^YELLOW%^A warm tingle washes up your arm as you grip the"+
		" Mace of the Heavens.");
		tell_room(environment(ETO),"%^YELLOW%^"+TP->QCN+" confidently wields the Mace"+
		" of the Heavens.",ETO);
      ETO->set_property("good item",1);
		return 1;
	}
	else {
		FLAG = 0;
		tell_object(ETO,"%^BOLD%^You can feel the power within the mace as you grasp the handle.");
      ETO->set_property("good item",1);
		return 1;
	}
}

int removeme()
{
	if(ETO->is_class("cleric")) {
		tell_object(ETO,"%^ORANGE%^You feel the power leave you as you release the mace.");
		tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+" sighs in exhaustion as"+
		" "+ETO->QS+" releases "+ETO->query_possessive()+" mace.",ETO);
		FLAG = 0;
      ETO->set_property("good item",-1);
		return 1;
	}
   ETO->set_property("good item",-1);
	return 1;
}

int hitme(object targ)
{
	if(FLAG != 1) {
		if(!random(5)) {
         tell_object(ETO,"You swing your mace with incredible might, striking "+targ->QCN+"!");
			tell_object(targ,""+ETO->QCN+" strikes you with incredible force!");
			tell_room(environment(ETO),""+ETO->QCN+" strikes "+targ->QCN+""+
			" with incredible force!",({ETO,targ}));
			targ->do_damage("torso",random(5)+3);
			return 1;
		}
		if(!random(10)) {
			tell_object(ETO,"%^YELLOW%^The mace glows with a faint light as you bash "+targ->QCN+".");
			tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s mace glows with a"+
			" faint light as "+ETO->QS+" hits you with it.");
			tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s mace"+
			" glows with a faint light as "+ETO->QS+" hits"+
			" "+targ->QCN+" with it.",({ETO,targ}));
			targ->do_damage("torso",random(4)+4);
			ETO->do_damage("torso",-(random(3)+2));
			return 1;
		}
		return 1;
	}
	if(FLAG == 1) {
		if(!random(25)) {
			tell_object(ETO,"%^YELLOW%^The mace bathes you in a warm golden glow.");
			tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" becomes"+
			" surrounded in a golden glow from "+ETO->query_possessive()+" mace.",ETO);
			ETO->do_damage("torso",-(random(8)+20));
			return 1;
		}
		if(!random(15)) {
			if(ALIGN->is_evil(targ)) {
				tell_object(targ,"%^BOLD%^%^RED%^An agonizing blaze of fire ignites the"+
				" evil within your soul!");
				tell_object(ETO,"%^ORANGE%^As you strike "+targ->QCN+""+
				" "+targ->QS+" doubles over in agony as your mace attacks"+
				" the evil it senses within "+targ->QO+".");
				tell_room(environment(ETO),"%^ORANGE%^"+targ->QCN+" suddenly"+
				" doubles over in agony after "+ETO->QCN+" hits "+targ->QO+".",({ETO,targ}));
				set_property("magic",1);
				targ->do_damage("torso",random(8)+20);
				remove_property("magic");
				return 1;
			}
			tell_object(ETO,"%^BOLD%^%^CYAN%^The mace seems to lend you power as you deliver a devastating"+
			" blow to "+targ->QCN+".");
			tell_object(targ,"%^ORANGE%^"+ETO->QCN+" practically knocks"+
			" you over with the sheer force of "+ETO->query_possessive()+" blow!");
			tell_room(environment(ETO),""+ETO->QCN+" strikes "+targ->QCN+""+
         " so hard "+ETO->QS+" nearly knocks "+targ->QO+""+
			" over.",({ETO,targ}));
			targ->do_damage("torso",random(8)+8);
			targ->set_paralyzed(2,"You're recovering from that last hit.");
			return 1;
		}
                if(!random(5) && objectp(targ)){
			tell_object(ETO,"%^BOLD%^You swing your mace with deadly ease, scoring a"+
			" costly blow on "+targ->QCN+".");
			tell_object(targ,"%^BOLD%^"+ETO->QCN+" seems to exert no"+
			" effort at all as "+ETO->QS+" strikes you with deadly accuracy.");
			tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" seems to"+
			" exert no effort at all as "+ETO->QS+" strikes "+targ->QCN+""+
			" with deadly accuracy.",({ETO,targ}));
			targ->do_damage("torso",random(5)+8);
			return 1;
		}
		return 1;
	}
	return 1;
}
