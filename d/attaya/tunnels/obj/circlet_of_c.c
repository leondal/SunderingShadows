// Coded by Lujke. 
// The circlet of control can be used in conjunction with 
// the bracelets of compliance to take control of another person's actions
// The victim must be wearing the bracelets and the controller must be 
// wearing the circlet. They must both be in the same room.
// If all these conditions are fulfilled, the controller can 
// 'command <victim> to <action>'
// most possible ooc and other abuses have been coded out. 
// Unlike the domination spell, the victim is still able to take their own
// actions at will. However, the duration is unlimited as long as the 
// victim is wearing the bracelets, which are cursed.

#include <std.h>
#include <move.h>
#define DAY 24000
#include <daemons.h>
#include <domination.h>
inherit ARMOUR;

string owner;
string query_owner();
void set_owner(string str);
string help();

void create()
{
  ::create();
  set_obvious_short("%^RESET%^dull gray circlet");
  set_name("gray circlet");
  set_short("%^BOLD%^%^BLACK%^c%^RESET%^i%^BOLD%^%^BLACK%^rcl%^RESET%^e"
           +"%^BOLD%^%^BLACK%^t %^RESET%^of %^CYAN%^c%^RESET%^o%^CYAN"
           +"%^ntr%^RESET%^o%^CYAN%^l%^RESET%^");
  set_id(({"circlet of control","circlet","gray circlet","dull circlet","dull gray circlet"}));
  set_long("A circlet of dull gray metal. It is designed to curve around"
          +" the wearer's head. The band swells and tapers in a curve. It"
          +" is widest across the centre of the forehead and tapers"
          +" somewhat over the temples.");
  set_lore("Rumours tell of a secret illithid plot to manufacture devices"
          +" to help their non-illithid employees keep their slaves in"
          +" check for them. There's no evidence that they ever managed"
          +" to make it work, but this does look very much like the"
          +" device they were supposedly trying to make.");
  set_property("lore difficulty",21);
  set_weight(5);
  set_type("clothing");
  set_limbs(({"head"}));
  set_ac(0);
  set_property("enchantment",1);
  set_value(5000);
  set_wear((:TO,"wearme":));
  set_remove((:TO,"removeme":));
  switch (random(6))
  {
  case 0:
    set_size(1);
    break;
  case 1:
    set_size(3);
  default:
    set_size(2);
  }
  set("language", "wizish");
  set("read","The circlet of control can be used in conjunction with the"
            +" bracelets of compliance to command another's actions. The"
            +" person to be commanded must be wearing the bracelets. When"
            +" you are wearing the bracelets,\n%^BOLD%^%^YELLOW%^'command"
            +" <victim name> to <action>' %^RESET%^\nEg%^BOLD%^%^YELLOW%^"
            +" command Lujke to drop 1000 gold coins'%^RESET%^\n\n"
            +"You may also %^YELLOW%^'torment <victim name>'%^RESET%^ -"
            +" to bring dreadful pain to your slave, OR"
            +"%^YELLOW%^'slay <victim name>'%^RESET%^ - to condemn your"
            +" slave to a lingering death. Once this is done, they will"
            +" no longer be at your command.\n"
            +"%^BOLD%^%^RED%^**** NOTE ****\n"
            +"Roleplay appropriately when using these items.  Do NOT use"
            +" them for any form of sexual harrassment or OOC abuse. If"
            +" you are not certain what that means, do not use them at"
            +" all without seeking advice from an Immortal" );
}

void init(){
  ::init();
  add_action("command_me","command");
  add_action("torment_me", "torment");
  add_action("slay_me", "slay");
  add_action("free_me", "free");
}

string query_owner(){
  return owner;
}

string set_owner(string str){
  owner = str;
}

int wearme(){
//  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (!query_owner()){
 if ((objectp(ETO) && ((string)ETO->query_position()=="newbie"))){
       tell_object (ETO,"The circlet twists and squirms in your hand."
                      +" You are unable to bring it under your control.");
    return 0;
    }  else{
      if (objectp(ETO)){
        tell_object(ETO,"%^BOLD%^%^BLUE%^You place the " + query_short() 
                    + "%^BOLD%^%^BLUE%^ onto your head and feel a brief"
                    +" struggle as the circlet fights you before finally"
                    +" acknowledging you as its new owner.\n" 
                   +" %^RESET%^%^ORANGE%^As you wear it, you feel the"
                   +" power of %^RESET%^control%^ORANGE%^ flow through"
                   +" your body and soul");
      }
      if (objectp(EETO)){
        tell_room(EETO,ETO->QCN + "%^BOLD%^%^BLUE%^ places the " 
              + query_short() + "%^BOLD%^%^BLUE%^ onto " + ETO->QP 
              + " head and smiles %^RESET%^grimly", ETO);
      }
      if (objectp(ETO)){
        set_owner((string)ETO->query_name());
      }
      return 1;
    }
    
  }
  if (objectp(ETO) && query_owner()==(string)ETO->query_name()){
    tell_object(ETO,"You place the " + query_short() + " onto your head"
                   +" and feel the power of control enter you as the"
                   +" circlet acknowledges you once more as its owner.");
    if (objectp(EETO)){
      tell_room(EETO,ETO->QCN + " places the " + query_short() 
              + " onto " + ETO->QP + " head and smiles grimly", ETO);
    }
    return 1;
  }else{ 
    if (objectp(ETO)){
      tell_object(ETO,"You struggle a bit to place the " + query_short() 
                  + " onto your head. You get it on, but you are left"
                  + " with the feeling the circlet does not really want"
                  + " you to wear it, as if it knows you are not the"
                  + " rightful owner.");
    }
    if (objectp(EETO)){
      tell_room(EETO,(string)ETO->QCN + " seems to struggle as " + 
                 (string)ETO->QS + " places the " + query_short() 
              + " onto " + ETO->QP + " head.", ETO);
    }
    return 1;
  }
  return 1;
}

