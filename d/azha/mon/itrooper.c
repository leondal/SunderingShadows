// Imperial Elite Trooper

#include <std.h>
#include <daemons.h>
inherit MONSTER;

int healings = 5;
object *parties;
void makeMe();


void create(){
        object ob;
        string name = ({}), *races;
        int i,j,k,num;
        ::create();
         set_class("fighter");
        set_name("Trooper");
        set_alignment(1);
        set_id(({"elite","imperial trooper", "guard", "itrooper", "trooper" }));
        set_short("Imperial Guard Trooper");
        set_race("human");
        set_hd(random(30)+20,8);
        set_hp(random(300)+150);
        set_exp(1050 * query_hd());
        set_body_type(query_race());
        set_gender("male");
        set_long(
@TSARVEN
This is an Imperial Elite Forces Trooper of Tsarven.  The Troopers are 
the Elite troops of the Empire and are highly trained and unbelievably
skilled.  A trooper's clothes are simple, yet effective and his equipment
is formidable.
TSARVEN
    );

	set_property("knock unconscious", 1);

	ob = new("/d/azha/equip/iscimitar");
	num = random(100);
	if(num) ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",3);
	ob->move(TO);
	ob->set_size(query_size());
	command("wield scimitar");

	ob=new("/d/azha/equip/iscimitar");
	num = random(100);
	if(num) ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",3);
	ob->set_size(query_size());
	ob->move(TO);
	command("wield scimitar");
	set_overall_ac(-7);

	ob = new("/d/azha/equip/iarmor.c");
	num = random(100);
	ob->set_property("enchantment",3);
	if(num) ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear armor");

	ob = new("/d/deku/armours/ring_p");
	num = random(100);
	if(num) ob->set_property("monsterweapon",1);
	ob->set_property("enchantment",3);
	ob->move(TO);
	command("wear ring");
	
	ob = new("/d/shadow/obj/potion/healing");
	ob->move(TO);
	ob->set_uses(75);
	
	set_money("gold",random(60));
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	parties = ({});
}


void heart_beat(){
        ::heart_beat();

        if(!objectp(TO) || !objectp(ETO)) return;

        if(query_hp()< 75 && present("vial",TO)){
	command("parry");
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
        command("rush "+victim->query_name());
        for(i =0;i<j;i++){
                        if(!objectp(parties[i])) continue;
                        if(pointerp(parties[i]->query_attackers())){
                                if(member_array(victim, parties[i]->query_attackers()) == -1){
                                        parties[i]->attack(victim);
                                }
                        } else {
                                parties[i]->attack(victim);
                        }
                }
        }
        return hold;
}

void add_party(object member){
        parties += ({member});
}

object *query_party(){return parties;}

