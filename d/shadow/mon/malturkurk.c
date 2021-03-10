//put the silk cloak on a Tonovi head guard and a comparable one on Pirate
//island a while back.  Now low levels don't get something they can't use &
//higher level ones don't have to kill a hermit wizard who doesn't hurt anyone
//or keep running to DD to get it.  *Styx*  2/22/02
//Was originally Rufsu - now is this kobold for the Pipe Quest -Circe- 8/17/03

#include <daemons.h>
#include "/d/shadow/mon/melnmarn.h"
#include "/d/shadow/room/cave/ddcaves.h"

inherit MONSTER;

int step1;
int step2;
int step3;
string *asked;
string *killers;


void create() {
    ::create();
	set_name("malturkurk");
	set_id( ({ "malturkurk","kobold","Malturkurk","monster" }) );
	set_race("kobold");
	set_gender("female");
      set_level(12);
	set_short("Malturkurk, a cowering kobold");
	set_long("This slight kobold seems smaller than most, and her "+
         "%^BOLD%^%^RED%^glowing red eyes %^RESET%^%^CYAN%^dart continually "+
         "as she nervously scans her surroundings.  Her scaly skin is "+
         "%^ORANGE%^dark rusty brown%^CYAN%^, and she has two small "+
         "%^WHITE%^horns %^CYAN%^protruding from her head.  Her long, "+
         "rat-like tail twitches beneath the ragged leather armor she "+
         "wears.  Her reptillian feet end in clawed toes much like her "+
         "hands, and she has two shabby-looking daggers at her side.  Her voice is strange, "+
         "much like that of a yapping dog."
      );
	set_body_type("human");
	set_class("thief");
  	set("aggressive", 0);
  	set_alignment(3);
  	set_size(1);
   	set_stats("intelligence",10);
   	set_stats("wisdom",10);
   	set_stats("strength",15);
   	set_stats("charisma",5);
   	set_stats("dexterity",18);
   	set_stats("constitution",14);
        set_hd(12,5);
      set_hp(random(25)+150);
	set_max_hp(query_hp());
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
//        new("/d/shadow/obj/clothing/silkcloak")->move(TO);
//        command("wear cloak");
      set_wielding_limbs( ({ "right hand", "left hand" }) );
      new("/d/common/obj/weapon/dagger")->move(TO);
        command("wield dagger");
      new("/d/common/obj/weapon/dagger")->move(TO);
        command("wield dagger");
      new(DDOBJ"ivorypipe")->move(TO);
      set_exp(500);
      set_scrambling(1);
      set_spoken("wizish");
      set_achats(5, ({"%^MAGENTA%^Marturkurk yells: %^RESET%^You baddie!!  Me boss kill you!!",
           "The kobold's tail twitches as she jumps around."}) );
      set_emotes(2, ({"The kobold whimpers quietly and slips into the shadows.",
           "The kobold straightens in bravado and stares at you.", 
           "The kobold's beady red eyes seem to be sizing you up.",
      }), 0); 
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
   string race;
   string name;
   object current;
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("PipeQuest_asked3");
   killers = SAVE_D->query_array("PipeQuest_killers3");
   if(!msg || !objectp(who)) return;
   if(member_array(name, killers) != -1) {
      force_me("emote darts to the side and brandishes her daggers.");
      force_me("say Stay back, baddie!  I kill you dis time!");
      return;
   }
   if (objectp(current) && who != current) {
     force_me("emote turns quickly and her tail twitches before returning to her conversation.");
     return;
   }
   if(who->query_quests()) {
     if(member_array("Pipe Quest",who->query_quests()) != -1) {
       switch( (string)who->query("pipequest") ) {
         case "dwarf" :
           force_me("emote growls and her tail twitches.");
           force_me("say You took pipe to baddie dwarf!");
           force_me("emote brandishes her daggers and growls menacingly.");
           break;
         case "kobold" :
           force_me("grin");
           force_me("say You take pipe to my master!  You my kind.");
           break;
      default: break;
       }
     return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say You find my master yet?");
     if(!random(3))
      force_me("say Take pipe to master so I can come out!");
      return;
   }
//lower case "hi" hits too often as a part of larger words, "ello" and "reeting"
//look funny, but it's the easy way to catch upper and lower case. *Styx*
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("cringe");
      force_me("say You baddie dere?!");
      if(member_array(race, TRUST) != -1) {
         force_me("say How you find me?  I know - you kill me!");
         force_me("emote trembles and holds out a pipe.");
         force_me("say Please no kill me!  Take, take!  I no steal from baddie dwarf!");
         return;
      }
      if(member_array(race, DISTRUST) != -1) {
         force_me("eye "+name);
         force_me("say You look okay...mebbe you help dis poor kobold?");
         force_me("say I stuck here 'till master finds baddie dwarf and kill him.");
         force_me("emote shakes her head as her beady eyes glow red.");
         force_me("say Mebbe you take dis pipe to master?");  
         return;
      }
      else {
         force_me("eye "+name);
         force_me("say I stuck here!  Can't leave 'till baddie dwarf gone.");
         force_me("say Mebbe you take dis pipe to master so he know what happened?");
         return;
      }
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"take the pipe") != -1)&& step1 && !step2)        {
      if(member_array(race, DISTRUST) !=-1){
         force_me("emote peers up and trembles slightly.");
         force_me("say I on secret mission, but go wrong.  Now I stuck here.  Can't leave.");
         force_me("nod "+name+" quickly");
         force_me("say Dis pipe need to go to master.  He know what to do, den I can leave.");
         force_me("say Will you take it?");
      }
      if(member_array(race, TRUST) !=-1){
         force_me("emote pushes the pipe out with shaking hands.");
         force_me("say Take, take!  Please no kill me!");
         force_me("say Will you take pipe and no kill me?");
      }
      else {
         force_me("emote gives a small, yellow-toothed grin.");
         force_me("say Master need dis pipe so he know I do my job!");
         force_me("say You take pipe to him?");
      }
      step2 = 1;
      return;
   }

   if((strsrch(msg,"pipe") != -1 || strsrch(msg,"dwarf") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kobold") != -1 || 
   strsrch(msg,"Yes") != -1 || strsrch(msg,"master") !=-1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("PipeQuest_asked3", name);
      }
      force_me("say Thank you!  Now mebbe I live!");
      if(present("ivory cave pipe",TO)){
         force_me("give pipe to "+name);
      }
      step3 == 1;
		return;
  }
  switch(random(10)){
      case 0:
         force_me("emote darts to the side and tries to hide within the shadows.");
         break;
      case 1:
         force_me("say Go away now!");
         break;
      case 2:
         force_me("say If you no baddie, mebbe you help me?");
         break;
      case 3:
         force_me("emote tries to sharpen her daggers against a rock.");
         break;
      case 4:
         force_me("emote trembles and mutters tearfully to herself.");
         break;
      case 5:
         force_me("emote looks around the cavern, searching for more places to hide.");
         break;
      default:
         force_me("say Wonder when master find me...");
   }
   return;
}
int kill_ob(object victim, int which){
//Note:  If someone is on the list that shouldn't be (i.e. name was used by
//another player that is gone), you can use the following eval to clear it
//eval return SAVE_D->remove_name_from_array("NBelfquest_killers2", "stringname")
    int hold;
    killers = SAVE_D->query_array("PipeQuest_killers3");
    hold = ::kill_ob(victim, which);
    if(member_array((string)victim->query_name(), killers) != -1) return hold;
    SAVE_D->set_value("PipeQuest_killers3", (string)victim->query_name());
    command("say %^BOLD%^%^RED%^I no forget dis, baddie!");
    return hold;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