int removeme(){
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO,"" + query_short() + "You take the circlet from your"
                 +" head and feel a weight of responsibility lift from"
                 +" you.");
  tell_room(EETO, ETO->query_cap_name()+" slips the circlet from " 
                + ETO->QP+" head. " + ETO->QS + " looks a little less"
                +" weighed down", ETO);
  set_ac(0);
  return 1;
}

int free_me(string str){
  object victim, bracelets;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  victim = present(str, EETO);
  if (!objectp(victim)){
    tell_object(TP, str + " is not here!");
    return 1;
  }
  bracelets = present("bracelets of compliance", victim);
  if (!bracelets ||!victim->query("compliant")){
    tell_object(TP, "You can try to free " + str + ", but "
    + victim->QS + " is not actually wearing the bracelets of"
    +" compliance to begin with!");
    return 1;
  }
  if ((string)bracelets->query_master()!= query_owner()){
    tell_object(ETO, "The circlet you are wearing has no power over this slave");
  }
  tell_object(ETO, "You relax the force of your will and allow " 
                  + victim->QCN + " to go free.");
  tell_object(victim, "You feel the grip of control leave your mind and"
                     +" the " +bracelets->query_short() + " fall from"
                     +" your wrists.");
  tell_room(EETO, "The " + bracelets->query_short() + " fall from " 
                  +victim->QCN  +"'s wrists, setting " + victim->QO 
                + " free!", victim);
  bracelets->unwear();
}

int slay_me(string str){
  object victim, bracelets;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (query_worn()!=ETO){
    tell_object(ETO, "You'll have to wear the circlet first!");
    return 1;
  }
  victim = present(str, EETO);
  if (!objectp(victim)){
    tell_object(TP, str + " is not here!");
    return 1;
  }
  bracelets = present("bracelets of compliance", victim);
  if(!objectp(bracelets)||(object)bracelets->query_worn()!= victim){
    tell_object(ETO, "%^RED%^You can try to slay " + str
                   + "%^RESET%^%^RED%^, but " + victim->QS 
                   + " is not likely to suffer much as " + victim->QS 
                   + " is not wearing bracelets of control!");
    if (victim->query("compliant")!=0){
      victim->set("compliant", 0);
    }
    return 1;
  }
  if ((string)bracelets->query_master()!= query_owner()){
    tell_object(ETO, "The circlet you are wearing has no power over this slave");
    return 1;
  }

  if (query_owner()!=(string)query_worn()->query_name()
          ||query_owner()!=(string)bracelets->query_master()){
    tell_object(ETO, "%^BOLD%^%^RED%^You can only slay your own slaves!");
    return 1;
  }
  tell_object(ETO, "%^CYAN%^With the briefest of effort, you send an"
                  +" order to the bracelets to"
                  +" %^BOLD%^%^GREEN%^sl%^RESET%^%^GREEN%^a"
                  +"%^BOLD%^%^GREEN%^y%^RESET%^%^CYAN%^ " + victim->QCN 
                  +" %^RESET%^%^CYAN%^and see the fear in " + victim->QP 
                  +" eyes as " + victim->QS + " realises what you have"
                  +" done.\nYou will no longer be able to control " 
                  + victim->QCN + ", but you can observe " + victim->QP 
                  + " lingering demise.");
  tell_object(victim, "%^RED%^A sudden %^BOLD%^%^RED%^pain"
                     +"%^RESET%^%^RED%^ stabs into your %^BOLD%^%^RED%^h"
                     +"%^RESET%^%^RED%^ea%^BOLD%^%^RED%^rt"
                     +" %^RESET%^%^RED%^ then runs through your chest and"
                     +" down your arms to the %^RESET%^ dull gray"
                     +" bracelets%^RED%^ on your wrists. \n%^CYAN%^You"
                     +" realise without knowing how that "
                     + (string)ETO->QCN 
                     +"%^RESET%^%^CYAN%^ has sentenced you to death"
                     +" through the %^RESET%^circlet%^CYAN%^ " 
                     + (string)ETO->QS 
                     +" wears. At least you are now free of "
                     + (string)ETO->QP +" control. If only you can find a"
                     +" way to get rid of the bracelets before they kill"
                     +" you!");
  tell_room(EETO, victim->QCN + " %^CYAN%^looks at "+ (string)ETO->QCN 
               +" %^RESET%^%^CYAN%^in sudden %^BOLD%^%^GREEN%^fear"
               +" %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^horror%^RESET%^"
               +"%^CYAN%^. You wonder what " + (string)ETO->QCN 
               +" %^RESET%^%^CYAN%^can have done!", victim, ETO);
  victim->set("compliant", 0);
  bracelets->set_death(time());
  return 1;
}

