#include <std.h>
#include "abolition.h"
#include "dir.h"
inherit "/std/vendor";

int at_shop();

void create() {
   ::create();
   set_name("Tony");
   set_id( ({ "tony", "man", "armory man"}) );
   set_short("Tony, the Sandy's Armory Shop owner.");
   set("aggressive", 0);
   set_level(10);
   set_long("He gives you the best deal for your money.\n"+
	"<help shop> will show you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(200));
   set_body_type("human");
set_storage_room("/d/mine2/sandy/room/armory_storage");
   set_property("no attack", 1);
   set_hd(10,4);
   set_items_allowed("armor");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(200));
   set_max_mp(query_mp());
   set_path_speed(3);
   set_event("10:00","say Time to go and eat!");
 set_event("10:01",({"OUT","ENTER RESTAURANT"}));
  set_event("10:15","say Time to go to work!");
    set_event("10:16",({"OUT","ENTER ARMORY"}));
   set_event("20:30","say I'm closing in 30 minutes!");
   set_event("20:45","say I'm closing in 15 minutes!");
   set_event("20:50","say I'm closing in 10 minutes!");
   set_event("20:55","say I'm closing in 5 minutes!");
   set_event("20:59","say I'm closing in 1 minute!");
   set_event("20:00","say The Armory is closed!");
   set_event("20:01",({"OUT","ENTER COFFEE SHOP"}));
   set_event("22:10","say Time to go to bed!");
  set_event("22:11",({"OUT","ENTER ARMORY"}));
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
	if(file_name(environment(TO)) != "/d/mine2/sandy/room/armory"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}


