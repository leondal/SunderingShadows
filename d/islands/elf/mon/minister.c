#include <std.h>
#include "../elf.h"

inherit NPC;

void create(){
    ::create();

    set_id(({"findecano", "minister", "elven minster"
	,"findecano vardamir","Findecano Vardamir","Findecano"}));
    set_name("Findecano Vardamir");
    set_short("Findecano Vardamir, Elven Minister");
    set_long("Findecano is a finely dressed gold elf who "+
	"is likely much older than he looks.  He has neatly "+
	"cropped blonde hair and matching golden eyes.  "+
	"Findecano is responsible for allocating resources "+
	"for the keep and other logistics.  He spends most "+
	"of his time at a desk listening to comments and "+
	"issuing equipment as needed.");
    set_race("elf");
    set_gender("male");
    set_size(2);
    set_hd(10+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-5);

    set_alignment(1);
    set_class("fighter");
    set_stats("charisma",12);
	force_me("speak elven");
    set_new_exp(30,"very low");
    set_max_level(35);
	 set_base_damage_type("bludgeoning");
}
void init() {
   ::init();
   call_out("reply_func",5,TP);
}

void receive_given_item(object obj){
   string name, item;


   if(!objectp(TP)) return;
   if(!ETO) return;
   name = TPQN;
   if(!objectp(obj)) return;
  
   if((string)obj->query_short() != "head of Tonovi Guard"){
       force_me("say Ummm thanks, but I don't want this.");
	  force_me("give "+obj->query_name()+" to "+name+"");
      return;
	  }

   
   force_me("say I didn't think you had it in you..."+
   "  but I'm true to my word.  Here is you spear.");
  
   force_me("emote goes to a rack and pulls a spear out.");
   TP->set_mini_quest("guard killer",6200000,"delivered a tonovi guard's head to the elves.");
   
   new(OBJ"tspear")->move(TO);
   force_me("give spear to "+name);
   force_me("say Take this, I hope it finds the heart of many more elven enemies.");
   tell_object(TP,"You have finished the quest, %^CYAN%^'Guard Killer'!\n");
     
    obj->remove();
   return;
}
void reply_func(object who){
   if(!interactive(who)) return;
   if(who->query_true_invis()) return;
   if(who->query_magic_hidden()) return;
   set_spoken("elven");

    force_me("emote turns from his work to look at you.");
    force_me("say Hello, you look like someone that"+
	" can get things done.   I like that.  There is "+
	"a town called Tonovi far from here.  I think they"+
	" all deserve to die.  Bring me the head of one of"+
	" their guards and I'll find a spare spear from the armory.");
	force_me("emote finishes and nods crisply.");
     return;
}