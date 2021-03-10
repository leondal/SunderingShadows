#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
   set_short("%^ORANGE%^A forest path%^RESET%^");
   set_long(
   "%^GREEN%^You are traveling along a little path that winds its way through"+
   " part of the forest. It was probably made by wild animals that"+
   " live in this forest and it is not very wide or easy to spot. But"+
   " it is at least a trail that winds between the %^ORANGE%^thick trees%^GREEN%^ that"+
   " rise up around you. The forest itself is vibrant with life. You"+
   " can see %^ORANGE%^squirrels%^GREEN%^ scampering about through the trees and along"+
   " the ground, collecting food. %^BOLD%^%^BLUE%^Bird%^RESET%^%^GREEN%^ song echoes throughout the"+
   " trees, and you can occasionally spot one of the shy avians before"+
   " it notices you and takes to the air. You hear distant rustlings"+
   " in the brush, and know that larger animals are also about somewhere."+
   " Despite all the activity going on around you, there is still a"+
   " %^CYAN%^tranquility%^GREEN%^ here that even the animals seem to sense and delight in.\n"
   );
   set("night long",
   "%^GREEN%^You're on a small path that winds its way through this forest. It"+
   " is hard to make out in the dark, but there is really nowhere else"+
   " to go because the trees are so thick. Some %^BOLD%^%^WHITE%^light%^RESET%^%^GREEN%^ manages to"+
   " trickle through the leaves and help light the way. Most of the %^ORANGE%^trees"+
   " %^GREEN%^are at least twenty feet tall, and some are gnarled with age,"+
   " but you get the feeling that this part of the forest is relatively"+
   " new. There are signs of %^BOLD%^life%^RESET%^%^GREEN%^"+
   " sprouting everywhere, and you can"+
   " hear the animals that are awake this night. An %^RESET%^owl"+
   " %^GREEN%^hoots somewhere"+
   " off in the distance, and you can hear the scampering of %^BOLD%^%^BLACK%^"+
   "mice%^RESET%^%^GREEN%^"+
   " under the brush and leaves. You can hear leaves and brush"+
   " crackling in the distance, obviously some larger animals are"+
   " about. Despite the tranquil nature of this forest, it is still"+
   " full of wild animals and it's best to be on guard.\n"
   );
   set_smell("default","The scent of the leaves drifts to your nose.");
   set_listen("default","You hear animals scampering in the bushes.");
   set_items(([
   ({"path","trail"}) : "%^ORANGE%^The trail is very narrow and easy to lose"+
   " if you aren't careful, but there's no other way through this"+
   " section of forest, really, the trees are so thick. On close"+
   " inspection this is probably primarily a deer path, judging by"+
   " the distinctive hoof prints that are all over the place. Other"+
   " animals undoubtedly use it as well, so it's best to be careful.",
   " squirrels" : "%^ORANGE%^Cute little squirrels are busy gathering food. They"+
   " don't really seem to be afraid of you, or much care that you're"+
   " even there if you don't have something for them to eat.",
   "mice" : "%^BOLD%^%^BLACK%^Mice are scampering about under the brush and leaves,"+
   " searching for something edible and trying not to be spotted by"+
   " any predators.",
   ({"bush","bushes","brush"}) : "%^GREEN%^Bushes line the trail, sometimes"+
   " covering it. They are all over the ground, but have been beaten"+
   " back off the trail because of its constant use by animals.",
   "leaves" : "%^BOLD%^%^GREEN%^The leaves are many shades of green depending on where"+
   " you look. There are some young saplings just springing up with"+
   " bright green leaves, and some older trees with darker leaves"+
   " that reach into the sky. The dead leaves have fallen to the forest"+
   " floor and turned varying shades of yellow and brown.",
   "trees" : "%^GREEN%^For the most part the trees stretch high into the sky."+
   " Some are gnarled with age, but looking around you notice that"+
   " none of them are very thick. The oldest one here is probably"+
   " not more than a hundred or so years old, which is odd for a"+
   " forest.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   if(query_night() == 1) {
      switch(random(13)) {
         case 0..3:
            new(MONS+"cougar")->move(TO);
            break;
         case 4..6:
            new(MONS+"bear")->move(TO);
            break;
         case 7..9:
            new(MONS+"bobcat")->move(TO);
            break;
         case 10..11:
            new(MONS+"direwolf")->move(TO);
            new(MONS+"direwolf")->move(TO);
            break;
         case 12:
            new(MONS+"direwolf")->move(TO);
            new(MONS+"direwolf")->move(TO);
            new(MONS+"direwolf")->move(TO);
            break;
      }
   }
   else {
      switch(random(5)) {
         case 0:
            new(MONS+"doe")->move(TO);
            break;
         case 1:
            new(MONS+"boar")->move(TO);
            break;
         case 2:
            new(MONS+"fox")->move(TO);
            break;
         case 3:
            new(MONS+"raccoon")->move(TO);
            break;
         case 4:
            new(MONS+"ferret")->move(TO);
            break;
      }
   }
}
