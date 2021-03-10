#include <std.h>
inherit "/std/ammo";

void create()
{
   ::create();
   set_name("arrows");
   set_short("A quiver of feathered arrows");
  set_id(({"longbow arrows","larrows","missiles","arrows","longbow arrow","quiver","feathered arrows","feathered arrow","quiver of feathered arrows"}));
   set_long("This is a quiver of flight arrows that have all been decorated"+
   " with feathers of varying colors, some of them bright red while others"+
   " are blue or a plain brown. The arrows themselves seem well made.");
   set_shots(30);
   set_wc(1,8);
   set_large_wc(1,8);
   set_ammo_type("longbow arrow");
   set_wield("%^BOLD%^The finely crafted bow fits nicely in your hands.");
   set_unwield("With some reluctance you release the bow.");
}
int is_arrows(){return 1;}
