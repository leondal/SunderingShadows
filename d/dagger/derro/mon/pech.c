//move stuff added by Circe to fix bugs with people's inventory being too full.  6/30/05
#include <std.h>
#include <move.h>
#include "/d/dagger/derro/derrodefs.h"
inherit MONSTER;
object obj;
int flag;
int step1;
int step2;
int step3;


void create(){
  ::create();
  set_name("Ruldizar");
  set_id(({"pech","little pech","gem-master","master","Ruldizar","ruldizar"}));
  set_race("pech");
  set_gender("male");
  set_short("Ruldizar, the pech gem-master");
  set_long(
  "  This small humanoid watches you come in with interest showing in"
  +" his wide, pupilless eyes.  He moves easily about the stone and earth"
  +" here and seems completly at home.  A strange aura surrounds him,"
  +" making you think of the power of earth and the strength of"
  +" mountains.  He looks you over as if interested in something you might"
  +" have.  Perhaps you could trade something to him?"
  );
  	set_ac(-13);
 	set_property("swarm",1);
  	set_size(1);
  	set_mob_magic_resistance("average");
  	set_body_type("human");
  	set_class("fighter");
  	set_mlevel(30);
  	add_search_path("/cmds/fighter");
  	set_alignment(5);
  	set_hd(30,20);
  	set_property("full attacks",1);
  	set_stats("strength",20);
  	set_stats("dexterity",18);
	set_stats("constitution",19);
  	set_stats("intelligence",15);
  	set_stats("wisdom",15);
  	set_stats("charisma",13);
  	set_guild_level("fighter",25);
  	set_hp(1000);
  	set_exp(10000);
  	obj=new("/d/deku/keep/obj/stonecutter.c");
  	obj->move(TO);
  	command("wield pick");
	force_me("speech say in a flat monotone voice");
}

void heart_beat(){
  int i,j;
  object *att;
  ::heart_beat();
  if((att=(object *)TO->query_attackers()) !=({})){
     j=sizeof(att);
     for(i=0;i<j;i++){
        if(!objectp(att[i])) continue;
        if((int)att[i]->query_highest_level()>29){
           call_out("force_me",2,"rush "+att[i]->query_name());
        }
     }
   }
}

void init(){
   ::init();
//   add_action("ask_em","ask");
//Removing this because I'm not sure what it was supposed to do
//and it causes bug reports ;)  Circe 12/01/07
}


