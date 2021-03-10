#include <std.h>
#include <move.h>
inherit "/d/common/obj/sheath/sheath_inherit";
inherit "/d/common/obj/armour/mshield";

void create(){
   ::create();
   set_name("steel shield");
   set_id(({"shield","steel shield","embossed shield","embossed steel shield","temperance","Temperance"}));
   set_short("%^BOLD%^%^BLACK%^Te%^RESET%^mp%^BOLD%^%^WHITE%^er%^RESET%^an%^BOLD%^%^BLACK%^ce%^RESET%^");
   set_obvious_short("%^RESET%^em%^RESET%^b%^BOLD%^%^BLACK%^os%^RESET%^s%^BOLD%^%^WHITE%^ed s%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^WHITE%^l s%^RESET%^h%^BOLD%^%^BLACK%^ie%^RESET%^l%^BOLD%^%^WHITE%^d%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This shield forms a perfect convex circle, except for the scalloped indentation that dips "
"gradually across the top quarter.  The face of the shield itself is a single thin sheet of %^BLACK%^gl%^RESET%^e%^BOLD%^"
"%^BLACK%^aming st%^RESET%^e%^BOLD%^%^BLACK%^el%^WHITE%^ emblazoned with the crest of a hawk, its wings spread and its "
"mouth open in a silent %^RED%^scream%^WHITE%^.  Its base frame is of solid poplar, pale and lightweight and polished to a "
"fine finish.  Several struts have been spaced across the back for support.  A sturdy strap of %^RESET%^%^ORANGE%^leather "
"%^BOLD%^%^WHITE%^has been secured across the thickest crosspiece, allowing space for an arm to pass through and hold the "
"shield aloft.  Oddly, another section of treated leather has been secured to the back, shaped much like a sheath for a "
"blade, and bearing the same catches as a normal sheath would have to keep it from slipping out.%^RESET%^\n");
   set_value(2670);
   set_weight(10);
   set_type("shield");
   set_limbs(({ "right hand" }));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({ "right hand" }));
   remove_property("original_weight");
   set_property("original_weight",10);
   remove_property("repairtype");
   set_property("repairtype",({ "armorsmith" }));
   remove_property("can_hold");
   set_property("can_hold",({ "gladius" }));
   set_ac(1);
   set_armor_prof("shield");
   set_block_chance(25);
   set_size(-1);
   set_lore("%^WHITE%^%^BOLD%^This shield bears the hawk crest of the Farracett house, a noble family of the "
"Zin'Charu.  Among their people they were considered unusual, as they gave equal respect both to magical and physical "
"prowess, while the Zin'Charu as a whole greatly favored arcane pursuits.  This gave rise, however, to their distinct "
"reputation as fearsome combatants, for where their spells failed them, their weaponmasters would enter the fray and "
"contend with difficult targets.  They tended to favor a particularly defensive style of combat that involved defense by "
"both spell and shield until at close range with a foe, at which point they would draw their short blades to contend with "
"them directly.  Such blades were kept within a specialized sheath upon the back of the shield, so as always to be within "
"easy reach.%^RESET%^\n");
   set_property("lore difficulty",27);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO, "remove_fun":));
}

int wear_fun() {
    int toenchant;
    if(userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(userp(ETO) && (int)ETO->query_level() < 21) {
      tell_room(ETO,"%^BOLD%^You must train further before you can attempt to use armor of this calibre.%^RESET%^");
      return 0;
    }
    tell_room(EETO,"%^BOLD%^%^WHITE%^The shield settles securely into place.%^RESET%^");
    toenchant = (int)ETO->query_level()/7;
    if(toenchant > 5) toenchant = 5;
    while((int)query_property("enchantment") != toenchant) {
      remove_property("enchantment");
      set_property("enchantment",toenchant);
    }
    return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BOLD%^%^WHITE%^You lift the shield from your arm and set it aside, already feeling vulnerable.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" lifts the shield from "+ETO->QP+" arm and sets it aside.%^RESET%^",ETO);
   remove_property("enchantment");
   return 1;
}

int item_allowed(object item) {
   if(!objectp(item)) return 0;
   if(base_name(item) != "/d/laerad/dojo/obj/gladius") {
     write("This shield would only ever hold a very specific kind of sword!\n");
     return 0;
   }
   if(sizeof(all_inventory(TO)) > 0) {
     write("There's already a sword there!\n");
     return 0;
   }
   return 1;
}