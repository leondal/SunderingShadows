#include "/d/dagger/aketon/short.h"
#include <daemons.h>
#include <security.h>

#define SAVEFILE "/d/save/aketon/artifacts"

inherit DAEMON;

mapping __Items;

void Save();
void Restore();
void CheckOwners();
int set_item(string item,string who);

void create(){
   ::create();
   __Items=([]);
   if(file_exists(SAVEFILE+".o")) Restore();
   CheckOwners();
}

void Save() {
   seteuid(UID_DAEMONSAVE);
   save_object(SAVEFILE);
   seteuid(getuid());
}

void Restore() {
   seteuid(UID_DAEMONSAVE);
   restore_object(SAVEFILE);
   seteuid(getuid());
}

void CheckOwners() {
   string who,*items;
   int i,j;
   items = keys(__Items);
   for(i=0;i<sizeof(items);i++) {
      who = __Items[items[i]][0];
      if((string)FINGER_D->user_finger_display(who) ==
         "No such member of the Shadow Gate World.\n") {
         map_delete(__Items,items[i]);
      }
      Save();
   }
   return;
}

int set_item(string item,string who) {
   if(!__Items) __Items = ([]);
   if(__Items[item]) return 0;
   __Items[item] = ({who,base_name(PO),time()});
   Save();
   return 1;
}

mapping query_items(mapping map) {
   return __Items;
}

string query_item(string item) {
   if(!__Items[item]) return 0;
   return __Items[item];
}

string query_owner(string item) {
   if(!__Items[item]) return 0;
   return __Items[item][0];
}

string query_where(string item) {
   if(!__Items[item]) return 0;
   return __Items[item][1];
}

int query_when(string item) {
   if(!__Items[item]) return 0;
   return __Items[item][2];
}

void remove_item(string item){
   if(__Items && __Items != ([]))
      if(__Items[item])
         map_delete(__Items,item);
   Save();
}

int clean_up(){return 1;}
