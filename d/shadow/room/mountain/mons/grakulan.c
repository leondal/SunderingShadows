//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//grakulan.c - kobold leader for revamped Pipe Quest

#include <std.h>
#include <daemons.h>

inherit MONSTER;
int step1;
int step2;
int step3;
string *asked;
string *killers;
int query_month();

void create(){
   ::create();
   set_name("grakulan");
   set_id(({"grakulan","Grakulan","kobold","kobold leader"}));
   set_short("Grakulan, kobold leader");
   set_long(
      "This hulking kobold seems to rule by might among his scaly kin.  "+
      "Though slender, his frame is well-muscled, and he stands nearly "+
      "five feet tall.  His dry, scaly skin is a deep rusty black, and his "+
      "eyes shine an eerie orange-red.  He wears a tattered orange bandana "+
      "on his head, through which poke two small ivory horns.  His clawed "+
      "fingers curve around the haft of the wicked axe he carries, adding to "+
      "the menacing sneer he wears.");
   set_gender("male");
   set_race("kobold");
   set_body_type("human");
   set_hd(20,3);
   set_max_level(20);
   set_size(1);
   set_alignment(3);
   set_overall_ac(0);
   set_max_hp(random(50)+250);
   set_hp(query_max_hp());
//   set_exp(2000);
   set_new_exp("normal",20);
   set_level(20);
   set_class("thief");
   set_mlevel("thief",20);
   set_guild_level("thief",20);
	set_stats("intelligence", 12);
	set_stats("wisdom", 12);
	set_stats("strength", 19);
	set_stats("charisma", 9);
	set_stats("dexterity", 18);
	set_stats("constitution", 15);
   set_property("full attacks",1);
   set_scrambling(1);
   add_money("electrum",random(500));
   set_wielding_limbs(({"right hand","left hand"}));
   new("/d/common/obj/armour/leather")->move(TO);
   command("wear armor");
   new("/d/common/obj/weapon/battle_axe")->move(TO);
   command("wield axe");
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Grakulan chuckles to himself:  %^RESET%^Take pipe from dwarf...s'like "+
        "takin' dagger from goblin.",
     "%^MAGENTA%^Grakulan grumbles:  %^RESET%^Where that stinkin' thief...she shoulda "
        "been back.",
     "%^MAGENTA%^Grakulan frowns and says:  %^RESET%^Not trustin' female...want "
        "somethin' done, do it yourself.",
     "%^MAGENTA%^Grakulan mutters:  %^RESET%^Where she hidin'?  I find her, I kill her "
       "myself!  Drawin' attention...",
     "Grakulan glances around and sighs as he lets out a sharp noise like a yapping dog.",
     "Grakulan tightens his grip on his axe and seems to be muttering to himself.",
   }), 0);
   set_emotes(3,({
     "%^MAGENTA%^Grakulan yaps:  %^RESET%^You think you kill me?!"
         "  I'll teach you!",
     "Grakulan's eyes flash red as he swings the might axe!",
     "%^MAGENTA%^Grakulan curses:  %^RESET%^You pay now!!  Mighty kobolds kill you baddie!",
   }), 1);
    set_monster_feats(({
	    "dodge",
		"evasion",
		"mobility",
		"scramble",
		"spring attack",
		"combat reflexes"
    }));   
}

