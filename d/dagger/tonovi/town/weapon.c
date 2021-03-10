//updated by Circe 9/7/04 with new desc
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_property("smithy",1); 
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("store");
    set_name("Tonovi Weapon Shop");
    set_short("Tonovi Weapon Shop");
/*
    set_long(
    "Here in this small weapon shop you can see the smith working hard over the flame, forming a custom blade for one of the nobility of the city."
    );
Original Description
*/
    set_long("%^BOLD%^%^GREEN%^Tonovi Weapon Shop%^RESET%^\n"+
       "The weapon store here in Tonovi has an orderly appearance.  "+
       "The long %^BOLD%^%^BLACK%^counter %^RESET%^is made of "+
       "%^BOLD%^%^BLACK%^shadowood%^RESET%^ that has been highly "+
       "polished.  Matching %^BOLD%^%^BLACK%^weapon racks %^RESET%^"+
       "stand against the walls, holding various types of %^RED%^"+
       "weapons %^RESET%^ranging from the practical to the clearly "+
       "ornamental.  The far wall is dominated by a massive "+
       "%^RED%^fi%^BOLD%^re%^RESET%^%^RED%^place %^RESET%^with a "+
       "%^BOLD%^stone ledge %^RESET%^supporting a huge %^BOLD%^"+
       "%^BLACK%^iron anvil%^RESET%^.  A small rack of %^BOLD%^"+
       "hammers %^RESET%^and other tools stands on the edge of "+
       "it, with a pair of %^ORANGE%^gloves %^RESET%^always "+
       "within easy reach.\n");
    set_items(([
       ({"weapon","weapons","racks","rack"}) : "%^BOLD%^%^BLACK%^"+
          "The shadowood racks are well-made and support %^WHITE%^"+
          "weapons %^BLACK%^of various kinds - axes, swords, hammers, "+
          "polearms, even bows and arrows.  A rack right near the "+
          "counter supports several %^YELLOW%^ornamental weapons"+
          "%^BLACK%^ - mostly daggers and swords.  These are most "+
          "likely ment for ceremonies or for the nobles of the land.",
       ({"counter","shadowood counter"}) : "The long counter made "+
          "of %^BOLD%^%^BLACK%^shadowood %^RESET%^stands toward "+
          "the back of the room, allowing ample room behind it "+
          "for the forge.  It appears to serve two purposes - "+
          "an additional work table when needed and a place to "+
          "conduct business.  It is highly polished and clearly "+
          "well-cared-for.",
       ({"fireplace","forge","fire"}) : "%^RED%^The large fireplace "+
          "is the central point of the forge, and the fire is "+
          "kept constantly burning.",
       ({"ledge","stone ledge","anvil","iron anvil"}) : "The "+
          "stone ledge at the side of the fireplace supports a "+
          "huge %^BOLD%^%^BLACK%^iron anvil %^RESET%^that seems "+
          "to have been in place for many years.  The far edge "+
          "of the stone has been charred black, but it seems "+
          "free of any recent ash.",
       ({"tools","hammers","tool rack","gloves"}) : "The small "+
          "rack on the stone ledge holds tools for use in the "+
          "forge.  Here, hammers, tongs, and other needed "+
          "implements may be found for use, though you must "+
          "provide your own metal.  A pair of gloves or two "+
          "is always kept nearby."
    ]));
    set_smell("default", "The acrid scent of fire is strong on the air.");
    set_listen("default", "The clang of a hammer on metal rings in you ears.");
/*
    set_items(([
      "weapons" : "Yep, that's what's usually in weapon shops...  weapons.",
      "flame" : "Never seen a fire before?",
      "blade" : "The red hot blade glows as the smith pounds a shape to the weapon",
    ]));
*/
    set_exits(([
      "south" : RPATH "street5",
    ]));
}

void reset(){
::reset();
    if(!present("leknor"))
      new(MPATH "leknor")->move(TO);
}
