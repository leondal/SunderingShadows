//Octothorpe (2/15/09)
//Underdark Mining Caverns, Kobold Sorceror
//Based on Rosinden
///d/shadow/room/ekibi/mon/rosinden.c

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit MONSTER;

int step1;
int step2;
string *asked;

void create(){
   object ob1;
   object ob2;
   ::create();
   set_id(({"kobold","kobold sorcerer","sorcerer","sistnak","Sistnak"}));
   set_name("sistnak");
   set_short("%^ORANGE%^Sistnak, Kobold Sorcerer");
   set_long("%^RESET%^%^ORANGE%^This short reptillian creature is "+
      "clothed in the remnants of a ragged %^BOLD%^%^BLACK%^black "+
      "%^RESET%^%^ORANGE%^robe and the stench of a mangy canine. The "+
      "kobold's head is obscured by a large, ridiculous looking dragon "+
      "mask, which does little to lend to this creature's credibility "+
      "or skill. His long tail is perpetually twitching and swishing "+
      "about, and bears deep gnaw marks on the tip.%^RESET%^");
   set_race("kobold");
   set_body_type("human");
   set_gender("male");
   set_alignment(3);
   set_size(1);
   set_class("mage");
   set_guild_level("mage",29);
   set_mlevel("mage",29);
   add_search_path("/cmd/mage");
   set_hd(29,random(4)+1);
   set_spells(({
      "meteor swarm",
      "greater shout",
      "magic missile",
      "magic missile",
      "meteor swarm",
      "powerword stun",
      "prismatic spray",
      "prismatic spray",
      "chain lightning",
      "chain lightning",
      "fireball",
      "fireball",
      "incendiary cloud",
      "ice storm"
   }));
   set_spell_chance(75);
   set_overall_ac(-5);
   set_stats("strength",11);
   set_stats("constitution",14);
   set_stats("dexterity",15);
   set_stats("charisma",13);
   set_stats("intelligence",18);
   set_stats("wisdom",11);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_max_hp(random(100)+225);
   set_hp(query_max_hp());
   set_new_exp(17,"boss");
   set_max_level(20);
   set_overall_ac(-10);
   set_mob_magic_resistance("average");
   set_property("spell penetration",45);
   set_wielding_limbs(({"left hand","right hand"}));
   ob1 = new(OBJ"dragoncloak");
   ob1->move(TO);
   command("wear cloak");
   ob2 = new(OBJ"dragonmask");
   ob2->move(TO);
   command("wear mask");
   set("aggressive",3);
   command("speak wizish");
   command("speech %^RESET%^%^ORANGE%^say in a muffled tone%^RESET%^");
   set_func_chance(30);
   set_funcs(({"stoneme","helpme"}));
   add_money("silver", random(10000)+30);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void receive_given_item(object obj){
   object ob;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "earth amulet") {
      obj->remove();
      force_me("emote wags his tail in an excited manner.");
      force_me("say Oh yes...da great Bloodscale be pleased wit dis offerin'.");
      if(!userp(TP)) return;
      if(member_array("Assisted the Kobolds",TP->query_mini_quests()) == -1){
         tell_object(TP,"%^BOLD%^You've just finished Assisted the "+
            "Kobolds!");
         TP->set_mini_quest("Assisted the Kobolds",500000,"Assisted the Kobolds");
      }
      if(ob = present("bldscl",TP)){
         ob->move("/d/shadowgate/void");
         ob->remove();
      }
      force_me("say Here, hab dis junk, surfacer.");
      TP->add_money("electrum",2000+random(1000));
      force_me("give "+query_money("electrum")+" electrum coins to "+TPQN);
      if(present("scale cloak",TO)) force_me("give cloak to "+TPQN);
      force_me("wear amulet");
      return;
   }
   force_me("say Wat is dis crap?");
   force_me("emote throws the item over his shoulder, sending it "+
      "falling into the chasm below.");
   obj->remove();
   return;
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(objectp(current) && who != current) {
      force_me("emote seems annoyed with the interruption and returns "+
         "his attention to "+who->QCN+".");
      return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
      if(member_array("Assisted the Kobolds",TP->query_mini_quests()) != -1){
         force_me("say Are da gnomeses be deads yet?"),
         force_me("emote begins pacing in a circle nervously.");
         return;
      }
      force_me("emote thoughtfully rubs his chin.");
      force_me("say Mebbe you be good helps fer da mighteh Bloodscale.");
      force_me("say Does ya want a chance to take cares of sum 'nnoyin' gnomeses?");
      force_me("emote unconsciously begins to gnaw on the end of his tail.");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"kay") != -1 || strsrch(msg,"elp") != -1 || strsrch(msg,"Ok") != -1 || strsrch(msg,"ok") != -1) && step1 && !step2){
      force_me("emote nods his head and grins a draconic grin.");
      force_me("say Da evil gnomses haz invaded da territory of da great "+
         "Bloodscale. Dey thinks dey be all crafties 'n such, but "+
         "nunthin gits by meh 'n the great Bloodscale.");
      force_me("say Da Bloodscale wants da glowy rocks 'n crystals in "+
         "da big cavern 'bove us.  Da gnomeses be tryin' to steals da "+
         "Great One's glowy rocks 'n stuff.");
      force_me("say But yous can help us keeps Bloodscale's glowly "+
         "rocks Bloodscale's.  How 'bout you help us tails 'n go kill "+
         "da gnomeses?");
      force_me("emote raises the ridge above his right eye in a "+
         "questioning manner.");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"kay") != -1 || strsrch(msg,"help") != -1 || strsrch(msg,"Ok") != -1 || strsrch(msg,"ok") != -1 || strsrch(msg,"ure") != -1) && step2 == 1){
      force_me("say Good, good good...");
      force_me("say Da slimey gnomeses can be found in da big cavern, "+
         "toward da south end.  Dey thinks dey be all smarts and hidey, "+
         "but methinks you find da way in.");
      force_me("emote nods to himself in a self-assured manner.");
      force_me("say Git in dere 'n kill teh big bad boss gnomes.  "+
         "He haz big shiney 'round his neck, bring it back to me, "+
         "'n I give ya some shiney junk fer ya trouble.");
      force_me("emote turns away and walks to the edge of the "+
         "outcropping.");
      new(OBJ"kobtoken")->move(TP);
      step1 = 0;
      step2 = 0;
      return;
   }
}

