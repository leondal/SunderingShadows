// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
inherit "/d/common/obj/armour/fullplate";

int OWNED;
string *owners;

void create(){
   ::create();
   set_name("stone-cut fullplate");
   set_short("%^BOLD%^%^BLACK%^Gra%^RESET%^%^ORANGE%^ni%^BOLD%^%^BLACK%^te Fullp%^RESET%^l%^BOLD%^%^BLACK%^ate%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^stone-c%^RESET%^u%^BOLD%^%^BLACK%^t ful%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^te%^RESET%^");
   set_id(({"plate","fullplate","armour","armor","full plate","stone
armor","granite armor","granite plate","granite fullplate","fullplate
armor","granite fullplate armor"}));
   set_long("Shaped as a set of full platemail, this small suit of armor "
"offers protection to nearly every part of the body. Yet instead of metal "
"forming the plates, each appears to be cut from a slab of dull, "
"%^BOLD%^%^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k st%^RESET%^o"
"%^BOLD%^%^BLACK%^ne%^RESET%^. Cunning %^RED%^hinges %^RESET%^hold the "
"slabs together, carefully placed to allow movement, and holding the "
"plates layered each over the next in such a fashion as to deflect blows "
"from nearly any angle. Despite that anything of stone of this size must "
"be terribly heavy, it is startlingly %^CYAN%^lightweight%^RESET%^, and "
"surely must only weigh as much as its metallic counterparts. Beneath the "
"stone lies a set of %^ORANGE%^padded armor%^RESET%^, to help distribute "
"the weight and make it easier for the wearer to bear.");
   set_lore("Unusual and rare armor such as this is only ever known to be "
"crafted and owned by dwarves, and even then only a few are ever recorded"
". These are mostly claimed as the possession of dwarvish royal lines, "
"although a few have been recorded as remaining prized artifacts of the "
"church of Grumbar. It is indeed only through the work of his priesthood, "
"that the armor is blessed and imbued with the very essence of the stone "
"it is worked from, to afford the protection of the earth to the wearer.");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_value(12000);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("damage resistance",5);
   set_item_bonus("constitution",4);
   set_size(-1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_struck((:TO,"strikeme":));
   owners = ({});
   set_property("no alter",1);
}

void init() {
   ::init();
   if(ETO->query_size() < 4 && member_array((string)ETO->query_name(),owners) != -1) TO->set_size(ETO->query_size());
   if(!query_property("no alter")) {
     set_property("no alter",1);
     set_name("stone-cut fullplate");
     set_short("%^BOLD%^%^BLACK%^Gra%^RESET%^%^ORANGE%^ni%^BOLD%^%^BLACK%^te Fullp%^RESET%^l%^BOLD%^%^BLACK%^ate%^RESET%^");
     set_obvious_short("%^BOLD%^%^BLACK%^stone-c%^RESET%^u%^BOLD%^%^BLACK%^t ful%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^pl%^RESET%^a%^BOLD%^%^BLACK%^te%^RESET%^");
     set_id(({"plate","fullplate","armour","armor","full plate","stone
armor","granite armor","granite plate","granite fullplate","fullplate
armor","granite fullplate armor"}));
     set_long("Shaped as a set of full platemail, this small suit of armor "
"offers protection to nearly every part of the body. Yet instead of metal "
"forming the plates, each appears to be cut from a slab of dull, "
"%^BOLD%^%^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k st%^RESET%^o"
"%^BOLD%^%^BLACK%^ne%^RESET%^. Cunning %^RED%^hinges %^RESET%^hold the "
"slabs together, carefully placed to allow movement, and holding the "
"plates layered each over the next in such a fashion as to deflect blows "
"from nearly any angle. Despite that anything of stone of this size must "
"be terribly heavy, it is startlingly %^CYAN%^lightweight%^RESET%^, and "
"surely must only weigh as much as its metallic counterparts. Beneath the "
"stone lies a set of %^ORANGE%^padded armor%^RESET%^, to help distribute "
"the weight and make it easier for the wearer to bear.");
     set_lore("Unusual and rare armor such as this is only ever known to be "
"crafted and owned by dwarves, and even then only a few are ever recorded"
". These are mostly claimed as the possession of dwarvish royal lines, "
"although a few have been recorded as remaining prized artifacts of the "
"church of Grumbar. It is indeed only through the work of his priesthood, "
"that the armor is blessed and imbued with the very essence of the stone "
"it is worked from, to afford the protection of the earth to the wearer.");
   }
}

int wearme(){
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this armor.");
     return 0;
   }
   tell_room(EETO,"%^ORANGE%^The fullplate settles in place with the "
"click of %^BOLD%^%^BLACK%^st%^RESET%^on%^BOLD%^%^BLACK%^e %^RESET%^"
"%^ORANGE%^against %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^"
"one%^RESET%^%^ORANGE%^.%^RESET%^");
   return 1;
}

int removeme(){
   tell_object(ETO,"%^ORANGE%^The stone plates of armor scrape together "
"as they move apart, setting you free of their protection.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^The stone plates of armor scrape together "
"as they move apart, setting "+ETO->QCN+" free of their "
"protection.",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
   int skinned, myrandom;
   if(random(2)) {
     tell_object(ETO,"%^RESET%^%^ORANGE%^The blow hits your armor with a "
"loud %^BOLD%^%^WHITE%^c%^YELLOW%^ra%^BLACK%^c%^WHITE%^k%^RESET%^"
"%^ORANGE%^, and spiderweb-thin shatter marks radiate out from the impact"
". Seconds later the plate itself seems to come alive, as the "
"%^BOLD%^%^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k st%^RESET%^o"
"%^BOLD%^%^BLACK%^ne %^RESET%^%^ORANGE%^not only grows over the cracks, "
"but out over your very skin!%^RESET%^");
     tell_object(who,"%^RESET%^%^ORANGE%^Your blow hits "+ETO->QCN+"'s "
"armor with a loud %^BOLD%^%^WHITE%^c%^YELLOW%^ra%^BLACK%^c%^WHITE%^k"
"%^RESET%^%^ORANGE%^, and spiderweb-thin shatter marks radiate out from "
"the impact. Seconds later the plate itself seems to come alive, as the "
"%^BOLD%^%^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k st%^RESET%^o"
"%^BOLD%^%^BLACK%^ne %^RESET%^%^ORANGE%^not only grows over the cracks, "
"but out over "+ETO->QP+" very skin!%^RESET%^");
     tell_room(environment(query_worn()),"%^RESET%^%^ORANGE%^The blow "
"hits "+ETO->QCN+"'s armor with a loud %^BOLD%^%^WHITE%^c%^YELLOW%^ra"
"%^BLACK%^c%^WHITE%^k%^RESET%^%^ORANGE%^, and spiderweb-thin shatter "
"marks radiate out from the impact. Seconds later the plate itself seems "
"to come alive, as the %^BOLD%^%^BLACK%^da%^RESET%^%^ORANGE%^r%^BOLD%^"
"%^BLACK%^k st%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^%^ORANGE%^not only "
"grows over the cracks, but out over "+ETO->QP+" very "
"skin!%^RESET%^",({ETO,who}));
     myrandom = roll_dice(2,4)+2;
     skinned = (int)(ETO->query_stoneSkinned());
     !skinned && skinned = skinned + myrandom;
     ETO->set_stoneSkinned(skinned);
   }
   return damage;
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
