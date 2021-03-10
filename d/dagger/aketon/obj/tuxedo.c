#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

string owner;

void create() {
   ::create();
   set_name("tuxedo");
   set_id( ({"tuxedo","jacket","suit"}) );
   set("short","A fine tuxedo suit");
    set("long","This is a fine tuxedo suit which every man wears at his "
      "wedding.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_value(500);
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
      write("This tuxedo suit is not yours!");
      return 0;
   }
   if( (string)TP->query_gender() != "male" ) {
      write("Hmm .. your figure is too good for this.");
      return 0;
   }
   else {
       write("The tuxedo suit fits your body perfectly!");
      return 1;
   }
}
