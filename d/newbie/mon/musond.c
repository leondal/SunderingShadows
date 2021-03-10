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
   set_name("musond");
   set_id(({"mercenary","half-orc","half-orc mercenary","musond","Musond"}));
   set_short("Musond, half-orc mercenary");
   set_long(
@STYX
Musond's orcish parentage is obvious but, if you'd never seen an orc, he might almost pass for an ugly or primitive human.  His nose is flattened but only somewhat snout-like below a low jutting forehead and deepset %^ORANGE%^dark brown eyes%^CYAN%^.  He has %^ORANGE%^dark brown, coarse hair %^CYAN%^and quite a bit of body hair that tends to obscure the slight grayish-green tint to his skin although many battle-scars are quite evident.  His clothing is well-worn and blood-stained. 
STYX
);
   set_gender("male");
   set_race("half-orc");
   set_body_type("human");
   set_hd(10,3);
   set_max_level(10);
   set_size(2);
   set_alignment(6);
   set_overall_ac(5);
   set_max_hp(random(10)+70);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(10);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_guild_level("fighter",10);
	set_stats("intelligence", 12);
	set_stats("wisdom", 12);
	set_stats("strength", 19);
	set_stats("charisma", 9);
	set_stats("dexterity", 16);
	set_stats("constitution", 18);
   set_property("full attacks",1);
   add_money("electrum",random(500));
   set_speed(80);
   set_wielding_limbs(({"right hand","left hand"}));
   new("/d/common/obj/armour/leather")->move(TO);
   command("wear armor");
   new("/d/common/obj/weapon/bastard_two")->move(TO);
   command("wield sword");
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Musond grumbles:  %^RESET%^Cursed elven scout better not find "
        "him 'fore I do.",
     "%^MAGENTA%^Musond mutters:  %^RESET%^They better make good on dat reward "
        "if I find that elf.",
     "%^MAGENTA%^Musond grumbles:  %^RESET%^Never trust a drow ya know, but "
        "there's supposed ta be money in this deal.",
     "%^MAGENTA%^Musond mutters:  %^RESET%^Dead or alive they say.  Dead's "
       "easier ta drag along.",
     "Musond shows his half-rotten teeth as he grins evilly.",
     "Musond licks some blood from the blade of his sword.",
   }), 0);
   set_emotes(3,({
     "%^MAGENTA%^Musond shouts:  %^RESET%^Bah, think it'll save him ta kill me?"
         "  Fat chance that!",
     "Musond lets out a blood-curdling scream as he swings his sword at your head!",
     "%^MAGENTA%^Musond curses:  %^RESET%^No reward fer you now, ya bloody fool.",
   }), 1);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init(){
   ::init();
}

void catch_say(string msg){
    if(!interactive(TP)) { return; }
   call_out("reply_func",1,msg,TP);
}

