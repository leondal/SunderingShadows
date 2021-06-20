/*
  Chamber of Whispers
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/std/templemisc";

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_temple("ashra");
    set_name("Chamber of whispers"); 
    set_short("%^BOLD%^%^BLACK%^Chamber of whispers%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The billowing wisps of black cloth hanging shroud-like across the entrance give way to a sea of darkness that hovers thick in the air. Underfoot the floor is lost in a miasma of shadow that creeps along at ankle height like a rolling fog.. Thick black spines curve upward from the balconies edge like twisted taloned fingers. Hanging from each of these spines are small %^RESET%^cage lanterns%^BOLD%^%^BLACK%^ that cast the surroundings in a %^RESET%^%^MAGENTA%^fl%^BOLD%^i%^RESET%^%^MAGENTA%^ck%^BOLD%^e%^RESET%^%^MAGENTA%^r%^BOLD%^i%^RESET%^%^MAGENTA%^ng %^BOLD%^violet light%^BLACK%^. Dominating the center of the room is an enormous %^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ound tabl%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ surrounded by smaller comfortable looking chairs. Rising from the rear of the balcony facing toward the large table is a jagged throne of gl%^WHITE%^i%^BLACK%^tter%^WHITE%^i%^BLACK%^ng jet that is flanked by two %^RESET%^wra%^BOLD%^i%^RESET%^thly f%^BOLD%^i%^RESET%^gures%^BOLD%^%^BLACK%^. Beyond the throne and the balcony itself, floating within the shade is an enormous orb of solid darkness encased in a corona of %^MAGENTA%^violet flame%^BLACK%^. Below the balcony, you can barely make out the %^MAGENTA%^light%^BLACK%^ of the %^RESET%^%^MAGENTA%^Chapel windows %^BOLD%^%^BLACK%^far below. All around you, whispers echo through the dark and you cannot help but wonder what secrets these ephemeral voices hold.%^RESET%^ ");
    set_smell("default","%^MAGENTA%^The heady, sweet aroma of an exotic incense is in the air.%^RESET%^");
    set_listen("default","%^MAGENTA%^You hear the soft rustle of cloth, clinking of swaying chains and the whispers that fill the air around you.%^RESET%^");
    set_items(([
        ({"shadow","shade","darkness"}) : "%^BOLD%^%^BLACK%^All around you, the air is filled with a pervasive gloom that whirls and flows like a sea of darkness. Dark shapes swim through this sea just beyond your vision revealed only barely by the %^RESET%^%^MAGENTA%^fl%^BOLD%^i%^RESET%^%^MAGENTA%^ck%^BOLD%^e%^RESET%^%^MAGENTA%^r%^BOLD%^i%^RESET%^%^MAGENTA%^ng %^BOLD%^lantern light%^BLACK%^.",
        ({"lanterns","spines","lantern","spine"}) : "%^BOLD%^%^BLACK%^Like the taloned fingers of some demonic giant, curving spines curl inward from the balcony rail. Hanging from swaying chains at the tip of each of these spines are %^RESET%^ivory cage lanterns %^BOLD%^%^BLACK%^that hold %^RESET%^%^MAGENTA%^fl%^BOLD%^i%^RESET%^%^MAGENTA%^ck%^BOLD%^e%^RESET%^%^MAGENTA%^r%^BOLD%^i%^RESET%^%^MAGENTA%^ng orbs of %^BOLD%^violet light%^BOLD%^%^BLACK%^.%^RESET%^",
        ({"throne"}) : "%^BOLD%^%^BLACK%^Rising out of the murk that shrouds the floor, this gl%^WHITE%^i%^BLACK%^tter%^WHITE%^i%^BLACK%^ng p%^WHITE%^i%^BLACK%^ece of jet has been fashioned into an intimidating throne. Wicked %^RED%^spines %^BLACK%^and %^RED%^barbs%^BLACK%^ adorn its back and arms and %^MAGENTA%^glittering amethyst%^BLACK%^ gems %^MAGENTA%^gl%^RESET%^%^MAGENTA%^o%^BOLD%^w %^BLACK%^softly at the ends of each armrest. Soft %^RESET%^%^MAGENTA%^violet cushions %^BOLD%^%^BLACK%^provide a sinfully comfortable seat worthy of royalty.%^RESET%^",
        ({"orb","eye"}) : "%^BOLD%^%^BLACK%^Floating high above the balcony is the central eye of the darkness that flows throughout the temple. Amorphous tendrils wriggle and writhe outward from the orb all surrounded by the %^RESET%^%^MAGENTA%^purple aura %^BOLD%^%^BLACK%^of %^RESET%^%^MAGENTA%^flame %^BOLD%^%^BLACK%^that envelopes the orb itself. As you look on the orb you cannot help but feel a sense of awareness from within it..almost as though it is looking right back at you....%^RESET%^",
        ({"floor"}) : "%^BOLD%^%^BLACK%^The shadows swirl around your feet, concealing the floor like a thick fog.%^RESET%^",
        ({"ceiling"}) : "%^BOLD%^%^BLACK%^You cannot see the ceiling through the impenetrable darkness overhead and it leaves you wondering just how high this tower rises.%^RESET%^",
        ({"cloth","shroud"}) : "%^BOLD%^%^BLACK%^These wisps of gauzy black cloth billow softly across the archway, partially concealing the landing that lies beyond.%^RESET%^",
    ]));
    set_exits(([
       "south" : "balcony",
    ]));
}

/*
Items: Obsidian round table    Descrip: %^BOLD%^%^BLACK%^This luxurious round table rises from a central pillar that is anchored to the floor somewhere beneath the murky darkness underfoot. A %^RESET%^%^MAGENTA%^ring %^BOLD%^%^BLACK%^of %^RESET%^%^MAGENTA%^deep purple %^BOLD%^%^BLACK%^pine surrounds the glossy obs%^WHITE%^i%^BLACK%^d%^RESET%^i%^BOLD%^a%^BLACK%^n disk set in its center. The surface of the obsidian is absolutely flawless and refl%^RESET%^e%^BOLD%^%^BLACK%^ct%^WHITE%^i%^BLACK%^ve like a pitch black %^RESET%^mirror%^BOLD%^%^BLACK%^. Surrounding the table are a collection of %^RESET%^%^MAGENTA%^matching chairs%^BOLD%^%^BLACK%^, %^RESET%^%^MAGENTA%^dark purple pine %^BOLD%^%^BLACK%^with glossy black cushions.%^RESET%^
                                             *Acts as mirror for scrying*

Echoes : %^BOLD%^%^BLACK%^A serpentine tendril snakes out of the darkness overhead, reaching toward you before diving back into the murky sea.%^RESET%^
       
             %^BOLD%^%^BLACK%^A %^BLUE%^c%^CYAN%^o%^BLUE%^ld %^CYAN%^shiver %^BLACK%^runs up your spine as you suddenly become aware of some terrible presence watching over you...%^RESET%^
           
            %^BOLD%^%^BLACK%^The shade overhead ripples as something large passes just above its surface.%^RESET%^

      
            %^BOLD%^%^BLACK%^The %^WHITE%^wr%^CYAN%^a%^WHITE%^ith%^CYAN%^l%^WHITE%^y g%^CYAN%^u%^WHITE%^ar%^CYAN%^d%^WHITE%^s %^BLACK%^fl%^WHITE%^i%^BLACK%^ck%^WHITE%^e%^BLACK%^r and their burning %^RESET%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t e%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s seem to bore into you.%^RESET%^

Guards: %^BOLD%^C%^CYAN%^e%^WHITE%^l%^CYAN%^e%^BLACK%^s%^WHITE%^ti%^BLACK%^a%^WHITE%^l wr%^CYAN%^a%^BLACK%^i%^WHITE%^th%^RESET%^		

Descrip: %^BOLD%^%^BLACK%^Tattered black robes hang loosely on the %^WHITE%^tr%^CYAN%^a%^WHITE%^nsl%^CYAN%^u%^WHITE%^cent eth%^CYAN%^e%^WHITE%^re%^CYAN%^a%^WHITE%^l fl%^CYAN%^e%^WHITE%^sh %^BLACK%^of this otherwordly being. Long dark hair spills down across its shoulders framing a %^WHITE%^androgynously beautiful face%^BLACK%^. Its %^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^y%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^s are empty black pools with glowing %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rpl%^BOLD%^e %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^p%^BOLD%^i%^RESET%^%^MAGENTA%^ls %^BOLD%^%^BLACK%^that look at the living with a cold hunger. Terrible black taloned hands curl at its sides eagerly and folded on its back are a pair of raven black wings.%^RESET%^
*/