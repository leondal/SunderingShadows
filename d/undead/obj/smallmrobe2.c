#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("silver robe");
	set_id(({ "robe", "silver robe", "dragon robe", "flowing robe"}));
	set_short("%^BOLD%^%^WHITE%^S%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^e%^RESET%^r %^BOLD%^%^WHITE%^R%^BLACK%^o%^RESET%^b%^BOLD%^%^WHITE%^e %^BLACK%^o%^RESET%^f %^BOLD%^%^WHITE%^t%^BLACK%^h%^RESET%^e %^BOLD%^%^WHITE%^L%^BLACK%^i%^RESET%^v%^BOLD%^%^WHITE%^i%^BLACK%^n%^RESET%^g %^BOLD%^%^WHITE%^W%^BLACK%^o%^RESET%^r%^BOLD%^%^WHITE%^l%^BLACK%^d%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a flowing %^WHITE%^s%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^ver %^BLACK%^robe%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This long, flowing robe is made of a blend of cotton and linen that takes on a rich "
"%^WHITE%^s%^BLACK%^i%^RESET%^l%^BOLD%^%^WHITE%^ver %^BLACK%^coloration in any light whatsoever. Extremely comfortable "
"and lightweight, the long robes are loose in fit, with several folds. A few of which might be made in such a way that "
"small items could be hidden amongst them. Plain appearing from the front, except for the ornate %^WHITE%^h%^BLACK%^e"
"%^RESET%^m%^BOLD%^%^BLACK%^at%^WHITE%^i%^RESET%^t%^BOLD%^%^WHITE%^e %^BLACK%^buttons, the back is covered in a majestic "
"image of a %^RESET%^%^ORANGE%^ro%^GREEN%^ll%^CYAN%^in%^BOLD%^%^BLACK%^g l%^RESET%^%^CYAN%^an%^GREEN%^ds%^ORANGE%^cape"
"%^BOLD%^%^BLACK%^. Vast %^RESET%^%^CYAN%^seas %^BOLD%^%^BLACK%^give way to sweeping %^RESET%^%^GREEN%^plains %^BOLD%^"
"%^BLACK%^and %^RESET%^%^ORANGE%^hills %^BOLD%^%^BLACK%^that rise toward tall %^WHITE%^snowcapped%^BLACK%^ mountains at "
"the base of the robe. The craftsmanship on this embroidered image is so detailed you can almost see the %^RESET%^"
"%^CYAN%^w%^GREEN%^a%^BLUE%^v%^CYAN%^es %^BOLD%^%^BLACK%^rolling toward the shore.%^RESET%^\n");
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
      if((int)ETO->query_highest_level() < 25) {
        tell_object(ETO,"The robe refuses to be worn by one as weak as you.");
        return 0;
      }
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" wraps the %^WHITE%^silver robe %^BLACK%^about "+ETO->QP+" shoulders "
"with a fluid easy movement.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^silver robe %^BLACK%^wraps about your shoulders in a fluid swirl "
"of glittering fabric.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slips the %^WHITE%^silver fabric %^BLACK%^of "+ETO->QP+" robe off"
".%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The fabric slips from your shoulders in a spill of %^WHITE%^silver fabric"
"%^BLACK%^.%^RESET%^");
	return 1;
}
