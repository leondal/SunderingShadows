//essyllis: Feb 2015
#include <std.h>
#include "../lgnoll.h"
inherit MONSTER;

void create (){
object obj;
::create ();
   set_name("khamvani");
   set_id(({"Wemic","wemic","Khamvani","khamvani"}));
   set_short("%^RESET%^%^ORANGE%^A tall wemic%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Standing %^RESET%^%^ORANGE%^tall %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^proud%^BOLD%^%^BLACK%^, "+
   "this wemic is almost frightening to behold. His upper torso is covered in "+
   "st%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^dd%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d l%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r "+
   "which seem to be made purely from %^RESET%^%^RED%^gnoll%^BOLD%^%^BLACK%^-%^RESET%^%^RED%^hide %^BOLD%^%^BLACK%^and gives "+
   "plenty of room for his %^RESET%^%^RED%^r%^ORANGE%^e%^RED%^d-%^ORANGE%^g%^RED%^o%^ORANGE%^ld%^RED%^e%^ORANGE%^n "+
   "m%^RED%^a%^ORANGE%^n%^RED%^e %^BOLD%^%^BLACK%^to flow down over his chest. His lower %^RESET%^%^ORANGE%^lion-torso "+
   "%^BOLD%^%^BLACK%^is covered by %^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ath%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rd%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ng "+
   "%^BOLD%^%^BLACK%^which seem to be made from the same %^RESET%^%^RED%^gnoll%^BOLD%^%^BLACK%^-%^RESET%^%^RED%^leather%^BOLD%^%^BLACK%^. "+
   "His %^ORANGE%^e%^BLACK%^y%^ORANGE%^es %^BLACK%^gleam with what looks like either %^RED%^ferociousness%^BLACK%^, "+
   "or %^MAGENTA%^madness%^BLACK%^.%^RESET%^\n");
   set_race("wemic");
   set_gender("male");
   set_body_type("wemic");
   set_attack_bonus(6);
   set_hd(14,10);
   set_overall_ac(-10);
   set_size(3);
   set_stats("intelligence",15);
   set_stats("strength",25);
   set_stats("wisdom",13);
   set_stats("dexterity",20);
   set_stats("constitution",18);
   set_stats("charisma",11);
   set_money("gold",random(2000));
   set_money("silver",random(1000));
   set_money("copper",random(500));
   set_money("electrum",random(1750));
   set_money("platinum",random(350));
   set_class("ranger");
   set_exp(5000);
   set_class("fighter");
   set_mlevel("fighter", 25);
   set_property("full attacks", 2);
   set_max_level(25);
   set_hp(random(200)+500);
   set_max_hp(query_hp());  
   set_alignment(6);
   //set("aggressive","aggfunc");
   set_mlevel("ranger",25);
   set_achats(10, ({"%^RED%^The %^ORANGE%^wemic %^RED%^glares at you m%^MAGENTA%^a%^RED%^dl%^MAGENTA%^y %^RED%^and %^MAGENTA%^f%^BOLD%^%^CYAN%^r%^RESET%^%^RED%^o%^BOLD%^%^CYAN%^t%^RESET%^%^MAGENTA%^h %^RED%^starts to form around his mouth%^BOLD%^%^BLACK%^.%^RESET%^",
        "%^GREEN%^The wemic swings his %^RED%^weapon %^GREEN%^around and %^YELLOW%^r%^RED%^o%^ORANGE%^a%^RED%^r%^ORANGE%^s f%^RED%^e%^ORANGE%^r%^RED%^o%^ORANGE%^c%^RED%^i%^ORANGE%^o%^RED%^u%^ORANGE%^sl%^RED%^y%^RESET%^%^GREEN%^!%^RESET%^"}) ); 
   set_emotes(1, ({"%^RESET%^%^GREEN%^The wemic shakes his head %^ORANGE%^viciously %^GREEN%^and %^RED%^growls %^GREEN%^at something unseen.%^RESET%^",
		"%^MAGENTA%^The wemic paces around in a %^BOLD%^%^BLACK%^circle %^RESET%^%^MAGENTA%^and %^RED%^hisses %^MAGENTA%^at any movement.%^RESET%^",
        "%^RED%^The wemic closes his %^YELLOW%^e%^BLACK%^y%^ORANGE%^es %^RESET%^%^RED%^and gives a sound that sounds like a p%^BOLD%^a%^RESET%^%^RED%^in%^BOLD%^e%^RESET%^%^RED%^d gr%^BOLD%^o%^RESET%^%^RED%^wl.%^RESET%^"}), 0);
     obj = new(OBJ"gnollbarding");
	 obj->move(TO);    
   new(OBJ"gnollhidepaws")->move(TO);
   force_me("wearall");
   new(OBJ"flamewhip")->move(TO);
   force_me("wield whip");
      set_monster_feats(({
      "impale",
	  "light weapon",
	  "improved two weapon fighting",
	  "strength of arm",
	  "sweepingblow",
	  "blade block",
	  "toughness",
	  "exotic weapon proficiency",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance",
	  "regeneration",
	  "powerattack",
	  "rush"
   }));
   set_funcs(({"sweeper"}));
   set_func_chance(20);
  }
void die(object ob) {
   tell_room(ETO,"%^ORANGE%^His front legs %^RED%^rakes %^ORANGE%^at you as a last effort, before he slumps to the ground .. %^BOLD%^e%^BLACK%^y%^ORANGE%^es %^RESET%^%^ORANGE%^turning %^BOLD%^%^BLACK%^peacefully dull%^RESET%^%^ORANGE%^.%^RESET%^");
:: die(ob);
}


