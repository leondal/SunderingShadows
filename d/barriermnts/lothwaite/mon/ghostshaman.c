#include <std.h>
#include <daemons.h>
#include "../lothwaite.h"
inherit MONSTER;

string *asked;
string *killers;
int step1;
int step2;
int step3;

void create()
{
object obj;
	::create();
	set_name("firbolg shaman");	
	set_id(({"ghost","undead","monster","firbolg","giant","firbolg ghost","giant ghost","shaman","firbolg shaman"}));
	set_short("A solemn firbolg ghost");
	set_gender("male");
	set_size(3);
      set_long(
        "This spirit somehow carries an aged, wise air heightened "+
        "by the %^RESET%^silver sheen %^CYAN%^of his long hair.  "+
        "Though insubstantial, his eyes still glimmer a %^BOLD%^"+
        "%^BLUE%^faint blue %^RESET%^%^CYAN%^and hint at a deep "+
        "intelligence and understanding.  The ghost towers well "+
        "over fifteen feet tall, and he hovers several inches off "+
        "the ground.  He is clad in long, flowing %^RESET%^white "+
        "robes %^CYAN%^gathered at the waist with a slender "+
        "%^ORANGE%^rope belt %^CYAN%^threaded with %^ORANGE%^"+
        "wooden beads%^CYAN%^.  He carries an intricate %^ORANGE%^"+
        "staff %^CYAN%^in his right hand, though he clearly does "+
        "not need it to walk now.  His furrowed brow reveals "+
        "that his heart is troubled by some unsettled matter, one "+
        "he might be willing to talk about."
      );
	set_property("undead",1);
	set_hd(40,6);
	set_max_level(40);
	set_body_type("firbolg");
	set_overall_ac(-10);
	set_alignment(4);
	set_race("ghost");
	set_max_hp(random(100)+750);
	set_hp(query_max_hp());
	set_class("cleric");
	set_mlevel("cleric",40);
      set_guild_level("cleric",40);
	set_level(40);
      new(OBJ"ghoststaff")->move(TO);
      command("wield staff");
	set_funcs(({"touch","drain","scare"}));
      set_func_chance(10);
	set_exp(60000+random(1500));
 	add_money("platinum",random(50)+25);
	set_property("swarm",1);
	set("aggressive",0);
	set_property("weapon resistance",2);
	set_mob_magic_resistance("average");
}

int touch(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^CYAN%^The ghost reaches "+
                    "out and touches your cheek, draining your strength!");
			tell_room(ETO,"%^BOLD%^%^CYAN%^The ghost"+
			" touches "+targ->query_cap_name()+"'s cheek and seems to drain"+
			" "+targ->query_objective()+" of "+targ->query_possessive()+""+
			" strength.",targ);
			targ->add_stat_bonus("strength",-1);
			return 1;
		}
		else {
			tell_object(targ,"You successfully resist the icy"+
			" touch of the ghost.");
			tell_room(ETO,"The ghost touches "+targ->query_cap_name()+","+
			" but "+targ->query_subjective()+" seems to be alright.",targ);
			return 1;
		}
		return 1;
}

int drain(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^The ghost seems to drain"+
			" your life force from you!");
			tell_room(ETO,"%^BOLD%^The ghost seems"+
			" to drain "+targ->query_cap_name()+"'s life force"+
			" from "+targ->query_objective()+"!",targ);
                     targ->resetLevelForExp(-(random(500)+500));
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^The ghost attempts to drain"+
			" away some of your life but fails.");
			tell_room(ETO,"The ghost tries to drain"+
			" away "+targ->query_cap_name()+"'s life force but"+
			" nothing seems to happen.",targ);
			return 1;
		}
		return 1;
}

int scare(object targ)
{
		if(!"daemon/saving_d"->saving_throw(targ,"spell")) {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes and you feel yourself "+
                     "frozen in fear!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" looks "+
                     "terrified as "+targ->QS+" gazes at the ghost!",targ);
                  targ->set_tripped(1,"%^BOLD%^You are frozen in fear of the ghost.");
			return 1;
		}
		else {
			tell_object(targ,"%^BOLD%^%^BLUE%^The ghost "+
                     "stares into your eyes, but you resist its power!");
			tell_room(ETO,"%^BOLD%^%^BLUE%^The ghost stares "+
                     "at "+targ->QCN+" but nothing happens.",targ);
			return 1;
		}
		return 1;
}

