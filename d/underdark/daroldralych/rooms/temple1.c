#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Temple antechamber");
   set_short("%^MAGENTA%^Temple antechamber%^RESET%^");
   set_long("%^MAGENTA%^Temple antechamber%^RESET%^\n"
"%^BOLD%^%^BLACK%^Around you rise four intimidating %^RESET%^%^RED%^spider st%^MAGENTA%^at%^RED%^ues%^BOLD%^%^BLACK%^, "
"alternatively crouching or rearing with their forelegs stretched towards the ceiling of this magnificent obsidian "
"temple.  Grand archways rise at evenly-spaced intervals around the %^RESET%^%^BLUE%^glos%^BOLD%^s%^RESET%^%^BLUE%^y "
"%^BOLD%^%^BLACK%^walls, carved in ornate patterning with the writhing silvery outlines of countless %^RESET%^%^WHITE%^"
"arac%^BOLD%^%^BLACK%^hn%^RESET%^ids%^BOLD%^%^BLACK%^ to finally meet in the centre of the roof above you.  Between the "
"archways are six tapestries, each showing an image from the history of the %^RESET%^%^BLUE%^drow %^BOLD%^%^BLACK%^race"
".  A line of soft %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^olet carpet %^BLACK%^%^BOLD%^runs in from the "
"southern doorway, and passes through the impressively arched doorway to the north where you can see a grand spherical "
"room that appears to be an altar chamber.  To the west seems to be a small healer's alcove, while opposite this opens "
"what looks like another much smaller %^RESET%^%^RED%^sh%^BOLD%^r%^RESET%^%^RED%^ine%^BOLD%^%^BLACK%^, decorated in "
"distinctly different style to the rest of the temple.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The heady, %^MAGENTA%^in%^CYAN%^to%^MAGENTA%^xica%^BOLD%^t%^RESET%^%^MAGENTA%^ing "
"%^ORANGE%^aroma of incense fills the air.");
   set_listen("default","%^CYAN%^P%^GREEN%^ra%^CYAN%^y%^GREEN%^er%^CYAN%^s %^GREEN%^of the faithful surround you with a "
"dull %^ORANGE%^mur%^YELLOW%^m%^RESET%^%^ORANGE%^ur %^GREEN%^of sound.");

   set_items(([
     ({"walls","floor","roof"}):"%^BOLD%^%^BLACK%^The grand hall you stand in has been shaped completely from %^RESET%^glo"
"%^BOLD%^%^BLACK%^ss%^RESET%^y obs%^BOLD%^%^BLACK%^i%^RESET%^dian%^BOLD%^%^BLACK%^, polished to a mirror's sheen.  Too "
"dark to properly capture and reflect an image, it nevertheless %^RESET%^%^BLUE%^g%^BOLD%^l%^RESET%^%^BLUE%^eams %^BOLD%^"
"%^BLACK%^with reflected light and motion as the temple's faithful pass by.  An elaborate retelling of the history of "
"%^RESET%^%^BLUE%^drowkind %^BOLD%^%^BLACK%^spans the tapestries that encircle the room, each image settled between "
"a pair of massive stone arches that rise to meet at the centre of the roof above.%^RESET%^",
     ({"tapestries","tapestry","images"}):"%^BOLD%^%^BLACK%^Around the walls is a depiction of the history of %^RESET%^"
"%^BLUE%^drowkind%^BOLD%^%^BLACK%^, told through a number of finely woven tapestries.  You could spare a closer look at each one, if you were curious about the details.",
     ({"tapestry 1","first tapestry","tapestry one"}):"%^BOLD%^%^BLACK%^The first tapestry depicts a split image of two "
"female forms, imposed across a split sky of %^RESET%^l%^BOLD%^i%^RESET%^ght %^BOLD%^%^BLACK%^and %^RESET%^%^BLUE%^dark"
"%^BOLD%^%^BLACK%^.  One has hair of fine-spun silver, while the other lustrous tresses of raven-black.  Each has a look "
"of infinite devotion on her face, with arms outstretched to embrace opposite sides of a small jagged chunk of rock, "
"speckled across the top with the %^RESET%^%^GREEN%^v%^BOLD%^i%^RESET%^%^CYAN%^b%^BOLD%^%^GREEN%^r%^BLUE%^a%^CYAN%^n"
"%^RESET%^%^GREEN%^t %^BOLD%^%^BLACK%^greens and blues of new life.  The figures become lost to vagarities of form as the "
"hair and flowing garb of each fades back into the nothingness of the air that surrounds the tiny planet.\n\n%^RESET%^"
"%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^At the beginning of all things...%^MAGENTA%^'%^RESET%^",
     ({"tapestry 2","second tapestry","tapestry two"}):"%^BOLD%^%^BLACK%^The second tapestry shows just one woman upon "
"the left, much like the raven-haired sister of the previous artwork, but of far more delicate aspect.  Her %^RESET%^fine-"
"b%^BOLD%^o%^RESET%^ned %^BOLD%^%^BLACK%^features are clearly elven, as are her pointed ears.  Opposite her on the far "
"right, a single massive eye floats aloft, surrounded by %^RESET%^%^GREEN%^sic%^ORANGE%^kl%^GREEN%^y g%^BOLD%^r%^RESET%^"
"%^GREEN%^een %^BOLD%^%^BLACK%^tentacles that writhe across its surface.  Between the two, a gathering of gray-skinned "
"elven forms lie prostrate before each in worship.\n\n%^RESET%^"
"%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^Patrons of our Ancestors%^MAGENTA%^'%^RESET%^",
     ({"tapestry 3","third tapestry","tapestry three"}):"%^BOLD%^%^BLACK%^Across the third tapestry, a %^RESET%^%^RED%^b"
"%^BOLD%^lo%^YELLOW%^o%^RESET%^%^RED%^d-r%^BOLD%^e%^RESET%^%^RED%^d %^BOLD%^%^BLACK%^sun shines down upon a pitched "
"battle that rages between similarly %^RESET%^gray-skinned %^BOLD%^%^BLACK%^elves and their cousins of fairer complexion"
".  Vicious weapons sing through the air as the %^CYAN%^cr%^GREEN%^ac%^YELLOW%^k%^CYAN%^le %^BLACK%^of arcane magic arcs "
"overhead, while casualties lie fallen upon both sides.  The faces of the gray-skinned elves bear an expression of "
"righteous fury, as their paler kindred seem more inclined to shelter behind a shield, or even attempt to flee"
".\n\n%^RESET%^%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^The Crown Wars%^MAGENTA%^'%^RESET%^",
     ({"tapestry 4","fourth tapestry","tapestry four"}):"%^BOLD%^%^BLACK%^The fourth tapestry is cast into shadow, "
"showing the entry to a %^RESET%^%^BLUE%^dark cavern %^BOLD%^%^BLACK%^where the same elves, now of ebon-black skin and "
"%^RESET%^bone-w%^BOLD%^h%^RESET%^ite %^BOLD%^%^BLACK%^hair, cower before the %^YELLOW%^inc%^WHITE%^an%^YELLOW%^des%^RED%^"
"c%^YELLOW%^ent %^BLACK%^aura of a mighty elven form.  His hand is outstretched, his face stretched into a tyrannical "
"scowl as he casts the dark elves below.  The eyes of the cowering elves now gleam %^RESET%^%^RED%^crim%^BOLD%^s%^RESET%^"
"%^RED%^on %^BOLD%^%^BLACK%^with unveiled hatred.\n\n%^RESET%^"
"%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^The Descent%^MAGENTA%^'%^RESET%^",
     ({"tapestry 5","fifth tapestry","tapestry five"}):"%^BOLD%^%^BLACK%^A majestic city of gleaming spires and leaping "
"bridges spreads across the fifth tapestry, set upon a backdrop of %^RESET%^%^BLUE%^n%^BOLD%^i%^RESET%^%^BLUE%^ght sky "
"%^BOLD%^%^BLACK%^and a range of %^RESET%^%^ORANGE%^ru%^GREEN%^gg%^ORANGE%^ed mo%^RED%^u%^ORANGE%^nt%^GREEN%^ai%^ORANGE%^"
"ns.  %^BOLD%^%^BLACK%^Tiny, dark figures can be seen within its streets but your eyes are ever drawn upward to the "
"elegant arches and spans of the drow architecture.  Surely such a city could not truly exist, for it seems too fragile "
"even to withstand a strong storm!\n\n%^RESET%^"
"%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^Juran'Xundessa%^MAGENTA%^'%^RESET%^",
     ({"tapestry 6","sixth tapestry","tapestry six"}):"%^BOLD%^%^BLACK%^The sixth and final tapestry shows a single drow "
"woman, arms and legs %^RESET%^%^CYAN%^gra%^BOLD%^c%^RESET%^%^CYAN%^ef%^GREEN%^ul%^CYAN%^ly %^BOLD%^%^BLACK%^extended as "
"if in the midst of a leap or dance.  Completely naked, her lithe figure is a flawless embodiment of mortality, or "
"perhaps something greater.  Her head is cast back, %^RESET%^%^RED%^crim%^BOLD%^s%^RESET%^%^RED%^on %^BOLD%^%^BLACK%^eyes "
"cast skywards as the slender fingers of one arm trail through the air above.  She has been imposed upon the backdrop of "
"a %^RESET%^%^BLUE%^giant black spider %^BOLD%^%^BLACK%^rearing higher yet, its many legs splayed aggressively in an "
"unsettling parody of her dance.\n\n%^RESET%^"
"%^MAGENTA%^Delicate stitches title the piece %^BOLD%^'%^WHITE%^The Dancer, Mistress of the Night%^MAGENTA%^'%^RESET%^",
     ({"arches","archways","grand archways"}):"%^BOLD%^%^BLACK%^Grand archways run up the walls at eight evenly-spaced "
"intervals around the room, bending inwards along the curved roofline to meet at the very pinnacle above.  They are all "
"patterned with etchings of %^RESET%^%^WHITE%^arac%^BOLD%^%^BLACK%^hn%^RESET%^id sil%^BOLD%^%^BLACK%^h%^RESET%^ouettes"
"%^BOLD%^%^BLACK%^, outlined in molten %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
"%^BLACK%^that causes them to writhe upwards like living creatures as light plays across their gleaming surfaces"
".%^RESET%^",
     ({"statues","spider statues"}):"%^BOLD%^%^BLACK%^At each of the four corners of the room stands a tall %^RESET%^"
"%^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BOLD%^%^BLACK%^statue, carved to resemble a giant hunting spider.  One rears back "
"on four legs, its other two pairs raised menancingly towards temple visitors and its palps spread in a silent %^RESET%^"
"%^GREEN%^h%^BOLD%^i%^RESET%^%^GREEN%^ss%^BOLD%^%^BLACK%^.  The one directly opposite has its cephalothorax lowered to "
"the ground and all legs splayed to either side, ready to leap at a second's notice.  Each piece is startlingly lifelike "
"and crafted with impeccable attention to detail.%^RESET%^",
     ({"carpet","violet carpet"}):"%^BOLD%^%^BLACK%^A single, slim line of %^RESET%^%^MAGENTA%^deep v%^BOLD%^i%^RESET%^"
"%^MAGENTA%^olet carpet %^BLACK%^%^BOLD%^traces a path from the southern doorway and leads directly northwards into the "
"many-levelled altar chamber beyond.  It serves as a small stretch of comfort, compared to the cold stone floor beneath"
".%^RESET%^",
   ]));
   set_exits(([
     "out":ROOMS"square2",
     "east":ROOMS"temple2",
     "west":ROOMS"temple3",
     "north":ROOMS"temple4",
   ]));
}
