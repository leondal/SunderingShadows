//updated by Circe 11/1/04 with color, etc.
#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_light(2);
   set_indoors(1);
   set_name("Winter's Emperor");
   set_short("Winter's Emperor");
   set_long("%^YELLOW%^Winter's Emperor%^RESET%^\n"+
      "This quaint shop is filled with strange %^MAGENTA%^items "+
      "%^RESET%^almost as unique as its name.  The plain %^ORANGE%^"+
      "walls %^RESET%^are ungraced by tapestries or paintings, "+
      "instead supporting simple %^ORANGE%^wooden shelves %^RESET%^"+
      "piled neatly with all manner of %^CYAN%^jars %^RESET%^and "+
      "%^YELLOW%^boxes%^RESET%^.  The strange %^GREEN%^odors %^RESET%^"+
      "that have become the signature aroma of magi pervade the "+
      "room, leaving little doubt as to what fills all those %^CYAN%^"+
      "jars %^RESET%^and %^YELLOW%^boxes%^RESET%^.  Despite the "+
      "lack of decoration, the shop has a somewhat elegant air, "+
      "perhaps granted it by the fastidious manner in which I-chou "+
      "keeps it clean and organized.\n");
   set_smell("default","The room is filled with mingled smells of various herbs and concoctions.");
   set_listen("default","An eerie silence pervades, much like a library.");
   set_exits(([
       "east" : ROOMS"north2",
   ]));
   set_items(([
      ({"shelves","wooden shelves"}) : "The plain wooden shelves are "+
         "highly varnished and well-tended, revealing the strong sense "+
         "of pride and duty felt by the shop owner.",
      ({"walls","wall"}) : "The walls bear no decoration whatsoever, "+
         "and each is covered in shelves.",
      ({"jars","boxes","components"}) : "The shelves hold countless "+
         "boxes and jars, each one housing a different spell "+
         "component so vital to the arcane arts.  The possible use "+
         "of these components would baffle all but magi or the "+
         "occasional extraordinary bard.",
      ({"alley","alleyway"}) : "The narrow alley outside the shop "+
         "greatly contrasts with the calm, clean world inside.  "+
         "Little light reaches the ground outside, most of it being "+
         "blocked by the tall buildings rising all around."
   ]));
}

void reset(){
   ::reset();
   if(!present("I-chou")) find_object_or_load("/d/tharis/monsters/I-chou")->move(TO); // do we need to copy this and yseult (jewelry) into the main dir?
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}