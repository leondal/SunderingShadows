//Nobacherie.c - The Tabaxi Elder
// Coded by Lujke 13/03/10
#include <std.h>
#include <party.h>
#include <daemons.h>
#include "../tecqumin.h"
inherit QNPC;

void set_responses();
void greet(object ob);
mapping greeted;
object * helpers, defenders, battler;
int delay;

void create(){
   ::create();
   set_name("Nobacherie");
   set_id( ({"nobacherie","noba","elder", "elder nobacherie", "tabaxi", "tabaxi elder"}) );
   set_short("Nobacherie, Tabaxi Elder");
   set_long((:TO, "long_desc" :));
   set_gender("male");
   set_race("tabaxi");
   set_body_type("humanoid");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_overall_ac(-60);
   set_class("fighter");
   set_mlevel("fighter",45);
   set_level(45);
   set_stats("wisdom",19);
   set_stats("strength",15);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",18);
   set_stats("dexterity",15);
   set_exp(60);
   set_speed(0);
   set("aggressive",0);
   set_responses();
   delay = 500;
   helpers = ({});
   greeted = ([]);
   defenders = ({});
   set_no_clean(1);
}

set_responses(){
  set_response(({"hello", "greetings", "good day", "gooday", "hi", "hai"}),
           ({"Hmm"}), "greet" );
  set_response(({"tabaxi"}), ({"Wee arre dee peeple of dee jongle, and dee"
              +" farmers of dee maize. Wee would be jus fine if eet was"
              +" not forr dee treat from dee orogs!" }) );
  set_response(({"orog"}),({"Dee orogs are dee curse of my peeple"}), "orogs" );
  set_response( ({"jungle"}), ({"Dee jongle is our mother and our"
                +" father. Wee arre of dee jongle and it is ourr home"}));
  set_response( ({"attack", "extort", "refuse"}), ({"Once beforre, we tried"
               +" refusing to giff ourr %^BOLD%^%^YELLOW%^maize%^RESET%^ to"
               +" dee %^GREEN%^orogs%^RESET%^. Dey attacked the veellage"
               +" and we werre unable to fight dem off. Dey burrned all off"
               +" ourr %^BOLD%^%^YELLOW%^grain %^RESET%^storres."}),
               "extort" );
  set_response(({ "help", "defend"}), ({"Could you elp uss defend ourr"
               +" veellage? Just nod to me eef you will. Dere could be some"
               +" %^BOLD%^%^BLUE%^rewards%^RESET%^ for jew eef you do..." })
               , "help" );
  set_response( ({"rewards"}), ({"Dee Tabaxi haff some relics of earrlier"
               +" times, when ourr ancestors werre more warrlike peeples. "
               +"But we arre farrmers now, and tillers of dee soil. If jew "
               +"weell elp uss %^RED%^defend dee veellage%^RESET%^ against "
               +"dee %^GREEN%^orogs%^RESET%^, den maybe wee can sharre de "
               +"ancient weapons wit jew."}) );
  set_response(({"ancient weapons", "weapon", "weapons", "relic", "relics"}),
                ({"Dee relics off our ancestors arre sacred to uss, but we"
               +" might be weelling to sharre them wit jew eef you can elp uss "
               +"defend dee veellage. Until den, I weell speak no more about"
               +" dem"}), "weapons" );
  set_response(({"store"}), ({"Wee have a grrain store near thee centre of thee veellage. Wee need"
                +" thee stores to carry us from one harvest to thee next. Weethout it, many of us"
                +" would starve." }) );
  set_response( ({"warrior"}), ({"You look like you would bee good in a fight. Would you"
                +" help us %^CYAN%^fight them off%^RESET%^?"}) );
  set_response( ({"fight them off", "fighting them off"}),({"My people would reesist the orogs eef"
                +" they could, but wee have"
                +" not the strength or skill.", "Eef wee could beat them just once, they would think"
                 +" twice before coming back.", "Will you help %^BLUE%^organise the resistance"
                 +"%^RESET%^?"}) );
  set_response(({"organise the resistance", "organising the resistance"}), ({"Eef you want to help,"
                +" look round thee veellage and do"
                +" whatever you can to %^BLUE%^prepare the defences%^RESET%^. When you are ready, form"
                +" a party with any friends you can get to help and come back to me.", "Tell me you"
                +" are ready to %^CYAN%^let battle commence%^RESET%^ and I will send a message of"
                +" defiance to the orogs. Then wee will see whether between us we can %^BLUE%^drive"
                +" them off%^RESET%^."}) );
  set_response(({"prepare the defence", "preparing the defence"}),({"You are thee experts at fighting."
               +" Look round thee veellage"
               +" and find any ways you can too make eet more deefenseeble. Eef you want help from any"
               +" of my peeople, go too them and %^CYAN%^request aid%^RESET%^ for thee veellage."}) );
  set_response(({"drive them off", "drive off the orogs"}), ({"Eef we can drive off or keell all thee"
               +" orogs who come to attack, wee will know that wee haf beaten them once and wee can"
               +" do eet again!"}) );
  set_response(({"quali", "jungle spirit"}), ({"Quali ees thee name the Tecqumin gave too their god of"
              +" thee jungle, who leeved in thee form of a great tree.", "Some of my peeople say they"
              +" haff seen a leeving tree out in thee jungle sometimes, but they say eet ees mad and"
              +" maybee dangerous!"}) );
  set_response(({"trained", "training"}), ({"No-one can fight dere best withowt trainin'!"}) );
  set_response(({"equipped"}), ({"No-one can fight dere best withowt weapons and armour!"}) );
  set_response(({"weapon", "armour"}), ({"Wee don't haff much. Maybee our %^BOLD%^%^BLACK%^blacksmith"
               +"%^RESET%^ could help, eef she was sober."}) );
  set_response(({"blacksmith"}), ({"Shee's a verry good blacksmeeth, but shee's been a bit tired an"
                +" eemotional for a long while. Her mate and kids werre killed in an"
                +" %^BOLD%^%^BLACK%^orog%^RESET%^ raid an shee took it reaally harrd."}) );
  set_response(({"tired an emotional", "tired and emotional"}), ({"Well, alright, shee ees eemotional,"
                +" an sometimes tired. But I really mean shee's been drunk a lonng time. It's herr way"
                +" of coping."}) );
  set_response(({"request aid for the village"}),
                ({"Yes - de veellagers weell elp if dey can. Jus tell dem dat "
               +"you want to %^CYAN%^request aid for de veellage%^RESET%^ and"
               +" dey weell elp. They arre not warriors, though, and may need to be"
              +" %^ORANGE%^trained%^RESET%^ and %^CYAN%^equipped%^RESET%^ to fight."})
               , "request", "Tabaxi defender" );
  set_response(({"defence", "defences"}), ({"Hmm"}), "defences");
  set_response(({"jongle", "veellage", "de", "dee", "jew", "eemotional"}), ({"Arre jew making"
               +" fun off my accent?"}),"accent"  );
  set_response(({"ready to fight"}), ({"Jew arre ready to fight?" }), "ready");
  set_response(({"try again"}), ({"Jew want too try again too defeat dee orog attack? Verry"
                +" well... Once we haff built up dee grain storres again, and"
                +" jew haff prepared dee defences, giff me dee signal"
                +" when jew weesh me to send de message dat weell start dee"
                +" attack!"}), "ready");
}

