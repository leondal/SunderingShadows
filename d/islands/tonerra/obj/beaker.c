//beaker

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit OBJECT;

int red, black,blue,bubbly;

void create(){
   ::create();

   set_name("a large beaker");
   set_id(({"beaker","large beaker"}));
   set_short("A large beaker");
   set_long(
@OLI
   This beaker is made to mix things in. You would just add the
various chemicals and poof, or boom.
OLI
   );
   set_weight(10);
   set_value(20);
}

void init(){
   ::init();
   add_action("addstuff","add");
}

int addstuff(string str){
   string type;
   object ob;

   if(!str){
      return notify_fail("add what?\n");
   }
   if(sscanf(str,"%s liquid",type) != 1){
      return notify_fail("Please <add type liquid>\n");
   }

   if(!ob = present(str,TP)){
      return notify_fail("You don't have that.\n");
   }

   if(type == "black"){
      black = 1;
   } else if(type == "red"){
      red = 1;
   } else if(type == "bubbly"){
      bubbly = 1;

   }else if(type == "blue"){
      blue =1;
   } else {
      return notify_fail("You think twice about adding that.\n");
   }
   tell_object(TP,"You add the "+str+" to the mixture in the beaker.");
   tell_room(ETP,"You see "+TPQCN+" add a "+str+" to the beaker.",TP);

   if(black && blue && bubbly && red){
      tell_room(ETP,"%^BOLD%^%^YELLOW%^ BBBBBBBBOOOOOOOOOOOOOMMMMMMMMMMM!");
      new(MON+"intelligence")->move(ETP);
   }
   ob->remove();
   return 1;
}
