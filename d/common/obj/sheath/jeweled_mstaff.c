#include <std.h>
inherit "/d/common/obj/sheath/sheath_inherit";

mixed query_property(string str) { return ::query_property(str); }

void create()
{
   ::create();
   remove_property("can_hold");
set_property("can_hold", ({"small staff","spear","tool","staff of sorrow","staff"}));
   remove_property("can_wear_limbs");
   set_property("can_wear_limbs",({"waist","torso"}));
   remove_property("sheath_size");
   remove_property("original_weight");
   set_property("sheath_size",2);
   set_property("original_weight",2);
   set_name("medium weapon sleeve");
   set_short("%^WHITE%^%^BOLD%^A jeweled medium weapon sleeve%^RESET%^");
   set_id(({"sleeve","medium weapon sleeve","medium sleeve","weapon sleeve","jeweled sleeve","jeweled weapon sleeve","medium jeweled sleeve","medium jeweled weapon sleeve"}));
   set_long("This is a sleeve-type casing suitable for long weapons"+
   " such as staves and spears. It is a long tube made of sturdy tanned"+
   " leather with a closed bottom that has been gilded with steel to"+
   " prevent the weapon from sliding out. It has adjustable straps to"+
   " hold it on your body. Several semi-precious stones have been added"+
   " onto the leather tube, held in place by silver or gold settings."+
   " There are several large, diamond shaped pieces of"+
   " %^YELLOW%^sunstone%^RESET%^ that are held with gold settings, along"+
   " with some %^ORANGE%^orange topaz%^RESET%^ and %^BOLD%^%^RED%^light"+
   " carnelian%^RESET%^ circles. Most of the other stones are held in"+
   " silver settings. There are several large pieces of geometrically"+
   " cut %^BOLD%^%^GREEN%^tourmaline%^RESET%^, some %^CYAN%^blue"+
   " moonstone %^RESET%^ crescents, a few long slivers of"+
   " %^BLUE%^lapis lazuli%^RESET%^ with its distinctive %^YELLOW%^gold%^RESET%^"+
   " flecks, and some rectangular pieces of %^MAGENTA%^purple"+
   " spinel%^RESET%^. All this combines for a beautiful mixture of"+
   " colors and shapes.");
   set_value(2175);
   set_max_internal_encumbrance(20);
}
