//mockspur.c

#include <std.h>
#include "/d/common/common.h"

inherit "/std/vendor";

void create(){
	::create();
	
	set_name("mockspur");
	
	set("id",({"mockspur","Mockspur","shopkeeper","keeper"}));
	
	set("short","Mockspur, shopkeeper of the Tharis fighter's guild");
	set("long",
@OLI
	This LARGE person stands something like a guard over his store.
He has been left with the duty of making sure that the valuables of 
his store are sold properly and only to the proper people. To
see his inventory <list>.
OLI
	);
	set_level(25);
	set_hd(25,1);
	set_hp(200);
	set_exp(10);
	set_gender("male");
   set_race("human");
	set_storage_room("/d/tharis/Tharis/cguilds/fighter/f_storage");
   set_items_allowed("all");
	set_body_type("human");
	set_wielding_limbs(({"right hand","left hand"}));
	new(CWEAP"longsword")->move(TO);
	command("wield sword");
	new(CWEAP"longsword")->move(TO);
	command("wield sword");
	
	}

int __Sell(string str){
    if(TP->is_class("fighter")) return ::__Sell(str);
    else {
      tell_object(TP, "We don't want your business!");
      return 1;
    }
}

int __List(string str){
    if(TP->is_class("fighter")) return ::__List(str);
    else {
      tell_object(TP, "We don't want your business!");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("fighter")) return ::__Buy(str);
    else {
      tell_object(TP, "We don't want your business!");
      return 1;
    }
}

int __Show(string str){
    if(TP->is_class("fighter")) return ::__Show(str);
    else {
      tell_object(TP, "We don't want your business!");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("fighter")) return ::__Value(str);
    else {
      tell_object(TP, "We don't want your business!");
      return 1;
    }
}
