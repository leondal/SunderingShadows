#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

void create()
{
   ::create();
   remove_property("can_hold");
   set_property("can_hold", ({"small axe","medium axe","mace","flail","small clublike","medium clublike","small hammer","medium hammer","whip"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",2);
   set_property("original_weight",2);
   set_name("medium weapon holster");
   set_short("%^WHITE%^%^BOLD%^A jeweled medium weapon holster%^RESET%^");
   set_id(({"holster","medium holster","Medium holster","medium weapon holster","jeweled holster","jeweled weapon holster","medium jeweled holster","jeweled medium weapon holster","medium jeweled weapon holster"}));
   set_long("This is a holster suitable for a variety of medium sized"+
   " weapons. A strip of gray leather six inches in width forms an"+
   " open-bottomed sheath for the handle, making it suitable for weapons"+
   " such as axes, hammers, and others with a straight handle or head"+
   " larger than the handle. There are soft adjustable straps in matching"+
   " gray to hold it to your body. Several small semi-precious stone"+
   " beads have been sewn onto the leather adjustable strap and weapon"+
   " loop with %^BOLD%^silver thread%^RESET%^. You notice some"+
   " %^BOLD%^%^CYAN%^turquoise triangles%^RESET%^, %^GREEN%^malachite"+
   " stars%^RESET%^, %^CYAN%^topaz circles%^RESET%^, and"+
   " %^BOLD%^moonstone crescents%^RESET%^ line the loop of the weapon."+
   " The adjustable strap has alternating beads of %^BOLD%^%^GREEN%^moss"+
   " agate%^RESET%^ and %^BLUE%^%^BOLD%^blue onyx%^RESET%^ running down"+
   " either side. In the center there are several beads woven in a"+
   " pattern of networking %^BOLD%^silver%^RESET%^. You recognize"+
   " %^YELLOW%^sunstone%^RESET%^, %^BOLD%^%^MAGENTA%^rose quartz%^RESET%^,"+
   " %^MAGENTA%^amethyst%^RESET%^, and %^BOLD%^%^RED%^red spinel%^RESET%^."+
   " The pattern is quite lovely in its intricacies.");
   set_value(780);
   set_max_internal_encumbrance(20);
}
