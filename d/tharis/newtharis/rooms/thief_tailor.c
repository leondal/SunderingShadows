//thief_tailor.c - new store for Tharis by Circe 9/9/04
// repurposing this to the new thieves guild entry. Let's give Manuel some air time! N, 12/15.
#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no sticks", 1);
   set_property("light",2);
   set_indoors(1);
   set_name("A Small Back Alley Shop");
   set_short("A Small Back Alley Shop");
   set_long("%^YELLOW%^A Small Back Alley Shop%^RESET%^\n"+
      "The %^BOLD%^%^BLACK%^shadowy alcove %^RESET%^outside "+
      "leads into this small shop, "+
      "almost entirely hidden from view.  It looks as though "+
      "this must once have been a much larger shop in a more "+
      "reputable building, but much of it has now been closed "+
      "off.  All that is left is this simple room, which consists "+
      "of many %^ORANGE%^crates%^RESET%^, %^YELLOW%^shelves"+
      "%^RESET%^, and %^CYAN%^piles %^RESET%^of various goods.  "+
      "Despite the transitory looking nature of the shop, "+
      "there is a %^BOLD%^%^BLACK%^padded leather chair %^RESET%^"+
      "sitting behind a small %^ORANGE%^wooden table %^RESET%^"+
      "with %^BOLD%^scuffmarks %^RESET%^on its edge that indicate "+
      "a confident pair of feet are often propped upon it.\n");
   set_smell("default","The smells of the city outside have made it in here.");
   set_listen("default","The bustle of the city outside can be heard here.");
   set_items(([
      ({"table","wooden table"}) : "The small wooden table "+
         "looks to be one of the few permanent pieces of "+
         "furniture in the room.  Scuffmarks are on the back "+
         "edge, just in front of the chair.",
      ({"crates","shelves","piles","goods"}) : "All of the "+
         "goods in the shop look to be somewhat hastily unpacked "+
         "and only partially displayed.  There seems to be no "+
         "rhyme nor reason to the items here - though many of "+
         "them look to be quite nice.  Open crates and boxes "+
         "are stacked beneath the shelves lining the walls, all "+
         "piled with clothing.",
      ({"chair","padded chair","padded leather chair"}) : "The "+
         "chair is by far the nicest piece of furniture in the "+
         "room and is still in great shape despite its obvious "+
         "use.  The chair has been made to lean back and swivel, "+
         "allowing the owner to sit in it and prop his feet up.",
      ({"marks","scuffmarks"}) : "The scuffmarks are clearly from "+
         "booted feet being propped upon the table."
   ]));

   set_exits(([
      "north" : ROOMS"east3",
   ]));
}

void reset(){
   ::reset();
   if(!present("manuel")) find_object_or_load(MOBS"manuel")->move(TO);
}

void init() {
    ::init();
    add_action("make", "make");
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int make(string str){
    if(str != "thief sign") return 0;
    if(TP->query_invis()){
        tell_object(TP, "You sign to the room that you are a thief. You don't think anyone noticed.");
        return 1;
    }
    if(!present("manuel")) return 0;
    if(!TP->is_class("thief") && !TP->is_class("bard")) {
        tell_object(TP, "Manuel considers you with suspicion, but nonetheless he steps aside, to allow you access to the door in the back of the room.");
        tell_room(ETP, TPQCN+" makes strange gestures towards Manuel, then heads towards a door in the back.", TP);
        TP->move_player(ROOMS"tguild");
    }
    else {
        tell_object(TP, "You make the thieves sign to Manuel. He gives a subtle nod and steps aside, to allow you access to the door in the back.");
        if(random(40) > (TP->query_stats("dexterity") + TP->query_stats("intelligence"))) tell_room(ETP, "You notice "+TPQCN+" making a strange sign to Drisman.", TP);
        TP->move(ROOMS"tguild");
        TP->describe_current_room(1);
    }
    return 1;
}