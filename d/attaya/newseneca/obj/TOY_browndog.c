#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("stuffed dog toy");
	set_id(({ "toy", "dog", "stuffed dog", "stuffed dog toy", "brown dog", "brown dog toy", "stuffed toy","stuffed animalz"}));
	set_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a dog%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a stuffed toy in the shape of a dog%^RESET%^");
	set_long(
@AVATAR
Padded with plenty of soft cotton, this little stuffed animal is shaped like a %^RESET%^%^ORANGE%^dog%^WHITE%^. Durable %^RESET%^%^ORANGE%^brown%^RESET%^ and %^BOLD%^%^WHITE%^white %^RESET%^broadcloth has been used to make the body of this stuffed animal. Long floppy ears hang on either side of the head, while %^BOLD%^%^BLACK%^black buttons %^RESET%^have been used to make the nose, eyes and ears. A %^BOLD%^%^MAGENTA%^pink felt %^RESET%^tongue extends from the yarn sewn mouth and several %^BOLD%^%^WHITE%^white spots %^RESET%^have been sewn over the %^ORANGE%^brown body %^RESET%^adding contrast. %^BOLD%^Something about this cute little dog makes you want to %^CYAN%^<%^WHITE%^squeeze%^CYAN%^> %^WHITE%^it.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(210);
}

void init(){
   ::init();
   add_action("squeeze_me","squeeze");
}

int squeeze_me(string str){
   if(!str) return 0;
   if(!id(str)) return 0;
   if (TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+TPQCN+" squeezes the soft "+
      "belly of the dog and it goes%^RESET%^ ' %^RESET%^"+
      "%^ORANGE%^ruff ruff ruff%^RESET%^ '",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You squeeze the soft "+
      "belly of the dog and it goes%^RESET%^ ' %^RESET%^"+
      "%^ORANGE%^ruff ruff ruff%^RESET%^ '");
   return 1;
}