#include <std.h>
inherit "/d/common/obj/armour/robe.c";

void create() {
   ::create();
   set_id(({"animal skin robe","robe","patchy robe","patchy hide robe","hide robe"}));
   set_short("%^RESET%^%^ORANGE%^Animal Skin Robe%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^a patchy hide robe%^RESET%^");
   set_long("%^RED%^This robe is %^BLUE%^massive %^RED%^and shabbily-crafted, giving it a somewhat formless "
"appearance. The holes in it might have been designed for a head and arms, though it's hard to tell - the "
"craftsmanship is terrible. It appears to be made up from the %^ORANGE%^hides %^RED%^of several different "
"animals. The short vari-coloured furs from the various skins give the robe the look of a %^ORANGE%^pa"
"%^WHITE%^tc%^RED%^hw%^BOLD%^%^BLACK%^or%^RESET%^%^ORANGE%^k %^RED%^quilt.\n%^RESET%^");
   set_lore("This animal skin robe is sewn in the manner of the ogres.  The wide, uneven stitching suggests "
"that it was either an amateur or perhaps not truly one of their number who pieced the robe.  A robe such as "
"this is given to an ogre upon his coming of age, and it is always made up of the skin of animals that the "
"ogre himself has killed and eaten... raw.");
   set_property("lore difficulty",3);
   set_size(3);
}
