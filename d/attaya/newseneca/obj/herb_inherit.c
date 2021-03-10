//herb inherit for new Seneca
//coded by ~Circe~ 4/19/08 
//with descriptions and actions by Lurue

#include <std.h>

inherit OBJECT;

string herb_name;

void set_herb_name(string str);
void query_herb_name();

void create(){
   ::create();
   set_name("herb");
   set_weight(1);
   set_cointype("silver");
}

void init(){
   ::init();
   add_action("use_em","use");
   add_action("treat_em","treat");
}

int use_em(string str){
   if(!id(str)) return 0;
   switch(random(100)){
      case 0..74:   tell_object(TP,"You use the %^GREEN%^"+herb_name+" "+
         "%^RESET%^and soon feel it affecting you in a helpful way.");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
      case 75..94:   tell_object(TP,"You use the %^GREEN%^"+herb_name+" "+
         "%^RESET%^and wait, but feel no effect.");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
      default: tell_object(TP,"You use the %^GREEN%^"+herb_name+" "+
         "%^RESET%^and soon begin to feel nauseous and ill!");
         tell_room(ETP,""+TPQCN+" uses some %^GREEN%^"+herb_name+"%^RESET%^.",TP);
         TO->remove();
         break;
   }
   return 1;
}

void set_herb_name(string str){
   if(!str) str = "herb";
   herb_name = str;
}

void query_herb_name(){
   return herb_name;
}

int is_herb(){ return 1; }