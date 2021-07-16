/*Slagruss was bugging with an error to call_out on line 92.  I checked it out, and it looks like he should have been autoattacking always, but I've never noticed him doing it.  I fixed the bug, and he definitely autos now.  May need to keep an eye on it.  Circe, 9/20/03*/
inherit "/std/monster";
#include <std.h>
#include <daemons.h>
#include "../lizard.h"

int weap;
int FLAG;

void create() {
        object ob;
        ::create();
        set_name("slagruss");
  	set_id(({"slagruss","king","lizardman king","lizard","lizardman"}));
  	set("race","lizardman");
  	set_gender("male");
  	set("short","%^BOLD%^%^GREEN%^Slagruss, Lizardman King%^RESET%^");
  	set("long","Standing over 7' tall this lizardman is a giant.  The other "+
        	"lizardmen seem to look to this one from leadership.  Muscles "+
        	"ripple underneath his leathery hide as he waves his weapons at you "+
        	"menacingly.  Sitting astride his giant lizard he looks to be very lethal.\n"
        	);
  	set_overall_ac(-8);
    set_class("fighter");
    set_mlevel("fighter", 22);
    set_property("full attacks",1);
  	set_body_type("human");
  	set("aggressive",18);
  	set_alignment(9);
  	set_hd(22,1);
  	set_stats("strength",19);
  	set_stats("charisma", 7);
  	set_stats("dexterity",17);
  	set_stats("constitution",16);
  	set_stats("wisdom",9);
  	set_stats("intelligence",11);
  	set_hp(350);
  	set_exp(10000);
  	set_size(3);
	set_property("add kits",3);
    set_nwp("riding",21);
  	set_wielding_limbs(({"right hand","left hand"}));
  	new(SHWEAP+"shortsword")->move(this_object());
  	command("wield sword");
  	call_out("do_lizard",1);
  	add_money("silver",random(1500));
  	add_money("gold",random(1500));
  	add_money("platinum",random(1500));
  	weap = (random(4));
        	if(weap == 1)       new(LWEAP+"flamesword")->move(this_object());
        	else if(weap == 2)  new(LWEAP+"flamemace")->move(this_object());
        	else if(weap == 3)  new(LWEAP+"flamethsword")->move(this_object());
        	else new(LWEAP+"flamessword")->move(this_object());
  		command("wield flame");
      add_search_path("/cmds/fighter");
    	set_emotes(3,({
		"%^GREEN%^Slagruss hisses: %^RESET%^Sssstand sssstill you worm.",
		"%^GREEN%^Slagruss hisses: %^RESET%^Ssscrawny...but Slagrusss sssshall "+
			"eatsss you anywaysss.\n",
		"%^BOLD%^%^GREEN%^Slagruss licks his lips hungrily.%^RESET%^",
		"%^GREEN%^Slagruss screams: %^BOLD%^%^YELLOW%^YOUSSSS NOT LEAVINGSSS "+
			"ALIVESSS!! %^RESET%^",
		"%^GREEN%^Slagruss hisses: %^RESET%^DIE INTERLOPERSSSS!",
		"%^BOLD%^%^GREEN%^Slagruss spits and hisses at you!%^RESET%^",
		"%^BOLD%^%^GREEN%^Slagruss hisses.",
		"%^BOLD%^%^GREEN%^Slagruss waves his %^RED%^flaming "+
			"%^GREEN%^weapon menacingly.%^RESET%^",
		"%^BOLD%^%^GREEN%^Slagruss growls menacingly.%^RESET%^",
		"%^GREEN%^Slagruss hisses: %^RESET%^Sssssoon....ssssoon.",
		"%^BOLD%^%^GREEN%^Slagruss smiles evilly showing you many rows "+
			"if razor sharp teeth.%^RESET%^",
		"%^GREEN%^Slagruss hisses: %^RESET%^Yousss ssssshall not passssss!",
		"%^BOLD%^%^GREEN%^Slagruss narrows his %^YELLOW%^yellow "+
			"%^GREEN%^reptilian eyes at you.",
    	}),0);
    	FLAG = 0;
    	set_funcs(({"flag_set"}));
    	set_func_chance(25);
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("reptile scales");
      ob->move(TO);
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("reptile scales");
      ob->move(TO);
}
void do_lizard() {
   	object lizard;
   	if(!objectp(ETO)) return;
   	lizard = new(LMON+"wlizard");
   	lizard->set_owner(TO);
   	lizard->move(ETO);
   	command("mount war lizard");
}
void init(){
	string mrace=TP->query_race();
    	::init();
    	if(avatarp(TP) || mrace == "lizardman" || mrace == "lizard") return;
    	call_out("coverass", 2, TP);
}
void coverass(object targ){
      if(!objectp(targ)) return;  //added by Circe 12/5/03
	command("kill "+targ->query_name()+""); //changed to fix call_out error - Circe 9/20/03
	command("rush "+targ->query_name()+"");
	if (FLAG == 1) return;
	force_me("parry");
	FLAG = 1;
}
void flag_set(){
   	if (FLAG == 0)return;
   	if(query_attackers() != ({})){
		FLAG = 0;
		return;
	}
}
void die(object ob) {
    int i;
    object *att;
	tell_room(ETO, "%^BOLD%^%^RED%^Slagruss gives a bloated cry as he"+
		" falls dead to the ground.  As his massive frame shakes the"+
		" room, something dislodges itself from the corpses around the"+
		" throne.");
att = all_living(ETO);
    for(i=0;i<sizeof(att);i++){
      if(!interactive(att[i])) continue;
      att[i]->set_mini_quest("Lizardmen Tribe", 500000,"%^BOLD%^%^GREEN%^You commited a genocidal act against Lizardmen! Congratulations!");
      tell_object(att[i], "\n%^GREEN%^With Slagruss' death, the lizardmen are left broken and confused.\n");
    }
	new("/d/common/obj/rand/epants.c")->move(TO);
    ::die(ob);
}
