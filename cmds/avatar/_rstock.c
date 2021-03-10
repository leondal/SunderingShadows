//faiths added by circe 3/25/04
#include <std.h>
#include "/d/dagger/sp_armor.h"
#include "/d/dagger/sp_weapons.h"
#include "/d/dagger/sp_other.h"
#include "/d/dagger/sp_mundane.h"
#include "/d/dagger/sp_faiths.h"


inherit DAEMON;

int cmd_rstock(string str){
   object thing;
   
   if(str == "rop +2"){
      thing = new("/d/deku/armours/ring_p.c");
      thing->set_property("enchantment",1);
      thing->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(str == "rop +3"){
      thing = new("/d/deku/armours/ring_p.c");
      thing->set_property("enchantment",2);
      thing->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(str == "rop +4"){
      thing = new("/d/deku/armours/ring_p.c");
      thing->set_property("enchantment",3);
      thing->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(str == "wool cloak small"){
      thing = new("/d/islands/pirates/armor/woolcloak.c");
      thing->set_size(1);
      thing->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(ARMOR)) !=-1) {
      new(thing = ARMOR[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(ARMOR2)) != -1) {
     new(thing = ARMOR2[str])->move(ETP);
     tell_object(TP,thing->query_short()+" appears before you.");
     return 1;
   }
   if(member_array(str, keys(WEAPONS)) !=-1){
      new(thing = WEAPONS[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(WEAPONS2)) !=-1){
      new(thing = WEAPONS2[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(OTHER)) !=-1){
      new(thing = OTHER[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(MUNDANE)) !=-1){
      new(thing = MUNDANE[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   if(member_array(str, keys(FAITHS)) !=-1){
      new(thing = FAITHS[str])->move(ETP);
      tell_object(TP,thing->query_short()+" appears before you.");
      return 1;
   }
   tell_object(TP,"That item isn't on the list.");
   return 1;
}
int help(){
   write("Syntax: rstock <item> \n\nThis will create the item you "+
      "wish.  To see a list of items available use the lstock "+
      "command. \n\nRelated subjects: lstock.");
   return 1;
}