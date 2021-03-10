#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

// Aquatic Quest - Offestry Valley - Created in March 2009 by Ari
// For inclusion into the Offestry Valley Upgrade by Nienne

object ob;
int step1;
int step2;
int step3;
string *asked;

void create(){
  ::create();
  set_name("acorn");
  set_id(({"acorn","atomie","sprite","Acorn"}));
  set_short("Acorn the Atomie");
  set_long("%^RESET%^%^GREEN%^Only about a foot tall, this little "+
"atomie is dressed in a gown of %^ORANGE%^oak leaves %^GREEN%^and "+
"%^BOLD%^moss%^RESET%^%^GREEN%^.  Long %^CYAN%^i%^WHITE%^r%^GREEN%^"+
"i%^CYAN%^de%^BLUE%^s%^WHITE%^c%^GREEN%^e%^CYAN%^nt %^GREEN%^"+
"colored dragonfly wings extend from her back and flutter with "+
"every breath, never holding still long enough to give you a "+
"good look at them.  Her heart shaped face is framed by %^ORANGE%^"+
"a%^WHITE%^s%^BOLD%^%^BLACK%^h%^RESET%^%^ORANGE%^y b%^WHITE%^l"+
"%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^nde %^GREEN%^curls that "+
"are held back by a strand of silky %^WHITE%^spider web"+
"%^GREEN%^.  She'd be very pretty except that her %^CYAN%^tears "+
"%^GREEN%^have made her face splotchy and her light gray eyes "+
"%^BOLD%^%^BLACK%^storm %^RESET%^%^GREEN%^colored.  She looks "+
"like she could use some %^YELLOW%^help%^RESET%^%^GREEN%^.%^RESET%^");

  set_gender("female");
  set_race("sprite");
  set_body_type("human");
  set_hd(10,3);
  set_max_level(10);
  set_size(1);
  set_alignment(7);
  set_overall_ac(5);
  set_max_hp(random(10)+60);
  set_hp(query_max_hp());
  set_exp(100);
  set_level(10);
  set_class("mage");
  set_mlevel("mage",10);
  set_guild_level("mage",10);
  set_stats("strength", 8);
  set_stats("dexterity", 20);

  set_stats("constitution", 12);
  set_stats("intelligence", 18);
  set_stats("wisdom", 12);
  set_stats("charisma", 18);
  
  new("/d/newbie/rooms/lake/spriterobe.c")->move(TO);
    command("wear robe");

  set_spell_chance(90);
  set_spells(({"magic missile","burning hands","sleep",
"color spray"}));

  set_emotes(1,({
    "%^RESET%^%^MAGENTA%^Acorn sighs and rubs her nose%^RESET%^: "+
"Such a mean old toad!",
    "%^RESET%^%^MAGENTA%^Acorn sniffs and looks up at you.%^RESET%^"+
": Will you help me?",

    "%^RESET%^%^MAGENTA%^Acorn sobs quietly as she looks down "+
"into the water.%^RESET%^",
    "%^RESET%^%^MAGENTA%^Acorn cries%^RESET%^: Mom's going to be "+
"so mad I lost her crown!",
  }), 0);
}

void reset(){
	::reset();
		step1 = 0;
		step2 = 0;
		step3 = 0;
}

void catch_say(string msg){
	call_out("give_quest",1,msg,TP);
	call_out("repeat_this",1,msg,TP);
}

