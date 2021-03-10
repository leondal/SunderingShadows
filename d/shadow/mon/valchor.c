#include "melnmarn.h"
#include "dir.h"
inherit "/std/vendor";

create() {
   ::create();
   set_name("Valchor");
   set_id( ({ "valchor", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Valchor, the clerk of Shadow's Weapon Store");
   set("aggressive", 0);
   set_level(19);
   set_long("Valchor is clearly showing his age but he still looks pretty spry. "+
      "The deep lines in his face and friendly smile make him look a little "+
      "grandfatherly to most young adventurers. He seems to enjoy providing a "+
      "good selection of weapons and advice now and then. You have to wonder how "+
      "many thousands of adventurers he's seen in his day and how many million "+
      "goblin bows he's bought. He generally mucks around behind the counter "+
      "arranging the various weapons and mumbling as if to try to remember this or "+
      "that. Now and then he'll notice a conversation and turn to try to answer a "+
      "question.\n\n<help shop> will get you a list of shop commands.");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
// moved storage room to special dir *Styx* 12/31/03, last change 5/2/02
   set_storage_room("/d/shadow/storage/weapon_storage");
   set_property("no attack", 1);
   set_hd(19,3);
  set_exp(10);
   set_max_hp(query_hp());
   set_property("generic db", 1);
   set_items_allowed("weapon");
   //set_db("valchor");
   //set_random_act_db("valchorrandom");
//   set_random_act_chance(10);  changing to let him use default *Styx* 12/31/03
//    set_path_speed(2);
//    set_event("10:11",({S,E,SE,SE,SE}));
//    set_event("10:16",({NW,NW,NW,E,E,E,N,N,NE,NE,NE,E,E,SE,SE,E}));
//    set_event("10:31","say The shop will be closing in 15 minutes!");
//    set_event("10:32",({W,SE,S,S,E,E,E,SW,SW,SW}));
//    set_event("10:46",({NE,NE,NE,W,W,W,N,N,NW,NW,NW,W,W,SW,SW,SW,S,S,W,W,W,W,N}));
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
	if(file_name(environment(TO)) != ROOMDIR+"weapon"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}
void init(){
    ::init();
	set_heart_beat(1);
}