void init(){
   ::init();
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

#define TRUST ({"firbolg", "gnome", "dwarf", "halfling"})
#define DISTRUST ({"drow", "half-drow", "orc", "half-orc", "goblin", "hobgoblin", "bugbear", "ogre", "half-ogre", "gnoll", "ogre-mage", "kobold"})

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   string race;
   string name;
   object current;
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("PipeQuest_asked2");
   killers = SAVE_D->query_array("PipeQuest_killers2");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote swings his axe wildly and hops to the side.");
      force_me("say You big baddie!!  No talk after you try kill me!");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote waves you away as he speaks to "+who->query_cap_name()+".");
     return;
   }
   if(who->query_quests()) {
     if(member_array("Pipe Quest",who->query_quests()) != -1) {
       switch( (string)who->query("pipequest") ) {
         case "dwarf" :
           force_me("sneer");
           force_me("say You helped baddie get back pipe.  You get my people "
           "hurt!  Go away, baddie!");
           force_me("emote waves his hand as his tail twitches.");
           break;
         case "kobold" :
           force_me("grin");
           force_me("say You my kind!  Play game with baddie dwarf.  You okay here.");
           break;
      default: break;
       }
     return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say You know where she is?");
     if(!random(3))
      force_me("say If ya find thiefie kobold, bring proof.  I give you somethin'!");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("eye "+name);
      force_me("say 'Lo...");
      if(member_array(race, TRUST) != -1) {
         force_me("say Why you talkin' to me?  You goodie kind...not like kobolds!");
         force_me("emote frowns and looks almost thoughtful.");
         force_me("say Mebbe doh...mebbe you help dis kobold?");
         return;
      }
      if(member_array(race, DISTRUST) != -1) {
         force_me("grin");
         force_me("say You just da kind to help me!  You be lookin' for something doh, I know...");
         force_me("cackle");
         force_me("say You help me if I give you somethin'?");  
         return;
      }
      else {
         force_me("say Mebbe you help me find someone?  No ask questions, though.");
         force_me("grin "+name);
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"not good") != -1)&& step1 && !step2)        {
      force_me("emote glances from side to side, then leans closer.");
      force_me("say Here goes...see, dis kobold - like me - she's missin'.  She went "+
         "on secret mission.  Steal baddie dwarf pipe.  She still gone doh.");
      force_me("nod "+name+" seriously");
      force_me("say I send some lookin' for her, but no find.  She may be dead!  I need "+
         "dat pipe.  You go look and find her...and da pipe.");
      force_me("say Will you bring it to me?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"pipe") != -1 || strsrch(msg,"dwarf") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kobold") != -1 || 
   strsrch(msg,"Yes") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("PipeQuest_asked2", name);
      }
      force_me("say One kobold seen her.  In the center of caves.  But she disappear!");
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say Hey!  You see kobold hidin'?");
         break;
      case 1:
         force_me("say I pay big you bring my thief.");
         break;
      case 2:
         force_me("say If you no baddie, mebbe you help me?");
         break;
      case 3:
         force_me("emote peers into the shadows of the caverns and mutters to himself.");
         break;
      case 4:
         force_me("emote grins and shows broken yellow teeth.");
         break;
      case 5:
         force_me("emote tilts his head and narrows his eyes, sizing you up.");
         break;
      default:
         force_me("emote mutters to himself and sharpens his axe.");
   }
   return;
}

void receive_given_item(object obj){
   object item;
   asked = SAVE_D->query_array("PipeQuest_asked2");
   killers = SAVE_D->query_array("PipeQuest_killers2");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote snarls and yaps, swinging his axe wildly.");
      force_me("say You baddie!!  Curse you!  You think I forget so easy?");
      return;
   }
   if(member_array("Pipe Quest",TP->query_quests()) != -1 && 
    (string)TP->query("pipequest") == "dwarf"){
      force_me("say What kind of trick you pullin'?  I hear you already give it to dat dwarf.");
      force_me("roll");
      return;
   }
   if(member_array("Pipe Quest",TP->query_quests()) != -1 && 
    (string)TP->query("pipequest") == "kobold"){
      force_me("say You already brought dis once.  Think I fall for it again?");
      force_me("smirk "+TP);
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say Why you think I want dis?  I don't know you.");
     return;
   }   
   if((string)obj->query_name() != "ivory cave pipe") {
      force_me("say Good gift!  Thank you...you no baddie.");
      return;
   }   
   if((string)obj->query_name() == "ivory cave pipe") {
        force_me("emote snatches the pipe greedily and studies it, his eyes glowing red.");
        force_me("emote tosses back his head and laughs.");
        force_me("say She did it!!  This dat baddie dwarf pipe!  She be alive.");
        obj->remove();
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("PipeQuest_asked2", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Pipe Quest",TP->query_quests()) == -1){
        force_me("say Guess I owe ya somethin'...");
        add_money("gold",900+random(300));
        force_me("give "+query_money("gold")+" gold coins to "+TPQN);
        item = new("/d/shadow/obj/misc/pipe");
        item->move(TP);        
        force_me("say You keep quiet now.  No want de dwarves to know...");
        force_me("snicker");
        tell_object(TP,"%^BOLD%^%^BLUE%^You have completed the Pipe Quest!%^RESET%^");
        TP->set_quest("Pipe Quest");
        TP->set("pipequest", "kobold");
        TP->fix_exp(800000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" helped out the %^BOLD%^%^RED%^kobold %^RESET%^"
          "on the Pipe Quest.");
      }
      return;
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("PipeQuest_killers2", "stringname")
    int hold;
    killers = SAVE_D->query_array("PipeQuest_killers2");
    hold = ::kill_ob(victim, which);
    if(member_array(victim->query_name(), killers) != -1 || !interactive(victim)) return hold;
    SAVE_D->set_value("PipeQuest_killers2", victim->query_name());
    force_me("say %^BOLD%^%^RED%^I no forget dis, baddie!");
    return hold;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
