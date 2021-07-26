/*
  Salon Balcony
  
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
    set_property("light",0);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_temple("ashra");
    set_name("Salon Balcony"); 
    set_short("%^MAGENTA%^Salon Balcony%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Dominating staircases of grand presence embrace the expansive balcony over the salon below. Sprawling %^RESET%^MAGENTA%^carpets%^BOLD%^%^BLACK%^ lounge from one staircase to the other in %^MAGENTA%^bold %^RESET%^%^MAGENTA%^violet hues%^BOLD%^%^BLACK%^. A smooth railing of  adamantine spans the precipice while ringing the balcony are pedestals upon which sit the %^WHITE%^w%^BLACK%^i%^WHITE%^ng%^BLACK%^e%^WHITE%^d eff%^BLACK%^i%^WHITE%^g%^BLACK%^i%^WHITE%^es %^BLACK%^who's %^RED%^agonized%^BLACK%^ gazes are drawn to the salon below. Here the cascading curtains of deepening darkness suffocate the air with their roiling dance upon a phantom breeze. Lurking beyond reach the maleficent haze pervades those below with an impending dread. Countless %^RESET%^%^MAGENTA%^orbs%^BLACK%^%^BOLD%^ of flickering %^RESET%^%^MAGENTA%^violet %^BOLD%^fire%^BLACK%^ dot this haze like %^MAGENTA%^stars%^BLACK%^ illuminating the area in a soft eerie glow. Upon the east and west walls elegant %^BOLD%^%^MAGENTA%^gem %^WHITE%^st%^MAGENTA%^u%^WHITE%^dd%^MAGENTA%^e%^WHITE%^d silver archways%^BLACK%^ open into dark corridors. Centering the northern wall rests an extravagant archway bearing an abyssal visage and featuring billowing wisps of gauzy black cloth veiling the room ahead.%^RESET%^");
    set_smell("default","%^MAGENTA%^A very light floral scent mixed with a hint of incense surrounds you.%^RESET%^");
    set_listen("default","%^MAGENTA%^A haunting wordless song full of sorrow and loss can be heard accompanied by the soft rustling of the curtains.%^RESET%^");
    set_items(([   
       ({"staircases", "staircase", "stairs"}) : "%^BOLD%^%^BLACK%^These curving staircases wind up to the balcony of the second floor, the soft %^RESET%^%^MAGENTA%^violet carpet %^BOLD%^%^BLACK%^flowing down them like a waterfall. The adamantine rails are gilded in %^WHITE%^silver %^BLACK%^and a pair of large %^RESET%^%^MAGENTA%^amethysts %^BOLD%^%^BLACK%^are imbedded deeply at their base.%^RESET%^",
       ({"ceiling", "haze" }) : "%^BOLD%^%^BLACK%^This black cloud roils across the ceiling of the chamber hiding it from view. Looking closer you think you can make out vague humanoid shapes moving within.%^RESET%^",
       ({"orbs", "stars" }) : "%^MAGENTA%^These flickering v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^o%^RESET%^%^MAGENTA%^rbs illuminate the chamber in a soft glow that barely penetrates the %^BOLD%^%^BLACK%^night %^RESET%^%^MAGENTA%^like veil of %^BOLD%^%^BLACK%^shadows %^RESET%^%^MAGENTA%^sh%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ou%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ing them. Beyond the d%^BOLD%^i%^RESET%^%^MAGENTA%^m l%^BOLD%^i%^RESET%^%^MAGENTA%^ght you can barely make out %^BOLD%^%^WHITE%^g%^RESET%^l%^BOLD%^e%^RESET%^a%^BOLD%^mi%^RESET%^n%^BOLD%^g %^RESET%^%^MAGENTA%^bits of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^er %^RESET%^%^MAGENTA%^reflecting from deep within haze.%^WHITE%^",
       ({"curtains" }) : "%^BOLD%^%^BLACK%^These l%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^str%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^us c%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^rt%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^in%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^are woven of the finest silks and wave gently on a phantom breeze making the walls appear almost alive.%^RESET%^",
       ({"silver archway", "silver arch" }) : "%^BOLD%^%^WHITE%^These silver archways contain fanciful images of fey creatures, all with a notably %^BOLD%^%^BLACK%^dark cast%^WHITE%^ to the their beautiful features. %^RED%^Ruby %^WHITE%^tears fall from their sparkling %^MAGENTA%^amethyst eyes%^WHITE%^ as they cry out at the %^RESET%^%^MAGENTA%^purple rimmed%^BOLD%^%^BLACK%^ dark moon%^WHITE%^ that dominates the center of the archways. An %^BOLD%^%^BLACK%^impenetrable wall of darkness%^WHITE%^ is all that lies beyond.%^RESET%^",
       ({"effigies", "effigy", "angel", "angels"}) : "%^BOLD%^%^WHITE%^These alabaster angels are crouched in what appears to be %^RED%^agony%^WHITE%^, hands gripping the sides of their heads and clawing at their contorted features. %^BOLD%^%^BLACK%^Raven black wings%^WHITE%^ sprout from their back and are folded about them protectively as though to shield them from some %^RESET%^%^RED%^terrible evil%^BOLD%^%^WHITE%^. Their bodies are riddled with %^BLACK%^dark veins%^WHITE%^ that seem to pulse beneath the stone as they offer up their silent cries to the %^BOLD%^%^BLACK%^Primordial%^WHITE%^ before them.%^RESET%^",
       ({"archway","arch"}) : "%^BOLD%^%^BLACK%^Gauzy black cloth hangs in billowing wisps across the entrance here concealing the room beyond in near total darkness. A distorted demonic countenance is mounted here above the archway itself, its glowing violet eyes looking down on all who would dare enter here.%^RESET%^",
    ]));
    set_exits(([
        "down" : "/d/magic/temples/ashra/salon",
        "north" : "/d/magic/temples/ashra/chamber",
    ]));
}