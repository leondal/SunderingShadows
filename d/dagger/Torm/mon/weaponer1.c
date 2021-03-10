#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
  set_name("Angel");
  set_id(({"angel","weaponsmith","angel the weaponsmith","smith"}));
  set_short("Angel the weaponsmith");
   set("aggressive", 0);
   set_level(19);
  set_long(
   "  This tall, amazingly beautiful woman looks with some interest over you as well for weapons of quality."
   "  Her gold skin gleams in the light of the forges behind her and her long dark hair is done up tightly in a ponytail to keep it out of the way."
  "  Scars crisscross her bare arms and you can see the muscles ripple beneath them, evidence to more than a passing knowledge of the weapons she makes."
  );
  set_gender("female");
  set_alignment(5);
  set_race("human");
   add_money("gold", random(500));
  set_property("always interact",1);
   set_body_type("human");
  set_storage_room(TSP+"weaponer1.c");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
   set_items_allowed("weapon");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
     set_nwp("weaponsmithing",20);
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
  //if(file_name(environment(TO)) !=TCITY+"c96.c"){
  //command("say Come see me in my Shop!!\n");
  //return 0;
  //}
	return 1;
}


