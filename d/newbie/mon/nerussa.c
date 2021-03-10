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
   set_name("nerussa");
   set_id(({"scout","elf","elven scout","nerussa","Nerussa"}));
   set_short("Nerussa, elven scout");
   set_long(
@STYX
%^RESET%^Nerussa's %^ORANGE%^mousy brown hair %^RESET%^sticks out chaotically in a variety of directions, giving him the frenzied look you might expect of a master wizard.  His %^GREEN%^dark emerald eyes %^RESET%^show incredible intelligence and wisdom.  Tucked into his %^ORANGE%^brown leather breeches %^RESET%^is a stained white tunic made of a comfortable looking cotton which appears to have taken the brunt of a few mishaps with spell components.  His features aren't quite as delicate and chiseled as one might expect of the elven race, but his fluid movements and unearthly grace leave little doubt of his heritage.
STYX
);
   set_gender("male");
   set_race("elf");
   set_body_type("human");
   set_hd(10,3);
   set_max_level(10);
   set_size(2);
   set_alignment(7);
   set_overall_ac(5);
   set_max_hp(random(10)+60);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(10);
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
	set_stats("intelligence", 18);
	set_stats("wisdom", 18);
	set_stats("strength", 6);
	set_stats("charisma", 9);
	set_stats("dexterity", 16);
	set_stats("constitution", 12);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_property("alignment adjustment",-1);
   add_money("electrum",random(500));
   set_speed(80);
   new("/d/common/obj/armour/robe")->move(TO);
   command("wear robe");
   new("/d/common/obj/misc/pouch")->move(TO);
   command("wear pouch");
   set_spell_chance(90);
   set_spells(({"color spray","acid arrow","lightning bolt","magic missile"}));
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Nerussa muses:%^RESET%^ I do hope our lost elven cousin is safe.",
     "%^MAGENTA%^Nerussa smiles cautiously: %^RESET%^Are you seeking an adventure?",
     "%^MAGENTA%^Nerussa muses sadly: %^RESET%^I must try to find him and return "
        "him safely to his family.",
     "%^MAGENTA%^Nerussa muses: %^RESET%^I've heard reports he's been seen in "
        "the forest.",
     "Nerussa glances through his book and makes a few notes in the back.",
     "Nerussa runs his fingers through his unruly hair worriedly.",
   }), 0);
   set_emotes(3,({
     "%^MAGENTA%^Nerussa shouts: You'll pay for this someday!",
     "%^MAGENTA%^Nerussa shouts: Your vile attack on me won't be forgotten!"
   }), 1);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init(){
   ::init();
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

#define TRUST ({"elf", "voadkyn", "firbolg", "gnome", "wemic"})
#define DISTRUST ({"drow", "half-drow", "orc", "half-orc", "goblin", "hobgoblin", "bugbear", "ogre", "half-ogre", "gnoll", "ogre-mage", "kobold"})

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("NBelfquest_asked");
   killers = SAVE_D->query_array("NBelfquest_killers");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote scowls and looks prepared to defend himself.");
      force_me("say %^BOLD%^%^BLUE%^Begone!  "
        "I haven't forgotten your attack on me!");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote waves you away as he speaks to "+who->query_cap_name()+".");
     return;
   }
   if(who->query_quests()) {
     if(member_array("Elf Journal Quest",who->query_quests()) != -1) {
       switch( (string)who->query("elfquest") ) {
         case "G" :
           if(!random(3)) force_me("say It is good to see you again friend.  "
              "Thank you again for your help!");
           force_me("smile "+name+" gratefully");
           break;
         case "E" :
           force_me("say I hear tell you helped that half-orc mercenary who would "
           "have the poor lost elf killed!  Get out of my sight!");
           force_me("glare "+name);
           break;
       }
     return;
     }
   }
   if(member_array(race, DISTRUST) != -1) {
      force_me("say I've always known your kind to be evil.  Please go back "
        "to whatever hole you came out of and leave the good people alone.");
      force_me("glare "+name);
      return;
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say Oh, have you found something of his?  I do hope so!");
     if(!random(3))
      force_me("say If you have one of those pages, please give it to me.");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote looks you over thoughtfully.\n");
      force_me("say Greetings.  My name is Nerussa and I am an elven scout.");
      if(member_array(race, TRUST) != -1) {
         force_me("say It is good to see those of goodly races around.");
         force_me("smile "+name);
         force_me("say Perhaps you can help me?");
         return;
      }
      else {
         force_me("eye "+name);
         force_me("say I don't know if I should be trusting your kind or not.");
         force_me("say If you aren't evil, perhaps you will help me though?");
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"not evil") != -1)&& step1 && !step2)        {
      force_me("say Oh, good.  I've been sent in search of a young elf you see."
      "  His family fears he's perished.");
      force_me("emote pauses and glances around worriedly.");
      force_me("say He is a follower of Selune and his parents were rangers, " 
      "so perhaps he's hiding out in the forest.");
      force_me("say Have you seen any signs of him?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"journal") != -1 || strsrch(msg,"page") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"sign") != -1 || 
   strsrch(msg,"no") != -1 || strsrch(msg,"Yes") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("NBelfquest_asked", name);
      }
      force_me("say I've seen some pages from a journal.  If you find "
      "anything like that, please bring it to me.");
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say Have you heard of my concern and brought news?");
         break;
      case 1:
         force_me("say Beware of the evil all about, there are many who would "
         "rather see us all dead than alive, or enslaved.");
         break;
      case 2:
         force_me("say There seem to be many well-hidden rewards about.  Be "
         "aware of everything around you as you explore if you wish to survive "
         "and prosper.");
         break;
      case 3:
         force_me("emote seems to be concentrating on studying notes in his book.");
         break;
      case 4:
         force_me("emote looks at you thoughtfully.");
         break;
      case 5:
         force_me("emote watches the passersby cautiously.");
         break;
      default:
         force_me("emote glances at you briefly, then turns to scribble some "
         "notes in his book, apparently pre-occupied.");
   }
   return;
}

