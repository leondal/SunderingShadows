//updated to use current code ~Circe~ 7/31/19
#include <std.h>
#include "../derrodefs.h"
inherit MONSTER;

object ob;

void create(){
  ::create();
  set_name("fire giant captive");
  set_id(({"giant","fire giant","captive","fire giant captive","wounded captive"}));
  set_race("giant");
  set_gender("male");
  set_short("Fire giant captive");
  set_long("Seemingly shrunken with his injuries, this massive giant still dwarfs most people.  The captive seems able to talk but appears to pose no threat as long as you keep your distance.  His body is covered in huge slash marks, and his skin appears burned in places.  Legend says that fire giants are immune to fire, so whatever caused these injuries must be truly fearsome.  He looks nervous and edgy - maybe you could calm him?");
  set_ac(0);
  set_size(3);
  set_body_type("human");
  set_class("fighter");
  set_mlevel("fighter",30);
  set_hd(30,3);
  add_search_path("/cmds/fighter");
  set_alignment(9);
  set_property("full attacks",1);
  set("aggressive",0);
  set_stats("strength",24);
  set_stats("intelligence",13);
  set_stats("wisdom",15);
  set_stats("dexterity",18);
  set_stats("constitution",19);
  set_stats("charisma",13);
  set_guild_level("fighter",35);
  set_wielding_limbs(({"right hand","left hand"}));
  set_max_hp(350);
  set_hp(120);
  set_exp(5000);
  new(OBJ"hobboots")->move(TO);
  command("wear boots");
  if(!random(2)){
  present("boots",TO)->set_property("monsterweapon",1);
  }
  //set_emotes(5,({"The fire giant backs as far away from you as possible and prepares to defend himself.  Maybe you could calm him?",}),0);
  remove_property("swarm");
}

