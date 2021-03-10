#include <std.h>
inherit "/std/vendor";

void create() {
   ::create();
   set_name("knight");
   set_id( ({ "knight", "clerk","keeper", "shop keeper", "shopkeeper"}) );
   set_short("Keeper of the store");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells equipment, but only deals with the noble born "
	"who have chosen the path to knighthood.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(1);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room("/d/shadow/room/city/cguild/cavalier/storage.c");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("all");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
}
int __List(string str){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "Thou ist not worthy!");
      return 1;
    }
}
int __Buy(string str){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "Thou ist not worthy!");
      return 1;
    }
}
int __Sell(string str){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "Thou ist not worthy!");
      return 1;
    }
}
int __Show(string str){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "Thou ist not worthy!");
      return 1;
    }
}
int __Value(string str){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "Thou ist not worthy!");
      return 1;
    }
}
