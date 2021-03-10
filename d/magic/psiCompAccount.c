//

#include <std.h>
#include <security.h>
#define SAVE_FILE "/d/magic/psi_comps/"

inherit OBJECT;


string id;
string owner;
mapping components = ([]);

int string_compare(string one, string two) {
   return strcmp(one, two);
}
void create(){
    ::create();
    seteuid(UID_RESTORE);
}

void Save(){
   save_object(SAVE_FILE+id+"/"+owner+".comp");
}

void Restore(){
   restore_object(SAVE_FILE+id+"/"+owner+".comp");
}

void set_owner(string theId, string who){
   id=theId;
   owner = who;
}

void add_comp(string comp, int amount){
   if (!components) {
      components = ([]);
   }

   if (!components[comp]) {
      if (amount > 0) {
         components[comp] = amount;
      }
      return;
   }

   components[comp]+= amount;
   if (components[comp] < 1) {
      map_delete(components,comp);
   }


}

void remove_comp(string comp, int amount){
   add_comp(comp, (-1)*amount);

}

int query_comp_quantity(string comp){

   if (!components) {
      components = ([]);
      return 0;
   }
   if (!components[comp]) {
      return 0;
   }
   return components[comp];

}

void listComps(object player){
   string *comps;
   int i,j;

   comps = keys(components);

  comps = sort_array(comps,"string_compare",TO);
   j = sizeof(comps);
   write("%^ORANGE%^<==========================>");
   write(" %^ORANGE%^     Crystals held    ");
   write("%^ORANGE%^<==========================>");
   for (i=0;i<j;i++) {
      write("%^ORANGE%^ "+arrange_string(comps[i],17)+" "+components[comps[i]]);
   }


}

