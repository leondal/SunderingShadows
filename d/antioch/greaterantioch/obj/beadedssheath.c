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
   set_property("can_hold", ({"small blades"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso","right arm","left arm","left leg","right leg"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",1);
   set_property("original_weight",4);
   set_name("small blade sheath");
   set_short("%^RESET%^%^ORANGE%^A small %^BOLD%^%^YELLOW%^be%^BOLD%^%^CYAN%^ad%^BOLD%^%^BLUE%^ed %^RESET%^%^ORANGE%^leather sheath%^RESET%^");
   set_id(({"sheath","small sheath","small sheaths","small Sheaths","small Sheath","weapsheath","leather sheath","small leather sheath"}));
   set_long("%^RESET%^This is a weapons sheath meant for single small bladed"+
   " weapon. There are adjustable straps to hold it to your body, and"+
   " they can even be adjusted to hold it in more than one location"+
   " depending on your preference. The sheath itself is made of tanned"+
   " and hardened %^RESET%^%^ORANGE%^leather %^RESET%^and has a hard tip to prevent the"+
   " blade from cutting through the bottom. The outside is beautifully"+
   " decorated with several %^BOLD%^%^BLUE%^be%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLUE%^ds"+
   " %^RESET%^made out of polished %^BOLD%^%^WHITE%^bone%^RESET%^. The beads"+
   " make patterns of animals, weapons and other %^RESET%^%^RED%^tribal %^RESET%^themes.");
   set_value(1050);
   set_max_internal_encumbrance(30);
}
