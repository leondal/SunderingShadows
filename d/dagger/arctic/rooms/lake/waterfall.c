#include <std.h>
#include "../../arctic.h"
inherit ROOM;

int FLAG;

void create()
{
    ::create();

    set_name("A Large Waterfall");
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
    set_climate("arctic");
    set_property("light", 2);

    set_short("%^CYAN%^A spectacular waterfall%^RESET%^");
    set_long("%^BLUE%^The cascading waterfall plummets down over "
        "five hundred feet from the sheer granite face of the mountain "
        "far above.  Thousands of tiny ice crystals rain all around "
        "you as stray water freezes in the cold air before it makes "
        "its way down to the frozen floor of the lake.  The waterfall "
        "pours into a very large opening down under the ice of the "
        "lake sending a spray of water high into the air.  That spray of "
        "water is frozen into an icy rainbow.  Untold thousands of "
        "icicles hang from every imaginable place along the walls.%^RESET%^");

    set_smell("default", "The cool scent of fresh water invigorates you.");
    set_listen("default", "The roar of the waterfall drowns out the sound "
                          "of everything else around you.");
    set_items(([
        ({"road","path","trail"}) : "The path here is windblown and "
        "smooth, but not well traveled.",
        ({"water","waterfall"}) : "The plummeting descent of the "
        "waterfall is breathtaking.  Hundreds of feet through the "
        "open air to plunge headlong into the frozen lake.  It is "
        "very dark behind the waterfall.",
        ({"granite","wall","mountain"}) : "The towering granite walls "
        " mountain reach straight up all around the small lake.  It "
        "looks as if it was carved straight from the mountain stone by "
        "the flowing water over the centuries.",
        "icicles" : "Tens of thousands of icicles, ranging in size "
        "from that of a finger, to hundreds of feet long cling to "
        "the rocky face of the mountain all around.",
        "ice" : "Ice coveres everything in this cold place, it clings "
        "tenaciously to every surface, including you when you stand "
        "still for very long.",
        "crystals" : "Tiny frozen crystals of ice from the spray of the "
        "waterfall slam into the ice all around.  A frozen rain of ice "
        "that dances in the chill arctic air.  Some of the crystals "
        "shatter as they impact the ice, others stick and hold fast "
        "where they land, still other bounce back into the air.",
        "rainbow" : "The light through the mist from the waterfall "
        "creates a rainbow in the air far above you.",
        "opening" : "The waterfall plunges down through the large "
        "opening.  It would be almost impossible to get back out "
        "if you fall in here."]));

    set_search("default", "It is very dark behind the waterfall");
    set_search("waterfall", "On closer inspection, there seems to "
        "be a cave behind the waterfall.");

    set_exits(([
        "cave"    : CAVE"cave1",
        "south"   : LAKE"road8",
        "opening" : UW"uw2",
             ]));
    
    FLAG = 1;

    set_pre_exit_functions(({"cave"}),({"GoThroughDoor"}));

}

int GoThroughDoor()
{
    if(TO->id("arcticmon")) return 1;
    if(TP->query_true_invis()) return 1;
    if(FLAG)
    {
        if(!present("tempest")) { new(MON"arctic_tempest")->move(TO); }
        FLAG = 0;
    }
    if(present("face"))
    {
        tell_object(ETO,"The watery face will not let you "
            "enter the cave!\n");
        tell_room(ETP, "The watery face prevents "+TP->QCN+" from "
            "entering the cave!\n", TP);
        return 0;
    }
    return 1;
}

void reset()
{
    ::reset();
    if(!random(3)) FLAG = 1;
    return;
}
