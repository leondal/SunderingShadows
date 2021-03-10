//black_mage.c
//corrected typo and color of key in long descriptions Styx 7/15/01

#include <std.h>

inherit MONSTER;

void create(){
	object ob;
	::create();
	set_name("black mage");
	set_id(({"black","mage","black mage"}));
	set_short("black mage");
	set_long(
@OLI
	This creature looks upon you with malevolence. You notice that he
is not entirely real, maybe not real at all. You do know that he stands
guard over this small room and you wonder what powers lie inside this 
creature.
OLI
	);
	set_hd(25,1);
	set_hp(200);
        set_max_level(25);
	set_exp(20000);
	set_body_type("human");
	set_class("mage");
	set_guild_level("mage",27);
	set_spells(({
		"magic missile",
		"scorcher",
		"acid orb",
		"acid breath",
		"cone of cold",
                "shout",
                "acid orb"
		}));
	set_spell_chance(0);
	set_race("etherial guardian");
	set_gender("male");
	set_funcs(({"start_out"}));
	set_func_chance(102);
	set_overall_ac(0);
      new("/d/common/obj/rand/randrobe")->move(TO);
	command("wear robes");
	ob = new("/d/magic/scroll");
       ob->set_spell(5);
	ob->move(TO);
	command("put scroll in robes");
        ob = new("/d/magic/scroll");
       ob->set_spell(6);
	ob->move(TO);
	command("put scroll in robes");
	set_alignment(9);
	set_mob_magic_resistance("average");
	
}

void start_out(object targ){
	"cmds/spells/m/_monster_summoning_ii"->use_spell(TO,0,30,100,"mage");
	set_func_chance(0);
	set_spell_chance(102);
	execute_attack();
	call_out("do_again",200);
}

void do_again(){
	set_func_chance(102);
	set_spell_chance(0);
}

void init(){
	::init();
	
	if(!TP->query_invis() && ALIGN->is_good(TP)){
		kill_ob(TP,1);
	}
        if(!TP->query_invis() && ALIGN->is_evil(TP) && query_attackers() == ({})){
        	call_out("give_em",5,TP);
		}
}

void give_em(object ob){
	string name;
	
	name = TPQN;

	if(present("key")){
        force_me("give key to "+name);
	}
}

void reset(){
	object ob;
	::reset();
	if(!present("key")){
	    ob = new(OBJECT);
		ob->set_name("black key");
       	ob->set_short("black key");
       	ob->set_long("This is an all black key");
       	ob->set_id(({"key","black key","evil_key","white"}));
       	ob->move(TO);
       	ob->set_value(1);
       	ob->set_weight(2);
    }
}

void heart_beat(){
	::heart_beat();
	if(!objectp(TO))
		return;
	if(!objectp(ETO))
		return;
	if(present("corpse",ETO)){
		"cmds/spells/a/_animate_dead"->use_spell(TO,"corpse",30,100,"mage");
		
	}
}