void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   int TSIZE;
   TSIZE = (int)TP->query_size();

   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote turns to look at "+who->QCN+".");
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
      force_me("say Hello.");
      force_me("say Don't get to many visitors here.");
      force_me("say While you are here though, feel like doing me a"
              +" favor?");
	force_me("emote stops chipping away a the large gem.");
	force_me("say I'll be able to reward you, if that is what you"
              +" want.");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 ||
      strsrch(msg,"kay") != -1 || strsrch(msg,"yea") != -1) 
             && step1 && !step2){
      force_me("say Mmm alright.");
	force_me("emote gives a nod of his head to you.");
      force_me("say I am in need of something from the Lava Rex.");
      force_me("say Which will make my work here easier.");
	force_me("emote nods his head to the large gem he was chipping away"
              +" at.");
	force_me("say Think you can face the Lava Rex and find what I"
              +" need?");
      step2 = 1;
      return;
   }   
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 || 
   strsrch(msg,"Sure") != -1 || strsrch(msg,"Yes") != -1 
            || strsrch(msg,"sure") !=-1) && step2 == 1) {
      force_me("say Very well then.");
      force_me("emote turns back to the gem.");
      force_me("say The Lava Rex isnt an easy foe to face.");
      force_me("say Once you kill him, a piece of him.");
      force_me("emote starts to chip away at the gem with his pick.");
      force_me("say Not any piece of him will do, I need one of the lava"+
		" sacks that are inside of him.");
      force_me("emote works on chipping the large gem away.");
	force_me("say Bring it to me, and you shall have your reward.");
	step1 = 0;
      step2 = 0;
      return;
  }
	if((interact("lava", msg))||interact("sack", msg)
            ||interact ("rex",msg) ) {
      force_me("emote runs his hand over the gem.");
      force_me("say The Lava Rex is a create made by the savants from the"
              +" lava here.");
      force_me("say To keep the others from coming to me for aid, the"
               +" savants have placed him as a guardian");
      force_me("say He's attended to by snakes made from fire and lava.");
      force_me("say Not even the King himself can stand up to the Lava"
              +" Rex.");
      force_me("say Being a creature of magic and fire, his lava sack can"
               +" serve my needs.");
      force_me("say Inside his body, the lava sack is able to store lava"
               +" and allow him to spew it forth.");
	force_me("say Without any injury to him or his body.");
	force_me("say Bring me the sack and I shall reward you.");
	force_me("emote chips away a piece of the gem with his pick.");
      return;
  }
  if((interact("Emerald", msg) || interact("merald", msg)) 
        && step3 == 1) {
      force_me("say Emerald is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large"
              +" emerald.");
      force_me("emote sets the emerald down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
             +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
             +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft emerald into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
              +" there.");
	obj = new("/d/dagger/derro/obj/bplate_emerald.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of emerald."+
		" Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
  if((strsrch(msg,"Moonstone") != -1 || strsrch(msg,"oonstone") != -1)                    
            && step3 == 1) {
      force_me("say Moonstone is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large"
               +" moonstone.");
      force_me("emote sets the moonstone down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
               +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
              +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft moonstone into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
              +" there.");
	obj = new("/d/dagger/derro/obj/bplate_moonstone.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of"
               +" moonstone. Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
	if((strsrch(msg,"Sunstone") != -1 || strsrch(msg,"unstone") != -1)
             && step3 == 1) {
      force_me("say Sunstone is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large"
              +" sunstone.");
      force_me("emote sets the sunstone down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
             +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
              +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft sunstone into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
              +" there.");
	obj = new("/d/dagger/derro/obj/bplate_sunstone.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of"
              +" sunstone. Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
  if((strsrch(msg,"Sapphire") != -1 || strsrch(msg,"apphire") != -1 )
    && step3 == 1) {
    force_me("say Sapphire is it, so it shall be.");
    force_me("emote walks over to the wall and breaks off a large"
            +" sapphire.");
    force_me("emote sets the sapphire down on the floor.");
    force_me("emote dips his hand into the sack and scoops some of the"
            +" lava from with in out.");
    force_me("emote slaps the lava onto the gem and begins to shape it.");
    force_me("say Fitted just for you, this breastplate will be.");
    force_me("emote molds the soft sapphire into a breastplate.");
    force_me("say You won't find a more comfortable suit of armor out"
           +" there.");
    obj = new("/d/dagger/derro/obj/bplate_sapphire.c");
    obj->set_owner(who->QCN);
    obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
    force_me("say There you go, a breastplate made for you of sapphire."+
		" Good day now, I have to return to my work.");
    step3 = 0;
      return;
  }
  if((strsrch(msg,"Amethyst") != -1 || strsrch(msg,"methyst") != -1) 
       && step3 == 1) {
      force_me("say Amethyst is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large"
               +" amethyst.");
      force_me("emote sets the amethyst down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
              +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
              +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft amethyst into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
             +" there.");
	obj = new("/d/dagger/derro/obj/bplate_amethyst.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of"
              +" amethyst. Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
  if((strsrch(msg,"Ruby") != -1 || strsrch(msg,"uby") != -1 )
         && step3 == 1) {
      force_me("say Ruby is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large"
              +" ruby.");
       force_me("emote sets the ruby down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
             +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
             +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft ruby into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
             +" there.");
	obj = new("/d/dagger/derro/obj/bplate_ruby.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of ruby."+
		" Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
  if((strsrch(msg,"Black opal") != -1 || strsrch(msg,"lack opal") != -1 )
        && step3 == 1) {
      force_me("say Black opal is it, so it shall be.");
      force_me("emote walks over to the wall and breaks off a large black"
              +" opal.");
      force_me("emote sets the black opal down on the floor.");
      force_me("emote dips his hand into the sack and scoops some of the"
             +" lava from with in out.");
      force_me("emote slaps the lava onto the gem and begins to shape"
             +" it.");
      force_me("say Fitted just for you, this breastplate will be.");
      force_me("emote molds the soft black opal into a breastplate.");
	force_me("say You won't find a more comfortable suit of armor out"
             +" there.");
	obj = new("/d/dagger/derro/obj/bplate_bopal.c");
	obj->set_owner(who->QCN);
      obj->set_size(TSIZE);
      if (obj->move(who) != MOVE_OK){ 
		force_me("say Hrm...looks like your hands are full.  I'll "+
			"just put this here.");
		force_me("emote puts the breastplate on the ground.");
		obj->move(environment(who));
	}
	force_me("say There you go, a breastplate made for you of black"
             +" opal."+
		" Good day now, I have to return to my work.");
	step3 = 0;
      return;
  }
}

void receive_given_item(object obj){
   
  if(!objectp(obj)) return;
  if(!objectp(TP)) return;
  if((string)obj->query_name() == "lava sack") {
    obj->remove();
    force_me("say So you beat the Lava Rex did you?");
    force_me("emote looks to you with a neutral bland gaze.");
    force_me("say Well done, didn't think it was possible.");
    force_me("emote looks over the sack in his hand");
    force_me("say Still enough lava left inside, yes this will work.");
    if(!userp(TP))  return;
    if(member_array("Ruldizar's Request",TP->query_mini_quests()) == -1) {
      tell_object(TP,"%^RED%^You helped fufill Ruldizar's Request!"
                     +"%^RESET%^");
      TP->set_mini_quest("Ruldizar's Request",1000000,"%^RED%^Ruldizar's"
                        +" Request%^RESET%^");
    }
    force_me("say Now comes a time for your reward, from the gems here,"
		+" and with part of this lava, I will be able to fashion a "
           +"breastplate for you.  Make your choice quickly though.  You"
           +" can choose to have it made from sunstone, sapphire, ruby,"
           +" emerald, amethyst, moonstone, or black opal.");
    step3 = 1;
    return;
  }
  force_me("say Thats not what I wanted.");
  force_me("emote tosses the item into a pit.");
  obj->remove();
  return;
}

