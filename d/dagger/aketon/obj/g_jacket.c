#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

string owner;

void create() {
   ::create();
   set_name("gentleman's jacket");
   set_id( ({"gentleman's","jacket","suit"}) );
   set("short","A gentleman's jacket");
    set("long","This is a gentleman's jacket. Every man wears it "
       "for some special occasions.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_value(400);
   set_wear( (: TO,"wear_func" :) );
}

int set_own(string str) {
   if(owner || !str)
      return 0;
   else {
      owner = str;
      return 1;
   }
}

int wear_func(string str) {
   if( (string)TPQN != owner ) {
       write("This gentleman's jacket is not yours!");
      return 0;
   }
   if( (string)TP->query_gender() != "male" ) {
      write("Hmm .. your figure is too good for this.");
      return 0;
   }
   else {
      write("The gentleman's jacket fits your body perfectly!");
      return 1;
   }
}
