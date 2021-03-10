#include <std.h>
inherit "/std/vendor";

string time;

create() {
   	::create();
  	set_name("Tolo");
  	set_id(({ "tolo","Tolo","shop keeper", "shopkeeper"}));
  	set_short("Tolo the trader");
   	set("aggressive", 0);
  	set_level(5);
  	set_long("He sells weapons and armour to adventurers that are trying "+
  		"to stay alive. \n\n\n\n%^RED%^%^BOLD%^Tolo tells "+
  		"you:%^RESET%^ <help shop> will help you with the commands you need. \n");
   	set_languages( ({ "common" }) );
   	set_gender("male");
   	set_alignment(4);
   	set_race("human");
   	add_money("gold", random(500));
   	set_body_type("human");
  	set_storage_room("/d/koenig/town/wp_ac_storage.c");
  	set_hd(5,10);
   	set_items_allowed("misc");
   	set_max_hp(query_hp());
   	set_max_sp(query_hp());
   	set_sp(query_max_sp());
   	set_mp(random(500));
   	set_max_mp(query_mp());
}

__List(str){
	if(!at_shop()) return 1;
	return ::__List(str);
}
__Buy(str){
	if(!at_shop()) return 1;
	return ::__Buy(str);
}
__Sell(str){
	if(!at_shop()) return 1;
	return ::__Sell(str);
}
__Show(str){
	if(!at_shop()) return 1;
	return ::__Show(str);
}
__Value(str){
	if(!at_shop()) return 1;
	return ::__Value(str);
}
int at_shop(){
  	if(file_name(environment(TO)) != "/d/koenig/town/store2"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}


void reset(){
  	::reset();
    	time = "daemon/events_d"->query_time_of_day();
    	if(time != "day")
    	remove();
}
