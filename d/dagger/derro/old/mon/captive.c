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
  set_name("Wounded captive");
  set_short("%^RED%^Wounded captive%^RESET%^");
  set_long(
  "Seemingly shrunken with his injuries, this massive giant still dwarfs you.  "
  "The captive seems able to talk but appears to pose no threat as long "
  "as you keep your distance.  His body is covered in huge slash marks, "+
  "and his skin appears burned in places.  But you've heard from legend "+
  "that fire giants are immune to fire, so whatever caused these injuries "+
  "must be truly fearsome.  He looks nervous and edgy - maybe you could calm him?"
  );
  set_ac(0);
  set_size(3);
  set_body_type("giant");
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
init()
  {
  ::init();
  add_action("calm","calm");
  add_action("ask","ask");
}
void receive_given_item(object item){
  if(!TP->query("TRusted")){
  tell_room(environment(TO),"%^MAGENTA%^Giant says:%^RESET%^ I'll have nothing to do with you till you gain the kings trust!");
  command("drop cow");
  return 0;
  }
  if(present("cooked cow",TO)){
  write(
  "\nThe giant grabs the cooked cow and tears into it with relish.\n\n"
  "%^BOLD%^%^WHITE%^He reaches out and breaks a fragment of stone off the wall and hands it to you.%^RESET%^\n"
  );
  tell_object(TP,"%^CYAN%^Firegiant captive whispers to you:%^RESET%^press cube against depression, to befriend the rock on the upper level and it well let you %^BOLD%^pass%^RESET%^ through.");
  tell_room(ETO,"%^RESET%^%^CYAN%^Firegiant captive whispers something to "+TPQCN+"",TP);
  say(""+TPQCN+" gives a huge cooked cow to the wounded captive who tears into it with relish");
  ob=present("cooked cow");
  ob->remove();
  new(OBJ"stonecube.c")->move(TP);
 return 1;
}
}

