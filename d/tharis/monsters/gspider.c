
#include <std.h>
inherit "/std/monster";

void new_form();
void make_imp();

void create() {
    ::create();
   set_name("spider");
    set_id(({"spider","giant spider"}));
   set_short("A giant spider");
   set_level(5);
      set_long("This large spider is very uncommon in the Shadowgate\n"+
                  "realm.  They are not web builders but they are raving\n"+
                  "hunters.\n");
   set_gender("female");
   set_race("spider");
   set_body_type("arachnoid");
   set_alignment(5);
   set_size(2);
   set_hd(5,5);
   set_stats("intelligence",5);
   set_stats("wisdom",4);
   set_stats("strength",10);
   set_stats("charisma",3);
   set_stats("dexterity",14);
   set_stats("constitution",5);
   set_max_hp(query_hp());
   add_money("copper",random(20));
   set_class("fighter");


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
