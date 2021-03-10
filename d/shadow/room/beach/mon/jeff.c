#include <std.h>
#include "zeek.h"
#include "dir.h"
inherit "/std/vendor";

int at_shop();

create() {
   ::create();
   set_name("Jeff");
   set_id( ({ "jeff", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Jeff, the General Store owner.");
   set("aggressive", 0);
   set_level(11);
   set_long("Jeff will buy and sell things for you.\n"
	"");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(200));
   set_body_type("human");
   set_storage_room("/d/shadow/room/beach/stores/gs_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("misc");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(200));
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
	if(file_name(environment(TO)) != "/d/shadow/room/beach/stores/gs_store"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}


