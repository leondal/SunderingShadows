//coded by Circe 9/14/04 - designed by Eiryasha
#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	set_name("%^GREEN%^Wooden Fairy Tale%^RESET%^");
	set_short("%^RESET%^A heavily %^BOLD%^engraved %^RESET%^"+
         "wide %^GREEN%^wooden bracelet%^RESET%^");
	set_id(({"bracelet","darkwood","fairy tale","darkwood bracelet",
         "wood bracelet","wooden bracelet"}));
	set_long(
         "This bracelet is carved from the %^BOLD%^%^BLACK%^dark wood "+
         "%^RESET%^of a rare %^GREEN%^tree%^RESET%^.  "+
         "The bracelet is wide enough to hang loosely on most people.   "+
         "The engravings depict a mural of %^CYAN%^fanciful sprites "+
         "%^RESET%^leading a %^BOLD%^swordsman %^RESET%^through a "+
         "heavy forest of %^ORANGE%^mushrooms%^RESET%^.  Strange "+
         "writing in flowing script flows across the inside."
	);
	set_weight(1);
	set_value(2500);
	set_type("ring");
	set_limbs(({"left arm"}));
}

void init(){
   ::init();
   add_action("read_em","read"); //done purposefully to add messages.  Circe
}

int read_em(string str){
   if(str != "bracelet" && str != "fairy tale" && str != "wood bracelet") return 0;
   tell_object(ETO,"%^BOLD%^%^GREEN%^As you read the bracelet, your "+
      "mind is filled with moving images, and you could swear you hear "+
      "a gentle voice singing along to these words...");
   tell_room(EETO,""+ETOQCN+" reads the bracelet.",ETO);
   ETO->more("/d/tharis/obj/rings/fairy_story");
   return 1;
}
