#include <std.h>
inherit "/std/armour";

string owner;
int OWNED, ontracker;

void create() {
    ::create();
    set_name("mithril amulet");
    set_short("%^BOLD%^%^WHITE%^Amulet of V%^YELLOW%^e%^WHITE%^iled Int%^CYAN%^e%^WHITE%^ntions%^RESET%^");
    set_obvious_short("%^RESET%^amulet of %^BOLD%^%^WHITE%^mi%^CYAN%^t%^WHITE%^hril%^RESET%^ and %^RED%^mo%^ORANGE%^tt%^RED%^led j%^YELLOW%^a%^RESET%^%^RED%^sp%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^r%^RESET%^");
    set_id(({"amulet","chain","mithril amulet","amulet of mithril and jasper","amulet of mithril","jasper amulet"}));
    set_long("%^RESET%^This chain is made of %^BOLD%^%^WHITE%^fine mi%^CYAN%^t"
"%^WHITE%^hril%^RESET%^, forming small interlocked links that look fragile, "
"but are stronger than steel.  It supports an amulet with a flat %^BOLD%^"
"%^WHITE%^mi%^CYAN%^t%^WHITE%^hril%^RESET%^ base and minimal decoration, with "
"four claws that curve around to grip a single smooth %^RED%^o%^ORANGE%^ch"
"%^RED%^re %^RESET%^gemstone, a jasper.  The stone has been cut as a perfect "
"oval and polished smooth, but despite its flawless exterior, the base color "
"remains inconsistant throughout, flowing from a %^RED%^dull bl%^BOLD%^oo"
"%^RESET%^%^RED%^d-red %^RESET%^through to a deeper shade of %^ORANGE%^near-"
"brown%^RESET%^.  Distinctive jagged bands and mottled patches of %^BOLD%^"
"%^BLACK%^black %^RESET%^and %^ORANGE%^amb%^YELLOW%^e%^RESET%^%^ORANGE%^r "
"%^RESET%^criss-cross its surface, breaking up the dull range of %^RED%^o"
"%^ORANGE%^ch%^RED%^re %^RESET%^shades that form the basis of the stone.  The "
"amulet itself fails to give an impression of elegance, but the %^CYAN%^qu"
"%^MAGENTA%^ali%^CYAN%^ty %^RESET%^of its crafting hints to a high market "
"value regardless.\n");
    set_lore("'Unto the varieties found in cuts of Jasper, of interest is the "
"distinctively marked type known as Picture Jasper.  While most stones bear "
"bands, flow patterns, or mottled colors across their surface, those stones "
"that simultaneously display many of these effects are known to have greatly "
"enhanced protective powers from certain forms of magical discernment.  They "
"can be used to great effect in the creation of amulets and rings by which the "
"wearer's true nature is hidden from inspection.'\n\n"
"--'Upon the nature and properties of crystals', by Havarsh Ellen.");
    set_property("lore difficulty",30);
    set_property("id difficulty",30);
    set_weight(5);
    set_value(3410);
    set_type("ring");
    set_limbs(({"neck"}));
    set_ac(0);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    ontracker = 0;
}

int wearme() {
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
    if(ETO->query_level() < 35) {
      tell_object(ETO,"You are not experienced enough to use this amulet.");
      return 0;
    }
    if(OWNED && owner != (string)TP->query_name() && !avatarp(TP)) {
      tell_object(ETO,"This amulet does not belong to you!");
      return 0;
    }
    if(!OWNED && !avatarp(TP)) {
      OWNED = 1;
      owner = (string)TP->query_name();
    }
    if(!ETO->query_property("hidden alignment")) {
      tell_object(ETO,"%^RESET%^%^RED%^You feel a little more secure as the "
"amulet comes to rest over your throat.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" %^RESET%^%^RED%^looks a "
"little more self-assured.%^RESET%^",ETO);
      ETO->set_property("hidden alignment",5);
      ontracker = 1;
    }
    return 1;
}

int removeme() {
    if(ontracker) {
      tell_object(ETO,"%^RESET%^%^RED%^You look around cautiously as you take "
"off the amulet - you never know who is watching.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^RED%^"+ETO->QCN+" %^RESET%^%^RED%^removes "
+ETO->QP+" amulet and looks around cautiously.%^RESET%^",ETO);
      ETO->remove_property("hidden alignment");
      ontracker = 0;
    }
    return 1;
}

int isMagic(){ return 1; }
