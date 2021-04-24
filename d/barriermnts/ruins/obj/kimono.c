#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

int tracker;

void create() {
   ::create();
   set_name("kimono");
   set_id(({"kimono","silk kimono","elegant kimono","elegant silk kimono","mantle of sunsets blossoms","mantle of sunset","mantle of sunset's blossoms","mantle"}));
   set_short("%^WHITE%^%^BOLD%^Man%^MAGENTA%^t%^WHITE%^le o%^CYAN%^f%^WHITE%^ Suns%^RESET%^%^MAGENTA%^e%^WHITE%^%^BOLD%^t's Blos%^YELLOW%^s%^WHITE%^oms%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^an ele%^CYAN%^g%^WHITE%^ant si%^YELLOW%^l%^WHITE%^k kim%^MAGENTA%^o%^WHITE%^no%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This garment is made from the finest of silks, left long and flowing for the "
"comfort of the wearer.  Its sleeves are long and draped, reaching down from the wrists to flow freely.  It is "
"worn wrapped around the body and crossed at the front, to give a high neck and accentuate the wearer's "
"figure.  It is secured at the waist by a %^RESET%^%^CYAN%^wide azure sash %^WHITE%^%^BOLD%^mottled with "
"floral patterns, and tied in a bow at the back.  The kimono itself has been dyed in pastel hues of the "
"sunset, ranging from %^RESET%^%^ORANGE%^faded oranges%^WHITE%^%^BOLD%^ and %^YELLOW%^yellows%^WHITE%^, "
"through to %^MAGENTA%^dusky pink %^WHITE%^and %^RESET%^%^MAGENTA%^pale violet%^WHITE%^%^BOLD%^.  Within the "
"cloth's folds, you can see two small pockets probably designed to carry a single item each.  The garment has "
"obviously been designed with elegance in mind.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This exotic garment was once the possession of the selunite bardess Rhiannon "
"Eiryanah, reknowned as a dancer of near unearthly grace and beauty.  She was said to hail from the distant "
"southeast of Azha, in a small region known as Shintensai.  This kimono was one of her most prized belongings, "
"which she kept for performances of her famous 'Hana no Odori', or 'Dance of the Flowers'.");
   set_property("lore difficulty",21);
   set_value(4000);
   set_size(2);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_max_internal_encumbrance(21);
}

int wear_fun() {
   if(ETO->query_highest_level() < 15) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't figure out how to wear the beautiful garment.%^RESET%^");
     return 0;
   }
   if(ETO->is_class("bard")) tracker = 1;
   else { tracker = 0; }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The beautiful kimono fits you perfectly, in unmatched comfort.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" drapes the silken kimono around "+ETO->QO+"self comfortably, "
"securing it with the wide sash.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You remove the silken kimono, already missing the touch of the "
"comfortable garment.%^RESET%^");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" looks almost disappointed to remove "+ETO->QP+" "
"kimono.%^RESET%^",ETO);
   tracker = 0;
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(tracker && !random(3)) {
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+" partially extends both arms and whirls gracefully, as a "
"flurry of %^MAGENTA%^small flower petals %^WHITE%^are cast forth through the air at "+who->QCN+
"!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^You partially extend both arms and step into a gracefully whirl, "
"casting a flurry of %^MAGENTA%^small flower petals %^WHITE%^through the air at "+who->QCN+"!%^RESET%^");
     tell_object(who,"%^WHITE%^%^BOLD%^"+ETOQCN+" partially extends both arms and whirls gracefully, as a "
"flurry of %^MAGENTA%^small flower petals %^WHITE%^are cast forth through the air at you!%^RESET%^");
     who->set_paralyzed((random(5)+15),"You're still trying to reorient yourself!");
     who->set_temporary_blinded(2,"You can't see past the cloud of scattered petals!");
     return 0;
   }
   return damage;
}
