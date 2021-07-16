#include <std.h>
#include "../theater.h"

inherit "std/monster";
    void create(){
      object obj;
      ::create();
	set_name("mashiva");
	set_id(({"mashiva", "devil","eryines"}));
	set_short("Mashiva, The Eryines");
	set_long("%^GREEN%^With her %^ORANGE%^d%^BOLD%^%^BLACK%^"+
		"a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k%^RESET%^%^ORANGE%^"+
		" cocoa%^GREEN%^ skin and short"+
		" %^BOLD%^%^BLACK%^black hair%^RESET%^%^GREEN%^, Mashiva"+
                " possesses an exotic beauty.  Her curvaceous form is a perfect"+
                " hourglass figure, a figure that mortal women would die for."+
		"  There is a womanly softness to her form, a body that is "+
		"neither too thin or lean, nor ample or hefty.  Her short "+
		"%^BOLD%^%^BLACK%^black hair%^RESET%^%^GREEN%^ spirals in "+
		"tight curls around her face, the dark color setting off "+
		"her %^BOLD%^%^MAGENTA%^magenta%^RESET%^%^GREEN%^ eyes.  "+
		"Rising out of her back are a pair of dark feathered wings."+
		"  The colors of her plumes fade from %^BOLD%^%^BLACK%^pitch "+
		"black%^RESET%^%^GREEN%^ to a %^BLUE%^blue%^GREEN%^-%^MAGENTA%^"+
		"violet%^GREEN%^ shade, adding to her unearthly beauty.  "+
		"Dressed in a tight outfit that is barely there, there is "+
		"little left to imagination with this devil.  Though being"+
		" an eryines, it's hard to say if this is her true form.%^RESET%^");
	set_race("devil");
	set_gender("female");
	set_body_type("human");
	set_overall_ac(8);
	set_hd(25,0);
	set_class("fighter");
	set_class("mage");
	set_class("cleric");
	set_mlevel("fighter",25);
	set_mlevel("mage",25);
	set_mlevel("cleric",25);
	set_level(25);
	set_guild_level("mage",25);
	set_guild_level("fighter",25);
	set_guild_level("cleric",25);
	set_size(2);
	set_stats("strength",19);
	set_stats("intelligence",10);
	set_stats("dexterity",18);
	set_stats("charisma",24);
	set_stats("constitution",18);
	set_stats("wisdom",12);
	set_alignment(3);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	add_search_path("/cmds/mage");
	add_search_path("/cmds/cleric");
      add_limb("left wing","torso",0,0,0);
      add_limb("right wing","torso",0,0,0);
		switch(random(20)){
case 0..5:
		obj=new(OBJ"glamchain")->move(TO);
		obj=new(OBJ"chessflail")->move(TO);
		obj=new(OBJ"steelshield")->move(TO);
		command("wield flail");
		command("wearall");
break;
case 6..9:
		obj=new(OBJ"titansword")->move(TO);
		obj=new(OBJ"eryinesleather")->move(TO);
		obj = new("/d/laerad/obj/bracers3");
		obj->set_property("monsterweapon",1);
		obj->move(TO);
		command("wear bodice");
		command("wield sword");
break;
case 10..14:
		obj=new(OBJ"titansword")->move(TO);
		obj=new(OBJ"glamchain")->move(TO);
		command("wield sword");
		command("wearall");
break;
default:
		obj=new(OBJ"chessflail")->move(TO);
		obj=new(OBJ"eryinesleather")->move(TO);
		obj = new(OBJ"steelshield")->move(TO);
		obj = new("/d/laerad/obj/bracers3");
		obj->set_property("monsterweapon",1);
		obj->move(TO);
		command("wearall");
		command("wield flail");
break;
}
	obj=new("/d/deku/armours/ring_p.c");
	obj->set_property("monsterweapon",1);
	obj->set_property("enchantment",3);
	obj->move(TO);
        obj=new(OBJ"innocentdress")->move(TO);
	new(OBJ"r_shoes")->move(TO);
	force_me("wearall");
	add_money("electrum",random(2000)+9000);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(50)+750);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",25);
	set_property("add kits",4);
	set_diety("loviatar");
	set_property("weapon resistance",2);
	set_property("no bow",1);
	set_property("no dominate",1);
	set_property("no trip",1);
	set_property("no paralyze",1);
	set_property("no stab",1);
	set_property("no rush",1);
	set_property("no charge",1);
	set_funcs(({"rushit","flashit","flashit","wail"}));
	set_func_chance(40);
	set_spells(({"acid orb",
                     "shout",
                     "wave of pain",
                     "lower_resistance",
                     "vampiric touch",
                     "shout",
                     "wave of pain",
                     "kiss of torment"}));
	set_spell_chance(45);
      set_exp(random(2000)+8000);
	  set_max_level(15);
	set_languages( ({ "common" }) );
	set_emotes(10,({"%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^Ah who sent "+
		"me children?","%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^I see bathing"+
		" is still not in style","%^MAGENTA%^Mashiva says in a sultry voice:%^CYAN%^"+
		"Gee you figured it all out.  Wow you are the smart one.","%^MAGENTA%^Mashiva says"+
		" in a sultry voice:%^CYAN%^With your looks, may I recommend a dark room."}),0);
	force_me("message in flies in on her wings");
      force_me("message out flies $D");
	set_monster_feats(({
      "parry",
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
}
void rushit(object targ) {
  	TO->force_me("rush" +targ->query_name());
}

void flashit(object targ) {
  TO->force_me("flash" +targ->query_name());
}

void wail(object targ)
{
	if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
    		tell_object(targ,"%^CYAN%^Mashiva takes a deep breath before she"+
			" lets loose an ear piercing scream that knocks you back.");
      	tell_room(ETO,"%^CYAN%^Mashiva takes a deep breath before she"+
			" lets loose an ear piercing scream that knocks. "+targ->QCN+""+
			" off their feet.",targ);
    				targ->set_trip(3,"%^BOLD%^%^CYAN%^Your ears are still ringing.");
        	return 1;
	}
else {
    	tell_object(targ,"%^CYAN%^Mashiva takes a deep breath before she"+
		" lets loose an ear piercing scream that knocks you back just slightly.");
     	tell_room(ETO,"%^CYAN%^Mashiva takes a deep breath before she "+
		"lets loose an ear piercing scream that knocks "+
      	" "+targ->QCN+" back slightly",targ);
    	return 1;
	}
}
void die(object ob) {
    int i;
    object *att;
	tell_room(ETO, "%^BOLD%^%^CYAN%^Mashiva falls from the air.  Her limp "+
		"body crashes against the flagstones of the courtyard."+
		"  %^BOLD%^%^BLACK%^Black blood%^CYAN%^ trickles"+
		" from her lifeless body, staining the stones.");
att = all_living(ETO);
    for(i=0;i<sizeof(att);i++){
      if(!interactive(att[i])) continue;
      att[i]->set_mini_quest("Desert Sun Theater", 1000000,"%^RED%^You solved the mystery of %^BOLD%^The %^YELLOW%^D%^RESET%^%^ORANGE%^e%^YELLOW%^s%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^%^ORANGE%^t%^RED%^ S%^BOLD%^u%^RESET%^%^RED%^n%^BOLD%^ Theater.");
      tell_object(att[i], "\n%^CYAN%^With the death of the eryines, the "+
		"mystery of The Desert Sun Theater has been solved.\n");
    }
    ::die(ob);
}
