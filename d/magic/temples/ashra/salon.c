/*
  Grand Salon
  
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
    set_name("Grand Salon"); 
    set_short("%^MAGENTA%^Grand Salon%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This vast and opulent salon is furnished sparsely around its edges with %^RESET%^%^MAGENTA%^plush velvet couches%^BOLD%^%^BLACK%^, %^RESET%^%^ORANGE%^small tables %^BOLD%^%^BLACK%^and %^RESET%^%^MAGENTA%^sitting cushions%^BOLD%^%^BLACK%^, while a pair of curving staircases stand on either side. Crouched along the balcony of the second floor you see several %^WHITE%^w%^BLACK%^i%^WHITE%^ng%^BLACK%^e%^WHITE%^d eff%^BLACK%^i%^WHITE%^g%^BLACK%^i%^WHITE%^es %^BLACK%^looking down upon this hall while dominating the center of the floor on a %^WHITE%^gl%^RESET%^e%^BOLD%^am%^RESET%^i%^BOLD%^ng %^BLACK%^on%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^x p%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^dest%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l is a large m%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rble st%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^tu%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^. The floor itself is covered in a %^RESET%^%^MAGENTA%^thick violet carpet %^BOLD%^%^BLACK%^that spans wall to wall disappearing into the murky darkness that creeps along the edges of the room. Immense s%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^lk%^RESET%^%^MAGENTA%^y %^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck c%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^rt%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ins drape down from the walls rippling and rolling in waves that reach the floor, a %^MAGENTA%^bright fiery motif %^BLACK%^licking along their edges. The walls themselves seem to climb a few stories upwards before vanishing into a shadowy haze. Countless %^MAGENTA%^orbs %^BLACK%^of flickering %^MAGENTA%^violet fire %^BLACK%^dot this haze like stars illuminating the area in a soft %^RESET%^%^MAGENTA%^eerie glow%^BOLD%^%^BLACK%^. Elegant %^WHITE%^g%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^m s%^BLACK%^t%^RESET%^%^MAGENTA%^u%^BOLD%^%^WHITE%^d%^BLACK%^d%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^d silver archways %^BLACK%^lead to dark halls in the east and west, while large foreboding double doors stand to the north and south.%^RESET%^");
    set_smell("default","%^MAGENTA%^A very light floral scent mixed with a hint of incense surrounds you.%^RESET%^");
    set_listen("default","%^MAGENTA%^A haunting wordless song full of sorrow and loss can be heard accompanied by the soft rustling of the curtains.%^RESET%^");
    set_items(([			
        ({"couches","couch"}) : "%^MAGENTA%^These deep violet couches are covered in soft velvet and gilded in elaborate %^BOLD%^%^BLACK%^adamantite frames%^RESET%^%^MAGENTA%^. The cushions are thick and comfortable and they look very inviting.%^RESET%^",
        ({"tables", "table" }) : "%^ORANGE%^Long low finely lacquored tables are set near each couch, each with a vase containing several %^BOLD%^%^BLACK%^black roses.%^RESET%^",
        ({"staircases", "staircase", "stairs"}) : "%^BOLD%^%^BLACK%^These curving staircases wind up to the balcony of the second floor, the soft %^RESET%^%^MAGENTA%^violet carpet %^BOLD%^%^BLACK%^flowing down them like a waterfall. The adamantine rails are gilded in %^WHITE%^silver %^BLACK%^and a pair of large %^RESET%^%^MAGENTA%^amethysts %^BOLD%^%^BLACK%^are imbedded deeply at their base.%^RESET%^",
        ({"effigies", "effigy", "angel", "angels"}) : "%^BOLD%^%^WHITE%^These alabaster angels are crouched in what appears to be %^RED%^agony%^WHITE%^, hands gripping the sides of their heads and clawing at their contorted features. %^BOLD%^%^BLACK%^Raven black wings%^WHITE%^ sprout from their back and are folded about them protectively as though to shield them from some %^RESET%^%^RED%^terrible evil%^BOLD%^%^WHITE%^. Their bodies are riddled with %^BLACK%^dark veins%^WHITE%^ that seem to pulse beneath the stone as they offer up their silent cries to the %^BOLD%^%^BLACK%^Primordial%^WHITE%^ before them.%^RESET%^",
        ({"marble statue", "statue" }) : "%^BOLD%^%^BLACK%^A woman of complete darkness is depicted here, her slender figure hidden beneath voluminous robes and her face behind a cr%^WHITE%^a%^BLACK%^ck%^WHITE%^e%^BLACK%^d yet %^RESET%^%^MAGENTA%^b%^BOLD%^e%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^t%^BOLD%^i%^RESET%^%^MAGENTA%^f%^BOLD%^u%^RESET%^%^MAGENTA%^l %^BOLD%^%^WHITE%^porcelain mask%^BLACK%^. Her arms are spread wide, %^CYAN%^invitingly %^BLACK%^as though she seeks to embrace all who set foot through the door. This glossy black marble statue radiates a supernatural presence, the power leaking off of it seeming to saturate the air around you. The %^RESET%^%^MAGENTA%^haunting song %^BOLD%^%^BLACK%^that drifts through the room seems to be coming from her.%^RESET%^",
        ({"carpet" }) : "%^MAGENTA%^As you look closer at this soft carpet you see that with each step you send a ripple along its surface, as though it were a liquid of some sort.%^RESET%^",
        ({"darkness", "murk" }) : "%^BOLD%^%^BLACK%^The inky darkness wriggles and crawls along the floor reaching out towards you hungrily whenever you venture near.%^RESET%^",
        ({"curtains" }) : "%^BOLD%^%^BLACK%^These l%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^str%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^us c%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^rt%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^in%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^are woven of the finest silks and wave gently on a phantom breeze making the walls appear almost alive.%^RESET%^",
        ({"ceiling", "haze" }) : "%^BOLD%^%^BLACK%^This black cloud roils across the ceiling of the chamber hiding it from view. Looking closer you think you can make out vague humanoid shapes moving within.%^RESET%^",
        ({"orbs", "stars" }) : "%^MAGENTA%^These flickering v%^BOLD%^i%^RESET%^%^MAGENTA%^ol%^BOLD%^e%^RESET%^%^MAGENTA%^t %^BOLD%^o%^RESET%^%^MAGENTA%^rbs illuminate the chamber in a soft glow that barely penetrates the %^BOLD%^%^BLACK%^night %^RESET%^%^MAGENTA%^like veil of %^BOLD%^%^BLACK%^shadows %^RESET%^%^MAGENTA%^sh%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^ou%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ing them. Beyond the d%^BOLD%^i%^RESET%^%^MAGENTA%^m l%^BOLD%^i%^RESET%^%^MAGENTA%^ght you can barely make out %^BOLD%^%^WHITE%^g%^RESET%^l%^BOLD%^e%^RESET%^a%^BOLD%^mi%^RESET%^n%^BOLD%^g %^RESET%^%^MAGENTA%^bits of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^er %^RESET%^%^MAGENTA%^reflecting from deep within haze.%^WHITE%^",
        ({"archway", "arch" }) : "%^BOLD%^%^WHITE%^These silver archways contain fanciful images of fey creatures, all with a notably %^BOLD%^%^BLACK%^dark cast%^WHITE%^ to the their beautiful features. %^RED%^Ruby %^WHITE%^tears fall from their sparkling %^MAGENTA%^amethyst eyes%^WHITE%^ as they cry out at the %^RESET%^%^MAGENTA%^purple rimmed%^BOLD%^%^BLACK%^ dark moon%^WHITE%^ that dominates the center of the archways. An %^BOLD%^%^BLACK%^impenetrable wall of darkness%^WHITE%^ is all that lies beyond.%^RESET%^",
    ]));
    set_exits(([
        "south" : "hall",
        "north " : "chapel",
        "up" : "balcony",
    ]));
    set_door("dark doors","hall","south",0);
    set_door_description("%^BOLD%^%^BLACK%^Dark doors%^RESET%^", "%^BOLD%^%^BLACK%^These large intimidating adamantium doors are of exquisite craft, their smooth surfaces glistening as though the metal had been freshly polished. On each door, shaped elegantly in the black metal is the silhouette of a voluptuous female form arms folded about her head, hair flying wildly about her. Directly behind the woman a crescent moon hangs precariously in the sky with some unidentifiable ichor dripping from it.. The doors appear quite sturdy.%^RESET%^");
    set_door("chapel door","chapel","north ",0);
    set_door_description("%^BOLD%^%^BLACK%^Large wooden double doors painted pitch black stand here. The doors are engraved with a sp%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^l p%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^tt%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rn of %^RESET%^%^MAGENTA%^wr%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^thing t%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^nt%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^cles %^BOLD%^%^BLACK%^emanating from a central %^RESET%^%^MAGENTA%^circle%^BOLD%^%^BLACK%^. They look very thick, and you can hear nothing from beyond them.%^RESET%^");
}