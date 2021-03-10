//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("black sapphire");
   set_id(({ "sapphire", "black sapphire" }));
   set_short("%^BOLD%^%^BLACK%^bla%^RESET%^%^BLUE%^ck sapp%^BOLD%^%^BLACK%^hire%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This small blackish-blue gem has a dull luster to it.  If you look closely you notice it is flawless without one trace of a mark or scratch.%^RESET%^");
   set_weight(5);
   set_property("no animate", 1);
   set_lore("The Black Sapphire is Lord Shadow's answer to Lysara's Scimitar of the Silvery Moon.  Lord Shadow has found a way to corrupt the blade of light into an effective tool of his twisted desires.");
  set_value(random(2000)+1000);
}

int drop(){
   if(!interactive(ETO)){
     ::drop();
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^BLACK%^The black gem flashes in your hand before fading into nothingness!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLACK%^The black gem flashes and fades into nothingness from the hands of "+TPQCN+"!%^RESET%^",TP);
   remove();
   return 1;
}

int is_scimitar_gem(){ return 1; }