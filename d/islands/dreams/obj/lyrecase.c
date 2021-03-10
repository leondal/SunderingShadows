//updated by ~Circe~ 10/5/19 to remove references to old gods
#include <std.h>
inherit "/d/common/obj/instruments/instrument_case.c";

void create(){
   ::create();
   set_name("ethereal case");
   set_id(({ "case", "icase","star case","ethereal case","instrument case","ethereal instrument case"}));
   set_obvious_short("%^BOLD%^%^BLUE%^An %^WHITE%^ethereal%^BLUE%^ instrument case%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^S%^CYAN%^t%^WHITE%^a%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLUE%^s%^CYAN%^i%^WHITE%^n%^RESET%^%^MAGENTA%^g%^BOLD%^%^BLUE%^e%^CYAN%^r%^WHITE%^'%^RESET%^%^MAGENTA%^s %^CYAN%^Case%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Fashioned from some %^WHITE%^ethereal%^BLUE%^ cloth, this leather case has a strange an curious look to it.  The %^WHITE%^milky white%^BLUE%^ cloth contains swirls that seems to always move, giving the cloth an every flowing look.  Motes of %^CYAN%^c%^MAGENTA%^o%^WHITE%^l%^BLUE%^o%^RESET%^%^MAGENTA%^r%^CYAN%^e%^WHITE%^d%^BOLD%^%^BLUE%^ lights can be seen in the milky cloth, fading into existance before winking out.  A %^RESET%^%^MAGENTA%^b%^BLUE%^r%^BOLD%^a%^WHITE%^i%^RESET%^%^MAGENTA%^d%^CYAN%^e%^BLUE%^d%^BOLD%^ silk strap is attached to the cloth, allowing for the wearer to sling the case over their shoulder.  The silk strap is trimmed with hollow %^WHITE%^silver%^BLUE%^ star shapes that chime rhythmically as the wearer moves about.%^RESET%^"); 
   set_value(4000);
   set_weight(4);
   set_lore("This famous instrument case was said to have once housed Miiriam Starsinger's famous lyre.  The cloth case is woven from moonfire threads it is said, giving it its etheral apperance.  The case was given to Miiriam Starsinger when the faith of Lysara rewarded her with her lyre.  Miiriam had aided the faith in locating one of the famous Silverstar Ring, a holy relic to the faith of Lady Graymantle.");
   set_property("lore difficulty",20);
}

int isMagic(){ return 1; }