#include <std.h>
inherit OBJECT;
int squeeze;

void create(){
	::create();
	set_name("pink dragon toy");
	set_id(({ "dragon", "dragon toy", "stuffed dragon", "stuffed pink dragon", "pink dragon", "stuffed animal", "pink stuffed animal" }));
	set_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a %^BOLD%^%^MAGENTA%^dr%^RESET%^%^MAGENTA%^a%^WHITE%^g%^MAGENTA%^o%^BOLD%^n%^RESET%^ ");
	set_obvious_short("%^BOLD%^%^WHITE%^a stuffed toy in the shape of a %^BOLD%^%^MAGENTA%^dr%^RESET%^%^MAGENTA%^a%^WHITE%^g%^MAGENTA%^o%^BOLD%^n%^RESET%^ ");
	set_long(
@AVATAR
%^RESET%^Made out of textured doeskin, this small stuffed animal looks like a fierce %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^WHITE%^r%^MAGENTA%^p%^BOLD%^le dr%^RESET%^%^MAGENTA%^a%^WHITE%^g%^MAGENTA%^o%^BOLD%^n %^RESET%^complete with %^BOLD%^%^MAGENTA%^pink wings %^RESET%^and%^MAGENTA%^%^BOLD%^ ridges %^RESET%^running along its back. Posed sitting up, its large %^MAGENTA%^%^BOLD%^pink wings %^RESET%^extend outward from the body while its head is lifted up in a mighty %^BOLD%^%^WHITE%^roar%^RESET%^. 

AVATAR
	);
	set_weight(1);
	set_value(600);
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
   say("%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft belly of the dragon and it goes%^RESET%^ ' %^BOLD%^%^MAGENTA%^rar rar%^RESET%^ '");
   write("%^BOLD%^%^WHITE%^You squeeze the soft belly of the dragon and it goes%^RESET%^ ' %^BOLD%^%^MAGENTA%^rar rar%^RESET%^ '");
   return 1;
}
