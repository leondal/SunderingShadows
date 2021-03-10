#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayvendor.c";

create() {
   ::create();
  set_name("Buemor");
  set_id(({
  "buemor","shop keeper","shopkeeper","clerk","armorer","dwarf",
  "dayperson",
  }));
    set_short("Buemor, Dwarven armorer extraodinaire");
  set_emotes(3,({
    "%^MAGENTA%^Buemor says: %^RESET%^Come look at my armor, best in the lands!",
   "%^MAGENTA%^Buemor says: %^RESET%^Money back guarantee on this plate if you die with it on.",
  "Buemor polishes a helmet and grins to a passerby.",
    "%^MAGENTA%^Buemor says: %^RESET%^Some thief mugged me and took me diamond "
      "hammer.  Guess I'll send off and have another made again.",
  }));
   set("aggressive", 0);
   set_level(19);
  set_long(
  "  Short and incredibly thick even for a dwarf, Buemor appears more a part of the earth than some mountains you've seen."
  "  His stout form is naked to the waist exposing a body scarred from a life of working at a forge."
   "  His upper body is incredibly muscled, especially his arms, and his hands appear almost permanently stained black from the soot of the forge.  His beard is long and braided, probably to help keep it out of the flames.  Despite the gray streaks in his hair, he seems full of energy."
  );
   set_gender("male");
   set_hd(28,2);
  set_alignment(5);
  set_race("dwarf");
   add_money("gold", random(500));
   set_body_type("human");
  set_storage_room(TSP+"armorer1.c");
   set_property("no attack", 1);
   set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_overall_ac(-9);
   set_stats("strength",18);
   set_class("fighter");
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
    set_exp(100);
  set_items_allowed("armor");
   set_max_hp(query_hp());
   if(!random(10)) {
      new("/d/dagger/Torm/obj/diamond_hammer")->move(TO);
      command("wield hammer");
   }
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
  if(file_name(environment(TO)) !=TCITY+"62.c"){
  //command("say Come see me in my SHOP!!\n");
  return 1;
	}
	return 1;
}


