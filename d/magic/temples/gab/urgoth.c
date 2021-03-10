#include <std.h>
#include <daemons.h>

#include "../loviatar.h"

inherit MONSTER;

int FLAG,FLAG1,num,timer,timer1;
object ob;

void do_check();
void faith_ck(object targ);

void create(){
::create();
	set_name("Urgoth");
	set_short("Urgoth, Head Inquisitor");
	set_id(({"monster","Urgoth","head inquisitor","urgoth",
		"inquisitor","torturer","half-ogre"}));
	set_long(
		"%^MAGENTA%^"+
		"The huge beast is a half-ogre.  His name is Urgoth "+
		"and his job is to cause pain.  Muscles ripple beneath "+
		"his sweat-stained leather vest.  His face is a mass of "+
		"scars and there is only a weeping empty socket where "+
		"his left eye used to reside.  The parts of his flesh "+
		"you can see are criss-crossed with scars.  It seems "+
		"even the master is not passed over for torture."
	);
	set_gender("male");
	set_race("half-ogre");
	set_hd(27,10);
	set_class("ranger");
	set_mlevel("ranger",30);
	set_level(30);
	set_alignment(3);
	set_body_type("human");
	set_size(2);
	set_overall_ac(5);
   set_exp(30000);
	set_stats("strength",20);
   set_stats("dexterity",13);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("constitution",19);
   set_stats("charisma",6);
	set_max_hp(200+random(200));
	set_hp(query_max_hp());
   set_emotes(1,({
		"Urgoth checks the equipment thoroughly.",
		"Urgoth spits on a dirty cleaning rag and then uses it to "+
			"clean the apparatus.",
		"%^CYAN%^Urgoth grunts: %^RESET%^who next, I gots a chair open "+
			"fer ya.\nUrgoth points to the spiked chair.\nUrgoth "+
			"chuckles to himself.",
		"Urgoth blows his nose loud and wet into the disgusting "+
			"cleaning rag he carries.",
		"Urgoth busies himself about the room.",
		"Urgoth slams a hot poker against the wall to startle the victim.",
		"Urgoth picks at his teeth with a sharp shard of bone.",
		"Urgoth leans in close to a victim and breathes his foul breath "+
			"into their face.",
		"Urgoth cracks his whip and cackles malefically.",
		"Urgoth looms over the victim and checks the chains."
    	}),0);
	num = random(100);
		ob = new(CWEAP+"whip");
    		if(num)ob->set_property("monsterweapon", 1);
       	ob->set_property("enchantment",5);
    		ob->move(TO);
    		command("wield whip");
	num = random(100);
		ob = new(CWEAP+"mclub");
    		if(num)ob->set_property("monsterweapon", 1);
       	ob->set_property("enchantment",5);
    		ob->move(TO);
    		command("wield club");
	num = random(100);
    	ob = new("/d/laerad/obj/bracers6.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->move(TO);
    		command("wear bracers");
	num = random(100);
    	ob = new("/d/deku/armours/ring_p.c");
    		if(num)ob->set_property("monsterweapon", 1);
    		ob->set_property("enchantment",3);
    		ob->move(TO);
    		command("wear ring");
	num = random(100);
    	ob = new("/d/islands/tonerra/obj/hide.c");
    		if(num)ob->set_property("monsterweapon", 1);
  			ob->set_short("%^BOLD%^%^BLACK%^torturer's vest%^RESET%^");
  			ob->set_obvious_short("a sweaty leather vest");
  			ob->set_id(({"vest","leather vest","torturer's vest"}));
  			ob->set_long("This vest covers and protects the "+
  				"wearer.  The leather is stained with sweat and "+
  				"the aroma of the previous wearer is very difficult "+
  				"to withstand.");
    		ob->move(TO);
    		command("wear vest");
	ob = new("/d/common/obj/potion/healing");
    		ob->move(TO);
    		ob->set_uses(50);
  	add_search_path("/cmds/ranger");
  	add_search_path("/cmds/fighter");
	command("speech grunt");
	command("speak wizish");
	set_property("knock unconscious",1);
	set_property("full attacks",1);
   set_property("no bows",1);
  	set_func_chance(25);
	set_funcs(({"thump"}));
   add_money("gold",random(50));
   add_money("silver",random(100));
   add_money("copper",random(600));
	FLAG1 = 0;
	FLAG = 0;
}
void init(){
 	::init();
 	add_action("free_em","free");
  	if(avatarp(TP) || !interactive(TP)) return;
	call_out("do_check",2);
}
void killem(object targ){
	command("say %^BOLD%^%^RED%^Urgoth warned ya he did.%^RESET%^");
	force_me("kill "+targ->query_name());
}
void thump(object targ){
 	if((int)targ->query_stats("dexterity")>random(25)){
   	tell_object(targ,"%^BOLD%^%^WHITE%^Urgoth swings his knobby "+
      	"club at your head and you duck in the nick of time!%^RESET%^");
      tell_room(ETO,""+targ->query_cap_name()+" dodges Urgoth's club.",targ);
  	}else{
   	tell_object(targ,"%^BOLD%^%^RED%^Urgoth swings his knobby club at "+
      	"your head and catches you with a stunning blow!%^RESET%^");
      tell_room(ETO,""+targ->query_cap_name()+" takes Urgoth's club "+
      	"upside "+targ->query_possessive()+" head and is stunned from the blow!",targ);
      targ->set_paralyzed((random(25)+5),"%^BOLD%^%^YELLOW%^You're still seeing stars!");
  	}
}
void iseeu(object targ){
   if((string)targ->query_diety() == "loviatar")return;
	force_me("say Hide will ya?  I kin smell ya!");
	force_me("say Get ya out o' Urgoth make you his bitch!");
	force_me("emote uncoils his whip slowly and smiles.");
	call_out("killem",5,targ);
	return;
}
int free_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^%^CYAN%^Free who?");
      return 1;
   }
  	if(!interactive(TP)){
  		tell_room(ETO,"%^BOLD%^"+TPQCN+" looks at Urgoth, looks "+
  			"at you, and then looks at the victim then backs away "+
  			"from Urgoth.  Looks like this is one job you'll have "+
  			"to do for yourself.\n");
  		return 1;
  	}
  	if(str == "victim"){
      if(!present("victim")){
      	tell_object(TP,"What victim?");
      	return 1;
      }
   	tell_object(TP,"%^BOLD%^You start to work at the chains "+
   		"restraining the victim.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" starts working on the "+
      	"chains that are restraining the victim.\n%^RESET%^",TP);
      switch(FLAG){
      	case (0):
      		command("say %^RED%^leave it be Urgoth sez!");
      		tell_object(TP,"The chain loosens a bit, maybe you need to try again.");
      		FLAG = 1;
      		break;
      	case (1):
      		command("say %^RED%^Wot Urgoth sed, not tellin' you no more!%^RESET%^");
      		tell_object(TP,"Urgoth moves towards you and you can "+
      			"feel the chain loosen a bit more.");
      		tell_room(ETP,"The victim cringes at the sound of Urgoth's bellow.");
      		FLAG = 2;
      		break;
      	case (2):
      		command("say %^BOLD%^%^RED%^DAT'S IT, NOW URGOTH MAD!!%^RESET%^");
      		tell_object(TP,"You have almost freed the victim.");
				call_out("killem",0,TP);
				FLAG = 3;
      		break;
      	case (3):
      		tell_object(TP,"%^BOLD%^Urgoth will not allow near the victim!%^RESET%^");
      		break;
      }
	}
	return 1;
}
void faith_ck(object targ){
	string pgod = targ->query_diety();

  	if(avatarp(targ) || !interactive(targ)) return;
 
  	if(pgod == "loviatar"){
  		if(targ->query_invis())return;
  		if(FLAG1 == 0){
  			command("say %^BOLD%^%^RED%^Loviatar%^RESET%^, her whip "+
  				"be's mighty, lash bring much anguish!");
  			if(targ->is_class("cleric")){
  				command("protect "+targ->query_name()+"");
  				command("protect "+targ->query_name()+"");
  				command("whisper "+targ->query_name()+" Urgoth watch yer back, have fun eh?");
  				command("protect "+targ->query_name()+"");
  				command("protect "+targ->query_name()+"");
 			}
  			FLAG1 = 1;
  		}
  		return;
  	}
	if(targ->query_invis()){
		call_out("iseeu",0,targ);
		return;
	}
}
int do_check(){
   int i;
   object *people, *list, person;
   people = ({});
   list = ({});

   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(TO->query_current_attacker()) return 1;

   people = all_living(environment(this_object()));

   for(i=0;i<sizeof(people);i++){
		if(!((people[i] == TO) || (avatarp(people[i]))))list += ({people[i]});
   }
	if(!list || !sizeof(list)) return 2;

	person = list[random(sizeof(list))];

	if(!present(person, ETO)) return 1;

	if(person->query_unconscious())return 1;
	if(person->query_bound())return 1;
	
	faith_ck(person);
	
	return 1;
}
void heart_beat() {
  	::heart_beat();
	if (!objectp(TO)) return;
	if (!objectp(ETO)) return;
  	if(present("kit",TO) && query_hp() < ((query_max_hp()/3)*2)){
		command("open kit");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
		command("quaff kit");
		command("offer bottle");
 	}
   if(present("bottle",TO)) command("offer bottle");
   timer1++;
   if(timer1 > 30){
   	timer1 = 0;
		if(query_attackers() != ({})){
   		do_check();
   	}
   	return;
   }
   if (FLAG1 == 0 && FLAG == 0)return;
   timer++;
   if(timer > 60){
   	timer = 0;
		if(query_attackers() != ({})){
			FLAG = 0;
			FLAG1 = 0;
		}
    	return;
  	}
}