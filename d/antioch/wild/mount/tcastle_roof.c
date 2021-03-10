#include <std.h>
#include <daemons.h>

#include "/d/antioch/areadefs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Rooftop of the castle");
    set_short("%^BOLD%^%^BLACK%^Rooftop of the castle%^RESET%^");
    set_long((:TO,"longdesc_fun":));
    set_smell("default",(:TO,"smell_fun":));
    set_listen("default","%^RESET%^%^CYAN%^Wind, %^BOLD%^%^BLACK%^thunder"
"%^RESET%^%^CYAN%^ and crashing %^BOLD%^%^CYAN%^waves%^RESET%^%^CYAN%^ create a "
"%^BOLD%^%^BLACK%^beautiful %^BOLD%^%^BLACK%^c%^BOLD%^%^CYAN%^a%^RESET%^"
"%^CYAN%^c%^BOLD%^%^BLACK%^oph%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^n"
"%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^ of noise.%^RESET%^");
    set_items(([
      "pool" : "%^RESET%^%^CYAN%^The water %^BOLD%^%^BLACK%^c%^BOLD%^%^CYAN%^h"
"%^BOLD%^%^BLACK%^ur%^BOLD%^%^CYAN%^n%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^ "
"tumultuously, goaded by the %^BOLD%^%^CYAN%^st%^RESET%^%^BLUE%^o"
"%^BOLD%^%^BLUE%^r%^BOLD%^%^CYAN%^m%^RESET%^%^CYAN%^ and %^BOLD%^%^BLUE%^w"
"%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^d%^RESET%^%^CYAN%^. The "
"pool is rectangular, and the bottom is lined with precious gems that "
"%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^t"
"%^BOLD%^%^BLACK%^t%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^RESET%^%^CYAN%^ in a "
"myriad of %^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^o%^BOLD%^%^CYAN%^l"
"%^RESET%^%^CYAN%^o%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^RESET%^%^CYAN%^, "
"creating a %^BOLD%^%^BLACK%^c%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^a"
"%^BOLD%^%^BLACK%^o%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^c"
"%^RESET%^%^CYAN%^ display on the choppy surface. Waves crash upon three "
"%^BOLD%^%^WHITE%^silver spires%^RESET%^%^CYAN%^ that jut upward, piercing the "
"%^BOLD%^%^BLACK%^dark clouds%^RESET%^%^CYAN%^ above.%^RESET%^",
      "sky" : "%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^st%^BOLD%^%^RED%^o"
"%^RESET%^%^MAGENTA%^r%^RESET%^%^RED%^m%^BOLD%^%^BLACK%^ eternally rages "
"overhead. Black clouds hang low in the gray sky, illuminated by %^BOLD%^"
"%^WHITE%^blinding flashes%^BOLD%^%^BLACK%^ of %^YELLOW%^lightning"
"%^BOLD%^%^BLACK%^. The clouds spiral around in a large, %^RESET%^dark"
"%^BOLD%^%^BLACK%^ v%^RESET%^o%^BOLD%^%^BLACK%^rt%^RESET%^e%^BOLD%^%^BLACK%^x. "
"%^RESET%^%^CYAN%^Wind%^BOLD%^%^BLACK%^ whips around you, tearing at your "
"clothing.%^RESET%^",
      "benches" : "%^BOLD%^%^BLACK%^Four marble benches surround the pool, one "
"on every side. You could probably sit there.%^RESET%^",
      "spires" : "%^BOLD%^%^WHITE%^Spiraling out of the pool are these three "
"spires. They look %^BOLD%^%^BLACK%^s%^RESET%^%^RED%^c%^MAGENTA%^o"
"%^BOLD%^%^BLACK%^rc%^RESET%^%^RED%^h%^ORANGE%^e%^BOLD%^%^BLACK%^d%^BOLD%^"
"%^WHITE%^ and worn, presumably from the %^YELLOW%^lightning%^BOLD%^%^WHITE%^ "
"that frequently strikes at them from the %^BOLD%^%^BLACK%^ra%^RESET%^g%^RED%^i"
"%^BOLD%^%^BLACK%^ng st%^RESET%^%^MAGENTA%^o%^BLUE%^r%^BOLD%^%^BLACK%^m"
"%^BOLD%^%^WHITE%^ above, traveling down the length of them and dispersing in "
"the %^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^a%^BOLD%^%^BLUE%^s"
"%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g "
"wav%^RESET%^%^GREEN%^e%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^ below.%^RESET%^",
      ({"ground","walkway"}) : "%^RESET%^%^GREEN%^The ground is covered in "
"%^BOLD%^%^BLACK%^dark g%^RESET%^r%^BOLD%^a%^BOLD%^%^BLACK%^y s%^RESET%^t"
"%^BOLD%^%^BLACK%^on%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^ that have a "
"%^BOLD%^%^WHITE%^gl%^RESET%^it%^BOLD%^%^WHITE%^t%^RESET%^er%^BOLD%^%^WHITE%^in"
"%^RESET%^g%^RESET%^%^GREEN%^ element about them. They are small and sharp and "
"would probably not feel at all pleasant beneath bare feet. A walkway cut from "
"%^BOLD%^%^BLACK%^black m%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^BLACK%^b%^RESET%^"
"l%^BOLD%^%^BLACK%^e s%^RESET%^q%^BOLD%^%^BLACK%^ua%^RESET%^r%^BOLD%^e%^BOLD%^"
"%^BLACK%^s%^RESET%^%^GREEN%^ snakes its way through this impressive garden of "
"stone.%^RESET%^",
      "statues" : "%^RESET%^A dozen statues stand erect around the garden, and "
"each one is different. There are demons, angels, warriors, priests, creatures "
"and more. Most are carved from %^BOLD%^%^BLACK%^dark stone%^RESET%^, while "
"others seem to be crafted from %^RESET%^%^ORANGE%^metal%^RESET%^. Each is a "
"rather %^BOLD%^impressive%^RESET%^ work of art, although their surfaces have "
"been %^BOLD%^%^BLACK%^worn%^RESET%^ and %^BOLD%^%^BLACK%^damaged%^RESET%^ to "
"some extent.%^RESET%^",
      "gargoyles" : "%^BOLD%^%^BLACK%^These winged creatures have the head of a "
"%^RESET%^%^ORANGE%^vulture%^BOLD%^%^BLACK%^ and the body of a %^YELLOW%^lion"
"%^BOLD%^%^BLACK%^. Their eyes glow with a %^YELLOW%^golden light%^BOLD%^"
"%^BLACK%^ and their mouths are open in an %^RESET%^%^CYAN%^eternal scream"
"%^BOLD%^%^BLACK%^ as they perch %^RESET%^majestically%^BOLD%^%^BLACK%^ on the "
"walls of the castle, peering down at the ground below.%^RESET%^",
      "wall" : "%^BOLD%^%^BLACK%^Cut from rough, dark stone, the wall is low "
"and probably placed there to prevent you from falling to a very messy, but "
"quick, demise.%^RESET%^",
    ]));
   set_exits(([
        "down": MOUNT + "tcastle_1",
   ]));
}

