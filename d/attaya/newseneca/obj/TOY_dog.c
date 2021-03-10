#include <std.h>
inherit OBJECT;
int squeeze;

void create(){
	::create();
	set_name("dog toy");
	set_id(({ "dog", "dog toy", "stuffed dog", "stuffed animal" }));
	set_short("%^BOLD%^%^BLACK%^a dog shaped stuffed animal%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a dog shaped stuffed animal%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Covered in soft, stringy wool dyed a deep shade of %^BOLD%^%^BLACK%^black%^RESET%^, this little stuffed animal is sewn in the shape of a small dog.  Large floppy ears hang on either side of the dog's head and a long, slender tail almost wags as it is moved around.  Shiny %^BOLD%^%^BLACK%^black buttons %^RESET%^have been used for the eyes and nose of this little toy, and its body has been stuffed with puffs of cotton to give it substance.%^RESET%^ 

AVATAR
	);
	set_weight(1);
	set_value(1200);
}

void init(){
   ::init();
   add_action("squeeze","squeeze");
}

int squeeze(string str) {
   if(!str) {
      notify_fail("Squeeze what?");
   }
   if (TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str != "belly") {
      notify_fail("Squeeze what?");
      return 0;
   }
   write("%^BOLD%^%^WHITE%^You squeeze the soft belly of the dog and it goes%^RESET%^ ' %^BOLD%^%^BLACK%^woof woof%^RESET%^ '");
   say("%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft belly of the dog and it goes%^RESET%^ ' %^BOLD%^%^BLACK%^woof woof%^RESET%^ '");
   return 1;
}
