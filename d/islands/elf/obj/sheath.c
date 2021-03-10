#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

int query_size() {
   int possible_size;
   possible_size = ::query_size();
   if (possible_size == 1)
      return 2;
   else
      return possible_size;
}

void create()
{
   ::create();
   remove_property("can_hold");
   set_property("can_hold", ({"small blades","medium blades"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso","right arm",
   "left arm","left leg","right leg"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",3);
   set_property("original_weight",4);
   set_name("large blade sheath");
   set_short("%^RESET%^%^ORANGE%^A medium w%^CYAN%^o%^ORANGE%^o%^CYAN%^d%^ORANGE%^en sheath%^RESET%^");
   set_id(({"sheath","medium sheath","medium sheaths",
   "medium Sheaths","medium Sheath","weapsheath","wooden sheath",
   "wood sheath"}));
   set_long("%^ORANGE%^This is a wooden weapon's sheath sized for a "+
   "medium bladed weapon. It has several %^CYAN%^silk straps%^ORANGE%^ to "+
   "adjust it to different limbs.  The sheath itself it "+
   "stained a %^CYAN%^dark brown%^ORANGE%^ and has several words inscribed "+
   "upon it.  The top and bottom have a tip of %^CYAN%^silver%^ORANGE%^ to"+
   " decorate either end.%^RESET%^"  );
   set_value(1050);
   set_max_internal_encumbrance(30);
   set_read("Protect Tel-Quessir.  This is Corellon Larethian's will.");
   set_language("elven");
}