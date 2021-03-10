//

#include <std.h>
#define SAVE_FILE "/d/magic/comps/"

inherit OBJECT;


string id;
string owner;
mapping components = ([]);

int string_compare(string one, string two) {
   return strcmp(one, two);
}
void create(){
    ::create();
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
   write(" %^ORANGE%^     Components held    ");
   write("%^ORANGE%^<==========================>");
   for (i=0;i<j;i++) {
      write("%^ORANGE%^ "+arrange_string(comps[i],23)+" "+components[comps[i]]);
//changed to 23, was 17, to allow the viewing of the whole component name Circe 6/18/07
   }


}