void init(){
  string * quests, * ignores, name;
  ::init();
  add_action("start_attack", "start");
  greet(TP);
}




void report(string what){
  /* "/daemon/reporter_d"->report("lujke", what); */
}

object * query_defenders(){
  return defenders;
}

int start_attack(string str){
  string party, * quests, name;
  object defender, * party_mems, granary;
  int i;
  report ("Trying to start attack");
  name = TP->query_name();
  if (str !="attack"){
    if (member_array(TP, defenders) !=-1){
      notify_fail("Start what? An attack or something?");
    }
    return 0;
  }
  quests = TP->query_mini_quests();
  if (member_array(TP, defenders) !=-1 && member_array("Tabaxi Defender", quests)==-1){
    tell_object(TP, "Nobacherie has not accepted your help to %^RED%^defend"
                   +" the village%^RESET%^, so he's not going to start the"
                   +" attack. Try talking to him some more.");
    return 1;
  }
  if (EVENT_RECORDS_D->completed_event(TPQN,"Failed to protect the Tabaxi" , 2000)>0){
    tell_object(TP, "You have Failed to protect the Tabaxi recently. You cannot start the fight again yet.");
    return 1;
  }
  EVENT_RECORDS_D->remove_event("Failed to protect the Tabaxi", TPQN);
  report ("Loading granary");
  granary = find_object_or_load(TABAXROOM + "granary");
  if (!objectp(granary)){
    tell_object(TP, "There was an ERROR loading the granary to check the Tabaxi grain stores. Please make a bug report on Nobacherie");
    return 1;
  }
  report ("Granary loaded okay");
  report ("Checking for recent successful defense by name: " + name);
  if( EVENT_RECORDS_D->completed_event(name, "Defended the Tabaxi grain stores", 24000)>0){
    force_me("say But dee Orogs are in retreat affter last time. Dey won't"
      +" be back forr a while. Ask me again laterr.");
    return 1;
  }
  report ("No-one in " + name + "'s party has defended the Tabaxi recently");
  if( EVENT_RECORDS_D->completed_event(name, "Failed to protect the Tabaxi", 3000)>0){
    force_me("say But wee need a bit morre time too build up ourr storres"
      +" first. Ask me again laterr.");
    return 1;
  }
  report ("No-one in " + name + "'s party has failed to defend the Tabaxi recently");
  report ("Checking if the granary is burned");
  if (granary->query_burned()>0){
    report("The granary is burned");
    force_me("say Ourr storres have not yet recoverred from being burrned. Ask me"
      +" again when we have had some morre time");
    return 1;
  }
  report("The granary is not burned");
  party = TP->query_party();
  if (stringp(party)){
    party_mems = PARTY_OB->query_party_members(party);
  } else {
    party_mems = ({TP});
  }
  defenders = ({});
  for (i=0;i<sizeof(party_mems);i++){
    defender = party_mems[i];
    if (objectp(defender)){
      quests = defender->query_mini_quests();
      if (member_array("Tabaxi Defender", quests)==-1){
        defender->set_mini_quest("Tabaxi Defender");
      }
      defenders += ({defender});
      tell_object(defender, "%^BOLD%^%^GREEN%^Nobacherie, elder of the Tabaxi,"
        +" has sent a message of defiance to the orog oppressors! Soon they"
        +" will attack the village, seeking to gain entrance and burn the"
        +" grain stores. Your party has agreed to help with the defence. "
        +"Defend the village! Protect the granary! Good luck, and may your"
        +" gods be with you.");
    }
  }
  call_out("start_attack2", 4, TP);
  return 1;
}

