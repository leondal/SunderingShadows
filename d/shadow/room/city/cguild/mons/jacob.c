#include <std.h>
inherit VENDOR;

int at_shop();

void create() {
   ::create();
   set_name("Jacob");
   set_id( ({ "jacob", "fighter", "clerk"}) );
   set_short("Jacob the Fighter Store Owner");
   set("aggressive", 0);
   set_hd(25,20);
  set_long("Jocob is a large fighter who won't put up with any crap.  "
"He is very large and could probably take almost every fighter that "
"is living.  He sits behind the counter selling and trading things for "
"his fellow fighters.");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set_race("human");
   add_money("gold", random(200));
   set_body_type("human");
   set_storage_room("/d/shadow/room/city/cguild/fighter/f_storage");
   set_property("no attack", 1);
   set_items_allowed("all");
}

int __List (string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "Jacob just scoffs at you.");
      return 1;
    }
}
int __Buy(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "Jacob just scoffs at you.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "Jacob just scoffs at you.");
      return 1;
    }
}
int __Show(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "Jacob just scoffs at you.");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "Jacob just scoffs at you.");
      return 1;
    }
}
