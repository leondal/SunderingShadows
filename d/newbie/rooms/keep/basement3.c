#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

int DESK;

void create() {
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A secret basement");
   set_short("%^RESET%^%^ORANGE%^Office in a secret basement%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Office in a secret basement%^RESET%^\n"
"This is quite a cosy office, located off the passageway in the secret basement "
"you've found.  The smooth stone %^BLUE%^walls %^RESET%^offer a dreary aspect "
"to the room and passageway, although this was perhaps softened once by the "
"%^ORANGE%^rug %^RESET%^and %^CYAN%^tapestries %^RESET%^that now lie in "
"varied states of ruin.  Against the western wall is a sizeable %^RED%^desk "
"%^RESET%^and chair, while a padded %^GREEN%^couch %^RESET%^sits at the "
"southern end of the room.  The eastern wall is set with a sturdy door, which "
"is flanked on either side by a pair of %^ORANGE%^bookshelves%^RESET%^.  A "
"dull %^YELLOW%^sphere %^RESET%^of light hangs from the roof, shedding a pale "
"glow around that is just enough to see by.\n");
   set_smell("default","The air is still and more than a little stale.");
   set_listen("default","The silence is eerie.");
   set_items(([
     ({"desk","drawers"}) : ((:TO,"desk_desc":)),
     "walls" : "%^BLUE%^The stone walls are unnaturally smooth, forming "
"perfect angles with the floor and ceiling.  Within the east wall there is "
"a large and sturdy door.%^RESET%^",
     "rug" : "%^ORANGE%^A bearskin rug covers most of the cold stone floor, "
"although it is long worn with age and covered in dust.  It was probably once "
"thick and pleasant underfoot.%^RESET%^",
     "tapestries" : "%^CYAN%^The stone walls are broken up by the remnants of "
"several tapestries, which hang in varied states of disrepair.  Some depict "
"vast landscapes and tall buildings, but the rest are too damaged to decipher "
"their imagery.%^RESET%^",
     "couch" : "%^GREEN%^The couch is still intact, despite the damage age has "
"caused to this room.  Various portions of it are worn and fraying, though it "
"may yet hold a person's weight.%^RESET%^",
     ({"bookshelf","bookshelves"}) : "%^ORANGE%^A pair of bookshelves flank the "
"doorway to the east.  Sadly, they are mostly empty, and what books remain have "
"been ravaged by time and damp, leaving the knowledge they perhaps once "
"contained, far beyond retrieval.%^RESET%^",
     ({"sphere","light"}) : "%^YELLOW%^A softly glowing sphere hangs down from "
"a chain attached to the ceiling.  It must be enchanted somehow, illuminating "
"the area without any source of flame.  It has grown dull over time, however, "
"and now only sheds a dim glow about the room.%^RESET%^",
   ]));
   set_search("default","%^ORANGE%^There is not much that stands out as "
"particularly remarkable in this room, but perhaps you could search the "
"%^YELLOW%^desk %^RESET%^%^ORANGE%^to see if it had anything in its "
"drawers?%^RESET%^");
   set_search("desk",(:TO,"search_desk":));
   set_search("drawers",(:TO,"search_desk":));
   set_exits(([
     "east" : ROOMS"basement2",
   ]));
   set_door("door",ROOMS"basement2","east",0);
   set_door_description("door","%^ORANGE%^There is a large, sturdy door in "
"the eastern wall.  It is in surprisingly good condition.%^RESET%^");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}

void reset() {
   ::reset();
   DESK = 0;
}

string desk_desc() {
   if(DESK) return("%^RED%^The large desk on the south side of the room appears "
"to have seen much use in its days, but is still in fairly good shape.  There "
"are a few large drawers and compartments on it for stashing stuff away.  It "
"seems someone has recently rummaged through them.%^RESET%^");
   else return("%^RED%^The large desk on the south side of the room appears "
"to have seen much use in its days, but is still in fairly good shape.  There "
"are a few large drawers and compartments on it for stashing stuff away.  "
"Perhaps if you %^YELLOW%^search %^RESET%^%^RED%^through them, you may find "
"something?%^RESET%^");
}

int search_desk() {
   object ob;
   if(DESK) {
     tell_object(TP,"%^YELLOW%^It looks as though someone has already searched "
"through the drawers of the desk, as there's nothing left.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches through the drawers of the "
"desk but finds nothing.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You search through the desk drawers and find a "
"small pouch and some coins, all wrapped in a folded robe.%^RESET%^");
   tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches through the desk drawers and "
"appears to find something of interest.%^RESET%^",TP);
   new(OBJ2"robe")->move(TO);
   ob = new("/std/obj/coins");
   ob->set_money("gold",random(10)+4);
   ob->set_money("electrum",random(20)+3);
   ob->set_money("silver",random(30)+5);
   ob->move(TO);
   ob = new(OBJ2"pouch");
   ob->move(TO);
   new(OBJ2"gem")->move(ob);
   new(OBJ2"gem")->move(ob);
   new(OBJ2"gem")->move(ob);
   DESK = 1;
   return 1;
}
