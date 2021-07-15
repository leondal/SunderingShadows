//Piaf Huffelmuffin the homeless gnome -Cythera
#include <std.h>
#include <daemons.h>
#include <move.h>
#include "../farm.h";

inherit MONSTER;
int step1;
int step2;

void create(){
   	::create();
   	set_name("piaf");
   	set_short("Piaf Huffelmuffin, A white haired gnome");
   	set_id(({"piaf huffelmuffin","piaf","gnome","farm_mon"}));
   	set_long("%^CYAN%^This poor gnome looks like he's not had a "+
		"good nights sleep in some time.  His %^BOLD%^%^WHITE%^"+
		"white hair%^RESET%^%^CYAN%^ sticks up wildly about him."+
		"  His %^BOLD%^%^WHITE%^white beard%^RESET%^%^CYAN%^"+
		" looks shaggy and unkempt, a rarity for a gnome.  The"+
		" older gnome's pale skin is creased and wrinkled, hinting"+
		" at how old he might be.  A pair of glasses rest on his "+
		"bulbous nose, showing off his pale blue eyes.  His robes "+
		"are heavily wrinkled, looking as if he's not had a fresh "+
		"change of clothing in a few days.  A pair of striped socks"+
		" covers his feet, showing his lack of shoes.");
   	set_race("gnome");
   	set_gender("male");
   	set_hd(12,4);
   	set_max_hp(120+random(50));
   	set_hp(query_max_hp());
   	set_overall_ac(0);
   	set_alignment(8);
   	set_class("wizard");
	set_class("cleric");
   	set_mlevel("wizard",12);
	set_mlevel("cleric",12);
   	set_level(12);
   	set_stats("intelligence",19);
   	set_stats("wisdom",17);
   	set_stats("charisma",11);
   	set_stats("strength",15);
   	set_stats("constitution",15);
   	set_stats("dexterity",18);
	add_search_path("/cmds/wizard");
	add_search_path("/cmds/priest");
	set("aggressive",0);
	new("/d/common/obj/armour/srobe")->move(TO);
	force_me("wearall");
   	set_exp(1000);
     	add_money("gold",random(10));
	add_money("silver",random(7));
	add_money("copper",random(2));
   	force_me("speech say in a nervous squeak");
  
}

void init(){
   ::init();
   add_action("ask_em","ask");
}


void catch_say(string msg)
{
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(interactive(TP)) 
    {
        call_out("reply_func",1,msg,TP);
        return;
    }
    return;
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote fidgets as he speaks to "+who->QCN+".");
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
            force_me("emote peeks out from inside a cart.");
      force_me("say Hello?");
      force_me("say OH! HELLO!");
      force_me("say Please come closer.");
	force_me("emote waves you closer to the cart.");
	force_me("say My name is Piaf Huffelmuffin, Member of the"+
		" Gnomish Experimenters' League. Can you please help me?");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 ||
      strsrch(msg,"kay") != -1 || strsrch(msg,"yea") != -1 || 
      strsrch(msg,"Help") != -1 || strsrch(msg,"help") != -1) && step1 && !step2){
      force_me("say Oh goody!");
	force_me("emote claps his hands together.");
      force_me("say Hildegard and her boys have taken over my house.");
      force_me("say I've been out here for THREE days without a book!");
	force_me("emote sighs as he looks frustrated.");
	force_me("say Can you please go ask her to leave?");
      step2 = 1;
      return;
   }   
   if((strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 || 
   strsrch(msg,"No") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"no") !=-1) && step2 == 1) {
      force_me("say Good.");
      force_me("emote hops out of the cart and smiles to you.");
      force_me("say She is one angry halfling..");
      force_me("say But I am sure she will listen to you when you ask her to leave.");
      force_me("emote eyes twinkle as he smiles to "+who->QCN+".");
      force_me("say If you could %^YELLOW%^bring%^RESET%^ back her pipe as"+
		" proof that she will leave I can reward you.");
      force_me("emote waves to you as he hops back into the cart.");
	force_me("say Good luck!  Please dont harm any of my books!");
	step1 = 0;
      step2 = 0;
      return;
  }
	if(strsrch(msg,"ildegard") != -1) {
      force_me("emote pauses for a moment and squints, wrinkling her nose.");
      force_me("say Hildegard is a mean cranky old halfling!");
      force_me("emote frowns as he looks at his home.");
      force_me("say She's taken over my house!  She "+
		"says that this is the least I owe her.");
      force_me("say She blames me for the loss of her arm when she"+
		" tried to rob the Tabor Bank with her bandits.");
      force_me("emote shakes his head as he waves his hands.");
      force_me("say I told her when she bought the crossbow that I'd not"+


                " had time to test it yet.  I think I used too much fire beetle"+
                " fluid.. Next time I will use less.");
	force_me("say She lost her arm due to the crossbow backfiring on her."+
		"  And she blames me for it!");
	force_me("say Please help me return to my home.");
	force_me("emote sniffles as he stares up at you with his wide sad blue eyes.");
      return;
  }
}

void receive_given_item(object obj){
   object reward;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "hildegard's pipe") {
      obj->remove();
      force_me("say Oh yes!  This is her pipe!");
      force_me("emote hops out of the cart and performs a comical dance.");
      force_me("say Now I can finally go back home!");
      force_me("emote smiles to you.");
      force_me("say I don't have much on me or in my house as I am sure"+
		" you can tell. Here though I want you to take this.");
      if(!userp(TP))  return;
      if(member_array("Piaf Huffelmuffin's Dilemma",TP->query_mini_quests()) == -1) {
         tell_object(TP,"%^CYAN%^You helped solve Piaf Huffelmuffin's Dilemma!%^RESET%^");
         TP->set_mini_quest("Piaf Huffelmuffin's Dilemma",150000,"%^CYAN%^Piaf Huffelmuffin's Dilemma%^RESET%^");
      }
      tell_object(TP,"Piaf races into his house and back out to give something to you.");
      reward = new(OBJ"clockwork2");
      if((int)(reward->move(TP))!=MOVE_OK){
         force_me("say Oh, you seem to have your hands full! I'll just drop this here.");
         force_me("emote places a strange object on the ground.");
         reward->move(ETP);
         return 1;
      }else{
         force_me("say Here you go! I hope you like it!");
         tell_room(ETO,"Piaf gives a strange object to "+TPQCN+"",TP);
         tell_object(TP,"Piaf hands you a strange object.");
         return 1;
      }
//Above added by ~Circe~ in response to bug reports that he sometimes didn't give a reward 5/10/11

//	force_me("give clockwork to "+TPQN+"");
      return;
   }
   force_me("say This doesn't look like Hildegard's pipe.");
   force_me("emote tosses the item into the cart.");
   obj->remove();
   return;
}
