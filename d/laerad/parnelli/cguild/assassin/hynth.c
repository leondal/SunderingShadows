//Coded by Bane//
#include <std.h>
inherit "/std/vendor";
void create() {
    ::create();
    set_id(({"hynth","shopkeeper","hynth the sly","sly","assassin"}));
    set_name("hynth");
    set_short("Hynth the sly");
    set_long(
	"Hynth is a very small, slender man.  He is dressed in a black tunic and "+
	"breeches.  Two daggers are hung from his belt.  He speaks in a low tone "+
	"and you have to lean close to hear him.  He tells you to <list> to see "+
	"what items he is pawning."
    );
   set_gender("male");
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_alignment(6);
    set_hd(19,3);
    set_hp(155);
    set("aggressive",0);
    set_storage_room("/d/laerad/parnelli/cguild/assassin/ass_stor");
}

int __Buy(string str){
    if(TP->query("is_assassin") || TP->is_class("assassin") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "Get lost bozo!");
      return 1;
    }
}

int __Sell(string str){
    if(TP->query("is_assassin") || TP->is_class("assassin") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "Get lost bozo!");
      return 1;
    }
}

int __Show(string str){
    if(TP->query("is_assassin") || TP->is_class("assassin") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "Get lost bozo!");
      return 1;
    }
}

int __List(string str){
    if(TP->query("is_assassin") || TP->is_class("assassin") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "Get lost bozo!");
      return 1;
    }
}

int __Value(string str){
    if(TP->query("is_assassin") || TP->is_class("assassin") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "Get lost bozo!");
      return 1;
    }
}

