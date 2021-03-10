//Octothorpe (4/21/11)
//Scrying, submitted by Alzar
//Based on mirror/crystal ball, /d/magic/obj/mirror.c & crystal_ball.c

#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("scrying bowl");
   set_id(({
      "scrying bowl",
	  "silver bowl",
	  "bowl",
	  "mirror",
	  "crystal ball"
   }));
   set_short("%^BOLD%^%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v"+
		 "%^WHITE%^er%^RESET%^%^RED%^ bowl%^RESET%^");
   set_long("%^RESET%^%^RED%^The %^RESET%^dull%^RED%^, %^BOLD%^"+
      "%^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^er%^RESET%^"+
	  "%^RED%^ bowl seems to be resting on an outstretched %^RESET%^"+
	  "skeletal%^RED%^ hand which extends from the pedestal. A dried, "+
	  "caked on %^BOLD%^%^RED%^blood %^RESET%^%^RED%^ red substance "+
	  "can be found inside the bowl.%^RESET%^");
   set_value(1001);
   set_weight(100000);
   set_no_clean(1);
}

int get() { return 0; }

int drop() { return 1; }
