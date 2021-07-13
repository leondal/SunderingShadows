// Chernobog (4/4/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Shadow Coliseum");
    set_short("%^RESET%^%^BOLD%^T%^CYAN%^rain%^RESET%^%^CYAN%^ing %^BOLD%^%^WHITE%^H%^CYAN%^al%^RESET%^%^CYAN%^l%^RESET%^");
    set_long("%^RESET%^%^CYAN%^These halls are much more sparse than the concourse up above. Gone are the %^BOLD%^%^BLACK%^on%^WHITE%^y%^BLACK%^x t%^RESET%^i%^BOLD%^%^BLACK%^l%^WHITE%^e%^BLACK%^s%^RESET%^%^CYAN%^, replaced with %^WHITE%^r%^BOLD%^ou%^RESET%^g%^BOLD%^h s%^RESET%^t%^BOLD%^on%^RESET%^e %^BOLD%^s%^RESET%^l%^BOLD%^ab%^RESET%^s %^CYAN%^that offer much better footing for those in training. %^RED%^T%^BOLD%^o%^ORANGE%^r%^RED%^c%^RESET%^%^RED%^h%^BOLD%^e%^ORANGE%^s %^RESET%^%^CYAN%^have been set in sconces spaced along the walls, the flickering flames scattering %^BOLD%^%^BLACK%^twisted shadows %^RESET%^%^CYAN%^along the far walls. A collection of %^WHITE%^t%^ORANGE%^r%^WHITE%^a%^BOLD%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^i%^RESET%^n%^ORANGE%^g %^BOLD%^%^WHITE%^d%^RESET%^u%^ORANGE%^m%^WHITE%^m%^BOLD%^i%^RESET%^%^ORANGE%^e%^WHITE%^s %^CYAN%^have been stacked against one of the walls and there are square %^BOLD%^%^BLACK%^slots %^RESET%^%^CYAN%^carved into the floor at odd intervals%^BOLD%^%^BLACK%^.%^RESET%^");
    set_smell("default","The cool damp air has the vague scent of mildew");
    set_listen("default","You can hear the echoes of footsteps further down the hall.");
    set_items(([
        ({"floor","stone slabs","slabs"}) : "%^BOLD%^%^BLACK%^Large %^RESET%^%^CYAN%^slabs o%^BOLD%^%^BLACK%^f crudely cut %^RESET%^gray stone %^BOLD%^%^BLACK%^have been layered together, mortared in place and evened out with steady foot traffic. There are odd %^RESET%^%^RED%^di%^BOLD%^sc%^RESET%^%^RED%^o%^BOLD%^l%^RESET%^%^RED%^or%^BOLD%^at%^RESET%^%^RED%^io%^BOLD%^n%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^here and there in the %^RESET%^stone%^BOLD%^%^BLACK%^.%^RESET%^",
        "dummies" : "%^BOLD%^%^BLACK%^These dummies are %^RESET%^%^ORANGE%^wooden frames %^BOLD%^%^BLACK%^covered in %^WHITE%^w%^RESET%^h%^BOLD%^it%^RESET%^e %^BOLD%^pa%^RESET%^d%^BOLD%^di%^RESET%^n%^BOLD%^g%^BLACK%^. They have been stacked against the wall, ready to be used for training practice. Each dummy has a square peg base. You can %^WHITE%^<%^RESET%^retrieve dummy%^BOLD%^> %^BLACK%^to grab one for practice, and you can %^WHITE%^<%^RESET%^return dummy%^BOLD%^> %^BLACK%^when finished.%^RESET%^",
        "slots" : "%^BOLD%^%^BLACK%^These square holes would be a perfect fit for the %^RESET%^t%^ORANGE%^r%^BOLD%^%^WHITE%^a%^RESET%^i%^BOLD%^ni%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g %^RESET%^d%^BOLD%^u%^RESET%^%^ORANGE%^m%^WHITE%^m%^BOLD%^i%^RESET%^e%^ORANGE%^s%^BOLD%^%^BLACK%^. They are deep enough to keep them secure, even after a few solid hits during training.%^RESET%^",
        ({"torches","sconces","shadows"}) : "%^BOLD%^%^BLACK%^Simple %^RED%^t%^ORANGE%^o%^RED%^r%^RESET%^%^RED%^c%^BOLD%^h%^ORANGE%^e%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^sit in %^RESET%^wrought iron sconces %^BOLD%^%^BLACK%^spaced around the hall. The flickering light offers a %^RESET%^%^RED%^primal %^BOLD%^%^BLACK%^insinuation down here.%^RESET%^",
        ]));
}

