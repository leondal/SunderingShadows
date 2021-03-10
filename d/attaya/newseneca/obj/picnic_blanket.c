//picnic blanket for new Seneca
//~Circe~ 12/13/07
#include <std.h>

inherit OBJECT;

int folded;

void create(){
   ::create();
   set_name("picnic blanket");
   set_id(({"blanket","picnic blanket","checkered blanket"}));
   set_short("%^BOLD%^%^RED%^a c%^WHITE%^h%^RED%^e%^WHITE%^c"+
      "%^RED%^k%^WHITE%^e%^RED%^r%^WHITE%^e%^RED%^d picnic "+
      "blanket (folded)%^RESET%^");
   set_long("This thin picnic blanket is made from soft "+
      "%^BOLD%^%^RED%^c%^WHITE%^h%^RED%^e%^WHITE%^c"+
      "%^RED%^k%^WHITE%^e%^RED%^r%^WHITE%^e%^RED%^d cotton "+
      "%^RESET%^edged in %^BOLD%^%^RED%^red satin%^RESET%^.  "+
      "It looks as though it may be %^BOLD%^%^RED%^<%^RESET%^"+
      "spread%^BOLD%^%^RED%^> %^RESET%^on the ground for "+
      "use, or you can %^BOLD%^%^RED%^<%^RESET%^fold%^BOLD%^"+
      "%^RED%^> %^RESET%^it for ease of storage.  When the "+
      "blanket is spread, you may also %^BOLD%^%^RED%^<"+
      "%^RESET%^sit%^BOLD%^%^RED%^> %^RESET%^or %^BOLD%^%^RED%^"+
      "<%^RESET%^lie%^BOLD%^%^RED%^> %^RESET%^on it.");
   set_weight(5);
   set_value(0);
   folded = 1;
}

void init(){
   ::init();
   add_action("fold_em","fold");
   add_action("spread_em","spread");
   add_action("sit_em","sit");
   add_action("lie_em","lie");
}

int fold_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(folded == 1){
      tell_object(TP,"The blanket is already folded!");
      return 1;
   }
   if(ETO != TP){
      tell_object(TP,"You need to pick up the blanket first.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You shake out the blanket and carefully "+
      "fold it, readying it for storage.%^RESET%^");
   tell_room(ETP,"%^BOLD%^"+ETOQCN+" shakes out the picnic blanket "+
      "and carefully folds it, readying it for storage.%^RESET%^",TP);
   set_short("%^BOLD%^%^RED%^a c%^WHITE%^h%^RED%^e%^WHITE%^c"+
      "%^RED%^k%^WHITE%^e%^RED%^r%^WHITE%^e%^RED%^d picnic "+
      "blanket (folded)%^RESET%^");
   folded = 1;
   return 1;
}

int spread_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(folded != 1){
      tell_object(TP,"The blanket is already spread out!");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You unfold the blanket and fan it out, "+
      "spreading it on the ground.%^RESET%^");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" unfolds a blanket and fans it out, "+
      "spreading it on the ground.%^RESET%^",TP);
   set_short("%^BOLD%^%^RED%^a c%^WHITE%^h%^RED%^e%^WHITE%^c"+
      "%^RED%^k%^WHITE%^e%^RED%^r%^WHITE%^e%^RED%^d picnic "+
      "blanket (spread out)%^RESET%^");
   if(ETO == TP){ TP->force_me("drop picnic blanket"); }
   folded = 0;
   return 1;
}

int sit_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(folded == 1){
      tell_object(TP,"The blanket is not spread out!");
      return 1;
   }
   if(ETO == TP){
      tell_object(TP,"You can't sit on that while you're holding it.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You take a seat on the soft blanket, all "+
      "ready for a picnic.%^RESET%^");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" takes a seat on the blanket.%^RESET%^",TP);
   return 1;
}

int lie_em(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if(folded == 1){
      tell_object(TP,"The blanket is not spread out!");
      return 1;
   }
   if(ETO == TP){
      tell_object(TP,"You can't lie on that while you're holding it.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You stretch out on the picnic blanket, "+
      "relaxing against the soft fabric.%^RESET%^");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" stretches out on the blanket.%^RESET%^",TP);
   return 1;
}