int page_current(object obj) {
   string month;
   string page;
   page = obj->query_property("pagex");
	month = EVENTS_D->query_month();
	switch(month) {
 	 case 1: if(page == "page_9") return 1;
 	    break;
	 case 2: if(page == "page_9") return 1;
	    break;
	 case 3: if(page == "page_8") return 1;
	    break;
	 case 4: if(page == "page_1") return 1;
	    break;
	 case 5: if(page == "page_2") return 1;
	    break;
	 case 6: if(page == "page_3") return 1;
	    break;
	 case 7: if(page == "page_4") return 1;
	    break;
	 case 8: if(page == "page_5") return 1;
	    break;
	 case 9: if(page == "page_6") return 1;
	    break;
	 case 10: if(page == "page_7") return 1;
	    break;
	 default: return 0;
  }
}

void receive_given_item(object obj){
   object item;
   int size;
   asked = SAVE_D->query_array("NBelfquest_asked");
   killers = SAVE_D->query_array("NBelfquest_killers");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote scowls and looks prepared to defend himself.");
      force_me("say %^BOLD%^%^BLUE%^Begone!  "
        "I haven't forgotten your attack on me!");
     return;
   }
   if(member_array("Elf Journal Quest",TP->query_quests()) != -1  && 
    (string)TP->query("elfquest") == "E") {
      force_me("say Well, thank you for the gift but that doesn't excuse "
        "your helping that half-orc mercenary.");
      force_me("glare "+TPQN);
      return;
   }   
   if(member_array("Elf Journal Quest",TP->query_quests()) != -1 && 
    (string)TP->query("elfquest") == "G") {
      force_me("say Oh, thank you again.  I will never forget your help!");
      force_me("smile "+TPQN+" gratefully");
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say Greetings and thank you for the gift.  Have we yet met?");
     return;
   }   
   if((string)obj->query_name() != "journal page") {
       force_me("say Greetings and thank you but this isn't any help.");
       return;
   }   
   if((string)obj->query_name() == "journal page") {
      force_me("emote reads over the page carefully and smiles.\n");
      if(!page_current(obj)) {
        switch(random(3)) {
         case 0:
          force_me("say This is indeed one of his, but I've seen him since this "
            "was written.  I need something more recent to reassure his family.");
          break;
         case 1:
          force_me("emote compares the page to one from his pouch and nods "
            "slowly.");
          force_me("say Yes, it looks like he wrote it, but I need something more "
            "recent to help locate him.");
          break;
         case 2:
          force_me("say If you have more, please let me see them.  If not, do "
            "please keep looking.");
          break;
        }
        force_me("emote sighs quietly and tucks the page away.");
        obj->remove();
        return;
      }
      force_me("say This confirms it's written in his hand and it seems recent.  "
        "It does certainly bring us hope to find him alive!");
      force_me("say I thank you for that and wish to reward you for your help.");
      obj->remove();
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("NBelfquest_asked", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Elf Journal Quest",TP->query_quests()) == -1){
        item = new("/d/newbie/obj/clothing/quest_armbandG");
        item->move(TO);        
        size = TP->query_size();
        item->set_size(size);
        force_me("give armband to "+TPQN);
        add_money("gold",900+random(100));
        force_me("give "+query_money("gold")+" gold coins to "+TPQN);
        force_me("say Please take that as a reward for your good deed!");
        tell_object(TP,"%^BOLD%^You have finished the Quest of the Elf Journal!");
        TP->set_quest("Elf Journal Quest");
        TP->set("elfquest", "G");
        TP->fix_exp(1000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" did the non-evil/good "
          "version of the newbie quest.");
        call_out("go_away",0);
      }
      return;
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("NBelfquest_killers", "stringname")
    int hold;
    killers = SAVE_D->query_array("NBelfquest_killers");
    hold = ::kill_ob(victim, which);
    if(member_array(victim->query_name(), killers) != -1) return hold;
    SAVE_D->set_value("NBelfquest_killers", victim->query_name());
    command("say %^BOLD%^%^RED%^You evil scum, this attack won't be forgotten!");
    return hold;
}

void go_away() {
   force_me("emote bows gratefully and then suddenly disappears.");
   TO->move("/d/shadowgate/void"); 
   TO->remove();
}


void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
