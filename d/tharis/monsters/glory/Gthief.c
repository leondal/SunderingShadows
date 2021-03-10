// test thief monster

#include <std.h>
#include <daemons.h>
inherit MONSTER;

#define CONSTS ({"b","c","d","f","g","h","j","k","l",\
  "m","n","p","q","r","s","t","v","w","x","z","th","ch","sh"})
#define VOWELS ({"a","e","i","o","u","y","ou"})
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

object *parties;

void create(){
  object ob, ob2;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	 set_class("thief");
  
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
 	races = races -  SHIT;
 	races = races - ({"firbolg","half-ogre","ogre","wemic"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(30)+20,8);
  	set_max_hp(random(150)+100);
  	set_hp(query_max_hp());
        set_exp(2000);
  	set_body_type(query_race());
  	set_gender(random(2)?"male":"female");
  	set_long("This is a glory hunter. Long has "+query_subjective()+" watched "+
           "as those around "+query_objective()+" gained glory in battle. "+
	   "Now the time has come for "+query_objective()+" to hunt out glory. "+
	   "The target: The most powerful players and monsters on the MUD. "+
	   "Only then will "+query_subjective()+" be remembered forever as a dominating "+
	   "force, and "+query_possessive()+" name will be written in the "+
	   "annals of ShadowGate."
	);
	set_guild_level("thief",query_level());

  	ob = new("/d/attaya/obj/screamer");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield dagger");

  	set_overall_ac(0);
  	ob = new("/d/deku/armours/hide");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear hide");

	ob = new("/d/laerad/obj/bracers5");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear bracers");

	ob = new("/d/deku/armours/ring_p");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",1);
	ob->move(TO);
	command("wear ring");

  	ob = new("/d/common/obj/potion/healing");
  	ob->move(TO);
  	ob->set_uses(random(25)+25);
      ob = new("/d/tharis/obj/bpowder");
      if(random(100)) ob->set_property("monsterweapon",1);
    ob->move(TO);

	ob = new("/d/tharis/obj/wrist_sheath");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);

  ob2 = new("/d/attaya/obj/screamer");
    num = random(100);
  if(num) ob2->set_property("monsterweapon",1);
  ob2->set_size(1);
  ob2->move(TO);
  ob2->move(ob);
  ob->move(TO);
  command("wear sheath");

  	set_money("gold",random(3000));
  	set_mob_magic_resistance("average");
  	set_thief_skill("hide in shadows",95);
  	set_thief_skill("move silently",95);
  	add_search_path("/cmds/thief");
  	set_invis();
  	parties = ({});
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp()< 80 && present("vial",TO)){
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

int do_damage(string limb, int damage){
  	int hold;
  	
  	hold = ::do_damage(limb,damage);
  	
  	if(living(PO)) command("throw powder at "+PO->query_name());
  	
  	if(PO->is_spell() && objectp(PO->query_caster()))
  		command("throw powder at "+PO->query_caster()->query_name());
  	return hold;
}


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
	command("stab "+ob->query_name());
	set_invis();
}

int kill_ob(object victim, int which){
	int hold;
	int i,j;
	hold = ::kill_ob(victim, which);
	
	j = sizeof(parties);
	if(hold) {
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


