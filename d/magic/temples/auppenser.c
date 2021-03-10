#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_light(2);
    set_indoors(1);
    set_smell("default","The air is filled with the tang of incense burning upon bronze.");
    set_listen("default","The pulse of the myriad crystals resonate their own harmonic chime.");
    set_name("A crystalline shrine");
    set_short("A crystalline shrine");
    set_long("%^BOLD%^%^CYAN%^A mountaintop shrine%^RESET%^\n"+
             "%^CYAN%^You are in what appears to be the hollow of a massive geode. "+
             "%^RESET%^%^RED%^C%^BOLD%^r%^RESET%^%^ORANGE%^y%^YELLOW%^s%^GREEN%^t"
             "%^RESET%^%^CYAN%^a%^BOLD%^l%^RESET%^%^MAGENTA%^s %^CYAN%^in many a hue "
             "adorn the sides of the spherical wall like so "+
             "many stalactites. The smooth floor, composed of worked %^BOLD%^"+
             "%^BLACK%^obsidian%^RESET%^%^CYAN%^ tiles, was grouted with "+
             "%^YELLOW%^molten %^RESET%^%^ORANGE%^bronze%^CYAN%^, lending its "+
             "surface a veined, living appearance. Three beaten %^ORANGE%^bronze "+
             "censers%^CYAN%^, each burning a heady incense, surround a massive "+
             "%^BOLD%^%^WHITE%^crystal monolith%^RESET%^%^CYAN%^ in a triangular "+
             "pattern. The monolith itself sits atop a burnished %^ORANGE%^bronze "+
             "ziggurat%^CYAN%^ and features an unusual %^BOLD%^cyan glow%^RESET%^"+
             "%^CYAN%^ within. The %^BOLD%^glow%^RESET%^%^CYAN%^ emanates from a "+
             "large, stylized eye, held within the crystal monolith's center.\n%^RESET%^"
        );
    set_items(([
                   "crystals" : "The cavern %^RESET%^%^RED%^s%^BOLD%^p%^RESET%^%^ORANGE%^a"
                   "%^YELLOW%^r%^GREEN%^k%^RESET%^%^CYAN%^l%^BOLD%^e%^RESET%^%^MAGENTA%^s "
                   "%^RESET%^with a myriad hues from the iridescent crystals lining the geode.",
                   ({"tile","tiles","obsidian","obsidian tiles"}) : "%^BOLD%^%^BLACK%^The obsidian "
                   "tiles are crafted into geometric shapes to mimic the crystals, and their "
                   "smooth surface shimmers in the light, brightened by the %^RESET%^%^ORANGE%^"
                   "bronze %^BOLD%^%^BLACK%^grout.%^RESET%^",
                   ({"grout","bronze grout","molten bronze"}) : "%^RESET%^%^ORANGE%^The grout "
                   "is truly a marvel. Molten bronze was poured into the recesses between "
                   "the tiles, and it still shines as if polished continually.%^RESET%^",
                   ({"censer","censers","bronze censers","bronze censer"}) : "Each %^ORANGE%^censer "
                   "%^RESET%^is made of a %^ORANGE%^bronze %^RESET%^bowl suspended from three "
                   "delicate chains. They dangle from the ceiling high overhead and house the "
                   "burning incense that permeates the air.",
                   ({"ziggurat","bronze ziggurat","monolith","crystal monolith"}) : "%^RESET%^%^ORANGE%^The "
                   "stepped tower of the ziggurat rises from the floor of the geode. Its bronze "
                   "sides are stamped with arcane symbols and other pictographs whose meanings "
                   "have been lost to time. Atop the ziggurat is a triangular %^BOLD%^%^WHITE%^"
                   "monolith %^RESET%^%^ORANGE%^with a carved stylized eye that %^CYAN%^gl%^BOLD%^"
                   "o%^RESET%^%^CYAN%^ws%^RESET%^%^ORANGE%^.%^RESET%^"
                   ]));
    set_exits(([
                   "out":"/d/darkwood/tabor/room/auppenser4"
                   ]));
}
