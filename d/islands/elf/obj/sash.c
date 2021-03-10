#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
   ::create();
   set_name("dusk sash");
   set_id(({"sash","dusk sash","tattered sash"}));
   set_obvious_short("%^MAGENTA%^tattered sash%^RESET%^");
   set_short("%^MAGENTA%^dusk sash%^RESET%^");
   set_lore("%^MAGENTA%^The pattern on this sash is elven."+
   "  However, the style is not current at all."+
   "  If this sash is as old as it looks it should "+
   "have worn to dust ages ago.  The will of the wearer "+
   "put magic into her clothing causing it to endure as if"+
   " her despair would not let her rest.%^RESET%^");
   set_property("lore difficulty",30);
   set_long("This is a silky sash that is a deep shade of purple."+
   "  It seems ancient.  The pattern looks terribly torn.  The "+
   "edges are frayed.  However, it seems to glow with a "+
   "strong magic.  It is almost as if the sash has a will"+
   " of its own that defies the forces of time and entropy.");
   set_size(-1);
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",4);
   set_item_bonus("craft, tailor",2);
}
int wear_me(){ 
  tell_object(ETO,"%^MAGENTA%^You wrap the sash around you and feel so alone...");
  return 1;
}
