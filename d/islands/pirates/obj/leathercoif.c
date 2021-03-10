#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather coif");
   switch(random(10)){
     case 0..3:
     set_id(({"coif","leather coif","simple coif","simple leather coif"}));
     set_short("%^RESET%^%^ORANGE%^simple leather coif%^RESET%^");
     set_long("This is a plain %^ORANGE%^leather coif%^RESET%^ of a simple design, to protect the head from "
"light blows.  The leather has been tanned and treated to make it more durable than simple clothing.  A thin "
"lining of %^WHITE%^%^BOLD%^pale wool%^RESET%^ is set in a layer along the underside, not particularly "
"thick, but enough to cushion the head somewhat.");
     break;

     case 4..7:
     set_id(({"coif","leather coif","old coif","old leather coif"}));
     set_short("%^RESET%^%^ORANGE%^old leather coif%^RESET%^");
     set_long("This coif might have once been an effective piece of armor, but it looks like it has seen "
"better days.  The %^ORANGE%^leather%^RESET%^ is cracked in several places and rubbed raw, leaving several "
"weaker spots upon its surface.  The inner lining of wool has %^BLACK%^%^BOLD%^grayed%^RESET%^ with age, and is starting to give off a rather bad smell, as though it has been worn for too long.");
     break;

     case 8..9:
     set_id(({"coif","leather coif","sturdy coif","sturdy leather coif"}));
     set_short("%^RESET%^%^ORANGE%^sturdy leather coif%^RESET%^");
     set_long("Thick, sturdy %^ORANGE%^leather%^RESET%^ forms this coif, that looks particularly well-made.  "
"It has a smooth surface along the outside, and would probably protect the head quite well from light "
"attacks.  The leather has been well-treated to be durable against blows, and proofed against harsh "
"weather.  %^WHITE%^%^BOLD%^Soft, pale wool%^RESET%^ lines the inner portions, in a thick enough layer to "
"comfortably cushion the head.");
     break;
   }
   set_ac(0);
   set_type("leather");
   set_limbs(({"head"}));
   set_property("enchantment",2);
   set_weight(3);
   set_value(20);
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^The distinctive style of the coif marks this as a commonly-used pirate coif.  "
"Such armor as this was commonly granted to higher-ranking mates on a ship, and often imbued with protective "
"enchantments by the ship's mage.%^RESET%^\n");
   set_property("lore difficulty",9);
   set_wear((:TO,"wear_fun":));
}

int wear_fun(){
   if(ETO->query_highest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You can't begin to figure out how to use this coif.");
     return 0;
   }
   return 1;
}
