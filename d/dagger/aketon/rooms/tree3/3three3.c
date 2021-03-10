#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A garden in Aketon");
   set_long("%^GREEN%^A garden in Aketon%^RESET%^\n"+
   "This room is bright and cheery and has been filled with many"+
   " yellow and white flowers. In the middle of the room a pot of"+
   " daffodils is growing, surrounded by pots of white daisies and"+
   " black-eyed susans. Orange poppies are fitted in in smaller pots"+
   " that ring the daisies and black-eyed susans. Around the edges of"+
   " the room are white tiger lilies, large cups of gold, and some"+
   " white geraniums growing in the large troughs. In a smaller row of"+
   " troughs in front of the other flowers are several yellow and white"+
   " snap dragons mixed with purple and yellow pansies. This garden"+
   " continues to the east, and near the exit are two smaller troughs"+
   " that reach in towards the broad walkway filled with goldenrods"+
   " and moonbeams. Vines of white morning glory are growing in the"+
   " nearby branches of the tree.");
   set_smell("default","The smells of the are garden pleasant.");
   set_listen("default","The wind rustles gently through the leaves.");
   set_items(([
   "daffodils" : "%^YELLOW%^The yellow daffodils sit in the center of"+
   " the room, looking almost proud with their circular centeral petals"+
   " standing up from the rest, as though they have their noses in the"+
   " air. They are a bright yellow in color with a few long, %^RESET%^%^GREEN%^dark"+
   " green leaves%^YELLOW%^ that are almost eclipsed in all the flowers.%^RESET%^",
   ({"daisies","white daisies"}) : "%^BOLD%^The daisies are pretty with"+
   " their slender white leaves that stretch out from their %^YELLOW%^bright"+
    " yellow%^WHITE%^ center. They bring a smile to most everyone's face.%^RESET%^",
   ({"susans","black eyed susans","black-eyed susans"}) : "%^YELLOW%^The"+
   " black-eyed susans are very similar to daisies, but the colors are"+
   " different. They have several slender yellow petals that spread out"+
   " from a %^BLACK%^dark center%^YELLOW%^ that earned them their name.%^RESET%^",
   ({"poppies","orange poppies"}) : "%^ORANGE%^Bright orange poppies"+
   " are growing in abundance. They flowers have four petals and they"+
   " grow on %^GREEN%^slender green stalks%^ORANGE%^ straight up from"+
   " the ground.%^RESET%^",
   ({"lilies","tiger lilies","white tiger lilies"}) : "%^BOLD%^Several"+
   " large white tiger lilies are in one section. They are four feet"+
   " tall with large %^RESET%^%^GREEN%^dark green leaves%^BOLD%^%^WHITE%^"+
   " and they come from stems near the top of the stalk. The petals are"+
   " more slender than normal ginger and they have a white stamen with"+
   " %^YELLOW%^yellow pollen%^WHITE%^ at the tip. The petals are striped"+
   " with %^BLACK%^black lines%^WHITE%^ which got them their name.%^RESET%^",
   ({"cups","cups of gold","gold cups"}) : "%^YELLOW%^The cups of gold"+
   " are very large, much larger than a normal sized goblet. They"+
   " are a beautiful golden shade and they are formed into cups with"+
   " the petals at the top drooping over the sides a little. A giant"+
   " could drink out of one quite easily, if he didn't mind the pollen"+
   " in the center.%^RESET%^",
   ({"geraniums","white geraniums"}) : "%^BOLD%^The little geraniums"+
   " have very %^RESET%^%^GREEN%^dark green leaves%^BOLD%^%^WHITE%^"+
   " that are quite smooth. The petals are white and very glossy and"+
   " they form tiny flowers with five petals with a %^YELLOW%^yellow%^WHITE%^"+
   " center.%^RESET%^",
   "snap dragons" : "%^BOLD%^There are both white and %^YELLOW%^yellow%^WHITE%^"+
   " snap dragons. They have delicate petals that appear to be snapping"+
   " shut with a tiny beak, which has earned them their name. They"+
   " tend to wilt when it gets very hot, but don't seem to be having"+
   " any problems this high up in the tree.%^RESET%^",
   "pansies" : "%^MAGENTA%^The pansies are very bright and pretty,"+
   " with dark purple covering most of the three petals and"+
   " %^YELLOW%^yelllow%^RESET%^%^MAGENTA%^ patches adding some cheer.%^RESET%^",
   "moonbeams" : "%^YELLOW%^The moonbeams are a low lying plant with"+
   " pale yellow flowers that open up in the shape of a star with"+
   " eight slender petals that come to a point at the end and a center"+
   " of yellowish green pollen. They are quite pretty.%^RESET%^",
   "goldenrods" : "%^YELLOW%^The goldenrod grows on a slender,"+
   " %^GREEN%^light green stalk%^YELLOW%^ with pointed leaves. The tops"+
   " are covered with the tiny, delicate yellow flowers that give the"+
   " plant its name.%^RESET%^",
   ({"morning glory","white morning glory","vine"}) : "%^BOLD%^The"+
   " morning glory is a %^RESET%^%^GREEN%^dark green vine%^BOLD%^%^WHITE%^"+
   " with several white cup shaped flowers that fan out flat at the"+
   " very top. It can often be quite a nuisance to trees and other"+
   " plants, but the elves appear to have it well maintained.%^RESET%^",
   ]));
   set_exits( (["east":RPATH3+"3three4",
      "southwest":RPATH3+"3three1"]) );
}