void reset() {
    ::reset();
    switch(random(6)){
      case 0: tell_room(TO,"%^BOLD%^%^BLACK%^Thunder rumbles overhead, shaking "
"the foundation of the castle.%^RESET%^"); break;
      case 1: tell_room(TO,"%^YELLOW%^Lightning crackles through the dark "
"clouds overhead.%^RESET%^"); break;
      case 2: tell_room(TO,"%^YELLOW%^Sparks fly everywhere as lightning "
"strikes the silver spires.%^RESET%^"); break;
      case 3: tell_room(TO,"%^RESET%^%^CYAN%^A sudden burst of wind tears at "
"your clothing.%^RESET%^"); break;
      case 4: tell_room(TO,"%^BOLD%^%^BLUE%^Waves crash over the edge of the "
"pool, spraying water across the ground.%^RESET%^"); break;
      default: break;
    }
}

string smell_fun() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return ("%^BOLD%^%^BLACK%^The darkness is frequently split by "
"%^RESET%^ja%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^g%^RESET%^ed%^BOLD%^%^BLACK%^ "
"bolts of light.");
   else return("%^BOLD%^%^BLACK%^The sun is blotted out by the %^RESET%^dark "
"clouds%^BOLD%^%^BLACK%^ rolling overhead.%^RESET%^");
}

