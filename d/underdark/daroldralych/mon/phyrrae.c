#include <std.h>
#include "../defs.h"
inherit "/std/barkeep";

void create() {
   ::create();
   set_name("phyrrae");
   set_id(({"phyrrae","barkeep","barkeeper"}));
   set_short("%^RESET%^%^BLUE%^Phyrrae Desphrayl, innkeeper of the Black Eclipse%^RESET%^");
   set_long("%^MAGENTA%^The innkeeper here, Phyrrae, is particularly well dressed, as befits an establishment "
"such as hers.  Delicate %^BOLD%^%^BLACK%^ebony combs %^RESET%^%^MAGENTA%^are the only restraint to her "
"%^RESET%^cropped white hair%^MAGENTA%^, held back from her face, yet too short even to reach her shoulders. "
" Her %^BLUE%^dark garments %^MAGENTA%^are clean and plain, yet elegant in their simplicity, with their closed "
"neckline and sleeves obviously quite sensible for work.  She has steady hands and a clear-headed, sensible "
"demeanor that is distinctly expressed through each of her actions.%^RESET%^");
   set_alignment(9);
   set_race("drow");
   set_class("warrior");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
   set_exp(1);

   set_currency("gold");
   set_menu(
     ({"grilled aboleth","raw pyrimo","rothe steak","seafood platter","crushed bloodfruit ice","water","herbal tea","black coffee","morimatra","luurden wine"}),
     ({"food","food","food","food","food","water","soft drink","caffeine","alcoholic","alcoholic"}),
     ({35,50,20,25,15,3,10,25,25,75})
   );
   set_my_mess(({
     "The grilled fish has a mild salty flavor, and a pleasant texture that crumbles in your mouth.\n",
     "The hot sauce forms a bold counterpart to the surprisingly sharp flavor of the raw fish, leaving your tongue tingling.\n",
     "The steak is thick and juicy, and cooked to perfection.\n",
     "The platter of seafood provides a pleasant variety of tastes and textures.\n",
     "Your mouth is chilled by the touch of the sweet-flavored ice.\n",
     "The water is cool and refreshing.\n",
     "You can't help but sigh as the tea warms your body, and the light spices soothe your senses.\n",
     "Alertness rushes through you as the bitter coffee kicks in.\n",
     "The dark wine has a pleasant taste, and leaves spiced hints of flavour upon your tongue.\n",
     "Each sip of the dusky wine washes your tastebuds with its rich fruity flavor, and you can't help but feel a little lightheaded.\n",
   }));
   set_your_mess(({
     "seems pleasantly surprised by the taste of the grilled fish.\n",
     "daintily picks at the slices of raw pyrimo, dipping some in the accompanying sauce.\n",
     "tears hungrily into the thick steak.\n",
     "takes samples of the different types of seafood from the platter.\n",
     "inhales sharply at the chill as they take a scoop from the icy dessert.\n",
     "lifts the glass and drains the sparkling water from it.\n",
     "sips their tea with a pleased sigh.\n",
     "drinks from a mug of steaming liquid and looks invigorated.\n",
     "slowly drains the glass of dark wine.\n",
     "sips from the wineglass, and a small hint of a grin tugs at their features.\n",
   }));
   set_menu_short(({
     "%^BOLD%^%^WHITE%^A serving of %^BLACK%^grilled %^WHITE%^fish%^RESET%^",
     "%^BOLD%^%^WHITE%^A plate of %^RESET%^sliced raw fish %^BOLD%^%^WHITE%^accompanied by a %^RED%^spicy sauce%^RESET%^",
     "%^BOLD%^%^WHITE%^A sizeable portion of %^RESET%^%^RED%^seared steak %^BOLD%^%^WHITE%^upon a bed of %^GREEN%^reeds%^RESET%^",
     "%^BOLD%^%^WHITE%^A platter of assorted %^BLUE%^seafood%^RESET%^",
     "%^BOLD%^%^WHITE%^A flattened glass set with a heaping of %^CYAN%^crushed ice%^RESET%^",
     "%^BOLD%^%^WHITE%^A glass of %^CYAN%^sparkling water%^RESET%^",
     "%^BOLD%^%^WHITE%^A mug of %^BLACK%^inky-black tea%^RESET%^",
     "%^BOLD%^%^WHITE%^A cup of %^RESET%^%^ORANGE%^steaming coffee%^RESET%^",
     "%^BOLD%^%^WHITE%^A glass of %^BLACK%^dark spiced wine%^RESET%^",
     "%^BOLD%^%^WHITE%^A glass of %^RESET%^%^MAGENTA%^dusky violet wine%^RESET%^",
   }));
   set_menu_long(({
     "%^BOLD%^%^WHITE%^Upon this plate lies a %^BLACK%^grilled %^WHITE%^length of what appears to be fish, "
"garnished with tiny flakes of %^RESET%^%^GREEN%^chopped green reeds%^BOLD%^%^WHITE%^.  The meat comes from a "
"fish-like creature known as an aboleth, a dangerous enemy of the drow, and can be quite expensive for the "
"rarety at which it can be acquired.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^This platter is set decoratively, surrounded by carefully-cut pieces of %^RESET%^"
"%^MAGENTA%^raw fish %^BOLD%^%^WHITE%^known as Pyrimo.  The central bowl holds a %^RED%^spicy sauce %^WHITE%^"
"fermented from a special kind of lichen, which has been added as a condiment for the equally rare and "
"expensive fish that it accompanies.  Pyrimo are highly %^GREEN%^poisonous %^WHITE%^fish, and it takes precise "
"preparation techniques to ensure that the meat is not still deadly upon consumption.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Settled on a bed of %^GREEN%^vibrant green reeds%^WHITE%^ lies this sizeable portion of "
"steak, which has been %^RED%^seared %^WHITE%^to perfection on both sides, while remaining soft and %^RESET%^"
"%^RED%^tender %^BOLD%^%^WHITE%^in the centre.  It has been taken from the rothe, an underdark beast compared "
"by many to the cow of the surface.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Upon the oval platter before you rests an assortment of %^BLUE%^seafood%^WHITE%^, "
"primarily shellfish of varied kinds.  You can recognize the %^RESET%^%^ORANGE%^crumbed rings %^BOLD%^%^WHITE%^"
"of some kind of squid, as well as pieces of lightly cooked %^RESET%^%^RED%^crab %^BOLD%^%^WHITE%^and %^BLACK%^"
"crayfish %^WHITE%^meat, some of the tinier species still encased within their shells.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Within the curve of a broad, flattened glass rests a heaping of %^CYAN%^crushed ice"
"%^WHITE%^.  A gentle %^MAGENTA%^rosy hue %^WHITE%^suffuses its crystalline substance, as it offers up a sweet "
"and fruity scent to the air.\n%^RESET%^",
     "%^BOLD%^%^WHITE%^A %^CYAN%^sparkling %^WHITE%^glass of water, cool and clear.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^This round mug of tea is %^RESET%^%^RED%^warm %^BOLD%^%^WHITE%^to the touch, and "
"carries an %^BLACK%^inky-black %^WHITE%^liquid that steams gently.  It carries an inviting aroma that "
"%^RESET%^%^GREEN%^soothes %^BOLD%^%^WHITE%^your senses.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^A %^RESET%^%^ORANGE%^dark brown liquid %^BOLD%^%^WHITE%^lies within this cup, hot "
"enough that a %^RESET%^light steam %^BOLD%^%^WHITE%^rises from its surface.  Even a slight whiff of its thick"
", heady scent invigorates your senses.  This drink is known upon the surface as %^BLACK%^coffee%^WHITE%^, and "
"is most likely imported from the realms above.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^This slender glass has been filled with spiced wine known to the drow as Morimatra, so "
"dark as to seem nearly %^BLACK%^black%^WHITE%^.  The gentle aroma of %^RESET%^%^ORANGE%^spices %^BOLD%^"
"%^WHITE%^wafts upwards from its surface.%^RESET%^\n",
     "%^BOLD%^%^WHITE%^Within this delicate glass swirls a wine of a %^RESET%^%^MAGENTA%^deep velvety purple"
"%^BOLD%^%^WHITE%^.  This rich and potent alcohol is known to the drow as Luurden wine.  Made from the fruit "
"of a rare underdark tree of the same name, it is highly prized among drow society, and is known to have mild "
"%^RESET%^%^CYAN%^hal%^GREEN%^lu%^CYAN%^cin%^MAGENTA%^oge%^CYAN%^nic %^BOLD%^%^WHITE%^properties.%^RESET%^\n",
   }));
}
