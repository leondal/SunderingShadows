//white_mage.c

#include <std.h>

inherit MONSTER;

void create(){
        object ob;
        ::create();
        set_name("white mage");
        set_id(({"white","mage","white mage"}));
        set_short("White mage");
        set_long(
@OLI
        This creature looks upon you with benevolence. You notice that he
is not entirely real, maybe not real at all. You do know that he stands
guard over this small room. you wonder what powers lie inside this
creature.
OLI
        );
        set_hd(30,1);
        set_hp(200);
        set_max_level(25);
        set_exp(20000);
        set_body_type("human");
        set_class("mage");
        set_guild_level("mage",31);
        set_spells(({
                "magic missile",
                "scorcher",
                "lightning orb",
                "greater shout",
                "cone of cold",
                "frost orb",
                "prismatic spary"
                }));
        set_spell_chance(0);
        set_race("ethereal guardian");
        set_gender("male");
        set_funcs(({"start_out"}));
        set_func_chance(102);
        set_overall_ac(0);
        new("/d/common/obj/rand/randrobe")->move(TO);
        command("wear robes");
        ob = new("/d/magic/scroll");
        ob->set_spell(5);
        ob->move(TO);
        ob = new("/d/magic/scroll");
        ob->set_spell(6);
        ob->move(TO);
        command("put scroll in robes");
        command("put scroll in robes");
        set_alignment(1);
        set_mob_magic_resistance("average");
      	ob = new("/d/common/obj/potion/healing");
       	ob->set_uses(25);
       	ob->move(TO);
}

void start_out(object targ){
        "cmds/spells/w/_wall_of_fire"->use_spell(TO,"northeast",31,100,"mage");
        call_out("cast_sec",50);
        
        set_func_chance(0);
        set_spell_chance(102);
        execute_attack();
        call_out("do_again",200);
}

void cast_sec(){
	"cmds/spells/w/_wall_of_fire"->use_spell(TO,"northwest",31,100,"mage");
	}

void do_again(){
        set_func_chance(102);
        set_spell_chance(0);
}

void init(){
       	::init();

        if(!TP->query_invis() && ALIGN->is_evil(TP))
                kill_ob(TP,1);
     
        if(!TP->query_invis() && ALIGN->is_good(TP) && query_attackers() == ({})){
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
		ob->set_name("white key");
       	ob->set_short("white key");
       	ob->set_long("This is an all white key");
       	ob->set_id(({"key","white key","good_key","white"}));
       	ob->move(TO);
       	ob->set_value(1);
       	ob->set_weight(2);
    }
}

void heart_beat(){
	::heart_beat();
	
	if(!objectp(TO))
		return;
	
	if(query_hp() < 150 && present("vial")){
		command("open vial");
		command("drink vial");
	}
	
	if(present("bottle")){
		command("offer bottle");
	}
}
