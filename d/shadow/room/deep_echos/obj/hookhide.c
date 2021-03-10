// hide made from a hook horror
#include <std.h>
inherit "/d/common/obj/armour/hide";


void create (){
  ::create();
  set_name("hookhide");
  set_value(300);
  set_short("%^RESET%^%^CYAN%^a shelled hide%^RESET%^");
  set_long("This %^CYAN%^blue%^BOLD%^%^BLACK%^-gray%^RESET%^"+
  " hide has many"+
  " pieces of shell to it.  However, the"+
  " plated shell doesn't seem added to the"+
  " hide but a part of the hide."+
  "  Whatever creature this was made from "+
  "must have been %^RED%^fearsome%^RESET%^.  The leather "+
  "is somewhat stretchable so no straps are "+
  "needed to wear it and have a snug fit."  );
  set_property("enchantment",2+random(2));
  set("lore difficulty",9);
  set_lore("Searching closely, a crest can "+
    "be found on the inside of the armor.  "+
    "it is that of a circle of malarite "+
    "hunters who roam the underdark searching"+
    " for skins to create trophies from.  \n"+
	"This hide was made from a hook horror.");
  set_item_bonus("slashing resistance",1);
}
