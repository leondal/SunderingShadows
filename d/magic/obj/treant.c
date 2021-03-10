//treant.c

#include <std.h>

inherit WEAPONLESS;

void make_me();
void remove_summoned(object ob);

object *summoned;

void create(){
	::create();
	
	set_name("treant");
	set_id(({"tree","treant"}));
	set("short","A grand treant");
	set("long",
@OLI
	This treant has seen many many years of glory in this forest. It has 
stood the test of time. Its thick base and knarled trunk show that it has
seen its fights and won. Its heavy foliage provides a large area of shade.
OLI
	);
	set_overall_ac(0);
	set_race("tree");
	add_limb("trunk","trunk",0,0,0);
	add_limb("right limb","trunk",0,0,0);
	add_limb("foliage","trunk",0,0,0);
	add_limb("root","trunk",0,0,0);
	add_limb("left limb","trunk",0,0,0);
	set_funcs(({"summon"}));
	set_func_chance(40);
	make_me();
	set_attack_limbs(({"right limb","left limb"}));
	set_attacks_num(2);
    set_stats("intelligence",1);
	set_alignment(7);
	summoned = ({});
	}
	
void make_me(){
	int i;
	i = random(7);
	set_hd(i+10,8);
   set_exp(1);
	set_hp(query_hd()*8);
	switch (query_hd()){
		case 10:
		case 11:
			set_damage(2,8);
			
			break;
		case 12:
		case 13:
			set_damage(3,6);
			break;
		case 14:
		case 15:
			set_damage(4,6);
			break;
		default:
			set_damage(5,6);
	}
}


void summon(object obj){
	int i,j;
	object ob;
	
	j = random(3);
	for(i=0;i<j;i++) {
		ob = new("/d/tharis/monsters/tree");
		ob->set_attackers((object)TO->query_attackers());
		ob->move(environment(TO));
		summoned += ({ob});
		ob->set_caller(TO);
		tell_room(ETO,"%^BOLD%^%^GREEN%^A tree uproots itself to come to the aid of the treant!");
	}
	set_func_chance(0);
}

void die(object ob){
	int i;
	for(i=0;i<sizeof(summoned);i++)
		if(objectp(summoned[i]))
			summoned[i]->remove();
	return ::die(ob);
}

void remove_summoned(object ob){
	if(member_array(ob,summoned) != -1)
		summoned -= ({ob});
}

int isMagic() {return 3;}
