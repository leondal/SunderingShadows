#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

void create()
{
   ::create();
   remove_property("can_hold");
set_property("can_hold",({"short blades","small blades","medium blades"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",2);
   set_property("original_weight",2);
   set_name("medium blade sheath");
   set_short("%^WHITE%^%^BOLD%^A jeweled medium sheath%^RESET%^");
   set_id(({"sheath","medium sheath","medium sheaths","medium Sheaths","medium Sheath","weapsheath","jeweled sheath","medium jeweled sheath"}));
   set_long("This is a weapons sheath meant for single medium-sized"+
   " bladed weapons. There are adjustable straps to hold it to your"+
   " body, and they can even be adjusted to hold it in more than one"+
   " loaction depending on your preference. The sheath itself is made"+
   " of tanned and hardened leather with a gilded tip to prevent the"+
   " blade from cutting through it. The outside is beautifully decorated"+
   " with several of the more durable but very pretty gemstones. You"+
   " recognize studs of %^BLUE%^dark blue lapis lazuli%^RESET%^ with"+
   " its distinctive flecks of %^YELLOW%^gold%^RESET%^, there is some"+
   " %^GREEN%^dark green malachite%^RESET%^ cut into various geometric"+
   " shapes, and %^BOLD%^%^GREEN%^lighter peridot%^RESET%^ studs as well."+
   " There are some carved pieces of fine %^RED%^dark red garnet%^RESET%^"+
   " and polished %^BOLD%^%^RED%^light red carnelian%^RESET%^ to"+
   " compliment it along with a few pieces of polished %^YELLOW%^yellow"+
   " topaz%^RESET%^. Rounded studs of %^MAGENTA%^amethyst%^RESET%^ and"+
   " %^BOLD%^opal%^RESET%^ are scattered about, along with some oval"+
   " shaped pieces of %^ORANGE%^tigers eye%^RESET%^. All these stones"+
   " are scattered across the sheath in an almost random pattern that"+
   " works together to well to be totally random, it is magnificent.");
   set_value(1550);
   set_max_internal_encumbrance(20);
}
