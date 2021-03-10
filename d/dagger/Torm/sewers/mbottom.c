#include <std.h>
#include "../tormdefs.h"
inherit ROOM;
void create(){
  ::create();
  set_property("light",1);
  set_property("no teleport",1);
  set_property("indoors",1);
  set_short("At a strange seal in the sewers under Torm");
  set_long(
  "  You are under the streets of the City of Torm in its sewer system."
  "  It's not as dirty as sewers often are, evident that it was maintained but has been left alone recently."
  "  A heavy mist settles around your feet and your moving makes edies of it swirl slugishly about."
   "  There is a faint chill in the air."
   "  A great brass door is here with a glowing sigil on it, which radiates an intense cold to the touch."
  );
  set("night long",
  "  A dread chill fills your soul as you walk the sewers of Torm at night"
  "  A thick mist comes up past your waist and it freezes you as it soaks through your clothes."
  "  You hear strange sounds of flapping feet in the distance and the rats scurry about through the mist hidden from view."
   "  A great brass door is here with a glowing sigil on it, which radiates an intense cold to the touch."
  );
  set_smell("default",
  "There is something foul down here."
  );
  set_listen("default",
  "A skittering of clawed feet tells you that you're not alone down here."
  );
  set_items(([
  "walls":"These walls are carved into the bedrock that the city of Torm sits on.  It's very fine work, with hardly any cracks or stoneworking marks anywhere.",
  "floors":"The floors show many prints of small rodents feet and some creatures with flat webbed feet as well.",
  (({"foot prints","prints"})):"The rat's prints are easy enough to figure out but what are the other ones?",
  (({"brass door","door","great brass door"})):"This brass door is starting to corrode even though from the looks of its hinges it's new.  A mystic sigil is inscribe on the door.",
  (({"sigil","mystic sigil","seal"})):" A strange sigil seals the brass door shut.  It glows with magic and you can't seem to get near it to try to attempt to open it.",
  (({"ceiling","roof"})):"The streets of Torm are above you and you wonder what the night sky still looks like.",
  "mist":"The mist here comes up to your waist and you hope there is nothing lurking in it out of your sight tougher than rats...",
  ]));
}
void reset(){
  object ob;
  ::reset();
  if(!(query_night())){
  if(!random(5)){
  if(!present("rat",TO)){
  new(MON+"rat.c")->move(TO);
  new(MON+"rat.c")->move(TO);
  }
  }
  }
  if(!random(6)){
  if(!present("strange man",TO)){
  new(MON+"sahuagin.c")->move(TO);
  new(MON+"sahuagin.c")->move(TO);
  }
  }
  if(!random(3)){
  if(!present("ratd",TO)){
  new(MON+"ratd.c")->move(TO);
  new(MON+"ratd.c")->move(TO);
  new(MON+"ratd.c")->move(TO);
  }
  }
  }
