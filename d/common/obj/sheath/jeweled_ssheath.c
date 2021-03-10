#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

void create()
{
   ::create();
   remove_property("can_hold");
   set_property("can_hold", ({"rapier","short blades","small blades","knuckles","fan"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso","right arm","left arm","left leg","right leg"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",1);
   set_property("original_weight",1);
   set_name("small blade sheath");
   set_short("%^WHITE%^%^BOLD%^A jeweled small sheath%^RESET%^");
   set_id(({"sheath","small sheath","small sheaths","small Sheaths","small Sheath","weapsheath","jeweled sheath","small jeweled sheath"}));
   set_long("This is a weapons sheath meant for single small bladed"+
   " weapon. There are adjustable straps to hold it to your body, and"+
   " they can even be adjusted to hold it in more than one location"+
   " depending on your preference. The sheath itself is made of tanned"+
   " and hardened leather that has been dyed a dark black and has a"+
   " silver gilded tip to prevent the blade from cutting through it."+
   " The outside is beautifully decorated with several of the more"+
   " durable but very pretty gemstones. There are slivers of"+
   " %^BOLD%^%^BLACK%^dark grey hematite%^RESET%^ and studs of"+
   " %^BLUE%^dark blue lapis lazuli%^RESET%^ with its distinctive"+
   " flecks of %^YELLOW%^gold%^RESET%^. Smoky quartz has been sliced"+
   " into geometrical patterns and %^BOLD%^%^BLUE%^blue onyx%^RESET%^"+
   " and %^MAGENTA%^purple spinel%^RESET%^ studs are scattered about."+
   " Half-circles of %^GREEN%^dark green jade%^RESET%^ are found in"+
   " places, along with some %^RED%^red jasper%^RESET%^ stars. The"+
   " edges of the sheath are lined in polished studs of"+
   " %^BOLD%^%^BLACK%^onyx%^RESET%^. Most of the stones here represent"+
   " health, luck, protection, and money. They are arrayed in an"+
   " intricate pattern so that each stone is surrounded by another"+
   " color for a pretty overall effect.");
   set_value(1150);
   set_max_internal_encumbrance(10);
}
