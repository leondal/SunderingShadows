// test cleric monster

#include <std.h>
#include <daemons.h>
inherit MONSTER;

#define CONSTS ({"b","c","d","f","g","h","j","k","l",\
  "m","n","p","q","r","s","t","v","w","x","z","th","ch","sh"})
#define VOWELS ({"a","e","i","o","u","y","ou"})
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

int healings = 5;
object *parties;


void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	 set_class("cleric");
  	j = random(8)+3;
  	name = CONSTS[random(sizeof(CONSTS))];
  	for (i= 2;i<=j;i++){
    	if(i%2)
      	name += CONSTS[random(sizeof(CONSTS))] ;
    	else 
      	name += VOWELS[random(sizeof(VOWELS))];
  	}
  	set_alignment(random(9)+1);
  	set_name(name);
  	set_id(({"hunter","glory",name}));
  	set_short(capitalize(name)+" the glory hunter");
  	races = RACE_D->query_races();
 	races = races - SHIT;
 	races = races - ({"beastman","firbolg","ogre","ogre-mage","voadkyn","wemic"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(30)+20,8);
  	set_hp(random(200)+200);
        set_exp(2000);
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
  	set_long("This is a glory hunter. Long has "+query_subjective()+" watched "+
           "as those around "+query_objective()+" gained glory in battle. "+
	   "Now the time has come for "+query_objective()+" to hunt out glory. "+
	   "The target: The most powerful players and monsters on the MUD."+
	   "Only then will "+query_subjective()+" be remembered forever as a dominating "+
	   "force, and "+query_possessive()+" name will be written in the "+
	   "annals of ShadowGate."
	);
  	set_guild_level("cleric",query_hd());
  	set_spells(({"call lightning", "limb attack"}));
  	set_spell_chance(90);

  	ob = new("/d/dagger/marsh/tower/obj/sorrow");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield staff");

  	set_overall_ac(-5);
  	ob = new("/d/attaya/obj/azure");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear plate");

  	ob = new("/d/common/obj/potion/healing");
  	ob->move(TO);
  	ob->set_uses(random(25)+25);

  	set_money("gold",random(3000));
  	parties = ({});
}


void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp() < 100 && healings){
    	new("/cmds/priest/_heal")->use_spell(TO,query_name(),200);
    	healings--;
  	}
  
  	if(!present("snake",ETO) && !ETO->query_property("used sticks"))
    	new("/cmds/priest/_sticks_into_snakes")->use_spell(TO,0,query_level());
  
  	if(query_hp()< 50 && present("vial",TO)) {
    	command("open vial");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
    	command("quaff vial"); 
    	command("offer bottle");
    	command("quaff vial");    
    	command("offer bottle");
    	command("quaff vial");
    	command("offer bottle");
	}
}

int kill_ob(object victim, int which){
  	int hold;
  	int i,j;

  	hold = ::kill_ob(victim, which);
    j = sizeof(parties);
  	if(hold) {
	  if(interactive(victim))  // added to cut down on multiples for snakes, etc.
	     new("/cmds/priest/_animate_object")->use_spell(TO,victim->query_name(),query_level());
    	for(i =0;i<j;i++){
		if(!objectp(parties[i])) continue;
		if(parties[i] == TO)  continue;
		if(pointerp(parties[i]->query_attackers())){
	 	   if(member_array(victim, parties[i]->query_attackers()) == -1){
			parties[i]->add_attacker(victim);
// changing to add_attackers to try to fix recursion problem  *Styx*  11/9/02
//			parties[i]->attack(victim);
		   }
		} else {
			parties[i]->add_attacker(victim);
//			parties[i]->attack(victim);
		}
	}
    }
    return hold;
}

void add_party(object member){
	parties += ({member});
}

object *query_party(){return parties;}

void init(){
	::init();
	
        if(TP->is_npc()) return;
	if(((int)TP->query_level() > query_level()) && !wizardp(TP) && (ALIGN->is_good(TP) != ALIGN->is_good(TO)) && !TP->query_invis() && (member_array(TP,parties) == -1))
		call_out("attack",1,TP);
}

void attack(object ob){
        if(!objectp(ob) || !objectp(TO))   return;
// changing to grab parsable name to avoid giving away real names *Styx*  11/23/03
	command("say Ahh the glory that you shall bring to me is indeed great, "+capitalize(ob->getParsableName())+"!");
	command("kill "+ob->query_name());
}