//int aggfunc() {
   
//}
void catch_say(string msg){
   call_out("do_ineract",1,msg,TP);
}


void do_ineract(string msg, object ob){
	
	
if(strsrch(msg, "noll") != -1 || strsrch(msg,"nolls") != -1 || strsrch(msg,"elp") != -1|| strsrch(msg,"ello") != -1){	
	
switch(random(10)){
		case 0..4:
	tell_object(ob,"%^YELLOW%^Khamvani%^BOLD%^%^BLACK%^ bares his teeth in a angry sneer at you.");
	tell_room(ETO,"%^YELLOW%^Khamvani%^BOLD%^%^BLACK%^ bares his teeth in a angry sneer at "+ob->QCN,ob);
	force_me("say You do not look like a Gnoll?");
	 return;
	 break;
	case 5..9:
	tell_object(ob,"%^YELLOW%^Khamvani%^RESET%^%^MAGENTA%^ appears confused and looks at you");
	tell_room(ETO,"%^YELLOW%^Khamvani%^RESET%^%^MAGENTA%^ appears confused and looks at "+ob->QCN,ob);
	force_me("say Save yourself and your cubs! They are attacking again!");
	return;
	break;
	}
}
if(strsrch(msg, "ub") != -1 || strsrch(msg,"ubs") != -1){
	
	switch(random(10)){
		case 0..3:
	tell_room(ETO,"A wave of sadness washes over %^YELLOW%^Khamvani's%^RESET%^ face");
	force_me("say Leave me be. You will find nothing but death here!");
	call_out("shouldaleft",random(20)+20,ob);
	return;
	break;
	case 4..9:
	tell_object(ob,"%^YELLOW%^Khamvani%^RESET%^%^MAGENTA%^ looks at you with a shimmer of hope deep in his crazed %^BOLD%^%^BLACK%^e%^YELLOW%^y%^BLACK%^es");
	tell_room(ETO,"%^YELLOW%^Khamvani%^RESET%^%^MAGENTA%^ looks at "+ob->QCN+"%^RESET%^%^MAGENTA%^ with a shimmer of hope deep in his crazed %^BOLD%^%^BLACK%^e%^YELLOW%^y%^BLACK%^es",ob);
	force_me("say My cubs ... Have you found my cubs??");
	return;
	break;
}
}


if(strsrch(msg, "no") != -1 || strsrch(msg,"orry") != -1|| strsrch(msg,"No") != -1){
 
	tell_room(ETO,"The hope in %^YELLOW%^Khamvani %^BLACK%^e%^YELLOW%^y%^BLACK%^es%^RESET%^ is extinguished and replaced with %^BOLD%^%^RED%^mindless rage");
	force_me("You killed my cubs! The sands will drink your blood!");
	tell_room(ETO,"%^YELLOW%^Khamvani%^RESET%^%^RED%^ gives %^BOLD%^bloodcurling roar %^RESET%^and attacks in a crazed frenzy");
	force_me("rush "+ob->query_name());
}
	
	switch(random(10)){
		case 0..6:
	tell_object(ob,"%^ORANGE%^Looks at you with %^BOLD%^%^BLACK%^empty expressionless %^ORANGE%^e%^RESET%^%^ORANGE%^y%^BOLD%^es%^RESET%^%^ORANGE%^. As if he doesn't even know you are there.");
	tell_room(ETO,"%^ORANGE%^Looks at "+ob->QCN+"%^ORANGE%^ with %^BOLD%^%^BLACK%^empty expressionless %^ORANGE%^e%^RESET%^%^ORANGE%^y%^BOLD%^es%^RESET%^%^ORANGE%^. As if he doesn't even know "+ob->QS+"%^ORANGE%^ are there.",ob);
	return;
	break;
		case 7..9:
	tell_object(ob,"%^YELLOW%^Khamvani %^BLACK%^looks chocked as you speak");
	tell_room(ETO,"%^YELLOW%^Khamvani %^BLACK%^looks chocked as "+ob->QCN+" speaks",ob);
	force_me("say You shall die for what you did to my mate!");
	tell_room(ETO,"Khamvani roars ferociously and attacks!");
	force_me("rush "+ob->query_name());
	return;
	break;
	}
}

void shouldaleft(object ob){
	tell_object(ob,"%^YELLOW%^Khamvani%^RESET%^%^ORANGE%^ look at you with %^RED%^battlecrazed eyes");
	tell_room(ETO,"%^YELLOW%^Khamvani%^RESET%^%^ORANGE%^ look at "+ob->QCN+" with %^RED%^battlecrazed eyes",ob);
	force_me("say You came to finish the job .. Thats why you didn't leave?! Have it your way!");
	force_me("rush "+ob->query_name());
}
	

void sweeper(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sweepingblow "+targ->query_name());
}

void heart_beat(){
	object *att;
	int i,j;
	::heart_beat();
  if(query_hp()<query_max_hp()){
     
  TP->add_hp(roll_dice(1,4)+4);}
  if(present("corpse of bloodfang"||"corpse of gnoll priest"||"corpse of gnoll warrior" ||"corpse of gnoll barbarian")){
	  tell_room(ETO,"The wemic tears into the corpse and eats a large chunk while growling madly.");
	  TO->do_damage("torso",-50);
	  force_me("get corpse");
	  force_me("offer corpse");
  }
 
 if(present("gnoll")){
force_me("rush gnoll");}
}