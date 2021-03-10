#include <std.h>
inherit "/d/common/obj/clothing/magerobe";

int cleaned;

void create() {
   ::create();
   set_name("robe");
   set_id(({"shaman robe","robe","shaman's robe","shamans robe","robe of the shaman"}));
   set_short("%^RESET%^%^BLUE%^Robe of the Shaman%^RESET%^");
   set_obvious_short("%^RESET%^%^BLUE%^a smelly blue robe%^RESET%^");
   set_long("%^CYAN%^This small, %^BLUE%^dark blue robe %^CYAN%^is lined with many tiny pockets, all of which "
"%^ORANGE%^reek %^CYAN%^with an awful stench.  Small talismans have been sewn into the fabric, everything from "
"%^WHITE%^rat skulls %^CYAN%^to %^ORANGE%^dried chicken feet%^CYAN%^, that produce quite a clamour "
"when the robe is moved.  You think perhaps you could keep some small items in the pockets, if you "
"%^YELLOW%^put item in robe%^RESET%^%^CYAN%^.  You suspect you might be able to make the garment a bit "
"more bearable if you %^YELLOW%^clean %^RESET%^%^CYAN%^it?%^RESET%^\n");
   set_lore("The small size and strange construction of this robe suggests that it was crafted by the unusual "
"creatures known as the xvarts.  They are often led by a shaman, who is generally more cunning than the rest, "
"and possesses some small knowledge of magic.  The robe's pockets are used to hold small amounts of "
"components.");
   set_property("lore difficulty",3);
   set_limbs(({"torso"}));
   set_type("clothing");
   set_weight(10);
   set_size(1);
   set_value(10);
   set_max_internal_encumbrance(10);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"remove_me":));
   cleaned = 0;
}

int wear_me() {
  if(!(int)ETO->is_class("mage") && !(int)ETO->is_class("psion") && !(int)ETO->is_class("bard") && !(int)ETO->is_class("sorcerer")) {
    tell_object(ETO,"%^BLUE%^This robe would only serve someone with arcane or psionic magic.%^RESET%^");
    return 0;
  }
  if(!cleaned) {
    tell_object(ETO,"%^ORANGE%^The tiny bones and skulls rattle together as you put on the robe.%^RESET%^");
    tell_room(EETO,"%^ORANGE%^As "+ETO->QCN+" puts on the robe, tiny bones and skulls rattle "
"together.%^RESET%^",ETO);
    return 1;
  }
  return 1;
}

int remove_me() {
  if(!cleaned) {
    tell_object(ETO,"%^YELLOW%^You finally get some peace and quiet as you slip out of the robe.%^RESET%^");
    tell_room(EETO,"%^YELLOW%^As "+ETO->QCN+" slides out of the robe, the constant clatter from the small bones "
"finally ends.%^RESET%^",ETO);
    return 1;
  }
  return 1;
}

void init() {
   ::init();
   add_action("tidy_fun","clean");
}

int tidy_fun(string str) {
   if(!objectp(TO)) return 0;
   if(!str) return notify_fail("What do you want to clean?\n");
   if(str != "robe" && str != "blue robe")
     return notify_fail("You can't clean that.\n");
   if((int)TO->query_worn())
     return notify_fail("That might be a bit difficult while you're wearing it.\n");
   if(sizeof(TP->query_attackers()) > 0)
     return notify_fail("That might be a bit difficult while you're fighting.\n");
   if(cleaned) return notify_fail("The robe has already been cleaned.\n");
   tell_object(TP,"You take a few moments to cleaning the dirt from the robe, pulling off the little trinkets.");
   tell_room(ETP,""+TP->QCN+" takes a few moments to clean the dirt from the robe, pulling off the little trinkets.",TP);
   TO->set_obvious_short("%^RESET%^%^BLUE%^a small blue robe%^RESET%^");
   TO->set_long("%^RESET%^%^CYAN%^This small, %^BLUE%^dark blue robe %^CYAN%^is "
"lined with many tiny pockets, some of which offer a %^ORANGE%^faint musty "
"smell%^CYAN%^.  A few smudges and tears mar the simple linen cloth, but "
"overall the garment seems in fairly good shape.  You think perhaps you could "
"keep some small items in the pockets, if you %^YELLOW%^put item in "
"robe%^RESET%^%^CYAN%^.%^RESET%^\n");
   set_value(15);
   cleaned = 1;
   return 1;
}