void give_quest(string msg, object who){
  string name;
  name=who->query_name();
  asked=SAVE_D->query_array("acorn_quest_asked");
    if(!msg || !objectp(who)) return;
	if(who->query_quests()){
	  if(member_array("%^YELLOW%^Recovered the Golden Crown%^RESET%^",
	    who->query_quests()) !=-1){
		force_me("say Oh! It's you.  Thank you again for "+
		"all your help!");
		tell_room(ETO,"Acorn smiles.",who);
		return 1;
		}
    }
	

	if(strsrch(msg,"repeat") !=-1 || strsrch(msg,"Repeat")
	  !=-1 && member_array(name,asked) !=-1){
	    force_me("emote looks up and sniffs.\n");
		force_me("say It's terrible!  Just terrible! That mean old "+
		  "toad took my mother's crown, and now he won't give it "+
		  "back. \n");
		force_me("say He took it to the bottom of the lake!\n");
		force_me("say Please help me get the crown back!\n");
	return;
	}
	
	if(member_array(name,asked) !=-1){
	  if(!random(3)){
	    tell_object(ETO,"Acorn looks down into the lake's water.");
		force_me("say Have you found my mother's crown yet?");
		force_me("say I don't know what else I could tell you, but "+
		"I'll %^YELLOW%^repeat %^RESET%^what I know.");

		}
	return;
	}
	
	if((strsrch(msg,"help") !=-1 || strsrch(msg,"Help") !=-1 ||
	  strsrch(msg,"crown") !=-1) && !step1){
	  tell_room(ETO,"Acorn looks up with tear-filled eyes.");
	  force_me("say Oh! Thank Mielikki!  Someone who could "+
	  "help me!");
	  tell_object(TP,"Acorn reaches out to you imploringly.");
	  tell_room(ETO,"Acorn reaches out toward "+who->QCN+".",TP);
	  force_me("say My name is Acorn, and I have a terrible "+
	  "%^YELLOW%^problem%^RESET%^!");
	  step1=1;
	  return 1;
	}

	
	if((strsrch(msg,"problem") !=-1 || strsrch(msg,"Problem") !=-1)
	  && step1 && !step2){
	  force_me("say Yes!  It's a terrible problem.  It really "+
	  "is!");
	  force_me("say My mother is Lilly, Queen of the Atomies "+
	  "who live here in this forest.");
	  force_me("say She has a crown and everything!");
	  tell_room(ETO,"Acorn suddenly looks very worried.");
	  force_me("say And that's the problem.  Her crown has been "+
	  "%^YELLOW%^stolen%^RESET%^!");
	  step2=1;
	  return 1;
	}
	
	if((strsrch(msg,"stolen") !=-1 || strsrch(msg,"Stolen")
	!=-1) && step1 && step2 && !step3){

      tell_room(ETO,"Acorn nods her head.");
      force_me("say Yes! Stolen.  But only because I was bad and "+
	  "and took it outside.");
	  force_me("say I only wanted to see what it looked like in "+
	  "my reflection in the water.");
	  tell_room(ETO,"Acorn sighs and rubs at her eyes a moment.");
	  force_me("say I didn't know that evil toad would be waiting "+
	  "to steal it away!");
	  force_me("say When I was looking in the water, he used his "+
	  "tongue to snatch it away and then swam to the bottom of "+
	  "the lake.");
	  force_me("say I don't know how to swim and he wont come back!");
	  tell_room(ETO,"Acorn looks up, her lower lip quivering.");
	  force_me("say Can you swim down there and make him give it "+
	  "back?  Please?");
	  step3=1;
	  return 1;

	}
	
	if((strsrch(msg,"yes") !=-1 || strsrch(msg,"Yes") !=-1)
	&& step3){
	  if(member_array(name,asked)==-1){
	  SAVE_D->set_value("acorn_quest_asked",name);
	  }
	  tell_room(ETO,"Acorn claps her hands together.");
	  force_me("say Oh! Thank you! Thank you!  I knew I could "+
	  "count on you!");
	  tell_room(ETO,"Acorn reaches over and plucks a couple "+
	  "reeds from the water's edge.");
	  new("/d/newbie/rooms/lake/spritereed.c")->move(TO);
	  force_me("give reed to "+TPQN+"");
	  force_me("say Here, take these.  They're magical and will "+
	  "help you breathe underwater.  They wont last very long "+
	  "but they should help you.");

	  force_me("say Please hurry.  Before mother finds out!");
	  return 1;
	}
}

void receive_given_item(object obj){
  string name;
  name=TPQN;
  asked=SAVE_D->query_array("acorn_quest_asked");
  
  if(!objectp(obj)) return;
  
  if(member_array("Recovered the Golden Crown",TP->query_quests())
  !=-1){
    force_me("say Oh, thank you.  That mean toad must have taken "+
	"this crown from someone else.  He's so mean!");
	force_me("say I'll find who this belongs to and return it to "+
	"them.");
	force_me("say Thank you for all your help!");
	obj->remove();
	return;
  }
  
  if(member_array(TPQN,asked)==-1){
    force_me("say Thanks again.");
	return;
  }
  
  if(member_array("crownriin",(string)obj->query_id()) !=-1){
    tell_room(ETO,"Acorn looks over the crown excitedly!");
	force_me("say Yes! This is my mother's crown.  Oh thank you! "+
	"Thank you, thank you, thank you!  I don't know what I "+
	"would have done if you hadn't gotten it back.");
	force_me("say I'm going to take this back right now.");
	tell_room(ETO,"Acorn hops up.");

	force_me("say Oh! Before I forget.  Here is a reward for "+
	"all your help.");
	force_me("say As long as you're anywhere in the valley, "+
	"all you have to do is think of home and it will take you "+
	"there.");
	force_me("say Thank you again!  Good bye!");
	tell_room(ETO,"Acorn's little wings flash quickly as she "+
	"flies off to return the crown to her mother.");
	  if(member_array(TPQN,asked) !=-1){
	    SAVE_D->remove_name_from_array("acorn_quest_asked",TPQN);
	  }
	  if(member_array(("Recovered the Golden Crown"),
	  TP->query_quests())==-1){
	    TP->fix_exp(1000,TP);
		TP->set_quest("%^YELLOW%^Recovered the Golden Crown%^RESET%^");
	    add_money("gold",200);
		new("/d/newbie/rooms/lake/acorn")->move(TO);
		force_me("give "+query_money("gold")+" gold coins to "+
		TPQN+"");

		force_me("give acorn to "+TPQN+"");
		tell_object(TP,"You Recovered the %^YELLOW%^Golden "+
		"Crown%^RESET%^!");
	  }
	obj->remove();
	call_out("go_away",0);
	return 1;
	}
return 1;
}

void go_away(){
    TO->move("/d/shadowgate/void");
	TO->remove();
}