void init(){
   ::init();
   add_action("calm","calm");
   add_action("ask","ask");
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void receive_given_item(object item){
   if(!TP->query("TRusted")){
      force_me("say I'll have nothing to do with you till you gain the king's trust!");
      command("drop cow");
      return 0;
   }
   if(present("cooked cow",TO)){
      tell_room(ETO,""+TPQCN+" gives a huge cooked cow to the wounded captive.",TP);
      tell_object(TP,"You give the huge cooked cow to the wounded captive.");
      force_me("emote grabs the cooked cow and tears into it with relish.");
      tell_room(ETO,"%^BOLD%^He reaches out and breaks a fragment of stone off the wall and hands it to "+TPQCN+".%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^He reaches out and breaks a fragment of stone off the wall and hands it to you.%^RESET%^");
      tell_object(TP,"%^CYAN%^Fire giant captive whispers to you: %^RESET%^press cube against depression to befriend the rock on the upper level, and it well let you %^BOLD%^pass%^RESET%^ through.");
      tell_room(ETO,"%^RESET%^%^CYAN%^Fire giant captive whispers something to "+TPQCN+"",TP);
      ob=present("cooked cow");
      ob->remove();
      new(OBJ"stonecube.c")->move(TP);
      return 1;
   }
}

int calm(string str){
   if ((str=="captive") || (str == "wounded captive") || (str=="him")||(str =="giant")){
      tell_room(ETO,"The giant settles down a bit as he realizes that you intend him no harm.\nHe looks west as if to see if anyone is lurking there.\n%^RESET%^%^MAGENTA%^Firegiant captive says:  %^RESET%^These foul %^BOLD%^%^BLUE%^Derro%^RESET%^ have caught another group then.  Let's hope you do better than the last ones did.\n%^MAGENTA%^Firegiant captive continues:  %^RESET%^I don't know where they came from, but they came at a %^BOLD%^bad time%^RESET%^ for us.  Although I can hardly say 'us'... only the %^RED%^king%^RESET%^ and the old %^BOLD%^cook%^RESET%^ remain.  I know a fair bit about the area down here, so %^BOLD%^ask about %^RESET%^whatever you need to know.");
      return 1;
   }
}

int ask(string str){
   tell_object(TP,"What would you like to ask him? You can simply speak aloud, and he will respond.");
   return 1;
}

//Changing him to use catch_say, but adding a hint for old players
void reply_func(string msg, object who){
   object current;
   object obj;
   string name;
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1){
      force_me("say What do you want?");
      return;
   }
   if(strsrch(msg,"derro") != -1 || strsrch(msg,"Derro") != -1){
      force_me("emote 's face twists a little as he thinks about the Derro.");
      force_me("say They came at a %^BOLD%^bad time%^RESET%^ for us, when there was nobody left to kick them back to thier barrows.  They must have been tunneling to the surface in search of new hunting grounds, and they've found them ... and a good hideout as well.  I've heard their %^BLUE%^savant%^RESET%^ talk about their tunnel collapsing that led back to thier home in the underdark.  I'm sure they could tunnel back out.  They just dont want to with such good pickings this close to the surface.");
      return;
   }
   if(strsrch(msg,"king") != -1 || strsrch(msg,"King") != -1){
      force_me("say Our king is truly a mighty warrior, but even he couldn't stand up to all these Derro alone.  They say they've got him trapped in the throne room, but the %^BLUE%^savant%^RESET%^ is scared to just go in after him.  I'm sure you could ask the king about many things as well.");
      return;
   }
   if(strsrch(msg,"savant") != -1 || strsrch(msg,"Savant") != -1){
      force_me("emote flinches.");
      force_me("say  That evil little bastard rules the clan.  He's a powerful magic user, and his students are numerous and work well with his foot soldiers.  He even managed to figure out a %^BOLD%^way out%^RESET%^ of here even though I am the only one who was entrusted with this knowledge of my people.");
      return;
   }
   if(strsrch(msg,"way out") != -1){
      force_me("say Ahh, but of course you'd like to know how to get out.  Don't know if I trust you with that information ... because if you can get out, you can get back in again.  The %^RED%^king%^RESET%^ will be the one you need to talk to, for I am bound not to help any who are not our allies.");
      force_me("emote pauses and looks at you suspiously.");
      force_me("say Hmm ... then again ... perhaps I will let you know how to get out.  Even if you do come back, what more harm could you do than the Derro have already done?");
      force_me("emote sighs and shakes his head, rubbing his stomach.");
      force_me("say But right now, I'm hungry and missing our %^BOLD%^cook%^RESET%^'s cooking.  Bring me a %^BOLD%^snack%^RESET%^, and I'll grant you the power to leave.");
      return;
   }
   if(strsrch(msg,"cook") != -1){
      force_me("emote gives a small grin.");
      force_me("say Now that's a weird one.  Captured a human one day in a raid on a caravan, and this guy wanted to work for us.  Said he needed to expand his expertise.  So, of course, we laughed at him and set a hound on him to see how he tasted.  Bugger killed the hound with his bare hands!  Impressed the king, who gave him one meal to prepare to seal his fate.  He's good with those swords ... that's for sure, although they seem to keep drawing blood on anyone else who tries to touch them.");
      return;
   }
   if(strsrch(msg,"bad time") != -1){
      force_me("emote shudders and unconsiously rubs at his wounds.");
      force_me("say That was a bad day, the one that we listened to the voices of %^RED%^the being%^RESET%^ that lives in the lava pools that formed most of this underground area before we moved in and carved it to our own preferences.  We were all standing out on the walkway over the %^RED%^lava sea%^RESET%^ when it arose.");
      force_me("say First thing it did was attack!  We felt we could control any minion of the flame, but it was more than just fire ... it was earth as well.  Most of the clan died there on that day.  A few survived, only to be swarmed by the Derro when they came upon us in our weakened state.");
      return;
   }
   if(strsrch(msg,"deed") != -1){
      force_me("emote looks at you suspiously.");
      force_me("say Hmm ... perhaps I will let you know how to get out.  Even if you do come back, what more harm could you do than the Derro have already done?");
      force_me("emote sighs and shakes his head, rubbing his stomach.");
      force_me("say But right now, I'm hungry and missing our %^BOLD%^cook%^RESET%^'s cooking.  Bring me a %^BOLD%^snack%^RESET%^, and I'll grant you the power to leave.");
      return;
   }
   if(strsrch(msg,"the being") != -1 || strsrch(msg,"lava being") != -1){
      force_me("emote 's eyes go wild as he talks about a huge creature that rose from the lava sea and killed and killed.");
      force_me("say Its power is incredible! There was nothing we could do against it. It just kept coming and coming, knocking people into the lava and swallowing them whole, nothing.  Nothing.");
      force_me("emote mutters to himself and crouches in his corner, clutching his wounds.");
      return;
   }
   if(strsrch(msg,"lava sea") != -1){
      force_me("say The lava is where we come from, and it holds its own life at times.  We all come from the earth and are formed of energy just as the lava is, but it is unreasoning and unpredictable.  Sometimes it's been known to captivate people with its swirling patterns, and they jump off the walkway and try to walk on the cooling crust - but those are weak-minded fools.");
   return;
   }
   if(strsrch(msg,"snack") != -1){
      force_me("emote sighs and settles back as if remembering something.");
      force_me("say I miss that good whole roasted cow the %^BOLD%^cook%^RESET%^ always used to make for me.  Perhaps if you brought him one, he'd COOK it for you.");
      return;
   }
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("beef",TO)){
      force_me("say I have no use for a frozen carcass!");
      command("drop beef");
   }
}
