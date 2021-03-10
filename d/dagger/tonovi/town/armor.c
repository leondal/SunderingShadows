//updated by Circe 9/7/04 with new desc
#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_indoors(1);
    set_name("Tonovi Armor Shop");
    set_short("Tonovi Armor Shop");
    set_long("%^BOLD%^%^GREEN%^Tonovi Armor Shop%^RESET%^\n"+
       "This armor shop is obviously well-funded and does "+
       "quite a brisk business.  The armorer proudly provides "+
       "all the armor to the %^BOLD%^%^GREEN%^Tonovi Guard"+
       "%^RESET%^, a fact he often mentions with a hint of "+
       "smugness.  The building itself is made of mortared "+
       "%^BOLD%^stone walls %^RESET%^with a thick %^BOLD%^"+
       "%^BLACK%^curtain %^RESET%^blocking off the back wall.  "+
       "No sign of a fireplace is in this room, hinting that "+
       "the forge must be behind the curtain.  A tall "+
       "%^BOLD%^stone counter %^RESET%^stands near the center "+
       "of the room, and around it are various pieces of "+
       "%^BOLD%^armor %^RESET%^displayed in cases or on "+
       "racks.  The %^BLUE%^suits of fullplate %^RESET%^"+
       "and %^BOLD%^shields %^RESET%^are displayed prominently, "+
       "while the %^ORANGE%^leather armors %^RESET%^are tucked "+
       "away to the side, almost as if they were being hidden.\n");
/*Original Description
    set_long(
    "You have entered a quaint, but large, armor shop.  You can see armor pieces all over the room as you glance about.  In one corner behind a partially open curtain you can see several finely crafted armors."
    );
*/
    set_items(([
       ({"wall","walls","stone walls"}) : "The walls of the "+
          "building are quite well-made, fashioned of stone "+
          "fitted with mortar - quite the expensive undertaking.  "+
          "One would assume the shopkeeper himself probably "+
          "did not build this on his own, but had a bit of "+
          "help from the %^BOLD%^%^GREEN%^Tonovi Guard%^RESET%^.",
       ({"curtain","thick curtain","back wall"}) : "The back wall "+
          "is obscured by a thick %^BOLD%^%^BLACK%^black curtain"+
          "%^RESET%^ that effectively keeps all the uglier "+
          "workings of the shop out of sight.  It leaves the "+
          "store with a clean appearance, though you can still "+
          "hear the ringing of hammer and anvil from behind the "+
          "curtain.",
       ({"counter","stone counter"}) : "The stone counter adds "+
          "to the crisp appearance of the shop.  Nothing at all "+
          "clutters its surface.",
       ({"armor","armors","racks","cases"}) : "Wooden cases and "+
          "racks support various pieces of metal armor - shields, "+
          "gauntlets, greaves, shoulderplates, and whole suits "+
          "of armor.  Fullplate seems to be quite popular here "+
          "in Tonovi, and several suits fitted with fluting and "+
          "spikes are displayed as well.",
       ({"leather","leather armor","leather armors"}) : "%^ORANGE%^"+
          "The few suits of leather armor the craftsman has "+
          "have been placed into one corner of the room, almost "+
          "out of sight.  It seems they must not be in high "+
          "demand here."
    ]));
    set_smell("default","The acrid scent of fire is strong in the air.");
    set_listen("default","The clang of a hammer on metal rings in your ears.");
/*
    set_items( ([
"flame" : "Never seen a fire before?",
    "armor" : "Ooohhhh  shiny",
    ]) );
*/
    set_exits( ([
      "north" : RPATH "street6",
    ]) );
}

void reset(){
::reset();
    if(!present("thobe"))
      new(MPATH "thobe")->move(TO);
}
