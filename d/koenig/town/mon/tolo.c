#include <std.h>
inherit "/std/vendor";

string time;

create() {
   ::create();
  set_name("Tolo");
  set_id(({ "tolo","Tolo","shop keeper", "shopkeeper"}));
  set_short("Mr. Tolo the Shopkeeper");
  set("aggressive", 0);
  set_level(5);
  set_long("%^RESET%^Mr. Tolo is the town's %^BOLD%^weapons%^RESET%^ and %^BOLD%^armor%^RESET%^ dealer. In a town such as this, it is a booming business to keep the locals and visitors well armed. Mr. Tolo is a middle-aged man, with crazy %^BOLD%^%^BLACK%^s%^RESET%^a%^BOLD%^%^BLACK%^lt-a%^RESET%^n%^BOLD%^%^BLACK%^d-pepp%^RESET%^e%^BOLD%^%^BLACK%^r hair%^RESET%^. He seems friendly enough, if not a bit guarded.");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
  set_storage_room("/d/koenig/town/wp_ac_storage.c");
  set_hd(5,0);
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


void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
