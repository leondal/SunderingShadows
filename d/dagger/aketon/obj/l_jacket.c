#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

string owner;

void create() {
   ::create();
   set_name("lady's jacket");
   set_id( ({"lady's","jacket","suit"}) );
   set("short","A lady's jacket");
    set("long","This is a lady's jacket. Every woman wears it "
      "for some special occasion.");
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
       write("This lady's jacket is not yours!");
      return 0;
   }
   if( (string)TP->query_gender() != "female" ) {
      write("Hmm .. your figure is too strong for this.");
      return 0;
   }
   else {
      write("The lady's jacket covers your body smoothly and perfectly!");
      return 1;
   }
}
