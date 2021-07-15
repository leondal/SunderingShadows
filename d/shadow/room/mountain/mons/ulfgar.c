//ulfgar.c - dwarf for the pipe quest
//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
#include <std.h>
#include <daemons.h>

inherit MONSTER;
int step1;
int step2;
int step3;
string *asked;
string *killers;

void create(){
object obj,obj2,obj3;
   ::create();
   set_name("ulfgar");
   set_id(({"ulfgar","dwarf","dwarven miner","miner","Ulfgar"}));
   set_short("Ulfgar, dwarven miner");
   set_long(
      "Ulfgar's strong, sinewy hands are weathered and creased from many years "+
      "spent in the mines of Echoes Mountains.  His leathery face is deep brown, "+
      "and covered in a three foot long beard that has been separated into "+
      "dozens of tiny braids tied with leather cording.  His hair is a dusky "+
      "gray and is kept short and neat.  His shoulders seem unnaturally wide "+
      "for someone his height, and he is well-muscled from swinging his pick "+
      "all day for many decades now.  His strong, proud chin is lifted, and his "+
      "clear blue eyes meet any gaze.  He is dressed simply, wearing a belted "+
      "brown tunic and leather breeches."
   );
   set_gender("male");
   set_race("dwarf");
   set_body_type("human");
   set_hd(20,3);
   set_max_level(20);
   set_size(2);
   set_monster_feats(({"parry"}));
   set_alignment(1);
   set_overall_ac(0);
   set_max_hp(random(50)+250);
   set_hp(query_max_hp());
//   set_exp(2000);
   set_new_exp(20,"normal");
   set_level(20);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_guild_level("fighter",10);
   set_stats("intelligence", 12);
   set_stats("wisdom", 14);
   set_stats("strength", 18);
   set_stats("charisma", 9);
   set_stats("dexterity", 14);
   set_stats("constitution", 20);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_property("alignment adjustment",-1);
   add_money("gold",random(200));
   set_speed(80);
   obj = new("/d/antioch/antioch2/obj/breeches.c");
   obj->move(TO);
   obj->set_size(2);
   force_me("wear breeches");
   obj2 = new("/d/antioch/antioch2/obj/tunic.c");
   obj2->move(TO);
   obj2->set_size(2);
   force_me("wear tunic");
   obj3 = new("/d/shadow/room/mountain/obj/mining_pick.c");
   obj3->move(TO);
   force_me("wield pick");
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Ulfgar mumbles gruffly:%^RESET%^ Blasted kobold!  Singe my beard...",
     "%^MAGENTA%^Ulfgar says a little loudly: %^RESET%^Hey there!  Think you'll help a dwarf like me?",
     "%^MAGENTA%^Ulfgar mutters: %^RESET%^I have to find that blasted kobold that stole my pipe.",
     "%^MAGENTA%^Ulfgar pauses and says: %^RESET%^He's got to be somewhere in them caves...",
     "Ulfgar hefts his mining pick and sighs as he glances down the tunnel.",
     "Ulfgar tugs at his braided beard and hmmphs loudly.",
   }), 0);
   set_emotes(3,({
     "%^MAGENTA%^Ulfgar shouts: I'll get you, you blasted son of a goat!",
     "%^MAGENTA%^Ulfgar shouts: No one attacks a dwarf and gets away with it!"
   }), 1);
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
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("PipeQuest_asked");
   killers = SAVE_D->query_array("PipeQuest_killers");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote hefts his pick and scowls menacingly.");
      force_me("say Vile scoundrel!! I haven't forgotten what ya did to me!");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote glances at you and frowns slightly as he speaks to "+who->query_cap_name()+".");
     return;
   }
   if(who->query_quests()) {
     if(member_array("Pipe Quest",who->query_quests()) != -1) {
       switch( (string)who->query("pipequest") ) {
         case "dwarf" :
           if(!random(3)) force_me("say It's good to see ya face again, stranger.  "+
              "Thanks for returning me pipe!");
           force_me("grin "+name+" happily");
           break;
         case "kobold" :
           force_me("say I heard you helped that little thief kobold!  Get away from "+
              "here before I pretend your head's a wall of rock!");
           force_me("emote hefts his pick and growls.");
           force_me("glare "+name);
           break;
       }
     return;
     }
   }
   if(member_array(race, DISTRUST) != -1) {
      force_me("say You're crazy if you think you're gonna be allowed to wander "+
         "these mines.  Get out of here now!");
      force_me("glare "+name);
      return;
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("emote glances around as his cheeks turn a light pink.");
      force_me("say Any luck yet on that...you know what?");
     if(!random(3))
      force_me("whisper "+name+" If you happen ta find my pipe, please give it to me.");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1 || strsrch(msg,"Hey") != -1) && !step1){
      step1 = 1;
      force_me("emote nods thoughtfully, stroking his beard.\n");
      force_me("say Hail!  Name's Ulfgar, and I'm a miner here in these glorious tunnels.");
      if(member_array(race, TRUST) != -1) {
         force_me("say Glad to see more of your kind around...");
         force_me("smile "+name);
         force_me("say Think ya could help me with something?");
         return;
      }
      else {
         force_me("eye "+name);
         force_me("say Your kind's not always too trustworthy, so I'm not sure if I should ask...");
         force_me("say But maybe, if you don't have an evil heart, you'd help this old dwarf out?");
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"not evil") != -1)&& step1 && !step2)        {
      force_me("say Ya will?  Great!  See, it goes like this...");
      force_me("emote frowns and glances around, then lowers his voice.");
      force_me("speech speak in hushed tones");
      force_me("say There's this kobold, see, and umm...well...it stole something "+
         "from me.");
      force_me("emote frowns deeply and blushes slightly.");
      force_me("say It's a family heirloom, a pipe.  And I need to be getting it back, but "+
         "I can't find the tricky little devil!  It could be anywhere in this cave system..."+
         "it connects all the way to Dragon's Den, ya know.  Have you seen the beast?");
      force_me("speech say");
      step2 = 1;
      return;
   }

   if((strsrch(msg,"yes") != -1 || strsrch(msg,"kobold") != -1 || 
   strsrch(msg,"no") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"pipe") != -1 || strsrch(msg,"No") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("PipeQuest_asked", name);
      }
      force_me("say I think it might be hiding with them other kobolds in Dragon's Den Caves.");
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("say Have you found any sign of that kobold yet?");
         break;
      case 1:
         force_me("say Careful of them little beady-eyed kobolds!  They're tricky, they are.");
         break;
      case 2:
         force_me("say There's hidden treasure all in caves, ya know.  Keep "+
            "ya eyes open and you just might find some.");
         break;
      case 3:
         force_me("emote swings his pick as he mines.");
         break;
      case 4:
         force_me("emote pauses and brushes dust from an unpolished gem.");
         break;
      case 5:
         force_me("emote glances nervously into the shadows of the tunnels.");
         break;
      default:
         force_me("emote looks at you carefully then shrugs his shoulders and returns to his work.");
   }
   return;
}

