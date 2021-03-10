#include "melnmarn.h"
#include "dir.h"
inherit "/std/vendor";

int at_shop();

void create() {
   ::create();
   set_name("Flugar");
   set_id( ({ "flugar", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Flugar, the clerk of Shadow's Armory");
   set("aggressive", 0);
   set_level(19);
   set_long(
@OLI
   Flugar is an older man but still heavily muscled, no doubt 
from years of blacksmith work hammering out the metals for 
the armor he sells.  Nowadays he has apprentices doing the hard 
work so he has more time to answer questions and advise young 
adventurers.  He still usually wears a blacksmith apron over his
woolen shirt and heavy breeches.  The wrinkles in his forehead 
deepen when he smiles and he seems to like giving advice about 
armor and talking about some of the surrounding area.
OLI
   );
   set_gender("male");
   set_alignment(2);
   set_race("human");
   set_body_type("human");
// moved the storage rooms to a special dir *Styx* 12/31/03, last change 5/17/03
   set_storage_room("/d/shadow/storage/armor_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_property("generic db", 1);
   set_items_allowed("armor");
   set_max_hp(query_hp());
   set_exp(20);
   set_path_speed(3);
//   set_db("flugar");
     add_dbs(({"flugar"}));
//   set_event("7:04","say Well, time to get some breakfast!");
//   set_event("7:05",({S,E,E,SE,SE,SE}));
//   set_event("7:30","say Well, time to get to work!");
//   set_event("7:31",({NW,NW,NW,E,E,E,N,N,NE,W}));
//   set_event("17:47","say The shop will be closing in 15 minutes!");
//   set_event("18:02","say The shop is closed!");
//   set_event("18:03",({E,NE,NE,NE,E,E,SE,SE,SE,S,S,E,E,E,SW,SW,SW}));  
//   set_event("19:30","say Well, time to get to bed!");
//   set_event("19:31",({NE,NE,NE,W,W,W,N,N,NW,NW,NW,W,W,SW,SW,SW,S,S,W,W,W,W,W,N}));
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
	if(file_name(environment(TO)) != ROOMDIR+"armor"){
		command("say Come see me in my shop!!\n");
		return 0;
	}
	return 1;
}


