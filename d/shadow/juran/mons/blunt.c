#include <std.h>
#include "../juran.h"
inherit "/std/vendor";

int at_shop();

create() {
   	::create();
	set_name("Blunt");
   	set_id( ({ "monster","Blunt","blunt","fighter", "clerk"}) );
   	set_short("Blunt the Fighter Store Owner");
   	set("aggressive", 0);
   	set_level(25);
  	set_long(
  		"Blunt is a large bugbear fighter who won't put up with any crap.  "
		"He is very large and could probably take almost every fighter that "
		"is living.  He sits behind the counter selling and trading things for "
		"his fellow fighters."
	);
     	set_spoken("wizish");
   	set_gender("male");
   	set_alignment(6);
   	set("race", "bugbear");
   	add_money("gold", random(200));
   	set_body_type("humanoid");
  	set_storage_room(JSTORE+"f_storage");
  	set_size(3);
 	set_property("no attack", 1);
   	set_hd(25,10);
   	set_items_allowed("all");
   	set_max_sp(query_hp());
   	set_sp(query_max_sp());
   	set_mp(random(200));
   	set_max_mp(query_mp());
   	set_exp(1000);
   	remove_std_db();
   	remove_dbs(({"/d/db/armors", "/d/db/vendor", "/d/db/weapons","/d/db/miscvendors"}));
   	remove_random_act_dbs(({"/d/db/armorsrandom"}));
}

int __List (string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "Blunt just scoffs at you.");
      return 1;
    }
}
int __Buy(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "Blunt just scoffs at you.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "Blunt just scoffs at you.");
      return 1;
    }
}
int __Show(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "Blunt just scoffs at you.");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "Blunt just scoffs at you.");
      return 1;
    }
}
