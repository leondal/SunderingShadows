#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
  set_name("gilles");
  set_id(({"clothier","giles","giles the tailor","tailor"}));
  set_short("Gilles the tailor");
   set("aggressive", 0);
   set_level(19);
  set_long(
   "  This fussy young man hurries about this way and that checking out a suit on a tailor's mannequin."
   "  He seems like he just can't stop fidgeting with what he's doing and keeps poking himself with a needle by accident."
   "  Despite his apparent awkardness, his clothing is well made, even if it doesn't fit him just right.  It seems he is constantly growing and doesn't have the time to adjust his own clothing he's so bogged down with other people's orders."
  );
   set_gender("male");
  set_alignment(5);
  set_race("human");
   add_money("gold", random(50));
   set_body_type("human");
  set_storage_room(TSP+"clothier.c");
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
  if(file_name(environment(TO)) !=TCITY+"60.c"){
  //command("say Come see me in my shop!!\n");
  //return 0;
	}
	return 1;
}