#define TRUST ({"elf", "voadkyn", "firbolg", "gnome", "wemic"})
#define DISTRUST ({"drow", "half-drow", "orc", "half-orc", "goblin", "hobgoblin", "bugbear", "ogre", "half-ogre", "gnoll", "ogre-mage", "kobold"})

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   string race;
   string name;
   object current;
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("NBelfquest_asked2");
   killers = SAVE_D->query_array("NBelfquest_killers2");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote spits at you and swings his sword menacingly.");
      force_me("say Curse you!  I'm not dealin' with ya after ya attacked me "
        "so go away!");
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
           force_me("say I hear ya helped that elven scout that wants ta save "
           "his kin.  Obviously yer not gonna be the type ta actually help me.");
           force_me("roll");
           break;
         case "E" :
           force_me("say Ya know somethin' else do ya?  I'm fresh outa rewards "
               "tho.");
           force_me("smirk "+name);
           break;
      default: break;
       }
     return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say Oh, have ya found somethin' of his?");
     if(!random(3))
      force_me("say If he's dead already, I ain't gonna get no reward for "
        "findin' him so give me what ya found will ya?");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("eye "+name);
      force_me("say Hey there.  Name's Musond and yeah, I'm lookin' for help.");
      if(member_array(race, TRUST) != -1) {
         force_me("say Ya really gonna talk ta an evil sod like me, bein' "
           "yer kind're gener'lly raised all goodly?");
         force_me("smirk "+name);
         force_me("say Well, if ya'll help just say so?");
         return;
      }
      if(member_array(race, DISTRUST) != -1) {
         force_me("say Yah, I bet you be just the sort I'm needin' ta get that "
           "reward.");
         force_me("cackle");
         force_me("say Can I bribe ya ta help me with findin' that elf kid?");  
         return;
      }
      else {
         force_me("say You the type that'll do somethin' fer a reward without "
           "askin' many questions?");
         force_me("smirk "+name);
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"not good") != -1)&& step1 && !step2)        {
      force_me("say OK then.  There be this young elf who knows too much.  I'm "
      "bein' paid ta shut him up, but I need help ta find him.");
      force_me("smirk "+name);
      force_me("say They say he follows Selune an his parents be rangers, " 
        "so we been lookin' in the forest.");
      force_me("say Ya seen any sign of him?");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"journal") != -1 || strsrch(msg,"page") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"sign") != -1 || 
   strsrch(msg,"Yes") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("NBelfquest_asked2", name);
      }
      force_me("say I seen some pages he wrote.  If ya find somethin' like "
        "that, bring 'em to me an we'll talk reward.");
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say Ya seen a young elf that's been writin' notes around?");
         break;
      case 1:
         force_me("say Bah, that elf scout's a goody goody but I bet he's "
           "just lookin' fer a reward too.");
         break;
      case 2:
         force_me("say A smart fella can make a good livin' if he don't get "
           "soft.  Who wants ta swing a mining pick 'cept maybe at dem little "
           "people's heads eh?");
         break;
      case 3:
         force_me("emote wipes some blood off his sword with his sleeve.");
         break;
      case 4:
         force_me("emote cackles and picks at something in his teeth.");
         break;
      case 5:
         force_me("emote seems to be sizing up everyone who passes by.");
         break;
      default:
         force_me("emote glances at you, then looks around the room as if "
         "distracted by something.");
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
   int size;
   object item;
   asked = SAVE_D->query_array("NBelfquest_asked2");
   killers = SAVE_D->query_array("NBelfquest_killers2");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote spits at you and swings his sword menacingly.");
      force_me("say Curse you!  I'm not dealin' with ya after ya attacked me "
        "so go away!");
      return;
   }
   if(member_array("Elf Journal Quest",TP->query_quests()) != -1 && 
    (string)TP->query("elfquest") == "G"){
      force_me("say Well, thank ya fer that, but I ain't givin' ya a reward "
        "when ya helped the elven scout already.");
      force_me("roll");
      return;
   }
   if(member_array("Elf Journal Quest",TP->query_quests()) != -1 && 
    (string)TP->query("elfquest") == "E"){
      force_me("say I already rewarded ya once, I ain't doin' it again.");
      force_me("smirk "+TPQN);
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say 'ello and thank ya I guess.  Have we met?");
     return;
   }   
   if((string)obj->query_name() != "journal page") {
      force_me("say Ha, this ain't what I'm needin' but thank ya I s'pose.");
      return;
   }   
   if((string)obj->query_name() == "journal page") {
      if(!random (4))
        force_me("emote practically snatches the page away and looks it over.");
      if(!page_current(obj)) {
        switch(random(3)) {
         case 0:
            force_me("say This be his I think.  But I seen him since this  "
            "and he got away.  I need somethin' fresher ta help find him.");
            break;
         case 1: 
          force_me("say If ya got more, let me have it.  If not, yer wastin' "
            "me time 'cause this ain't enuf help.");
          break;
        case 2:
          force_me("say Keep lookin' will ya?  This is too old ta be useful.");
          break;
        }
        force_me("emote grumbles and curses as he wads up the page.");
        obj->remove();
        return;
      }
      force_me("say Ahah!  Looks ta be his all righty and maybe it'll help me "
        "find the little troublemaker an get that reward.");
      obj->remove();
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("NBelfquest_asked2", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Elf Journal Quest",TP->query_quests()) == -1){
        force_me("say Guess ya earned somethin' fer the trouble.");
        add_money("gold",500+random(400));
        force_me("give "+query_money("gold")+" gold coins to "+TPQN);
        item = new("/d/newbie/obj/clothing/quest_armbandE");
        item->move(TO);        
        size = TP->query_size();
        item->set_size(size);
        force_me("give armband to "+TPQN);
        force_me("say There ya be, just keep yer mouth shut now eh?");
        tell_object(TP,"%^BOLD%^You have finished the Quest of the Elf "
           "Journal! (gasp - the evil version)");
        TP->set_quest("Elf Journal Quest");
        TP->set("elfquest", "E");
        TP->fix_exp(1000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" did the "
           "somewhat evil version of the newbie quest.");
        call_out("go_away", 0);
      }
      return;
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("NBelfquest_killers2", "stringname")
    int hold;
    killers = SAVE_D->query_array("NBelfquest_killers2");
    hold = ::kill_ob(victim, which);
    if(member_array(victim->query_name(), killers) != -1) return hold;
    SAVE_D->set_value("NBelfquest_killers2", victim->query_name());
    command("say %^BOLD%^%^RED%^You evil scum, this attack won't be forgotten!");
    return hold;
}

void go_away() {
   force_me("emote cackles and then suddenly disappears.");
   TO->move("/d/shadowgate/void"); 
   TO->remove();
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
