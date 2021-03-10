#include "/d/shadow/room/city/melnmarn.h"
#include "/d/antioch/areadefs.h"
inherit "/std/vendor";

create() {
   ::create();
set_name("orc");
set_id( ({ "orc","shopkeeper" }) );
   set_short("An old Hag, the Keeper of the little shack.");
   set("aggressive", 0);
   set_level(19);
set_long(
"This orc is bad to the bone.  He wields a axe in his and ready for"+
"any move you might make.  He looks at you and grins a hideous grin.\n"+
      "<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(4);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
set_storage_room(VIL+"gs_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("misc");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
new("/d/antioch/weapon/axe")->move(TO);
command("wield axe");
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
        if(file_name(environment(TO)) != "/d/shadow/room/tour/death/dth_store"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}