void heart_beat()
{
   ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(query_hp() < query_max_hp())
      add_hp(random(5));
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("lothwaite_asked");
   killers = SAVE_D->query_array("lothwaite_killers");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote 's eyes flash as a low rumble fills the halls.");
      force_me("say %^BOLD%^%^BLUE%^Foul deceiver!  You will not take "+
         "me again!");
      force_me("emote grows translucent, then fades away!");
      TO->move("/d/shadowgate/void"); 
      TO->remove();
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote seems absorbed in his conversation with "+who->QCN+".");
     return;
   }
   if(who->query_quests()) {
     if(member_array("Lothwaite Quest",who->query_quests()) != -1) {
        force_me("say %^BOLD%^%^BLUE%^Thank you for your aid in "+
           "returning one of my most precious creations.");
        force_me("say %^BOLD%^%^BLUE%^You are free to come and go "+
           "as you please in return for your aid.  All you need "+
           "do is simply knock on the wall, and the lid will open "+
           "for you!");
        force_me("emote smiles.");
     return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say %^BOLD%^%^BLUE%^I implore you, seek out my king!");
     if(!random(3))
      force_me("say %^BOLD%^%^BLUE%^If there is kindness in your heart, "+
         "find the belt and return it to the king so our souls may rest.");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote pauses in his ceaseless hovering to look down at you.");
      force_me("say %^BOLD%^%^BLUE%^Greetings, I was once the grand "+
         "shaman of this vale.  I am called Helgatha Rothmar.");
      if(race == "firbolg") {
         force_me("say %^BOLD%^%^BLUE%^It is good to see one of my kind here.");
         force_me("smile "+name);
         force_me("say %^BOLD%^%^BLUE%^Perhaps you can help me?");
         return;
      }
      else {
         force_me("eye "+name);
         force_me("say %^BOLD%^%^BLUE%^I do not know how you were "+
            "admitted to this sacred resting ground, but...");
         force_me("say %^BOLD%^%^BLUE%^I suppose I must ask for your "+
            "aid anyway.  I am at a loss.  Will you help me?");
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"not evil") != -1)&& step1 && !step2)        {
      force_me("say %^BOLD%^%^BLUE%^My spirit - and those of my "+
         "kindred - has been lying at rest here for centuries.  "+
         "Recently, though, there have been...disturbances.");
      force_me("emote pauses and glances around worriedly.");
      force_me("say %^BOLD%^%^BLUE%^A thief has slipped in among "+
         "us and stolen the king's belt!  It is a most precious "+
         "item, and it must be returned, else the spirits of "+
         "my kindred will rise up in wrath!");
      force_me("say %^BOLD%^%^BLUE%^Have you seen a golden belt?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"belt") != -1 || strsrch(msg,"golden belt") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"gem") != -1 || 
   strsrch(msg,"no") != -1 || strsrch(msg,"Yes") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("lothwaite_asked", name);
      }
      force_me("say %^BOLD%^%^BLUE%^The thief did not come this way, "+
         "so I am sure he is down below in the crypts.  The king's "+
         "chamber is hidden there as well.  Find the belt and take "+
         "it to the king.  He will reward you richly!");
      step3 == 1;
		return;
  }
  switch(random(4)){
      case 0:
         force_me("say %^BOLD%^%^BLUE%^Have you ventured below?");
         break;
      case 1:
         force_me("say %^BOLD%^%^BLUE%^Beware the spirits!  They are in "+
            "a foul rage.");
         break;
      case 2:
         force_me("say %^BOLD%^%^BLUE%^Have you heard my tale of "+
            "thieves and intrigue?");
         break;
      case 3:
         force_me("emote peers down the stairwell, preoccupied.");
         break;
   }
   return;
}

void receive_given_item(object obj){
   object item;
   int size;
   asked = SAVE_D->query_array("lothwaite_asked");
   killers = SAVE_D->query_array("lothwaite_killers");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote 's eyes flash as a low rumble fills the halls.");
      force_me("say %^BOLD%^%^BLUE%^Foul deceiver!  You will not take "+
         "me again!");
      force_me("emote grows translucent, then fades away!");
      TO->move("/d/shadowgate/void"); 
      TO->remove();
      return;
   }
   if((string)obj->query_name() != "belt of giant strength") {
       force_me("say %^BOLD%^%^BLUE%^Thank you, kind soul...though "+
          "I do not know how I deserve this.");
       obj->remove();
       return;
   }   
   if((string)obj->query_name() == "belt of giant strength") {
      force_me("emote smiles slightly.");
      force_me("say %^BOLD%^%^BLUE%^Please, I implore you...find our "+
         "king hidden deep within these catacombs.  Return the belt to "+
         "him so that we might find rest once more.");
      force_me("give belt to "+TPQN+"");
      return;
   }
   return;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}