remove_missing_defenders(){
  int i;
  object * removes;
  removes = ({});
  if (sizeof(defenders)<1){ return;}
  for (i = 0;i<sizeof(defenders);i++){
    if (!objectp(defenders[i])){
      removes  += ({defenders[i]});
    }
  }
  if (sizeof(removes)>0){
    for (i=0;i<sizeof(removes);i++){
      defenders -= ({removes[i]});
    }
  }
}

start_attack2(object ob){
  int i;
  object who;
  remove_missing_defenders();
  if (sizeof(defenders)<1 || !objectp(ob) ){ return;}
  for (i=0;i<sizeof(defenders);i++){
    who  = defenders[i];
    if (objectp(who)){
      tell_object(who, "There are movements in the jungle, as the orogs muster for their attack.");
    }
  }
  battler = new(TABAXOBJ + "tabaxi_battler");
  battler->move(TO);
  battler->start_attack(ob);

}

void accent(object ob){
  string name;
  if (!objectp(ob)){return;}
  name = ob->query_true_name();
  force_me("emoteat " + name + " frowns at $N");
}
void orogs(object ob){
  force_me("emote pulls a face");
  force_me("say Dey are dee ogliest tings jew will find in dee"
          +" %^GREEN%^jongle%^RESET%^ and eevil too. Every season dey"
          +" %^CYAN%^extort%^RESET%^ much of our grrain from us. Eef we "
          +"%^RED%^refuse%^RESET%^, dey weel attack us an burrn ourr food"
          +" storres");
}

