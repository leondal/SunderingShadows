#include <std.h>
inherit ARMOUR;
#define MAXUSES 50

int uses;

void create(){
	::create();
	set_name("ring");
	set_id(({ "ring", "ring of warmth", "warmth" }));
	set_short("%^BOLD%^%^RED%^Ring of Warmth%^RESET%^");
	set_obvious_short("a red steel ring");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A thin band of red steel is what this ring is made of. On a closer inspection, you realize the red steel has been braided with a %^YELLOW%^yellow hued%^RED%^ metal, though it almost seems to blend together. As you look closer, you notice something written on the yellow strip of metal.

AVATAR
	);
	set("read",
@AVATAR
%^YELLOW%^Remember the fires of the %^RED%^hearth%^YELLOW%^ to stay toasty warm when Auril's chill is in the air.

AVATAR
	);
     set("langage","str");	set_weight(1);
	set_value(50);
	set_lore(
@AVATAR
The Ring of Warmth is prized by both Kossuthians and Lathanderites for it's ability to ward off Auril's chill. From there many other faiths have found a use for it, when travelling to the frigid north. Of course adventures prize it claiming it helps ward off magical cold attacks.

AVATAR
	);
	set_property("lore",9);
	set_type("ring");
	set_limbs(({ "left hand","right hand" }));
	set_size(2);
	set_property("enchantment",0);
}


void init() {
   ::init();
   add_action("warm","hearth");
}

int warm() {
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paraylyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) return notify_fail("You have to wear the ring first.");
   if(uses < MAXUSES) {
      tell_object(TP, "%^BOLD%^%^RED%^You speak a word and feel warmer.");
      tell_room(ETP, "%^BOLD%^%^RED%^"+TPQCN+" speaks a word and is briefly covered in a faint red glow.",TP);
      uses +=1;
      return 1;
      }
   else{
      set_value(0);
      tell_object(TP, "The ring is out of charges.");
   }
   return 1;
}
