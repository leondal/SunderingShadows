#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A garden in Aketon");
   set_long("%^GREEN%^A garden in Aketon%^RESET%^\n"+
   "You have walked into a room that is simply filled with large pots"+
   " of flowers. There are so many here that it is hard to make your"+
   " way around in places. In the front are several pots of irises."+
   " Two regular pots of tall standing purple irises flank the smaller"+
   " crested iris that sits between them. Dark purple asters in smaller"+
   " pots sit in front of the irises. Long stalks of white indigo are"+
   " in front of the troughs on the edges of the room. Pretty"+
   " bluebells are in a large pot near the middle of the room and"+
   " a row of cardinal flowers stands tall behind them. In the northwest"+
   " corner is a large pot filled with blue lupine. In the very back of"+
   " the room is a large trough filled with wild columbine that is a"+
   " pretty shade of mauve.");
   set_smell("default","The smells of the are garden pleasant.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_items(([
   ({"irises","purple iris"}) : "%^MAGENTA%^The purple irises stand"+
   " a few feet tall with long stalks covered in the purple flowers"+
   " that have several petals branching out and curling around, with"+
   " the largest petal on the bottom with a patch of %^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^"+
   " at the base of the petal with a stripe of %^YELLOW%^yellow%^RESET%^%^MAGENTA%^"+
   " in it.%^RESET%^",
   "crested iris" : "%^MAGENTA%^The crested iris is smaller than other"+
   " iris plants and it has three sets of three petals that all branch"+
   " out to form a star. The largest petals in the back each have"+
   " a wide stripe of %^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^ with a"+
   " smaller stripe of %^YELLOW%^yellow%^RESET%^%^MAGENTA%^ in the"+
   " very center.%^RESET%^",
   ({"asters","purple asters"}) : "%^MAGENTA%^The dark purple asters"+
   " are delicate flowers with a multitide of thin petals that come"+
   " out from a %^YELLOW%^yellow%^RESET%^%^MAGENTA%^ center in a"+
   " circle.%^RESET%^",
   ({"indigo","white indigo"}) : "%^BOLD%^The white indigo is"+
   " essentially one long %^RESET%^%^GREEN%^dark green stalk%^BOLD%^%^WHITE%^"+
   " that has sprigs of small, delicate white flowers sprouting along"+
   " from top to bottom.%^RESET%^",
   "bluebells" : "%^BOLD%^%^MAGENTA%^The bluebells are actually a very"+
   " light purple in the center, with the color growing %^RESET%^%^MAGENTA%^darker%^BOLD%^"+
   " toward the edges of the petals. They are shaped sort of like a"+
   " bell, with a %^YELLOW%^yellow stamen%^MAGENTA%^ in the center and"+
   " five joined petals coming up around it. When they begin to wilt or"+
   " die the flower bends down so that it's facing the ground, and is"+
   " truly like a bell.%^RESET%^",
   "cardinal flowers" : "%^RED%^The cardinal flowers are almost four"+
   " feet tall. Long %^GREEN%^dark green stalks%^RED%^ reach into the"+
   " air. %^GREEN%^Green leaves%^RED%^ fill the lower part of the"+
   " stalk while delicate, red flowers cover the top. The petals"+
   " bend towards the ground and they almost look like the small"+
   " feathers of a cardinal.%^RESET%^",
   ({"lupine","blue lupine"}) : "%^BLUE%^The lupine is very pretty."+
   " tall stalks of %^GREEN%^dark green%^BLUE%^ rise up from a bed of"+
   " %^BOLD%^%^GREEN%^lighter green leaves%^RESET%^%^BLUE%^ that are"+
   " shaped like star bursts. The flowers are on sprigs that shoot off"+
   " the central stalk and they are a %^BOLD%^%^CYAN%^lighter"+
   " blue%^RESET%^%^BLUE%^ on the bottom with a darker purplish blue"+
   " top. The petals come together almost completely, with a small"+
   " opening in the center that holds the dew. They will slowly open"+
   " up more as they begin to die, but they are very beautiful.%^RESET%^",
   ({"columbine","wild columbine"}) : "%^MAGENTA%^%^BOLD%^The wild"+
   " columbine seems to be doing quite well. It is growing five feet"+
   " tall with large, ruffled leaves. The flowers grow at the ends of"+
   " long, slender stems that are extended from the main part of the"+
   " plant. The flowers have several slender petals that extend from"+
   " a dark mauve base, growing lighter at the ends. They mostly lean"+
   " towards the ground and have yellow stamens covered in pollen"+
   " protruding from the center to the ends of the petals.%^RESET%^",
   ]));
   set_exits( (["north":RPATH3+"3three1"]) );
}