void stoneme(){
   if(TO->query_stoneSkinned()){
      return 0;
   }
   new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,29,100,"mage");
}

void helpme(object targ)
{
	object obx;
   	object oby;
   	object obz;
	if(present("kobold 6", ETO)) 
	{
		return stoneme();
	}
   	TO->force_me("say Eeeek! Dey be too strongs, git mar tails 'n 'ere quicks!");
   	tell_room(ETO,"%^ORANGE%^The sound of scampering claws becomes "+
      "louder as some draconic backup enters the area.%^RESET%^");
   	obx = new(MON+"kobchamp.c");
   	obx->move(ETO);
   	TO->add_follower(obx);
   	TO->add_protector(obx);
    	if(!random(2) && !present("kobold 5", ETO))
	{
      	oby = new(MON+"koboldbasic.c");
	      obz = new(MON+"koboldbasic.c");
		TO->add_follower(oby);
	  	TO->add_follower(obz);
      	oby->move(ETO);
      	obz->move(ETO);
      	TO->add_protector(oby);
	  	TO->add_protector(obz);
   	}
} 

//Adapted from Grazzt's goblins, query_invis suggestion from Nienne
void init(){
   string mrace=TP->query_race();
   ::init();
   if(TP->query_invis()) return;
   if(mrace == "gnome" || mrace == "svirfneblin" || mrace == "halfling" || mrace == "elf" || mrace == "hook horror" || mrace == "dwarf"){
      command ("kill "+TPQN);
      new("/cmds/spells/w/_wall_of_fire.c")->use_spell(TO,0,29,100,"mage");
   new("/cmds/spells/d/_dragon_scales.c")->use_spell(TO,TO,29,100,"mage");
   }
   if(present("gldstr",TP)){
      command ("kill "+TPQN);
   } 
}

//Thanks to Nienne for the following code
void die(object ob){
   int i, flag;
   object myob, myob2, myob3, *mytarg;
   mytarg=TO->query_attackers();
   flag = 0;

   if(sizeof(mytarg)){
      for(i=0; i< sizeof(mytarg); i++)
      if(userp(mytarg[i])) flag = 1;
   }
   if(!flag){
      myob=present("scale cloak");
         if(myob){
            myob->move("/d/shadowgate/void");
            myob->remove();
         }
      myob2=present("dragon mask");
      if(myob2){
         myob2->move("/d/shadowgate/void");
         myob2->remove();
      }
      myob3=present("ruby amulet");
      if(myob3){
         myob3->move("/d/shadowgate/void");
         myob3->remove();
      }
   }
   ::die();
}
