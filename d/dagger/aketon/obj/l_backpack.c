#include <std.h>

inherit PARMOUR;

void create(){
   ::create();
   set_name("wearable leather backpack");
   set_id( ({"backpack","leather backpack","wearable leather backpack"}) );
   set_short("leather backpack");
   set_long("This is a wearable leather backpack that you could put your "
       "valuables into.");
   set_weight(5);
   set_value(100);
   set_type("clothing");
   set_property("magic",1);
   set_property("no animate",1);
   set_limbs( ({"back"}) );
   set_max_internal_encumbrance(15);
   set_wear( (: TO,"wear_func" :) );
}

void init() {
   string *limbs;
   ::init();
   limbs = ETO->query_limbs();
   if( interactive(ETO) ) {
      if( member_array("back",limbs) == -1 )
         ETO->add_limb("back","torso",0,0,0);
   }
}

int wear_func() {
   if( interactive(TP) )
      write("The backpack adjusts itself to fit your body.");
   return 1;
}
