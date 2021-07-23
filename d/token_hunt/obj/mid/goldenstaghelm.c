#include <std.h>
inherit "/d/common/obj/armour/helm.c";

void create(){
	::create();
	set_name("golden helm");
	set_id(({ "helm", "helmet", "horned helm", "helm of the golden stag", "golden helm" }));
	set_short("%^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den H%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^YELLOW%^m %^BLACK%^o%^YELLOW%^f t%^RESET%^%^ORANGE%^h%^YELLOW%^e S%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^YELLOW%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den %^RESET%^%^ORANGE%^horned helmet%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This large full-faced helm is designed for protection, though its stylish design makes it a beautiful, artistic "
"headpiece as well.  The plates that wrap around the head are created from molded %^YELLOW%^golden sheets of metal%^RESET%^%^ORANGE%^, and are adorned "
"with %^GREEN%^emerald green vines %^ORANGE%^studded with %^MAGENTA%^amethyst %^ORANGE%^and %^WHITE%^pearl%^RESET%^%^ORANGE%^ roses.  Crowning the "
"helm is a set of %^YELLOW%^golden antlers%^RESET%^%^ORANGE%^.  At least twenty points on either side, they are both massive and majestic.  Each tip is "
"inset with shards of %^RED%^rubies%^ORANGE%^, giving them the illusion of having %^RED%^blood%^ORANGE%^ dripping down their lengths.%^RESET%^");
   set_value(0);
	set_lore("%^RED%^Remembered from an ancient journal:%^RESET%^ The Golden Stag, the General Ta'marni, surged through the tide of men, his aura of "
"power a shield against even the bravest of warriors.  From dawn till dusk, he turned the tide with just his presence alone.  For in his wake, his "
"warriors traveled, taking courage and strength from the prowess of their leader and his unstoppable desire to stop the Dresttel.  No matter where he "
"stepped, all could see him, for the golden horns which rose upon the great helm that graced his head.  Catching the morning's light and glittering "
"beckoningly to the forces of Inomor.");
	set_property("lore difficulty",23);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("charisma",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_func(){
	tell_room(environment(ETO),"%^YELLOW%^As "+ETOQCN+" sets their "+query_short()+" %^YELLOW%^upon their head, they seem to grow in presence and stature.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^The rubies glitter for all to see as you set the helm upon your head.  The majestic antlers adding both presence and weight to your bearing. %^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^YELLOW%^"+ETOQCN+" draws a deep and settling breath as they remove their "+query_short()+".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You lift the helm from your head and the sense of presence and baring slowly fade.%^RESET%^");
	return 1;
}