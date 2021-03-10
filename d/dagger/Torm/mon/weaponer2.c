#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayvendor.c";

create() {
   ::create();
  set_name("petire");
  set_id(({"petire","weaponsmith","smith","dealer","gnome","petire the weapons dealer","dayperson","weapons dealer"}));
  set_short("Petire the weapons dealer");
   set("aggressive", 0);
   set_level(19);
  set_long(
   "  This youngish looking gnome's eyes light up as he sees you near his stall."
   "  His nose is small for that of a gnome, but it is still much more bulbous than any human's nose.  He has a beard that is kept shortly trimmed and his dark hair is braided back out of his face, although it's curiously full of brightly colored beads.  Gnomes are so strange and eccentric you can't always tell what they're going to do or say next."
  "  His grin is almost infectious as he pulls you closer to show you a fine looking axe."
  );
   set_gender("male");
  set_alignment(5);
  set_race("gnome");
   add_money("gold", random(50));
   set_body_type("human");
  set_storage_room(TSP+"weaponer2.c");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
   set_items_allowed("weapon");
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
  if(file_name(environment(TO)) != TCITY+"65.c"){
  //command("say Come see me in my Shop!!\n");
  return 1;
	}
	return 1;
}


