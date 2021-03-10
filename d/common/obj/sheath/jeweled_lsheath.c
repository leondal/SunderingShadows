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
   set_property("can_hold", ({"medium blades","large blades"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso","right arm","left arm","left leg","right leg"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",3);
   set_property("original_weight",4);
   set_name("large blade sheath");
   set_short("%^WHITE%^%^BOLD%^A jeweled large sheath%^RESET%^");
   set_id(({"sheath","large sheath","large sheaths","large Sheaths","large Sheath","weapsheath","jeweled sheath","large jeweled sheath"}));
   set_long("This is a weapons sheath meant for single large bladed"+
   " weapon. There are adjustable straps to hold it to your body, and"+
   " they can even be adjusted to hold it in more than one location"+
   " depending on your preference. The sheath itself is made of tanned"+
   " and hardened leather and has a bronze gilded tip to prevent the"+
   " blade from cutting through the bottom. The outside is beautifully"+
   " decorated with several of the more durable but very pretty"+
   " gemstones. There are some sparkling pieces of multi-faceted"+
   " %^ORANGE%^amber%^RESET%^ with some smaller and brighter studs of"+
   " %^YELLOW%^yellow sunstone%^RESET%^ nearby. There are a few large"+
   " pieces of %^BOLD%^%^RED%^fire opal%^RESET%^ scattered about, along"+
   " with some geometrically cut pieces of %^RED%^fire agate%^RESET%^."+
   " There are a couple pieces of %^MAGENTA%^rose quartz%^RESET%^ that"+
   " have been cut into animal shapes such as birds, wolves, horses, etc."+
   " Some crescent shaped pieces of %^BOLD%^moonstone%^RESET%^ are also"+
   " found every now and then, along with some %^BOLD%^%^CYAN%^light"+
   " blue aquamarine%^RESET%^ studs. The brighter colors are nicely"+
   " contrasted by the few subtle pieces of %^BOLD%^%^CYAN%^aquamarine%^RESET%^"+
   " and %^BOLD%^moonstone%^RESET%^, which also help to bring out the"+
   " many colors in the %^BOLD%^%^RED%^fire opal%^RESET%^. The end"+
   " result is quite beautiful.");
   set_value(1850);
   set_max_internal_encumbrance(30);
}
