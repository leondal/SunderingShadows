// Artifact weapon inheritable for Aketon
// 170898 - Obsidian@ShadowGate

#include "/d/dagger/aketon/short.h"
#include <security.h>

inherit WEAPON;

string item_location,item_name;

void log_func(string str,int type);

create() {
    ::create();
   set_short("");
   set_long("");
   set_id( ({"artifact"}) );
   set_property("no offer",1);
   set_property("no steal",1);
   set_heart_beat(1);
}

void set_item_location(string str) {
   item_location = str;
}

void set_item_name(string str) {
   item_name = str;
}

void query_item_location() {
   return item_location;
}

void query_item_name() {
   return item_name;
}

void init() {
   ::init();
   set_heart_beat(1);
   call_out("check_it",1);
   if( wizardp(TP) || avatarp(TP) )
      return;
   if(interactive(ETO) && TP == ETO) {
      find_object_or_load(item_location)->
      register_item(item_name,TPQTN);
   }
   else if(TP != ETO) {
      find_object_or_load(item_location)->reset_item(item_name);
      log_func("remove",1);
      remove();
   }
   return;
}

int drop() {
   if( !interactive(TP) )
      return 0;
   if( base_name(PO) != "/std/user" ) {
      write("%^RED%^You cannot drop the artifact!");
      return 1;
   }
}

void check_it() {
   object *inven,*arti;
   int i;
   if( !interactive(ETO) || wizardp(ETO) || avatarp(ETO) )
      return;
   arti = ({});
   inven = deep_inventory(ETO);
   for(i = 0;i < sizeof(inven);i++) {
      if( member_array("artifact",(string)inven[i]->query_id()) != -1)
         arti += ({inven[i]});
   }
   if( sizeof(arti) > 1 ) {
      tell_object(ETO,"%^BLUE%^You cannot carry two artifacts!");
      log_func("remove",2);
      remove();
      return;
   }
   return;
}

void heart_beat() {
   if( !objectp(ETO) || !objectp(TO) )
      return;
   if( ETO->query_ghost() ) {
      find_object_or_load(item_location)->reset_item(item_name);
      log_func("remove",3);
      remove();
      return;
   }
   if( !interactive(ETO) ) {
      find_object_or_load(item_location)->reset_item(item_name);
      if( ETO->query_true_name() )
         log_func("remove",3);
      else
         log_func("remove",4);
      remove();
      return;
   }
   return;
}

void log_func(string str,int type) {
   if(wizardp(ETO) || avatarp(ETO))
      return;
   seteuid(UID_LOG);
   if(str == "get")
      log_file("aketon",capitalize(ETO->query_true_name())+" got "+TOQCN+
         " at "+ctime(time())+"\n");
   if(str == "remove" && type == 1)
      log_file("aketon",capitalize(ETO->query_true_name())+" lost "+TOQCN+
         " at "+ctime(time())+" : Initiation check violation\n");
   if(str == "remove" && type == 2)
      log_file("aketon",capitalize(ETO->query_true_name())+" lost "+TOQCN+
         " at "+ctime(time())+" : Two artifacts in inventory\n");
   if(str == "remove" && type == 3)
      log_file("aketon",capitalize(ETO->query_true_name())+" got "+TOQCN+
         " at "+ctime(time())+" : Ghost environment detected\n");
   if(str == "remove" && type == 4)
      log_file("aketon",TOQCN+" removed from game at "+ctime(time())+
         " : Non-interactive environment detected\n");
   seteuid(getuid());
   return;
}
