#include <std.h>
inherit "/d/common/obj/sheath/shieldstrap";

void create(){
   ::create();
   set_name("shield strap");
   set_short("%^WHITE%^%^BOLD%^A jeweled shield strap%^RESET%^");
   set_id(({"strap","straps","shield strap","jeweled strap","jeweled shield strap"}));
   set_long("This is a particularly exquisite version of the more simple shield"+
   " strap.  There are sturdy straps to hold it to your body, which would keep"+
   " the shield securely across your back.  The sheath itself is made of tanned"+
   " and hardened leather and has bronze gilded edges to prevent the shield from"+
   " cutting or damaging the leather itself.  The outside is beautifully"+
   " decorated with several of the more durable but very pretty gemstones."+
   " There are some sparkling pieces of multi-faceted %^YELLOW%^amber%^RESET%^"+
   " with some smaller and brighter studs of %^CYAN%^%^BOLD%^water opal%^RESET%^"+
   " nearby.  There are a few large pieces of %^WHITE%^%^BOLD%^diamond%^RESET%^"+
   " scattered about, along with some step cut pieces of %^RED%^%^BOLD%^fire"+
   " agate%^RESET%^.  Some star-shaped pieces of %^MAGENTA%^amethyst%^RESET%^ are"+
   " also found every now and then, along with some deep green %^GREEN%^emerald"+
   "%^RESET%^ studs. The brighter colors are nicely contrasted by the few subtle"+
   " pieces of %^ORANGE%^topaz%^RESET%^ and %^WHITE%^%^BOLD%^moonstone%^RESET%^,"+
   " which also help to bring out the many colors in the %^RED%^%^BOLD%^fire"+
   " agate%^RESET%^. The end result is quite beautiful.");
   set_value(1650);
   set_max_internal_encumbrance(30);
}
