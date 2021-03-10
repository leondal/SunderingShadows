#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit VENDOR;

create() {
   ::create();
  set_name("Shamus");
  set_id(({"shamus","shopkeeper","shop keeper"," clerk","armorer"}));
    set_short("Shamus, Torm's Armorer");
   set("aggressive", 0);
  set_emotes(3,({
  "Shamus polishes a shield and sets it carefully back on the rack.",
  "Shamus watches one of his apprentices twist wire into the leather brace of a helmet and nods.",
  "Shamus tugs on his beard.",
  }),0);
   set_level(19);
  set_long(
   "  A long, flowing red beard tinged with burns and scorches dominates your image of Shamus."
   "  It's quite odd that a man who wears a heavy leather apron to protect himself would allow his beard to catch fire, but perhaps he gets lost in his work."
   "  He is a tall man, reaching six feet in height, and is heavily muscled.  He has hazel eyes and is actually rather pale in complexion next to many of the town's citizens."
   "  He probably moved here from somewhere else, Torm is a large trading town after all, bringing in an almost constant supply of business."
  );
   set_gender("male");
  set_property("always interact",1);
  set_alignment(5);
  set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
  set_storage_room(TSP+"armorer2.c");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
  set_items_allowed("armor");
   set_max_hp(query_hp());
     set_nwp("armorsmithing",20);
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
  if(file_name(environment(TO)) !=TCITY+"c96.c"){
  //command("say Come see me in my SHOP!!\n");
  return 1;
	}
	return 1;
}