void weapons(object ob){
  force_me("emote shakes his head wisely");
}

void ready(object ob){
  string * quests, party, quest, name;
  object mem, * party_mems;
  int i;
  if (!objectp(ob)){return;}
  name = ob->query_name();
  if( EVENT_RECORDS_D->completed_event(name, "Defended the Tabaxi grain stores", 24000 )>0){
    force_me("say But dee Orogs are in retreat affter last time. Dey won't"
      +" be back forr a while. Ask me again laterr.");
    return;
  }
  if( EVENT_RECORDS_D->completed_event(name, "Failed to protect the Tabaxi", 24000)>0){
    force_me("say But wee need a bit morre time too build up ourr storres"
      +" first. Ask me again laterr.");
    return;
  }
  force_me("say Verry well... I ope jew haff prepared dee defences well!"
          +" Giff me dee signal when jew weesh me to send de message dat"
          +" weell start dee attack!");
  tell_object(ob, "%^BOLD%^%^YELLOW%^Make sure you are really prepared! "
         +"\n%^BOLD%^%^RED%^Important: You will need to be in a party with"
         +" anyone who is planning to help you out.\n%^BOLD%^%^YELLOW%^"
         +"When you are sure you are ready, type <start attack> (a brief "
         +"prayer might be in order first)%^RESET%^");
  party = ob->query_party();
  if (stringp(party)){
    party_mems = (object *)PARTY_OB->query_party_members(party);
    if (sizeof(party_mems) >0){
      mem = party_mems[i];
      if (objectp(mem)){
        if (member_array(mem, helpers)!= -1){
          helpers -= ({mem});
        }
        if (member_array(mem, defenders) == -1){
          defenders += ({mem});
        }
        quests = mem->query_mini_quests();
        if (member_array("Tabaxi Defender",quests)==-1){
          mem->set_mini_quest("Tabaxi Defender");
        }
      }
    }
  }
}

void extort(object ob){
  force_me("say Now we musst geef dem dee grrain dey demand, unless we can"
          +" get help to %^RED%^defend de veellage%^RESET%^.");
}

void hmm(object ob){
  force_me("emote hmms");
}

void request(object ob){
  force_me("emote nods");
}

object * query_helpers(){
  return helpers;
}

mapping query_greeted(){
  return greeted;
}

void defences(object ob){
  if (member_array(ob, helpers)==-1){
    force_me("say We need elp too %^RED%^defend de veellage%^RESET%^ from "
          +"de %^GREEN%^orogs%^RESET%^. Can jew %^BOLD%^%^YELLOW%^help"
          +"%^RESET%^ us?");
    return;
  }
  force_me("say When dey come, de %^GREEN%^orogs%^RESET%^ weell be trying to"
          +" find ways into de veellage. Look around and find whatever ways "
          +"jew can to stop dem, or slow dem down. De veelagers weell elp jew"
          +" eef dey can. Just tell dem dat jew want to %^CYAN%^request aid"
          +" for de veellage%^RESET%^.");
}

void help (object ob){
  if (!arrayp(helpers) || sizeof(helpers)<1){
    helpers = ({});
  }
  if (objectp(ob)){
    helpers += ({ob});
  }
}

