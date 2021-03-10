#include <std.h>
#include "../defs.h"
inherit "/std/barkeep";

void create() {
   ::create();
   set_name("ghauntar");
   set_id(({"ghauntar","barkeep","barkeeper"}));
   set_short("%^RESET%^%^BLUE%^Ghauntar, barkeeper of the Flaming Goblin%^RESET%^");
   set_long("%^BLUE%^Ghauntar is fairly nondescript as far as drow go - another male in a city full of the "
"same.  His %^WHITE%^snowy hair %^BLUE%^is longer than most, held back in a loose ponytail.  His garments are "
"clean and well-kept but not of particularly expensive appearance, and he wears no visible jewelry.  He is "
"constantly busy here, it seems, taking orders and providing drinks to customers, as well as occasionally "
"holding quiet conversations with some of them.%^RESET%^");
   set_alignment(9);
   set_race("drow");
   set_class("thief");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("male");
   set_exp(1);
   set_scrambling(1);

   set_currency("silver");
   set_menu(
     ({"cheese and crackers","sporebread","mushroom salad","cured rothe meat","spiced sausages","water","lichen tea","mushroom ale","berdruskan dark"}),
     ({"food","food","food","food","food","water","soft drink","alcoholic","alcoholic"}),
     ({4,6,7,10,15,1,5,10,22})
   );
   set_my_mess(({
     "Crumbs fall to the ground as you crunch through the crackers and cheese.\n",
     "The bread is bland and fairly tasteless, with an odd fibrous texture.\n",
     "The mushroom salad has quite a unique texture, but nearly no flavour at all.\n",
     "The cured meat is fairly tough and chewy, but with a pleasant smoky flavour.\n",
     "You feel tears coming to your eyes at the spicy taste of the sausages.\n",
     "The water is refreshing enough, if a little stale.\n",
     "The tea, despite its rather flavorless tone, is warm and soothing nonetheless.\n",
     "The ale is particularly smooth, though rather bland in taste.\n",
     "Sweet at first on your tongue, the dark spirits burn their way down your throat as you swallow.\n",
   }));
   set_your_mess(({
     "crunches through a plate of crackers and cheese.\n",
     "eats a few slices of grainy bread.\n",
     "snacks on a bowl of salad.\n",
     "chews on strips of cured meat.\n",
     "munches through the two spiced sausages, their eyes watering.\n",
     "drains the water from the mug.\n",
     "sips from the mug of tea.\n",
     "throws back a glass of frothy ale.\n",
     "slams down a mouthful of dark spirits.\n",
   }));
   set_menu_short(({
     "%^BOLD%^%^WHITE%^A plate of %^BLACK%^crackers %^WHITE%^and %^RESET%^%^ORANGE%^rothe cheese%^RESET%^",
     "%^BOLD%^%^WHITE%^A few slices of %^RESET%^%^ORANGE%^gra%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^ny bread%^RESET%^",
     "%^BOLD%^%^WHITE%^A bowl of %^RESET%^%^GREEN%^tos%^BOLD%^s%^RESET%^%^GREEN%^ed mush%^RESET%^ro%^GREEN%^om salad%^RESET%^",
     "%^BOLD%^%^WHITE%^Strips of %^BLACK%^cured rothe meat%^RESET%^",
     "%^BOLD%^%^WHITE%^A pair of %^RESET%^%^RED%^th%^ORANGE%^i%^RED%^ck spiced sa%^BOLD%^%^BLACK%^us%^RESET%^%^RED%^ages%^RESET%^",
     "%^BOLD%^%^WHITE%^A mug of %^RESET%^%^CYAN%^clear water%^RESET%^",
     "%^BOLD%^%^WHITE%^A mug of %^RESET%^%^GREEN%^dark green tea%^RESET%^",
     "%^BOLD%^%^WHITE%^A large mug of %^RESET%^%^ORANGE%^fro%^RESET%^t%^ORANGE%^hy ale%^RESET%^",
     "%^BOLD%^%^WHITE%^A squat glass holding a nip of %^BLACK%^dark spirits%^RESET%^",
   }));
   set_menu_long(({
     "%^BOLD%^%^WHITE%^Around the edges of this small, round plate are multiple crackers made from the ground "
"remains of harvested %^RESET%^%^ORANGE%^mushrooms%^WHITE%^%^BOLD%^. In the middle rests a small, semi-solid "
"block of %^RESET%^pale rothe cheese%^BOLD%^%^WHITE%^, obviously to dip the crackers in%^WHITE%^.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Upon this flat plate are a few thick slices of %^BLACK%^dark, grainy bread%^WHITE%^.  "
"No condiments are provided with them, leaving no means to flavor the otherwise plain food.\n",
     "%^BOLD%^%^WHITE%^This high-sided round bowl is filled with all kinds of %^RESET%^%^ORANGE%^mushrooms "
"%^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^thick leafy vegetables%^BOLD%^%^WHITE%^, many of which you can't even begin to identify.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Several long strips of %^RESET%^%^RED%^cured meat%^BOLD%^%^WHITE%^, taken from the "
"rothe, the common herd animal of the underdark.%^RESET%^",
     "%^BOLD%^%^WHITE%^This pair of sausages rest upon a simple platter.  They are thick and %^BLACK%^dark-"
"skinned%^WHITE%^, and smell strongly of exotic spices.%^RESET%^",
     "%^BOLD%^%^WHITE%^A round mug of %^RESET%^%^CYAN%^water%^BOLD%^%^WHITE%^, clear but probably lukewarm."
"%^RESET%^\n",
     "%^BOLD%^%^WHITE%^A narrow mug filled with %^RESET%^%^GREEN%^dark green tea%^BOLD%^%^WHITE%^, with coils "
"of steam rising from its heated surface.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^A large, heavy mug filled with %^YELLOW%^pale, frothy ale%^WHITE%^.  It is said to be "
"made from mushrooms, as is the case with so many foods in these parts.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^In the bottom of this squat glass rests a nip of %^BLACK%^dark spirits%^WHITE%^, almost "
"black in color.  It smells extremely %^RESET%^%^RED%^strong%^BOLD%^%^WHITE%^, but carries a hint of sweetness."
"%^RESET%^\n",
   }));
}
