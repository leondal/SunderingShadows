#include <std.h>

inherit "/std/spell_vend.c";

void create() {
  	int i,j;
  	float fi;
  	object ob;
  	mapping spells_sold,spells_to_sell;
  	string *spells;

  	::create();
  	set_property("no attack",1);
  	set_property("no bump", 1);
  	set_property("strength","spells");
  	set("aggressive", 0);
  	set_name("Hetori");
  	set_id( ({ "monster","Hetori", "hetori", "clerk", "shop keeper", "shopkeeper"}) );
  	set_short("%^BOLD%^%^BLACK%^He%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^i, %^RESET%^%^ORANGE%^S%^ORANGE%^p%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^l-K%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^eper%^RESET%^");
  	set_level(20);
  	set_long(
		"Hetori is a large, old, ogre-mage.  The long hair growing from "+
		"his topknot is graying and his face is lined with the wrinkles "+
		"of age.  One eye is pale and cloudy, either from his extreme "+
		"age or an errant spell, no one knows.  He offers spells for "+
		"lots and lots of money and seems to live richly as his clothing "+
		"and rings show.\n<help shop> will get you a list of shop commands."
  	);
  	set_gender("male");
  	set_alignment(3);
  	set("race", "ogre-mage");
  	set_class("mage");
  	set_hd(20,1);
   	set_size(3);
  	set_stats("intelligence",19);
  	set_stats("wisdom",14);
  	set_stats("strength",18);
  	set_stats("charisma",6);
  	set_stats("dexterity",10);
  	set_stats("constitution",17);
  	set_body_type("human");
  	set_guild_level("mage",20);
  	set_mlevel("mage",20);
  	set_overall_ac(0);
    set_spells_sold(gen_spells_sold(35));
  	set_spell_chance(90);
  	set_spells(({
  		"powerword stun",
  		"hideous laughter",
  		"fireball",
  		"magic missile",
  		"monster summoning i"
  	}));
  	set_size(3);
  	set_wielding_limbs( ({ "right hand","left hand" }) );
  	i=1000000+random(2000000);
  	set_emotes(0,({
    		"%^CYAN%^Hetori says%^RESET%^: Make your mind up and move on.",
    		"%^CYAN%^Hetori says%^RESET%^: Time is money.",
    		"%^CYAN%^Hetori says%^RESET%^: I haven't got all day.",
    		"%^CYAN%^Hetori says%^RESET%^: You look like you could use meteor "+
    			"swarms....for you only 98,000 gold.",
    		"Hetori watches you closely.",
    		"Hetori raises an eyebrow, then shakes his head while mumbling something",
    		"Hetori watches to make sure none of his scrolls walk out unpaid for."
    	}), 0);
  	set_emotes(0, ({
    		"%^BOLD%^%^CYAN%^Hetori says%^RESET%^: You bastard...I'll "+
    			"kill you for that!",
    		"%^BOLD%^%^CYAN%^Hetori says%^RESET%^: OOOOOO!!  That's gonna leave a mark!",
    		"%^BOLD%^%^CYAN%^Hetori says%^RESET%^: Dying sucks boy!"
    	}), 1);
  	ob=new("/d/shadow/obj/armor/robe.c");
  	ob->set_short("A purple robe");
  	ob->set_long("This is a purple robe owned by Hetori, the resident spell "+
  		"selling ogre-mage in Juran's tower of the magi.");
  	ob->move(TO);
  	command("wear robe");
     	set_spoken("wizish");
   	set_exp(100);
}
void init(){
    	::init();
    new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,50,100,"mage");
}
int __Pickup(string str){
    	if(TP->is_class("mage") || TP->is_class("sorcerer") || TP->is_class("bard") || avatarp(TP))
    		return ::__Pickup(str);
    	else {
      	tell_object(TP, "%^CYAN%^Hetori says%^RESET%^: You?  Hahaha, you're not "+
      		"worthy of one of these.");
      return 1;
    	}
}

int __Buy(string str){
    	if(TP->is_class("mage")|| TP->is_class("sorcerer")  || TP->is_class("bard") || avatarp(TP))
    		return ::__Buy(str);
    	else {
      	tell_object(TP, "%^CYAN%^Hetori says%^RESET%^: You?  Hahaha, "+
      		"you're not worthy of one of these.");
      return 1;
    	}
}

int __List(string str){
    	if(TP->is_class("mage") || TP->is_class("sorcerer") || TP->is_class("bard") || avatarp(TP))
    		return ::__List(str);
    	else {
      	tell_object(TP, "%^CYAN%^Hetori says%^RESET%^: You?  Hahaha, "+
      		"you're not worthy of one of these.");
      return 1;
    	}
}

int __Sell(string str){
    	if(TP->is_class("mage") || TP->is_class("sorcerer") || TP->is_class("bard") || avatarp(TP))
    		return ::__Sell(str);
    	else {
      	tell_object(TP, "%^CYAN%^Hetori says%^RESET%^: You?  Hahaha, "+
      		"you're not worthy of one of these.");
      return 1;
    	}
}

int __Help(string str){
    	if(TP->is_class("mage") || TP->is_class("sorcerer") || TP->is_class("bard") || avatarp(TP))
    		return ::__Help(str);
    	else {
      	tell_object(TP, "%^CYAN%^Hetori says%^RESET%^: You?  "+
      		"Hahaha, you're not worthy of one of these.");
      return 1;
    	}
}