string longdesc_fun() {
   if ((string)EVENTS_D->query_time_of_day() == "night")
     return ("%^BOLD%^%^BLACK%^At night, the rooftop of this castle "
"takes on an eerie presence. Strange figures jut out from the ground, their "
"dark silhouettes deepening the shadows. %^RESET%^Mi%^BOLD%^%^WHITE%^s%^RESET%^t"
"%^BOLD%^%^BLACK%^ rises from the dark pool in the center of the courtyard, "
"%^BOLD%^%^WHITE%^e%^RESET%^n%^BOLD%^%^BLACK%^s%^BOLD%^%^WHITE%^h%^RESET%^r"
"%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^u%^RESET%^d%^BOLD%^%^BLACK%^i%^BOLD%^"
"%^WHITE%^n%^RESET%^g%^BOLD%^%^BLACK%^ the air in a %^RESET%^thi%^BOLD%^"
"%^WHITE%^c%^RESET%^k f%^BOLD%^%^BLACK%^o%^RESET%^g%^BOLD%^%^BLACK%^, and "
"making it nearly impossible to see. Rising from the center of the pool, three "
"%^BOLD%^%^WHITE%^silver spires%^BOLD%^%^BLACK%^ reach toward the heavens, "
"stirring the dark clouds above. Stone gargoyles with %^YELLOW%^glowing "
"%^RESET%^%^ORANGE%^golden%^YELLOW%^ eyes%^BOLD%^%^BLACK%^ perch upon the low "
"stone walls that circle the perimeter. The ground is covered in sharp stones "
"that dig into your feet as you walk.%^RESET%^\n");
   else return ("%^RESET%^Up here on the rooftop of the castle, it seems as if "
"the %^CYAN%^heavens%^RESET%^ are but an arm's length away. In the center of "
"the area, a large %^BOLD%^%^BLUE%^p%^RESET%^%^BLUE%^o%^BOLD%^%^CYAN%^o"
"%^RESET%^%^CYAN%^l%^RESET%^ reflects the %^BOLD%^%^RED%^r%^RESET%^%^RED%^a"
"%^MAGENTA%^g%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^RED%^g%^RESET%^ sky "
"above. Benches carved from %^BOLD%^%^BLACK%^black m%^RESET%^a%^BOLD%^%^BLACK%^r"
"%^RESET%^bl%^BOLD%^%^BLACK%^e%^RESET%^ line its edges. Three %^BOLD%^%^WHITE%^"
"silver sp%^BOLD%^%^BLACK%^ir%^BOLD%^%^WHITE%^es%^RESET%^ jut upward from the "
"middle of the pool, vanishing into the %^BOLD%^%^BLACK%^dark %^RESET%^"
"%^ORANGE%^st%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^r%^RESET%^%^ORANGE%^m%^BOLD%^"
"%^BLACK%^ clouds%^RESET%^. The ground is covered in %^BOLD%^%^BLACK%^g"
"%^RESET%^l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^t%^RESET%^t%^BOLD%^%^WHITE%^e"
"%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g s%^RESET%^t"
"%^BOLD%^%^BLACK%^on%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^, with a %^BOLD%^"
"%^BLACK%^black walkway%^RESET%^ snaking around the area. Strange %^RESET%^"
"%^ORANGE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^at%^RESET%^u%^BOLD%^%^BLACK%^e"
"%^RESET%^%^ORANGE%^s%^RESET%^ are placed at random intervals throughout the "
"stone garden. Around the perimeter of the courtyard are perched hideous "
"%^RESET%^%^GREEN%^ga%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^go%^RESET%^%^ORANGE%^yl"
"%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^s%^RESET%^, peering over the edge of the "
"castle. A short %^BOLD%^%^BLACK%^black wall%^RESET%^ encloses the area. "
"%^RESET%^%^CYAN%^Wi%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^d%^RESET%^ rips and tears "
"at your clothing, urging you closer to the edges, where it looks like a very "
"long, very %^RESET%^%^RED%^de%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^ly"
"%^RESET%^, fall to the ground below.\n");
}

string query_weather(){ return "%^BOLD%^%^BLUE%^A %^BLACK%^thunderstorm %^BLUE%^rages overhead.%^RESET%^"; }
