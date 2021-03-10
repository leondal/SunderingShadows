// cluster.c

#include <std.h>
#include "../yntala.h"
inherit OBJECT;
int uses;

void create(){
   ::create();
set_id(({"cluster", "grapes", "cluster of grapes"}));
   set_name("%^RESET%^%^MAGENTA%^cluster of grapes%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^A cluster of grapes%^RESET%^");
   set_long("%^RESET%^This is a cluster of small %^MAGENTA%^wine grapes.  %^RESET%^Known for their"
" %^BOLD%^%^MAGENTA%^fuller flavor, %^RESET%^these are about half the size of traditional %^MAGENTA%^grapes"
" %^RESET%^but taste a whole lot better.  There are quite of few of them still stuck to the %^GREEN%^vine."
" %^RESET%^Perhaps you can take one to try it?%^RESET%^");
   set_weight(3);
   uses =random(10)+15;
}
void init(){
  ::init();
  add_action("take","take");
}
int take(string str){
   if(str == "grape"||str == "a grape"||str == "grape from cluster"||str == "a grape from cluster"||str == "grape from the cluster"||str == "a grape from the cluster"){
      if (!uses==0){
         tell_object(TP,"%^RESET%^%^MAGENTA%^You pick a grape from the cluster.%^RESET%^");
         tell_room(ETP,"%^RESET%^%^MAGENTA%^"+TP->query_cap_name()+" takes a grape from the cluster.%^RESET%^",TP);
      new(OBJD+"grape.c")->move(ETO);
         uses --;
      return 1;
      }
      if (uses==0){
         tell_object(TP,"%^RESET%^%^GREEN%^You go to take another grape only to realize that the vine is empty.%^RESET%^");
         tell_room(ETP,"%^RESET%^%^GREEN%^"+TP->query_cap_name()+" looks disappointed as "+TP->query_subjective()+" looks at the empty vine.%^RESET%^",TP);
         TO->remove();
      return 1;
      }
   }
}
