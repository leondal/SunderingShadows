#include "/d/attaya/seneca/short.h"

#define SAVE_MONSTER "/d/save/nellie"

inherit NPC;

string *killers;

void create(){
    object ob;
	::create();
	killers = ({});
	seteuid(geteuid());
	restore_object(SAVE_MONSTER);
	set_name("nellie");
	set_id(({"nellie","Nellie",}));
	set_short("Nellie, the guild guardian");
	set_long(
@OLI
Nellie is the beautiful guardian of the thieves' guild in Seneca. She has long brown hair with red highlights and sparkling hazel eyes. You will need to <register> in order to enter here and to enjoy the services provided.
OLI
	);
	set_race("human");
set_gender("female");
	set_class("thief");
	set_hd(30,1);
	set_hp(300);
	set_exp(1000);
	set_body_type("human");
	set_wielding_limbs(({"right hand","left hand"}));
    ob = new("/d/attaya/obj/screamer");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger");
    ob = new("/d/attaya/obj/screamer");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wield dagger");
     set_nwp("concealment",45);
     set_event("7:04","say Well, time to make sure nothing is missing...");
    save_object(SAVE_MONSTER);

}

void init(){
	::init();
	
	add_action("register","register");
	add_action("bump","bump");
	}

int register(){
	if(member_array(TPQN,killers) != -1) return notify_fail("You are no longer welcome here because of your crimes against the guild!\n");
	
	if(TP->query_money("gold") < 20000) return notify_fail("I'm sorry You need 20000 gold to enter.\n");

	if(environment(TO)->add_member(TPQN)){
		TP->add_money("gold",-20000);
		write("%^BOLD%^%^RED%^Welcome to the guild. You will find many useful items in the shop.");
		return 1;
		}else
		notify_fail("You have no need to register. You are already a member silly\n");
	}
	
int kill_ob(object victim, int which){
	int hold;
	hold = ::kill_ob(victim, which);
	if(member_array(TPQN, killers) != -1) return hold;
	killers += ({TPQN});
	environment(TO)->remove_member(TPQN);
	save_object(SAVE_MONSTER);
	return hold;
	}

int bump(string str){
	string var1, var2;
	if(!str) return 0;
	
	if(sscanf(str, "%s %s", var1, var2) != 2) return 0;
	if(id(var1)) return notify_fail("Delusional?\n");
	return 0;
}