void receive_given_item(object obj){
   object item;
   asked = SAVE_D->query_array("PipeQuest_asked");
   killers = SAVE_D->query_array("PipeQuest_killers");
   if(!objectp(obj)) return;
   if(member_array(TPQN, killers) != -1) {
      force_me("emote hefts his pick and scowls deeply.");
      force_me("say Evil scoundrel!  Ya think I've forgotten what you've done?");
     return;
   }
   if(member_array("Pipe Quest",TP->query_quests()) != -1  && 
    (string)TP->query("pipequest") == "kobold") {
      force_me("say Oh, think you can just give me this and I'll forget you helped that little thief, eh?");
      force_me("glare "+TPQN);
      return;
   }   
   if(member_array("Pipe Quest",TP->query_quests()) != -1 && 
    (string)TP->query("pipequest") == "dwarf") {
      force_me("say Thank ye again for helping me with my little...umm...problem there.");
      force_me("grin "+TPQN+" sheepishly");
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say Well, where did ye find this?  How did you know I was looking for it?");
     force_me("emote frowns slightly and seems confused.");
     force_me("say It does look like something I was looking for...but how do I know you aren't "+
        "one of those tricky magic users?  Nah...I can't accept this.  You come back if you "+
        "feel like talking like a civilized person...");
     force_me("emote gives a small grin but seems suspiscious as he looks over the pipe, then smashes "+
        "it with his pick, muttering something about illusions.");
     obj->remove(TO);
     return;
   }   
   if((string)obj->query_name() != "ivory cave pipe") {
       force_me("say Ahh...that's very nice of you, but it's not quite what I'm looking for.");
       return;
   }   
   if((string)obj->query_name() == "ivory cave pipe") {
      force_me("emote turns the pipe carefully in his hands as his face breaks into a wide grin.");
      force_me("say This most certainly is my family pipe!  I hope that blasted kobold thief "+
         "pays for its ways...");
      force_me("say I thank ye for all your help.  It won't be forgotten.  My family can rest peacefully "+
         "in their graves now, with this out of the hands of that thieving little scoundrel.");
      obj->remove();
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("PipeQuest_asked", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Pipe Quest",TP->query_quests()) == -1){
        item = new("/d/shadow/obj/misc/pipe");
         item->move(TP);
        add_money("gold",900+random(300));
        force_me("give "+query_money("gold")+" gold coins to "+TPQN);
        force_me("say I don't have much to offer, but here's a bit of reward for all your help.  And "+
           "please take this pipe as well...nothing like a good pipe!");
        tell_object(TP,"%^BOLD%^%^BLUE%^You have completed the Pipe Quest!%^RESET%^");
        TP->set_quest("Pipe Quest");
        TP->set("pipequest", "dwarf");
        TP->fix_exp(800000,TP);
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" helped out the dwarf "
          "on the Pipe Quest.");
      }
      return;
   }
   return;
}

int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("PipeQuest_killers", "stringname")
    int hold;
    killers = SAVE_D->query_array("PipeQuest_killers");
    hold = ::kill_ob(victim, which);
	//changed by Saide to use victim->query_name() - instead of TPQN - in order to 
	//prevent an occassional error for snakes or whatever other mobs might attack it,
	//looks like it works fines 10/27/03
    if(member_array(victim->query_name(), killers) != -1 || !interactive(victim)) return hold;
    SAVE_D->set_value("PipeQuest_killers", victim->query_name());
    command("say %^BOLD%^How dare you attack me?  Villain!  This won't be forgotten!");
    return hold;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