void greet_great_defenders(object ob){
  int i, num;
  object * battlers,  battler, defender;
  string * def_names, def_name, how_failed, * quests;
  def_names = ({});
  battlers = children(TABAXOBJ + "tabaxi_battler");
  num  = sizeof(battlers);
  if (num > 0){
    for (i=0;i<num;i++){
      def_names = battlers[i]->query_def_names();
      def_name = ob->query_true_name();
      if (sizeof(def_names)>0){
        if (member_array(def_name, def_names)!=-1){
          battler = battlers[i];
          break;
        }
      }
    }
  }
  if (objectp(battler)){
    force_me("emote breaks into a broad grin");
    force_me("say Thee orogs are defeated! For once we are keeping all of our harvest for ourselves!");
    num = sizeof(def_names);
    if (num>0){
      for (i=0;i<num;i++){
        def_name = def_names[i];
        defender = find_player(def_name);
        if (!objectp(defender)) continue;
        quests = defender->query_mini_quests() + defender->query_quests();
        greeted[def_name] = time();
        if (sizeof(quests) <1 || member_array("Great Defender of the Tabaxi", quests) ==-1)
        {
          defender->set_quest("Great Defender of the Tabaxi");
          defender->add_exp(21000000);
        }
      }
    }
    battler->move("/d/shadowgate/void");
    battler->remove();
  } else //if no relevant battler was found, just greet the great defenders
  {//bah
    force_me("emote acknowledges " + ob->QCN);
    force_me("say Ello again, friend. All dee Tabaxi thank jew for jour aid!");
    greeted[ob->query_name()] = time();
    return;
  }
  call_out("offer_reward", 3, ob);
}

void remove_greeted(string name){
  string * greeted_names;
  if (!mapp(greeted) || sizeof(greeted)<1)
  {
    greeted = ([]);
    return;
  }
  greeted_names = keys(greeted);
  if (member_array(name, greeted_names) ==-1) return;
  map_delete(greeted, name);
}

void remove_greeted_object(object ob){
  remove_greeted(ob->query_name());
}

void offer_reward2(object ob){
  object key;
  if (!objectp(ob) || (objectp(ETO) && !present(ob, ETO)) ) return;
  force_me("say Here, I give you thee key so jew can unlock eet an choose what jew want.");
  key = new(TABAXOBJ + "tabaxi_key");
  key->move(TO);
  force_me("give key to " + ob->query_name());
}

void offer_reward(object ob){
  if (!objectp(ob) || (objectp(ETO) && !present(ob, ETO)) ) return;
  force_me("say Wee don' have much too offer for a reward, but therre are a few things jew might like in thee strongbox in my room.");
  call_out("offer_reward2", 2, ob);
}

void greet(object ob){
  string * quests, * ignores, name, how_failed;
  report ("Responding to a greeting");
  if (!ob->is_player()){
//    report ("I was greeted by someone who's not a player");
    return;
  }
  quests = (string *)ob->query_mini_quests() + (string *) ob->query_quests();
  ignores = keys(greeted);
  name = ob->query_name();
  if (sizeof(ignores) >0 && member_array(name, ignores)!=-1){
    if (greeted[name] > time()-300){
      report ("I have greeted " + name + " before recently");
      return;
    }
  }
  if (EVENT_RECORDS_D->completed_event(name, "Defended the Tabaxi grain stores", 3000)!=-1){
//  if (sizeof(quests)>0 && member_array("Great Defender of the Tabaxi", quests)!=-1){
    greet_great_defenders(ob);
    greeted[name] = time();
    return;
  }
//  if (sizeof (quests)>0 && member_array( "Great Defender of the Tabaxi", quests)!=-1){//gah
//    force_me("say Ello again, friend. All dee Tabaxi thank jew for jour aid!");
//    greeted[name] = time();
//    return;
//  } //gah
//  report (name + " has not succeeded in helping the Tabaxi recently");
  if (EVENT_RECORDS_D->completed_event(name, "Failed to protect the Tabaxi", 3000)>0){
    if (objectp(battler)){
      how_failed = battler->query_meth();
      if (interact(how_failed, "The battle is lost! The orogs have destroyed"
          +" the tabaxi's crops. They burned the whole lot. They gained entry by ")){
        how_failed = how_failed[strlen("The battle is lost! The orogs have"
                                      +" destroyed the tabaxi's crops. They"
                                      +" burned the whole lot. They gained"
                                      +" entry by ")..strlen(how_failed)-1];
      }
      force_me("emote looks up despairingly");
      force_me("say " + how_failed);
      greeted[name] = time();

      call_out("fail_speech", 2);
      return;
    }
  }
  report (name + " has not Failed to protect the Tabaxi recently");
  if (arrayp(quests) && member_array("Tabaxi defender", quests)!=-1){
    force_me("say Ello again, friend. Tanks for agreeing too elp protect our"
            +" grain stores. Pleese urry.");
    greeted[name] = time();
    return;
  }
  force_me("say Greetings, stranger. Dee Tabaxi welcome all who are not friends to dee Orogs");
  greeted[name] = time();
}

