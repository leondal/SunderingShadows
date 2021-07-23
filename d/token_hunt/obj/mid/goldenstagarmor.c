#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create(){
	::create();
	set_name("golden armor");
	set_id(({ "armor", "golden armor", "platemail", "plate", "plate mail" }));
	set_short("%^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den P%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^YELLOW%^te %^BLACK%^o%^YELLOW%^f t%^RESET%^%^ORANGE%^h%^YELLOW%^e S%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^YELLOW%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a suit of %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den %^RESET%^%^ORANGE%^armor%^RESET%^");
	set_long("%^ORANGE%^This armor is forged from %^YELLOW%^golden sheets of metal %^RESET%^%^ORANGE%^that shine with an almost divine light.  Across the "
"breastplate of this magnificent suit is a heraldic stag, portrayed in a deeper, richer %^YELLOW%^o%^BLACK%^c%^YELLOW%^her %^RESET%^%^ORANGE%^then the golden "
"metal.  The stag stands rampant with both forehooves flailing in the air.  His head is thrown back and the full rack of horns glitter with tiny %^RED%^rubies "
"%^ORANGE%^set at the tips, giving them a blood like glint.  Circling the stag and running across the shoulder guards and back plate, a network of "
"%^GREEN%^emerald vines %^ORANGE%^are traced and studded with tiny %^MAGENTA%^amethyst %^ORANGE%^and %^WHITE%^pearl%^ORANGE%^ roses, which only help add to "
"the stunning display.  All of which is backed by the most supple of leather.  Its golden luster adding to the allure of the suit and its golden majesty.%^RESET%^");
	set_weight(50);
   set_value(0);
	set_lore("%^RED%^Recounted from an ancient journal:%^RESET%^ It was dawn when the battle commenced.  As though the subtle lifting of the veil of darkness "
"had turned a switch upon the spirits of the warriors below and they, in turn filled the shells of their bodies with fire and drive to combat their enemies.  "
"There was barely any light, and yet the clang of steel, the scream of voices and the cries of death filled the silent air till there was only the blaze of morning "
"light and the cacophony of battle.  And deep within that flesh and steel tide stood the lone warrior.  The General Ta'marni, the Golden Stag.  All around him, the "
"followers of Dresttel fell into the glow of his power and were snuffed out like so many candles, even before the mighty sword Akarel found its place in their hearts.");
	set_property("lore difficulty",23);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("spell damage resistance",20);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_func(){
	tell_object(ETO,"%^YELLOW%^An aura of warmth and belonging fills you as you dawn this suit of armor and marvel at how well it fits.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^YELLOW%^Regret fills you that you must remove this suit of armor.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 200){
	tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^As "+who->QCN+"'s blow is landed, the scent of %^RED%^roses %^WHITE%^lifts into the air and "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^shimmers with light.  From out of the metal, %^GREEN%^emerald vines %^WHITE%^grow rapidly, their %^BLACK%^thorn %^WHITE%^and %^RED%^rose %^WHITE%^covered lengths, twining about "+who->QCN+"'s limbs and tangling them in the swirl of new life!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^As "+who->QCN+"'s blow is landed, the scent of %^RED%^roses %^WHITE%^lifts into the air and your "+query_short()+" %^BOLD%^%^WHITE%^shimmers with light.  From out of the metal, %^GREEN%^emerald vines %^WHITE%^grow rapidly, their %^BLACK%^thorn %^WHITE%^and %^RED%^rose %^WHITE%^covered lengths, twining about "+who->QCN+"'s limbs and tangling them in the swirl of new life!%^RESET%^");
	tell_object(who,"%^BOLD%^%^WHITE%^As your blow is landed, the scent of %^RED%^roses %^WHITE%^lifts into the air and "+ETOQCN+"'s "+query_short()+" %^BOLD%^%^WHITE%^shimmers with light.  From out of the metal, %^GREEN%^emerald vines %^WHITE%^grow rapidly, their %^BLACK%^thorn %^WHITE%^and %^RED%^rose %^WHITE%^covered lengths, twining about your limbs and tangling you up in the swirl of new life!%^RESET%^");
		who->set_paralyzed(roll_dice(1,6));
return damage;	}
}