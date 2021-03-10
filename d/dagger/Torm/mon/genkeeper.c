#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
  set_name("Jomai");
  set_id(({"jomai","shifty-eyed jomai","shifty","clerk","store keeper"}));
  set_short("Shifty-eyed Jomai, general store clerk");
   set("aggressive", 0);
   set_level(19);
  set_property("always interact",1);
  set_long(
   "The first thing that comes to your mind when looking at this man is that he's definitely not to be trusted.  He seems rather slimy, especially given the grease that covers his dark brown hair.  His eyes are constantly shifting about and you don't like the way he keeps looking at your items.  It's not as though he's wanting to buy them exactly, or at least not for a reasonable price."
  );
  set_gender("male");
  set_alignment(5);
  set_race("human");
   add_money("gold", random(100));
   set_body_type("human");
  set_storage_room(TSP+"genstore.c");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
  set_items_allowed("misc");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   remove_std_db();
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
  if(file_name(environment(TO)) !="/d/dagger/Torm/city/c28.c"){
  //command("say Come see me in my shop!!\n");
  return 1;
	}
	return 1;
}


