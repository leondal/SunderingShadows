#include <std.h>
#include <objects.h>
#define RUNEPLACE "/d/islands/common/eldebaro/rune_placer.c"
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() 
{
    ::create();
    set_property("light",3);
    set_property("no teleport",1);
    set_property("indoors",0);
    set_climate("desert");
    set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_name("A vast sandscape");
    set_short("%^RESET%^%^ORANGE%^A vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^");
    set_listen("default", "%^CYAN%^\nThe loud slapping of water echoes all around you "
    "here, as the winds continue to increase in ferocity.%^RESET%^");

    set_long("%^ORANGE%^A vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ "+
        "stretches out before you. The sand is %^BOLD%^%^BLACK%^"+
        "dark%^RESET%^%^ORANGE%^ and wet making it difficult to walk through. There are rolling %^BOLD%^"+
        "sand dunes%^RESET%^%^ORANGE%^ which never stay in the same place for long, as the wind here is "+
        "increasing v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
        "n%^BOLD%^%^MAGENTA%^t%^RESET%^%^ORANGE%^ and ch%^BOLD%^%^BLACK%^ao%^BOLD%^%^WHITE%^tic%^RESET%^%^ORANGE%^, "+
        "and causes them to shift continually. In fact, the wind almost seems"+
        " as if something or someone is controlling it. Judging by the cl%^BOLD%^%^WHITE%^ou%^RESET%^%^ORANGE%^ds "+
        "hanging heavily over the island it looks like a st%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^rm "+
        "of %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
        "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^ "+
        "proportions is just over the horizon. There are many %^BOLD%^palm trees%^RESET%^%^ORANGE%^ "+
        "dotting the s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^, "+
        "and they are blowing about crazily in the wind. Some of them have actually been uprooted and many of the ones that "+
        "remain standing are br%^BOLD%^o%^RESET%^%^ORANGE%^k%^BOLD%^e%^RESET%^%^ORANGE%^n over. "+
        "%^RESET%^%^ORANGE%^The forboding ocean collides v%^BOLD%^%^MAGENTA%^i%^RESET%^"+
        "%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
        "n%^BOLD%^%^MAGENTA%^tl%^RESET%^%^ORANGE%^y with the s%^BOLD%^a%^RESET%^%^ORANGE%^"+
        "ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ to the south. A series of "+
        "wooden planks and piers extend into the ocean, serving as a makeshift dock.%^RESET%^.\n");
        
    set_smell("default", "%^YELLOW%^\nA tranquil odor from the sea assaults you and mixes "
        "with something else that you are not quite able to discern.%^RESET%^");

    set_exits(([
        "north" : "/d/islands/common/eldebaro/newrooms/room22",
        "west" : "/d/islands/common/eldebaro/newrooms/room7",
        "east" : "/d/islands/common/eldebaro/newrooms/room8",
    ]));

    set_items(([
        ({"pier", "dock"}) : "%^RESET%^%^MAGENTA%^A series of wooden planks and piers extend into the ocean from "+
        "here, they serve as a makeshift dock.",
        ({"storm", "clouds", "storm clouds", "heavy storm clouds"}) : (:TO, "cloud_desc":),
    ]));
}

void reset()
{
    ::reset();
    if(!present("profile")) 
    {
        new("/d/islands/common/eldebaro/profile")->move(this_object());
    }
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

string cloud_desc()
{
    string current_location, ret;
    current_location = RUNEPLACE->get_current_location();
    ret = "%^BOLD%^%^BLACK%^The clouds "+
        "that hang over the island look nightmarish. Simply looking up at them you get a terribly feeling in "+
        "the pit of your stomach. It is as if there is a storm of apocalyptic proportions hanging just over the "+
        "horizon. It seems like something is keeping it at bay, at least for the time being, but you are "+
        "unsure of what or for how long that will last.%^RESET%^";    
    if(stringp(current_location))
    {
        if(current_location != "" && current_location != "NIL")
        {
            ret += "%^BOLD%^%^BLACK%^ Bolts of %^BOLD%^%^YELLOW%^lightning%^BOLD%^%^BLACK%^"+
            " zap toward "+current_location+"!%^RESET%^";
        }
    }
    return ret;
}
