// sea elf wants fish
// and other stuff -H 11/1/20
#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit "/std/monster";

create() {
  ::create();
  set_name("sea elf");
  set_id(({"elf","monster","sea elf","fisher"}));
  set_gender("female");
  set_race("elf");
  set_short("Sea Elf Fisher");
  set_long("This elf is dressed in some large "+
  "fish hides to fight the cold.  She has an "+
  "assortment of culinary items equipped ready to prepare seafood for dinner.");
  set_body_type("human");
  set_alignment(6);
  set_hd(6,8);
  set_stats("strength",8);
  set("aggressive",0);
  set_stats("intelligence", 16);
  set_stats("wisdom", 6);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_property("swarm",0);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(12);
  set_hp(random(50)+10);
  set_max_level(3);
  set_emotes(2,({
   "Sea Elf prepares crab parts for cooking.",
   "Sea Elf repairs some crab pods.",
   "Sea Elf sharpens a small knife.",
   "Sea Elf puts some crab parts in a box.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ I want lots of lobster.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ Crabs eat dead things  I bet there are lots of dead things under the ice.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ The heart of water was moved and weird things started happening in the sea.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ If you get me a lobster or a crab I will pay you for it.",
   "Sea Elf throws some firewood on the fire.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ Imagine going to dinner and getting served a six foot lobster!",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ I wonder if edea coming here came at a price.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ Got a bad feeling about the waters now... They seem wrong.",
   "%^MAGENTA%^Sea Elf says:%^RESET%^ The gold elves seem really worried about the ruins below.",
   }),0);
}
void receive_given_item(object obj){
   string name, item, id1;
   string *ids;
   object *ppl;
   int i;
   if(!objectp(TP)) return;
   if(!ETO) return;
   name = TPQN;
   if(!objectp(obj)) return;
   item = obj->query_name();
   ids = obj->query_id();
   id1 =ids[0]; 
   if(  (string)obj->query_name() != "Dire Crab"
     && (string)obj->query_name() != "Dire Lobster"
     && (string)obj->query_name() != "betrayer's edge"
     && (string)obj->query_name() != "shell shield"
     && (string)obj->query_name() != "Stingray spear") {
      force_me("say Ummm thanks, but this won't help.  I'll just set this on the ground for you.");
	   force_me("drop "+id1+"");
      return;
	  }

   switch (item){
     case "Dire Crab" :{
	     force_me("say Thank you for the Crab!");
   }
	 break;
	 
	 case "Dire Lobster":{

	     force_me("say Thank you for the Lobster.");
    }
    case "betrayer's edge":{
       new(OBJ"clance")->move(TO);
       force_me("give lance to "+name);
       force_me("say Thanks, the gold elves said to give you this for that.");
       obj->remove();
       return;
    }
   case "shell shield":{
       new(OBJ"sheep_hat")->move(TO);
       force_me("give hat to "+name);
       force_me("say Thanks, the gold elves said to give you one of these for that.");
       obj->remove();
       return;
    }
   case "Stingray spear":{
       new(OBJ"c_blade")->move(TO);
       force_me("give sword to "+name);
       force_me("say Thanks, take this huge thing.  It is big so it has to be good!");
       obj->remove();
       return;
    }
   case "seeweed belt":{
       new(OBJ"tail")->move(TO);
       force_me("give belt to "+name);
       force_me("say A belt?  Try this one it is better!");
       force_me("wink");
       obj->remove();
       return;
    }
   case "Gloves of the Vampire":{
       new(OBJ"staff")->move(TO);
       force_me("give staff to "+name);
       force_me("say Here try this staff I think it might do something interesting!");
       force_me("smirk");
       obj->remove();
       return;
    }
	 break;}
	 
   tell_room(ETO,"The Sea Elf puts the meat away and hands you some money.");
   
   force_me("say Thanks for helping.  Trying to get those "+
   "things caught in a trap is proving to be impossible but they look really tasty!");
  
   force_me("emote gets a sack of gold.");

   tell_object(TP,"Sea Elf gives you 1000 gold coins.");
   TP->add_money("gold",1000);
}
void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   set_spoken("wizish");
   if(!msg || !objectp(who)) return;

    force_me("say Hello Traveler, you look capable enough. "+
    " I'm trying to capture some of the lobsters and crabs "+
    "down in the water but they are really strong.  I'll pay 1000 gold for each dead one.");
   force_me("emote sighs and continues.");
   force_me("say Also, the gold elves said to trade any evil"+
   " items found down there for good ones they made so if you"+
   " have something give it to me and I'll see if there is something good to trade if for.");
     return;
}

