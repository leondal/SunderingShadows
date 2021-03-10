#include <std.h>
#include "../defs.h"
inherit "/std/barkeep";

create() {
   ::create();
   set_name("ilihen");
   set_id(({"ilihen","cook","kobold cook"}));
   set_short("Ilihen, kobold cook");
   set_long("Ilihen is the same short, scaly creature as others of his kin, though he seems rather well "
"built for a kobold.  He also seems to be quite dominant over the other two here, perhaps because of his "
"size.  He has a dull rust-coloured hide, two horns upon his head, and a stumpy tail that looks as though it "
"has been cut off at some point and never regrown.  He spends much of his time behind the partition in the "
"hovel, smashing and stirring and squishing various things into what a kobold might consider food.");
   set_gender("male");
   set_alignment(9);
   set_race("kobold");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_body_type("human");
   set_class("fighter");
   set_class("thief");
   set_scrambling(1);
   set_spoken("undercommon");
   set_currency("silver");
   set_menu(
     ({"gruel","stuffed worms","rat skewer","fried batwings","water","dark brew"}),
     ({"food","food","food","food","water","alcoholic"}),
     ({5,7,10,15,2,10})
   );
   set_my_mess(({
     "You choke down the bowl of thick gruel, which leaves a rather nasty aftertaste in your mouth.\n",
     "The worms have a slimy texture, with a slight tang from the stuffed leaves, but they slide down "
"easily.\n",
     "The rat is not entirely cooked through and still juicy, with a crunchy tail.\n",
     "The fried wings are surprisingly tasty, resembling the flavour of fried fowl.\n",
     "The water has a gritty taste, like it has bits of dirt in it.\n",
     "The alcohol tastes horrible, and burns fiercely as you drink it down, but it leaves a warm feeling in "
"your stomach.\n"
   }));
   set_your_mess(({
     "forces down the bowl of thick gruel.\n",
     "eats the worms with a look of distaste.\n",
     "chews through the entire rat and crunches on the tail.\n",
     "savours the taste of the fried batwings.\n",
     "gulps down the murky water.\n",
     "slams down the mug of dark alcohol, eyes watering afterward.\n"
   }));
   set_menu_short(({
     "A bowl of thick gruel",
     "Several worms on a plate",
     "Barbequed rat on a skewer",
     "A plate of fried black wings",
     "A murky glass of water",
     "A mug of thick black liquid"
   }));
   set_menu_long(({
     "%^WHITE%^%^BOLD%^Filling this bowl is a serving of %^RESET%^%^ORANGE%^thick, sloppy gruel "
"%^WHITE%^%^BOLD%^with a somewhat unpleasant smell.  You can only imagine what might've gone into the mix "
"to make it.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^The plate is covered in several fat %^RESET%^%^MAGENTA%^caveworms%^WHITE%^%^BOLD%^.  "
"They have been stuffed with some sort of %^RESET%^%^ORANGE%^leaf%^WHITE%^%^BOLD%^, and have slimy-looking "
"skin.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^Skewered on the stick is a %^BLACK%^large rat%^WHITE%^, skinned and fried on all "
"sides.  It looks quite plump and juicy.%^RESET%^",
     "%^WHITE%^%^BOLD%^The wooden platter carries a number of small, %^BLACK%^batlike wings%^WHITE%^.  They "
"have been fried on both sides, and give off quite an appealing aroma.  These are the closest thing to a "
"delicacy in these parts.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A dirty glass of water, with a rather murky consistency.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A mug of thick %^BLACK%^black%^WHITE%^ liquid, that the creatures around here know only as 'Dark brew'.  A thick, nearly choking smell rises off the top of the drink.%^RESET%^\n"
   }));
}
