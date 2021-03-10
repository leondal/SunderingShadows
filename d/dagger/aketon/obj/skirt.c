#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

string owner;

void create() {
   ::create();
   set_name("skirt");
   set_id( ({"skirt"}) );
   set("short","A skirt");
    set("long","This is skirt. Every woman wears it for some special "
        "occasion.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"waist"}) );
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
      write("The skirt is not yours!");
      return 0;
   }
   if( (string)TP->query_gender() != "female" ) {
      write("Hmm .. you look aweful with this.");
      return 0;
   }
   else {
      write("The skirt fits you perfectly!");
      return 1;
   }
}
