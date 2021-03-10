#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

string owner;

void create() {
   ::create();
   set_name("trousers");
   set_id( ({"trousers","pants"}) );
   set("short","A pair of trousers");
   set("long","This is a pair of trousers. Every man wears it "
      "for some special occasion.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"left leg","right leg"}) );
   set_value(200);
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
      write("The pair of trousers is not yours!");
      return 0;
   }
   if( (string)TP->query_gender() != "male" ) {
      write("Hmm .. your figure is too good for this.");
      return 0;
   }
   else {
      write("The pair of trousers fits your legs perfectly!");
      return 1;
   }
}