int torment_me(string str){
  object victim;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (query_worn()!=ETO){
    tell_object(ETO, "You'll have to wear the circlet first!");
    return 1;
  }
  victim = present(str, EETO);
  if (!objectp(victim)){
    tell_object(TP, str + " is not here!");
    return 1;
  }
  if(!victim->query("compliant")){
    tell_object(ETO, "You can try to torment " + str + ", but "
    + victim->QS + " is not going to respond much as " + victim->QS 
    + " is not wearing the bracelets of compliance!");
    return 1;
  }
  tell_object(ETO, "Using the power of the " + query_short() + ", you"
                 +" unleash a torment of suffering upon " + victim->QCN);
  tell_object(victim, TPQCN +" sends you a sharp %^BOLD%^%^RED%^rebuke!");
  if(!"daemon/saving_d"->saving_throw(victim,"rod_staff_wand"
                                          , (int)TP->query_level()/3*-1)){
   
    tell_object(victim, "%^RESET%^Your entire body twists as it is"
                    +" %^BOLD%^%^RED%^wracked%^RESET%^ with pain. The"
                    +" %^MAGENTA%^agony%^RESET%^ of it takes you and will"
                    +" not let go!");
    tell_room(ETO, victim->QCN + " suddenly %^BOLD%^%^GREEN%^screams"
                 +" %^RESET%^and writhes as if " + victim->QP + " body is"
                 +" %^BOLD%^%^RED%^wracked%^RESET%^ in pain, even though"
               +" there is nothing visibly wrong with " 
               + victim->QO +".", victim);
    victim->set_paralyzed(1+random(4));
  }else{
    tell_object(victim, "But your mind is strong and you are able to"
                       +" %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ea%^BOLD%^"
                       +"%^CYAN%^ther%^RESET%^ the attack.");
    tell_object(ETO, "Nothing seems to happen");
  }
  return 1;
}

int command_me(string str){
  string who, command, edict, remainder;
  object victim;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (query_worn()!=TP){
    tell_object(ETO, "You'll have to wear the circlet first!");
  }
  if(sscanf(str,"%s to %s",who,edict) != 2) {
    return help();
  }
  victim= present(who, environment(this_player()));
  if(!victim) {
    notify_fail("Command who to "+edict+"?\n");
    return 0;
  }
  if (ETO->query_ghost()) {
      notify_fail("You cannot do that in your immaterial state.\n");
      return 0;
  }
  if(victim== ETO) return notify_fail("Just do it.\n");
  if(!victim->query("compliant")){
    return notify_fail("You try to force " + who + " to do"
                      +" your bidding, but " + victim->QS + " doesn't"
                      +" respond to your command.");
  } 
  if (sscanf(edict,"%s %s", command, remainder)<2){
    if (sscanf(edict,"%s", command)<1){
      tell_object(ETO, help());
    }
  }

  if(member_array(command, SAFE_DOM_CMDS) ==-1){
    return notify_fail("You can't get " + victim->QCN + " to " + edict +
                       "."); 
  }

/*  if(member_array(command,({"call","eval","xmote","alias","unalias",               "passwd","describe","nickname","chfn","bug","idea","mudidea",                   "typo","mail","forsake","suicide","quit","harass","shout",
        "thought", "withdraw", "pickup", "backup", "account", 
        "pkmail","avatarmail", "skills", "bboard","pkmail","adjective",
        "describe","background","bboard","praise","inactive",
         "inform","fighter","ranger","assassin","cleric","mage","bard",
         "cavalier","newbie","paladin","antipaladin", "thief",
         "informemote", "thiefemote","fighteremote","rangeremote", 
         "assassinemote", "clericemote","mageemote", "bardemote", 
         "cavalieremote", "newbieemote","paladinemote", 
         "antipaladinemote"}),0) > 0){
    return notify_fail("You can't get " + victim->QCN + " to " + edict +
                       "."); 
  } */
  victim->force_me(edict);
  return 1;
}

string help(){
  return "Try %^BOLD%^%^YELLOW%^'command <target name> to <action>'";
}
