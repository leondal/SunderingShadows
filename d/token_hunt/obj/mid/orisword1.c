#include <std.h>
inherit "/d/common/obj/weapon/katana.c";

void create() {
   ::create();
   set_name("katana");
   set_id(({"katana","talon","black talon","steel katana","tsukikage's talon","tsukikage's black talon","slender katana","orisword1"}));
   set_short("%^BLACK%^%^BOLD%^Tsukikage's Black Talon%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^slender steel katana%^RESET%^");
   set_long("%^ORANGE%^This elengant weapon is four and a half feet long from tip to hilt.  It consists of a "
"single-sided, razor-sharp blade of %^WHITE%^folded steel%^ORANGE%^, polished to a %^WHITE%^%^BOLD%^brilliant "
"sheen%^RESET%^%^ORANGE%^.  The blade holds a slight curve, giving the sword a more vicious edge.  Where the "
"blade meets the hilt is a hand-guard, known as a tsuba, of %^BLACK%^%^BOLD%^blackened steel%^RESET%^%^ORANGE%^"
", where a skilled user could catch and deflect an attacker's weapon.  The hilt itself is of the same steel as "
"the blade, wrapped in %^BLACK%^%^BOLD%^braided black leather %^RESET%^%^ORANGE%^to form a comfortable grip "
"for the wielder.  The entire weapon is somewhat lighter than other blades of its size, possibly because of "
"the blade's slender width.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^This weapon was crafted and used by an ogre-mage warrior named Raiken.  While he "
"is not remembered for his skill as a warrior, he is reknowned for his skills in smithing weapons unlike any "
"other.  His greatest achievement in his craft was a pair of blades, one larger than the other, used in the "
"distinctive fighting style of his clan.  They were named as the Talon and the Fang, after the great black "
"dragon known as Tsukikage, who was revered by their clan for centuries.  Raiken himself gained the blessings "
"of their clan shaman upon the blades, and it was said that while useless alone, with both blades carried in "
"the right hands, they carried the fury of the great black dragon within them.%^RESET%^");
   set_property("lore difficulty",25);
   set_weight(6);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("reflex",1);
   set_type("slashing");
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun(){
    tell_object(ETO,"%^BLACK%^%^BOLD%^You grasp the katana's hilt in an easy grip.%^RESET%^");
    tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" grasps the katana's leatherbound hilt in an easy grip.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You release your hold on the katana's leatherbound hilt.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" releases "+ETO->QP+" hold on the slender katana.%^RESET%^",ETO);
   return 1;
}