//Coded by Circe 6/8/04
#include <std.h>
inherit OBJECT;

int count;
void create(){
   ::create();
   set_name("soap");
   set_id(({"soap","bar of soap","bar"}));
   set_short("%^BOLD%^%^WHITE%^Bar of Soap%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is simply a bar of soap with "+
      "a fresh, clean scent.  It is small and compact and would "+
      "fit neatly into a pouch, though you would probably want "+
      "to let it dry first.  With it, you may %^CYAN%^wash %^WHITE%^your face, "+
      "hands, or body to cleanse yourself of dirt, grime, and "+
      "unwanted smells.  You'll most likely want water nearby "+
      "to rinse.");
   set_value(25);
   set_weight(1);
}

void init(){
        :: init();
        add_action("wash_me","wash");
}


int wash_me(string str){
   if(!str){
      tell_object(TP,"Using this soap, you may wash your "+
         "face, hands, or body.  What would you like to wash?");
      return 1;
   }
   if(str == "face" || str == "body" || str == "hands"){
      if(count > 4){
         tell_object(TP,"The bar of soap has run out.");
         TO->remove();
         return 1;
      }
      tell_object(TP,"You lather up the soap and wash your "+
         ""+str+".  You rinse and put the bar away, feeling "+
         "clean and refreshed.");
      tell_room(ETP,""+TPQCN+" washes "+TP->QP+" "+str+" with "+
         "a bar of soap.",TP);
      TP->set("long");
      count++;
      return 1;
   }
   return 0;
}

