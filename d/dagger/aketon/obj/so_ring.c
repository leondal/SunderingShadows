#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int flag;

create() {
   ::create();
   set_name("silver ornate ring");
   set_id(({"ring","silver ornate"}));
   set("short","silver ornate ring");
   set("long","This is a silver ornate ring.\n");
   set_type("ring");
   set_ac(0);
   set_limbs( ({"right hand"}) );
   set_weight(1);
   set("value",50);
   set_wear( (: TO,"wear_func" :) );
   flag = 0;
}

void init() {
   ::init();
   if(flag)
      return;
   if(ETO == TP && (string)TP->query_race() == "elf") {
      if( !random(50) )
         set_ac(1);
      flag = 1;
   }
}

int wear_func(string str) {
   object *stuff;
   int i,j,flag1;
   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i = 0;i < j;i++) {
      if( (string)stuff[i]->query_type() == "ring" &&
         (string)stuff[i]->query_name() == "silver ornate ring" ) {
         flag1 = 1;
         break;
      }
   }
   if(flag1) {
      write("Wear only one at a time please.");
      return 0;
   }
   return 1;
}
