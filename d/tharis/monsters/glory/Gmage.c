// test mage monster

#include <std.h>
#include <daemons.h>
inherit MONSTER;

#define CONSTS ({"b","c","d","f","g","h","j","k","l",\
  "m","n","p","q","r","s","t","v","w","x","z","th","ch","sh"})
#define VOWELS ({"a","e","i","o","u","y","ou"})
#define SHIT ({"dragon","elven-dragon","pegataur","alaghi","unborn"})

object *parties;
int skins = 7;

void create(){
  	object ob;
  	string name = ({}), *races;
  	int i,j,k,num;
  	::create();
 	 set_class("mage");
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
  	races = ({"elf","half-elf","human","ogre-mage","voadkyn"});
  	set_race(races[random(sizeof(races))]);
  	set_hd(random(30)+20,8);
  	set_max_hp(random(100)+100);
  	set_hp(query_max_hp());
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
  	set_guild_level("mage",query_hd());
  	set_spells(({"magic missile", "lightning bolt", "cone of cold", "fireball", "vampiric touch"}));
  	set_spell_chance(98);

  	switch (query_alignment()){
  		case 1:
  		case 4:
  		case 7: ob = new("/d/tharis/obj/white_robes");
  				break;
  		case 2:
  		case 5:
  		case 8: ob = new("/d/tharis/obj/black_robes");
  				break;
  		case 3:
  		case 6:
  		case 9: ob = new("/d/tharis/obj/black_robes");
  		        break;
  		default: break;
  		}
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	command("wear robes");

  	ob = new("/d/tharis/barrow/obj/staff");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
  	ob->move(TO);
  	ob->set_size(query_size());
  	command("wield staff");
  	set_overall_ac(0);

	ob = new("/d/laerad/obj/bracers8");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
    ob->move(TO);
	command("wear bracers");

	ob = new("/d/deku/armours/ring_p");
    num = random(100);
    if(num) ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",2);
	ob->move(TO);
	command("wear ring");

  	ob = new("/d/common/obj/potion/healing");
  	ob->move(TO);
  	ob->set_uses(random(25)+25);

  	set_money("gold",random(3000));
  	set_mob_magic_resistance("average");
  	parties = ({});
}

void heart_beat(){
  	::heart_beat();
  
  	if(!objectp(TO) || !objectp(ETO)) return;
  	
    if(!present(query_name()+" summoned",ETO) && sizeof(query_attackers())){
    	new("/cmds/wizard/_monster_summoning_vii")->use_spell(TO,0,query_level());
  	}
  	
  	if(present("snake",ETO)){
  		new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  	}
  	
  	if(!query_stoneSkinned() && skins){
    	new("/cmds/wizard/_stoneskin")->use_spell(TO,TO,query_level());
    	skins--;
  	}
  	
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
    new("/cmds/wizard/_finger_of_death")->use_spell(TO,ob->query_name(),query_level());
	command("kill "+ob->query_name());
	//new("/cmds/wizard/_wall_of_fire")->use_spell(TO,0,query_level());
}

void add_party(object member){
	parties += ({member});
}

object *query_party(){return parties;}