void fail_speech(){
  force_me("say If jew want too %^BLUE%^try again%^RESET%^ too elp us, jew might"
    +" try too find a way too stop dem doing dat.");
}


void heart_beat(){
  int i, num;
  string * names, name, * removes;
  ::heart_beat();
  if (sizeof(greeted)<1){
    return;
  }
  names = keys(greeted);
  removes = ({});
  for (i=0;i<sizeof(greeted);i++){
    name = names[i];
    num = greeted[name];
    num --;
    if (num == 0){
      removes += names[i];
    } else {
      greeted[name] = num;
    }
  }
  if (sizeof(removes) >0){
    for (i=0;i<sizeof(removes);i++){
      name = removes[i];
      map_delete(greeted, name);
    }
  }
}

void catch_tell(string str){
  object ob;
  string name;
  int i;
  if (interact("nods to you", str)){
     for (i=0;i<sizeof(all_living(ETO));i++) {
       if (interact(all_living(ETO)[i]->query_cap_name(), str)) {
          ob = all_living(ETO)[i];
          break;
       }
    }

    if (member_array(ob, helpers)!=-1){
      if (objectp(ob) && ob->is_player()){
        name = ob->query_true_name();
        force_me("emoteat " + name + " turns to face $N");
        force_me("say Truly? Jew will elp de Tabaxi? Dis is "
          +"wonderrful news! Jew weell prrobably need some frends"
          +" as well, and jew weell need to tink about ow to "
          +"%^RED%^prepare de defences%^RESET%^. When jew tink jew"
          +" are ready, come and tell me jew are %^MAGENTA%^ready"
          +" to fight%^RESET%^. ");
        force_me("say I weell send a %^CYAN%^message off"
          +" defiance%^RESET%^ to dee %^GREEN%^orogs%^RESET%^ and"
         +" provoke an attack. Den we weell see eef jew can really"
         +" elp us!");
      }
    }
  }
}

string long_desc(){
  string desc;
  desc = "A tall, dignified older Tabaxi. His body has lost the power of its youth,"
           +" but his eyes shine bright with intelligence. His movements are slow and"
           +" careful. He has many tattoos decorating his face and upper body, and"
           +" wears a long bone through his nose. One of his teeth glints gold when"
           +" the light catches it. His arms are a bit skinny and he is carrying a"
           +" little extra weight on his belly. His once upright posture has stooped"
           +" slightly, rounding his shoulders and giving him an air of defeat.\n";
  if (member_array(TP, helpers)!=-1){
    desc += "%^BOLD%^%^YELLOW%^Nobacherie is waiting for you to tell him you are <ready"
            +" to fight>. You might want to make sure you have prepared all the "
            +"%^RESET%^%^CYAN%^defences%^BOLD%^%^YELLOW%^ you can, first  - and you may"
            +" want some friends to help you in the battle ahead.";
  }
  if (member_array(TP, defenders)!=-1){
    desc += "%^BOLD%^%^YELLOW%^Nobacherie is waiting for you to tell him to"
            +" %^BOLD%^%^RED%^<start attack>%^BOLD%^%^YELLOW%^. You might want to make"
            +" sure you have prepared all the %^RESET%^%^CYAN%^defences%^BOLD%^"
            +"%^YELLOW%^ you can, first  - and make sure you are in a party with any "
            +"players who are going to be helping out.";
  }
  return desc;
}
