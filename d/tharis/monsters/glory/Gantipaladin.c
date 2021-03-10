// test antipaladin monster

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
 	 set_class("antipaladin");
  	j = random(8)+3;
  	name = CONSTS[random(sizeof(CONSTS))];
  	for (i= 2;i<=j;i++){
    	if(i%2)
      	name += CONSTS[random(sizeof(CONSTS))] ;
    	else 
      	name += VOWELS[random(sizeof(VOWELS))];
  	}
  	set_name(name);
      set_alignment(9);
  	set_id(({"hunter","glory",name}));
  	set_short(capitalize(name)+" the glory hunter");
  	races = RACE_D->query_races();
 	races = races - SHIT;
  	set_race("human");
  	set_hd(random(30)+20,8);
     set_nwp("riding",query_hd());
  	set_hp(random(270)+200);
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
  	set_guild_level("cleric",query_hd()-9);
  	set_spells(({"call lightning", "limb attack", "hold person"}));
  	set_spell_chance(20);

	if(random(2)) 
		ob = new("/d/dagger/marsh/tower/obj/unholy");
	else ob = new("/d/darkwood/equip/desecrator");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield sword");

  	ob = new("/d/common/obj/weapon/hhlance");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",4);
  	ob->move(TO);

  	set_overall_ac(-3);
  	ob = new("/d/dagger/marsh/tower/obj/unplate.c");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear plate");

  	ob = new("/d/dagger/marsh/tower/obj/unshield.c");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear shield");

  	ob = new("/d/dagger/marsh/tower/obj/uncoif.c");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear coif");

  	ob = new("/d/deku/armours/ring_p");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->set_property("enchantment",1);
  	ob->move(TO);
  	command("wear ring");

  	ob = new("/d/common/obj/potion/healing");
  	ob->move(TO);
  	ob->set_uses(random(25)+25);

  	ob = new("/d/azha/obj/mr_ring");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
  	command("wear ring");

  	set_money("gold",random(3000));
  	set_property("full attacks",1);
  	set_mob_magic_resistance("average");
  	call_out("horsey",1);
  	parties = ({});
}


void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
  	if(query_hp() < 100 && healings){
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	new("/cmds/priest/_cure_light_wounds")->use_spell(TO,query_name(),200);
    	healings--;
  	}
  
     if(present("corpse"))  
    	new("/cmds/priest/_animate_dead")->use_spell(TO,0,query_level());
   
  	if(query_hp()< 70 && present("vial",TO)){
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
  	if(hold){
// this was looping after the fix below, added it to spell list above instead 11/12/02
//    	new("/cmds/priest/_hold_person")->use_spell(TO,victim->query_name(),query_level());
    	command("sic "+victim->query_name());
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


void init(){
	::init();
	
        if(TP->is_npc()) return;
	if(((int)TP->query_level() > query_level()) && !wizardp(TP) && ALIGN->is_good(TP) && !TP->query_invis() && (member_array(TP,parties) == -1))
		call_out("attack",1,TP);
}

void add_party(object member){
	parties += ({member});
}

object *query_party(){return parties;}

void attack(object ob){
        if(!objectp(ob) || !objectp(TO))   return;
// changing to grab parsable name to avoid giving away real names *Styx*  11/23/03
	command("say Ahh the glory that you shall bring to me is indeed great, "+capitalize(ob->getParsableName() )+"!");
	command("kill "+ob->query_name());
}

void horsey(){
	new("/d/shadow/room/city/cguild/paladin/war_horse")->move(ETO);
	command("mount horse");
}
