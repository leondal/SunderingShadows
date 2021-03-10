#include <std.h>

#define SD "/d/common/daemon/randstuff_d"
inherit ROOM;
int searched;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(PAVED_ROAD);
    set_name("Executioner's Room");
    set_short("Executioner's Room");
    set_long("This cavelike chamber with smooth %^BOLD%^%^WHITE%^"+
    "stone floor%^RESET%^ and %^BOLD%^%^WHITE%^walls%^RESET%^ is "+
    "thirty feet high and extends about fourty feet into the "+
    "%^BOLD%^%^WHITE%^rock%^RESET%^.  A large %^YELLOW%^lantern"+
    "%^RESET%^, hanging by a %^RED%^chain%^RESET%^ from the ceiling "+
    "sheds %^YELLOW%^light%^RESET%^ on the whole room.  At the rear "+
    "of the cavern is another of the eight feet tall %^MAGENTA%^kegs"+
    "%^RESET%^ of mead like those in the cellar.  Toward the back of "+
    "the chamber, on the east side sits a five feet long %^RED%^chest"+
    "%^RESET%^ with the lid removed.  Nearer the door, is a mound "+
    "of %^RED%^furs%^RESET%^, %^RED%^skins%^RESET%^, and "+
    "%^RED%^feathers%^RESET%^ that serve as a makeshift %^RED%^bed"+
    "%^RESET%^.");
    set_smell("default","The smell of stale beer is almost overwhelming in this room.");
    set_listen("default","You hear the sound of careless movement "+
    "on stone floors.");
    
    set_exits(([  "south" : "/d/deku/open/guard"  ] ));
    set_search("default","The pile of furs, skins, and feathers "+
    "could hide just about anything.");

    set_search("mound",(:TO,"search_bed":));
    set_search("bed",(:TO,"search_bed":));
    set_search("skins",(:TO,"search_bed":));
    set_search("furs",(:TO,"search_bed":));
    set_search("feathers",(:TO,"search_bed":));

    set_items(([
    ({"furs", "skins","feathers","mound","bed"}) : "The furs, skins, and feathers "+
    "serve as a makeshift bed that has been quickly thrown together.  "+
    "They have began the process of decaying and give off a horrible "+
    "stench.  They are stacked several feet high and could probably "+
    "conceal just about anything.",
    ({"keg","kegs"}) : "The tall keg is less than half full of mead, most of it "+
    "either consumed or spilled to the floor.",
    ({"floor","walls","stone","rock","stone floor"}) : "%^BOLD%^%^WHITE%^This entire "+
    "chamber has been dug into the natural stone of this region.  "+
    "It is an almost solid gray, with the walls, floor, ceiling, and "+
    "doorway constructed entirely of it.%^RESET%^",
    "light" : "%^YELLOW%^Light spews forth at all times from the "+
    "lantern dangling from the chain in the center of this chamber."+
    "%^RESET%^",
    "lantern" : "%^YELLOW%^This massive lantern rests lazily at the "+
    "end of a thick and rusty chain.  It is open on all sides and burns "+
    "brightly with a soft yellow flame.  It is obviously "+
    "of magical design and operation, as it never dims.%^RESET%^",
    "chain" : "%^RED%^This thick and rusty chain dangles from the "+
    "ceiling of the chamber and easily holds a massive lantern at "+
    "its end.%^RESET%^",
    "ceiling" : "%^BOLD%^%^WHITE%^The ceiling of this chamber is "+
    "made from the natural gray stone of this region.  A thick and "+
    "rusty chain dangles down from the center of it, holding a "+
    "massive lantern at its end.%^RESET%^",
    "chest" : "%^RED%^This chest is made from a rusted iron.  Its lid has "+
    "been removed at some point leaving the empty state of its "+
    "belly open for all to behold.%^RESET%^",
    ] ));
}

void search_bed() {
  tell_room(TO,TP->QCN+"%^RED%^ carefully digs through the grotesque "+
   "pile of skins, furs, and feathers.%^RESET%^",TP);
   if(searched == 0) {
     if(random(10) >= 7) {
       SD->find_stuff(TO,"random");
       tell_object(TP,"%^RED%^You carefully dig through the rotting "+
       "pile of skins, furs, and feathers and find something of "+
       "value!%^RESET%^");
       searched = 1;
       return;
      }
      tell_object(TP,"%^RED%^You carefully dig through the rotting "+
      "pile of skins, furs, and feathers but find nothing you would "+
      "want to keep.%^RESET%^");
      searched = 1;
      return;
  }
  tell_object(TP,"%^RED%^You carefully dig through the rotting "+
  "pile of skins, furs, and feathers but find nothing you would "+
  "want to keep.%^RESET%^");
  return;
}

void reset() {
  ::reset();
  if(!present("boris") && !random(3)) {
    new("/d/deku/monster/hill")->move(TO);
  }
  if(random(10) >= 5) {
    searched = 0;
  }
}
