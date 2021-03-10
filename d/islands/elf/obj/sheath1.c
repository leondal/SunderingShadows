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
   set_name("bone sheath");
   set_short("%^RESET%^B%^BOLD%^%^BLACK%^o%^RESET%^ne Sh%^BOLD%^%^BLACK%^e%^RESET%^ath%^RESET%^");
   set_id(({"sheath","medium sheath","medium sheaths",
   "medium Sheaths","medium Sheath","weapsheath","bone sheath"}));
   set_long("This is bone sheath sized for medium and small blades."+
   "  It is looks like a hollowed out leg bone.  There is a slim"+
   " leather band to attach it to a limb with a latch to secure it"+
   " in place.  There is a small bit of writing on the inside"+
   " of the sheath one could read."  );
   set_value(1050);
   set_max_internal_encumbrance(30);
   set_read("Death is not the end.");
   set_language("elven");
}