int calm(string str){
  if ((str=="captive") || (str == "wounded captive") || (str=="him")||(str =="giant")){
  message("enviroment",
  "The giant settles down a bit as he realizes that you intend him no harm.\n"
  "  He looks west as if to see if anyone is lurking there then says:  These foul %^BOLD%^%^BLUE%^Derro%^RESET%^ have caught another group then.   Let's hope you do better than the last ones did.\n"
  "He continues:  I don't know where they came from, but they came at a %^BOLD%^bad time%^RESET%^ for us."
  "  Although I can hardly say us, only the %^RED%^king%^RESET%^ and the old %^BOLD%^cook%^RESET%^ remain."
  "  I know a fair bit about the area down here, so %^BOLD%^ask about %^RESET%^whatever you need to know."
  ,ETO);
  return 1;
  }
}
int ask(string str){
  if(!str)return notify_fail("\nAsk about what?\n");
  if ((str=="about derro") || (str=="about Derro")){
  message("environment","\n The captives face twists a little as he thinks about the Derro.\n"
   "%^MAGENTA%^Captive says:%^RESET%^ They came at a %^BOLD%^bad time%^RESET%^ for us, when there was nobody left to kick them back to thier barrows."
  "  They must have been tunneling to the surface in search of new hunting grounds and they've found it and a good hide out as well.   I've head their %^BLUE%^savant%^RESET%^ talk about their tunnel collapsing that led back to thier home in the underdark.   I'm sure they could tunnel back out they just dont want to with such good pickings this close to the surface."
  ,environment(TO));
  return 1;
  }
  if((str=="about king")){
   message("environment","\n   The captive looks to make sure no derro are coming and says:  Our king is truly a mighty warrior but even he couldn't stand up to all these Derro alone.   They say they've got him trapped in the throne room but the %^BLUE%^savant%^RESET%^ is scared to just go in after him."
  "  \n Im sure you could ask the king about many things as well."
  ,environment(TO));
  return 1;
  }
  if((str=="about savant")){
  message("environment",
  "\nThe captive flinches."
  "\n%^MAGENTA%^Captive says:%^RESET%^That evil little bastard rules the clan.   Hes a powerfull magic user and his students are numerous and work well with his foot soldiers."
  "  He even managed to figure out a %^BOLD%^way out%^RESET%^ of here even though I am the only one who was entrusted with this knowledge of my people."
  ,environment(TO));
  return 1;
  }
 if((str=="about way out")){
   message("environment","\n%^MAGENTA%^Captive says:%^RESET%^ Ahh but of course you'ld like to know how to get out.   Dont know if I trust you with that information cause if you can get out you can get back in again."
  "  The %^RED%^king%^RESET%^ will be the one you need to talk to for I am bound not to help any who are not our allies."
  ,environment(TO));
  return 1;
}
  if((str=="about cook")){
  message("environment","\n %^MAGENTA%^With a grin the captive says:%^RESET%^ Now thats a wierd one."
  "  Captured a human one day in a raid on a caravan and this guy wanted to work for us.    Said he needed to expand his expartise.   So of course we laughed at him and set a hound on him to see how he tasted."  
  "  Bugger killed the hound with his barehands.   Impressed the king who gave him one meal to prepare to seal his fate."
  "   Hes good with those swords thats for sure although they seem to keep drawing blood on anyone else who tries to touch them."
  ,environment(TO));
  return 1;
  }
  if((str=="about bad time")){
  message("environment","\n He shudders and unconsiously rubs at his wounds.\n"
  "That was a bad day the one that we listened to the voices of the %^RED%^being%^RESET%^ that lives in the lava pools that formed most of this underground area before we moved in and carved it to our own preferences."
 "  We were all standing out on the walkway over the %^RED%^lava sea%^RESET%^ when it arose."
  "\n  First thing it did was attack!\n"
  "  We felt we could control any minion of the flame but it was more than just fire it was earth as well."
  "   Most of the clan died there on that day.   A few survied only to be swarmed by the derro when they came upon us in our weakened state."
  ,environment(TO));
  return 1;
}
  if((str=="about deed")){
  message("environment","Captive looks at you suspiously.\n"
  "  Hmm.  Perhaps I will let you know how to get out."
  "  Even if you do come back what more harm could you do than the derro have already done?"
  "\n  But right now Im hungry and missing our %^BOLD%^cook%^RESET%^s cooking."
  "  Bring me a %^BOLD%^snack%^RESET%^ and I'll grant you the power to leave."
  ,environment(TO));
  return 1;
}
  if((str=="about being")){
  message("environment","  %^BOLD%^The captives eyes go wild as he tells you about a huge creature that rose from the lava sea and killed and killed.\n"
  "  Its power is incredible, he continues, theres nothing we could do against it it just kept coming and coming, knocking people into the lava and swallowing them whole, nothing.  Nothing.\n"
  "\n The captive mutters to himself and crouches in his corner clutching his wounds."
  ,environment(TO));
  return 1;
  }
  if((str=="about lava sea")){
  message("environment",
  "  %^MAGENTA%^\n Captive says:  %^RESET%^The lava is where we come from, and it holds its own life at times."
  "  We all come from the earth and are formed of energy just as the lava is, but it is unreasoning and unpredictable."
  "  Sometimes it's been known to captivate people with its swirling patterns, and they jump off the walkway and try to walk on the cooling crust - but those are weak minded fools."
  ,environment(TO));
  return 1;
  }
  if((str=="about snack")){
  message("environment",
  "\nThe captive sighs and settles back as if remembering something.\n"
  "%^MAGENTA%^Captive says:%^RESET%^I miss that good whole roasted cow the %^BOLD%^cook%^RESET%^ always used to make for me.   Perhaps if you brought him one he'ld COOK it for you."
  ,environment(TO));
  return 1;
  }
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(present("beef",TO)){
  tell_room(environment(TO),"%^MAGENTA%^Captive says:%^RESET%^ I have no use for a frozen carcass!");
  command("drop beef");
  }
}
