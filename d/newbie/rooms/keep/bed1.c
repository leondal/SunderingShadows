#include <std.h>
#include "../inherit/keep.h"
inherit CVAULT;

int FOUND;

void create() {
   set_monsters(({MONS+"xvart"}),({1}));
   ::create();
   set_repop(40);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("Bedroom in a ruined keep");
   set_short("%^CYAN%^Bedroom in a ruined keep%^RESET%^");
   set_long("%^CYAN%^Bedroom in a ruined keep%^RESET%^\n"
"This room appears to have once been a bedroom, though it has long since fallen "
"into disrepair.  The %^BLUE%^walls %^RESET%^are crumbling, full of holes and "
"cracks that let in the weather.  A layer of dust and dirt covers everything, "
"from the %^ORANGE%^floor %^RESET%^to the remnants of %^RED%^furniture "
"%^RESET%^that lie broken around the room.  Streaks of mud and patches of "
"%^GREEN%^moss %^RESET%^still further add to the poor state of the chamber.  "
"Shredded %^MAGENTA%^drapes %^RESET%^and %^CYAN%^curtains %^RESET%^hang limply "
"from broken pieces of furniture, or lie strewn about the floor.\n");
   set_smell("default","The air is filled with dust.");
   set_listen("default","The wind whistles through the cracks in the walls.");
   set_items(([
     ({"walls","holes","cracks"}) : "%^BLUE%^The stone walls that border the "
"room are in moderate shape.  They don't look as if they'll fall down any time "
"soon, but there are enough holes and cracks running through some blocks, "
"letting in the wind and allowing moisture to creep inside.",
     ({"floor","dust","dirt","mud"}) : "%^ORANGE%^The floor is made of stone "
"bricks and is covered in dirt and dust.  Streaks of mud have been tracked "
"across it, and patches of %^GREEN%^moss %^ORANGE%^spot the floor and "
"walls.%^RESET%^",
     ({"curtains","drapes","furniture"}) : "%^MAGENTA%^Tattered remnants of "
"drapes and curtains lie strewn across the floor, or snagged on pieces of "
"broken furniture.  You suspect some of the pieces might once have been part of "
"a bed, a cupboard, and perhaps a chair as well.  Across the room, a single "
"%^YELLOW%^dresser%^RESET%^%^MAGENTA%^ is still intact, perhaps you should take "
"a look at it?%^RESET%^",
     "dresser" : "%^MAGENTA%^This dresser seems to be the only piece of "
"furniture still intact.  It is a little damaged, but perhaps you could still "
"find something of worth in it if you tried to %^YELLOW%^search %^RESET%^"
"%^MAGENTA%^it?%^RESET%^",
     "moss" : "%^GREEN%^Patches of moss have grown over the walls and floor.  "
"They are wet and slimy, making footing treacherous in some places.%^RESET%^",
   ]));
   set_exits(([
     "south" : ROOMS"keep4",
   ]));
   set_door("door",ROOMS"keep4","south",0);
   set_door_description("door","%^ORANGE%^This door has become a little stiff "
"over the years, and would require effort to open.  A thick iron lock holds it "
"shut.%^RESET%^");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}

void init() {
   ::init();
   add_action("search_fun","search");
}

void reset() {
   ::reset();
   FOUND = 0;
}

int search_fun(string str) {
   if(!str) {
     tell_object(TP,"%^ORANGE%^You take a careful look around the room.  The "
"damage to the room doesn't leave a lot of interest to search through, but "
"perhaps there could be something in amongst the damaged %^MAGENTA%^furniture"
"%^ORANGE%^.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" takes a look around the room"
".%^RESET%^",TP);
     return 1;
   }
   if(str == "furniture") {
     tell_object(TP,"%^MAGENTA%^Most of the furniture is broken beyond repair "
"or value.  There are remains of what might have been a bed, and a chair too.  "
"The only intact piece worth looking at is a %^YELLOW%^dresser %^RESET%^"
"%^MAGENTA%^in the corner of the room.%^RESET%^");
     return 1;
   }
   if(str == "dresser") {
     if(FOUND) {
       tell_object(TP,"%^ORANGE%^You search through the dresser and find "
"nothing of interest, but it does appear as though someone has already searched "
"through here recently.%^RESET%^");
       tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the dresser but "
"doesn't seem to find anything.%^RESET%^",TP);
       return 1;
     }
     tell_object(TP,"%^ORANGE%^You search through the dresser and find "
"something sparkly!%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through the dresser and "
"appears to find something.%^RESET%^",TP);
     switch(random(10)) {
       case 0..1: new(CLOTHING"c_bracelet")->move(TO); break;
       case 2..3: new(CLOTHING"c_necklace")->move(TO); break;
       case 4..5: new(CLOTHING"c_ring")->move(TO); break;
       case 6..7: new(CLOTHING"c_clasp")->move(TO); break;
       case 8..9: new(CLOTHING"c_pendant")->move(TO); break;
     }
     FOUND = 1;
     return 1;
   }
   return 0;
}
