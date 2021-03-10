// Selim al-Ghazi, Pasha of the Azha Market
// Thorn@ShadowGate
// 12/19/95
// Azha Keep
// alghazi.c

#include <std.h>

inherit MONSTER;

create() {
	int level;
	object ob;
	
	::create();
	set_name("Al-Ghazi Pasha");
	set_id(({ "alghazi", "pasha", "selim", "al-ghazi" }));
	set_short("Selim al-Ghazi, Pasha of the Azha Market");
	set_long(
@TSARVEN
	Selim al-Ghazi holds the important office of the Pasha of the Azha
Market.  He regulates the traffic into and out of the market,
checking for contraband and forged licenses.  Al-Ghazi Pasha has
become very, very adept at finding both of these.  Its not likely
that you will get into the market without legitimate papers when his
eye is on you.... 
TSARVEN
	);
	set_body_type("human");
	set_race("human");
	set_gender("male");
	set_class("mage");
	level = 15;
	set_hd(level, 10);
	set_stats("strength", 10);
	set_stats("constitution", 12);
	set_stats("wisdom", 15);
	set_stats("charisma", 10);
	set_stats("intelligence", 16);
	set_stats("dexterity", 12);
}

heart_beat() {
	object *atkrs;
	int num, x;
	string name;
	
	::heart_beat();
   if(!objectp(TO)) return;
	atkrs = TO->query_attackers();
	num = sizeof(atkrs);
	if(num) {
		for(x=0;x<num;x++) {
			atkrs[x]->move("/d/azha/town/jail");
			tell_object(atkrs[x], wrap("Al-Ghazi Pasha suddenly claps his hands and "+
			"you find yourself beaten senseless by a group of Azha watchmen!!  "+
			"You wake up in Azha jail, with minor bruises but otherwise unhurt."));
			name = capitalize(atkrs[x]->query_name());
			tell_room(environment(TO), wrap(name+" is beaten senseless by some guards "+
			"and dragged off to jail while Al-Ghazi Pasha shakes his head and sighs."));
		}
		tell_room(environment(TO), wrap("Al-Ghazi Pasha says: There's nothing "+
		"to see here, go about your business.  Just a few ruffians foolishly "+
		"attempting to upset the peace of the Empire."));
	}
}
	
