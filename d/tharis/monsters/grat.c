#include <std.h>
inherit "/std/monster";

void new_form();
void make_imp();

void create() {
    ::create();
   set_name("giantrat");
   set_id( ({ "giantrat","giant","rat","giant rat" }) );
   set_short("A giant rat");
   set_level(2);
   set("long", "A giant rat.\n");
   set_gender("male");
    set("race", "rat");
   set_body_type("quadruped");
   set_alignment(2);
   set_hd(2,0);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",1);
   set_stats("wisdom",4);
   set_stats("strength",12);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",17);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_mp(0);
   set_mp(query_max_mp());
   add_money("copper",random(5));

}

void heart_beat(){
	::heart_beat();
	
	
	if(query_race() == "imp" && query_attackers() == ({}))
		new_form();
	if(query_race() != "imp" && query_attackers() != ({}))
		make_imp();
	
	if(query_hp() < 10){
		run_away();
		set_invis();
	}
}

void new_form(){
	int num;
	int my_hp;
	object ob;
	
	num = random(2);
	seteuid(getuid());
	if(num){
		ob = new("/d/tharis/monsters/grat");
		ob->set_hp(TO->query_hp());
		ob->move(ETO);
		ob->set_attackers(query_attackers());
	}else{
	    ob = new("/d/tharis/monsters/gspider");
		ob->set_hp(TO->query_hp());
		ob->move(ETO);
		ob->set_attackers(query_attackers());
	}
	
		
	tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wonderous transformation as this creature changes form!");
	remove();
}
	
void make_imp(){
	object ob;
	ob = new("/d/tharis/monsters/wimp");
	ob->set_hp(TO->query_hp());
	ob->move(ETO);
	ob->set_attackers(query_attackers());
	tell_room(ETO,"%^BOLD%^%^YELLOW%^You witness a wonderous transformation as this creature reveals it's true form!");
	remove();
}



void init(){
	::init();
	
	if(ALIGN->is_good(TP))
		kill_ob(TP,1);
}

int kill_ob(object victim, int which){
	object *inven;
	int i,k;
	
	::kill_ob(victim,which);
	make_imp();
}
	
