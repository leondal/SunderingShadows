#include <std.h>
#include <daemons.h>

inherit ROOM;


void create()
{
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(FRESH_BLAZE);
    set_short("%^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^e%^WHITE%^ren%^BOLD%^%^BLACK%^e %^RESET%^%^GREEN%^g%^WHITE%^r%^GREEN%^o%^BOLD%^v%^RESET%^%^GREEN%^e %^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^n %^WHITE%^Ara%^BOLD%^%^GREEN%^m%^BLACK%^ant%^RESET%^h %^BOLD%^%^GREEN%^I%^RESET%^slan%^BOLD%^%^GREEN%^d%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^S%^RESET%^%^GREEN%^e%^WHITE%^ren%^BOLD%^%^BLACK%^e %^RESET%^%^GREEN%^g%^WHITE%^r%^GREEN%^o%^BOLD%^v%^RESET%^%^GREEN%^e %^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^n %^WHITE%^Ara%^BOLD%^%^GREEN%^m%^BLACK%^ant%^RESET%^h %^BOLD%^%^GREEN%^I%^RESET%^slan%^BOLD%^%^GREEN%^d%^RESET%^
%^GREEN%^You stand in a grove of palm trees near the beach. The %^CYAN%^o%^BOLD%^%^WHITE%^ce%^RESET%^%^CYAN%^an%^RESET%^%^GREEN%^ could be seen in between palm t%^BOLD%^ree%^RESET%^%^GREEN%^s. Unnatural, but serene darkness envelops this place, broken by %^ORANGE%^star%^BOLD%^l%^RESET%^%^ORANGE%^ight%^RESET%^%^GREEN%^ and %^ORANGE%^fire%^WHITE%^fli%^ORANGE%^es%^GREEN%^ suspended in the air. A well of %^WHITE%^moon%^GREEN%^ light stands in the middle of this clearing.
");
    set_listen("default", "The ocean waves are somewhat relaxing as they lap against the beach...");
    set_exits(([
        "north" : "/d/islands/common/aramanth/room37",
    ]));
    set_items(([
                   ({"moon","sky"}):(:TO,"sky":),
                   "trees":"%^GREEN%^Palm trees surround you. They whisper quietly on the wind, in unison with waves in the distance",
                   "fireflies":"%^ORANGE%^Fireflies lighten the darkness." 
    ]));
}

string sky()
{
    int align;
    align = TP->query_alignment();

    if(align==6)
        return "%^BOLD%^%^BLACK%^You feel well known darkness. The black moon is up there in the sky, shining its black light down at you.";
    if(align<4)
        return "%^RESET%^%^WHITE%^Small grey m%^BOLD%^oo%^RESET%^n with a ring dominates the sky.";
    if(align<7)
        return "%^RESET%^%^WHITE%^Large white m%^BOLD%^oo%^RESET%^n dominates the sky.";
    
    return "%^WHITE%^Three tiny m%^BOLD%^oo%^RESET%^ns dance in the sky.";    
}

