//description changed by Circe 6/10/04
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
   set_long("Jacob is a middle aged man with the quiet strength "+
      "that seems to come with age.  His shoulders are broad and "+
      "his form stout, if not particularly muscular.  He seems "+
      "to possess a brute strength that lies quiet for the moment "+
      "but could easily be awakened should he be angered.  His eyes "+
      "are a dusty hazel with brown highlights that match his short "+
      "hair.  Numerous small scars cover his body, evidence of the "+
      "days he spent exploring this world.  Now, however, he remains "+
      "here, selling needed items to younger adventurers.");
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
      tell_object(TP, "The salesman just scoffs at you.");
      return 1;
    }
}
int __Buy(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "The salesman just scoffs at you.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "The salesman just scoffs at you.");
      return 1;
    }
}
int __Show(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "The salesman just scoffs at you.");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("fighter") || TP->is_class("bard") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "The salesman just scoffs at you.");
      return 1;
    }
}
