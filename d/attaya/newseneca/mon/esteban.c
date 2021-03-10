//esteban.c - by ~Circe~ for new Seneca 11/24/07
//Adjustment code taken from Mina in Antioch - by Crystal
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("Esteban Vega");
   set_id(({"Esteban","esteban","clothier","shopkeeper","tailor","guardsman","retired guardsman","vega","esteban vega","Esteban Vega"}));
   set_short("Esteban Vega, a retired guardsman");
   set_long("Esteban is an aging man who has retired from the "+
      "%^BOLD%^Seneca Guard %^RESET%^%^CYAN%^and now makes "+
      "clothing for his fellow guardsmen.  He originally learned "+
      "to sew by making small repairs on his uniforms before "+
      "he apprenticed with Akanar to learn more.  He still "+
      "maintains his short military haircut, with only a little "+
      "of his %^RESET%^white hair %^CYAN%^showing.  He is "+
      "clean-shaven with a lined face, and his eyes are a "+
      "deep %^ORANGE%^chestnut brown%^CYAN%^.  He has proven as "+
      "adept at tailoring as he was at performing his duties "+
      "in the guard - and he was quite the guardsman.  Esteban "+
      "has also been known to alter the clothing he creates for "+
      "a fee.  Simply %^BOLD%^<%^RESET%^%^CYAN%^give%^BOLD%^> "+
      "%^RESET%^%^CYAN%^him the item you wish for him to %^BOLD%^"+
      "alter%^RESET%^%^CYAN%^.\n\n"+
      "%^RESET%^%^CYAN%^<%^RESET%^help shop%^CYAN%^> %^RESET%^"+
      "will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_level(30);
   set_hd(30,20);
   set_hp(200+roll_dice(30,20));
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_stats("strength",19);
   set_stats("dexterity",17);
   set_overall_ac(-21); 
   set_max_hp(query_hp());
   set_nwp("tailoring",20);
   set_storage_room(STORAGE"esteban_storage.c");
   force_me("speech say in a gruff voice");
   set_items_allowed("clothing");
}

void catch_say(string message){
	object ob;

	if((mixed *)TO->query_attackers() != ({ })) {
		force_me("say I'm being attacked, please help!");
		return 1;
	}
   if(strsrch(message,"fit") != -1 || strsrch(message,"size") != -1 || (strsrch(message,"tailor") != -1 && strsrch(message,"tailoring") == -1)|| strsrch(message,"alter") != -1) {
      if(TP->query_invis()) {
         force_me("say Well I need to see you if you want me to get the"+
         " measurements right.");
         return 1;
      }
      else {
         force_me("say You can give me items that you wish to have"+
         " refitted to your size. I charge 10 gold for alterations to"+
         " make the item smaller, and 15 gold to enlarge the item.");
         return 1;
      }
    } else 
     ::catch_say(message);
}

void receive_given_item(object ob){
   if(!objectp(ob)) return;
   if(TP->query_invis()){
      force_me("say Well I need to see you if you want me to get the"+
      " measurements right.");
      force_me("give "+ob->query_name()+" to "+TPQN+"");
      return 1;
   }
   if((string)ob->query_type() != "clothing") {
      force_me("say I'm a tailor, I only work with clothing, and I"+
      " only alter my own work.");
      force_me("give "+ob->query_name()+" to "+TPQN+"");
      return 1;
   }
   if(!ob->id("esteban_clothing")) {
      force_me("say Sorry, I only alter my own work.");
      force_me("give "+ob->query_name()+" to "+TPQN+"");
      return 1;
   }
   if((int)TP->query_size() == 1) {
      if((int)ob->query_size() == 1) {
         force_me("say Clearly this will already fit you, I don't know"+
         " what you need my services for.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      if((int)ob->query_size() != 2) {
         force_me("say If you alter garments too many times they're no"+
         " good. I'm sure you'll find something else you'll like in my"+
         " shop, I'm always making different things.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      if(!TP->query_funds("gold",10)) {
         force_me("say The cost to alter this is 10 gold.  You don't "+
            "seem to have enough money.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      else {
         TP->use_funds("gold",10);
         force_me("emote alters the "+ob->query_name()+" to fit"+
         " "+TPQCN+".");
         ob->set_size(1);
         force_me("say There you go!");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
   }
   if((int)TP->query_size() == 3) {
      if((int)ob->query_size() == 3) {
         force_me("say Clearly this will already fit you, I don't know"+
         " what you need my services for.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      if((int)ob->query_size() != 2) {
         force_me("say If you alter garments too many times they're no"+
         " good. I'm sure you'll find something else you'll like in my"+
         " shop, I'm always making different things.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      if(!TP->query_funds("gold",15)) {
         force_me("say The cost to alter this is 15 gold.  You don't "+
            "seem to have enough money.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      else {
         TP->use_funds("gold",15);
         force_me("emote alters the "+ob->query_name()+" to fit"+
         " "+TPQCN+".");
         ob->set_size(3);
         force_me("say There you go!");
         force_me("smile "+TPQN+"");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
   }
   if((int)TP->query_size() == 2) {
      if((int)ob->query_size() == 2) {
         force_me("say Clearly this will already fit you, I don't know"+
         " what you need my services for.");
         force_me("give "+ob->query_name()+" to "+TPQN+"");
         return 1;
      }
      force_me("say If you alter garments too many times they're no"+
      " good. I'm sure you'll find something else you'll like in my"+
      " shop, I'm always making different things.");
      force_me("give "+ob->query_name()+" to "+TPQN+"");
      return 1;
   }
}
