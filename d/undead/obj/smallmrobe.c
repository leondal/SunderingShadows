#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("golden robe");
	set_id(({ "robe", "golden robe", "dragon robe", "topaz robe","flowing robe" }));
	set_short("%^YELLOW%^G%^RESET%^%^ORANGE%^o%^RED%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n R%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^b%^YELLOW%^e %^RESET%^%^RED%^o%^YELLOW%^f t%^BLACK%^h%^YELLOW%^e R%^RED%^i%^BLACK%^s%^RESET%^%^RED%^i%^ORANGE%^n%^YELLOW%^g D%^BLACK%^r%^RESET%^%^RED%^a%^ORANGE%^g%^BOLD%^%^RED%^o%^YELLOW%^n%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a flowing %^YELLOW%^g%^RESET%^%^ORANGE%^o%^RED%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n %^RESET%^%^ORANGE%^robe%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This long, flowing robe is made of a blend of cotton and linen that takes on a deep "
"%^YELLOW%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^p%^YELLOW%^az %^RESET%^%^ORANGE%^coloration in any light whatsoever.  "
"Extremely comfortable and lightweight, the long robes are loose in fit, with several folds.  A few of which might be "
"made in such a way that small items could be hidden amongst them.  Plain appearing from the front, except for the ornate "
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^d %^RESET%^%^ORANGE%^buttons, the back is covered in a "
"majestic image of a %^RED%^d%^BOLD%^r%^RESET%^%^MAGENTA%^a%^RED%^g%^BOLD%^o%^RESET%^%^RED%^n %^ORANGE%^caught in flight"
".  Its wings spread, its tail streaming out behind it, the dragon seems almost alive as it swoops through the %^BOLD%^"
"%^CYAN%^a%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^r%^RESET%^%^ORANGE%^.  The craftsmanship on this embroidered image is so "
"detailed you can almost see the gusts of %^WHITE%^w%^BOLD%^%^WHITE%^i%^BLUE%^n%^RESET%^%^WHITE%^d %^ORANGE%^curling "
"about the dragon in flight.%^RESET%^\n");
	set_weight(5);
	set_value(4000);
	set_lore("Some claim that there are two strands of magic that flow in the world.  Both touch upon the weave, but "
"in different ways.  These followers of the twin paths, claim that the dragons learned a magic different from the elven "
"high-art from which much magic is traced.  However these followers also point to the similarities between draconic and "
"arcana and say that these guttural words are actually forms of dragon magic.  That humans have blended the two together "
"into a poor substitution of true power and it is this reason that draconica and high-art have faded from the world.  "
"Followers of the twin paths strive to separate the two powers back into their pure form, in an effort to restore true "
"magic to the world.  Many dress in ornate garments that symbolize the core of these efforts. Majestic dragons or images "
"of sweeping vistas often decorate their clothing, helping them identify one another and the paths they study.");
	set_property("lore difficulty",20);
	set_max_internal_encumbrance(21);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(1);
	set_property("enchantment",3);
      while (query_property("enchantment") != 3) {
        remove_property("enchantment");
        set_property("enchantment",3);
      }
      set_item_bonus("magic resistance",1);
      set_item_bonus("sight bonus",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
      if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
        tell_object(ETO,"You have not earned the right to make use of this item.");
        return 0;
      }
      if(!TP->is_class("bard") && !TP->is_class("psion") && !TP->is_class("mage")) {
        tell_object(ETO,"The magic within these robes prevents you from wearing them.");
        return 0;
      }
      if((int)ETO->query_highest_level() < 25) {
        tell_object(ETO,"The robe refuses to be worn by one as weak as you.");
        return 0;
      }
	tell_room(EETO,"%^YELLOW%^"+ETOQCN+" wraps the golden robe about "+ETO->QP+" shoulders with a fluid easy movement"
".%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^The golden robe wraps about your shoulders in a fluid swirl of glittering fabric"
".%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(EETO,"%^YELLOW%^"+ETOQCN+" slips the golden fabric of "+ETO->QP+" robe off.%^RESET%^",ETO);
	tell_object(ETO,"%^YELLOW%^The fabric slips from your shoulders in a spill of golden fabric.%^RESET%^");
	return 1;
}