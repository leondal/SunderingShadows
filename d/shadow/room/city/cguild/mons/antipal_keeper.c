#include <std.h>
inherit "/std/vendor";

void create() {
   ::create();
   set_name("keeper");
   set_id( ({ "knight", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Knight of the Dark Order");



   set("aggressive", 0);
   set_level(19);
   set_long("She buys and sells equipment.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("female");
   set_alignment(9);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room("/d/shadow/room/city/cguild/antipaladin/storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("all");
   set_max_hp(query_hp());
   remove_std_db();
   remove_dbs(({"/d/db/armors","/d/db/vendor","/d/db/weapons", "/d/db/miscvendors"}) );
   remove_random_act_dbs(({"/d/db/armorsrandom"}));
}

__List(string str){
    if(TP->is_class("antipaladin") || TP->is_class("paladin") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "You are hardly worthy of our items or this place, leave now!");
      return 1;
    }
}
__Buy(string str){
    if(TP->is_class("antipaladin") || TP->is_class("paladin") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "You are hardly worthy of our items or this place, leave now!");
      return 1;
    }
}
__Sell(string str){
    if(TP->is_class("antipaladin") || TP->is_class("paladin") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "You are hardly worthy of our items or this place, leave now!");
      return 1;
    }
}
__Show(string str){
    if(TP->is_class("antipaladin") || TP->is_class("paladin") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "You are hardly worthy of our items or this place, leave now!");
      return 1;
    }
}
__Value(string str){
    if(TP->is_class("antipaladin") || TP->is_class("paladin") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "You are hardly worthy of our items or this place, leave now!");
      return 1;
    }
}
