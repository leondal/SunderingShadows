#include <std.h>
#include "abolition.h"
#include "dir.h"
inherit "/std/vendor";

int at_shop();

create() {
   ::create();
   set_name("Steve");
   set_id( ({ "steve", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Steve the Weapon Store owner.");
   set("aggressive", 0);
   set_level(11);
   set_long("Steve spends his tme fixing up old weapons and selling them.\n"+
	"");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(300));
   set_body_type("human");
   set_storage_room("/d/mine2/sandy/room/weaponry_storage.c");
   set_property("no attack", 1);
   set_hd(10,2);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(200));
   set_max_mp(query_mp());
   set_items_allowed("weapon");
//   set_path_speed(3);
//   set_event("8:11","say How your this morning?");
//   set_event("8:20","say Can I help you?");
//   set_event("9:00","say hello!");
//   set_event("9:30","say The shop will be closing in 30 minutes!");
//   set_event("9:45","say The shop will be closing in 15 minutes!");
//   set_event("9:59","say One minute till closing!");
//   set_event("10:00","say Time to go and eat!");
//   set_event("10:02",({OUT,EC}));
//   set_event("10:16","say Time to go to work!");
//   set_event("10:16",({OUT,EW}));
//   set_event("20:30","say I'm closing in 30 minutes!");
//   set_event("20:45","say I'm closing in 15 minutes!");
//   set_event("20:50","say I'm closing in 10 minutes!");
//   set_event("20:55","say I'm closing in 5 minutes!");
//   set_event("20:59","say I'm closing in 1 minute!");
//   set_event("20:00","say The Weaponry is closed!");
//   set_event("20:01","say bye!");
//   set_event("20:02",({OUT,EH}));
//   set_event("21:01","say Time to go to bed!");
//   set_event("23:30",({OUT,EW}));
//   set_event("23:32","say I'm here!");
//   set_event("23:59","say It's midnight!");
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
	if(file_name(environment(TO)) != "/d/mine2/sandy/room/weaponry"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}
void init(){
    ::init();
	set_heart_beat(1);
}

