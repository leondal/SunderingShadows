#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayvendor.c";

create() {
   ::create();
  set_name("furtrader");
  set_id(({"trader","fur trader","dayperson"}));
  set_short("Furtrader");
   set("aggressive", 0);
   set_level(19);
  set_property("always interact",1);
  set_long(
   "The beastman stands proud and tall.  An olive green fur covers his body, but no one else seems to pay him any more attention than the other vendors.  He carries a leather pack full of tanning equipment.  It is indeed very odd to see one of his race filling such a capacity, but you suppose Torm is a good place for misfits."
  );
   set_gender("male");
  set_alignment(5);
   set_race("beastman");
   add_money("gold", random(50));
   set_body_type("human");
  set_storage_room(TSP+"furtrader.c");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
  set_items_allowed("clothing");
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
  if(file_name(environment(TO)) !=TCITY+"57.c"){
  //command("say Come see me in my shop!!\n");
  return 1;
	}
	return 1;
}


