#include "/d/islands/dallyh/fways.h"
inherit HEALER;

void create() 
{
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_short("%^RESET%^%^ORANGE%^The healing shelter%^RESET%^");
    set_long("%^RESET%^%^GREEN%^From here you can tell that this large shelter "+
    "has not been built up into the trees, but rather it is part of them. "+
    "It looks %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^ and %^BOLD%^%^WHITE%^sturdy"+
    "%^RESET%^%^GREEN%^. You are not sure if it was created or simply developed, it is "+
    "impossible to tell. This particular one has been devoted to providing healing "+
    "services. There are %^RESET%^%^ORANGE%^herbs%^RESET%^%^GREEN%^,"+
    " %^RESET%^%^ORANGE%^balms%^RESET%^%^GREEN%^, and all types of %^BOLD%^%^BLACK%^substances"+
    "%^RESET%^%^GREEN%^ packed into %^RESET%^%^ORANGE%^wooden shelves%^RESET%^%^GREEN%^ "+
    "which line the northern and southern walls of this shelter. The natural wooden floor is "+
    "much smoother here and placed strategically across it are very soft and thick mats.%^RESET%^");
    
    
    set_smell("default", "The strong odor of herbs, balms, and other substances hangs heavily in the air.");
    set_listen("default","The sounds of forest life echo all around you.");
    set_items( ([ 
        ({"shelter", "shelters", "healing shelter", "trees"}) : "%^RESET%^%^GREEN%^This large "+
        "shelter has not been built up into the trees. It is actually a part of the trees. "+
        "It is almost as if it inside of them and the trees actually seem to be continually "+
        "growing around it, providing it with an enormous amount of protection. It seems very "+
        "sturdy and quite ancient.%^RESET%^",
        
        ({"herbs", "balms", "substances", "shelves", "wooden shelves"}) : "%^RESET%^%^ORANGE%^"+
        "These wooden shelves are filled with herbs, balms, and other unknown substances. There "+
        "purpose is quite clear, to heal the sick or injured.%^RESET%^",
        
        ({"wooden floor", "natural wooden floor", "floor"}) : "%^RESET%^%^ORANGE%^The natural "+
        "wooden floor here is much smoother than the other shelters. As if it has been formed so that "+
        "those who find themselves laying on it will have some measure of peace and comfort.%^RESET%^",
        
        ({"mats", "soft mats", "thick mats"}) : "%^BOLD%^%^MAGENTA%^These thick and soft mats are a "+
        "wide variety of color. However, each looks very clean, as if the person responsible for cleaning "+
        "up after what happens here takes their job very seriously.%^RESET%^",
        
      ]) );
    set_name("Raliat");
    set_exits( ([
            "west" : FRPATH "road3",
      ] ));
}

void reset()
{
    ::reset();
    if(!present("raliat"))
          new( FMPATH "raliat")->move(TO);
}
