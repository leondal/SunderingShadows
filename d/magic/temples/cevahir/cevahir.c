//Temple of Cevahir by ~Circe~ 11/10/19
//maybe replace /d/magic/temples/selune - connect to /d/dagger/road/road15
//or go south of Torm along the coast
#include <std.h>
inherit "/std/temple";

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("cevahir");
   set_name("Temple of Cevahir");
   set_short("%^RESET%^%^MAGENTA%^Temple of Cevahir%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^Temple of Cevahir%^RESET%^\nPerched atop a %^BOLD%^%^WHITE%^high cliff %^RESET%^overlooking the %^CYAN%^sea %^RESET%^is this grand temple crafted from %^BOLD%^wh%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^te m%^CYAN%^a%^WHITE%^rb%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^. A trio of wide, square %^BOLD%^archways %^RESET%^to the east reveal a stunning view of the %^BOLD%^%^BLUE%^oc%^CYAN%^e%^BLUE%^an %^RESET%^below, while the other walls have been covered in precise %^MAGENTA%^m%^BOLD%^o%^RESET%^%^MAGENTA%^s%^ORANGE%^a%^MAGENTA%^i%^RESET%^c%^MAGENTA%^s %^RESET%^depicting battle scenes. Slender %^MAGENTA%^purple wall hangings %^RESET%^lined in %^BOLD%^white %^RESET%^and %^ORANGE%^thread of g%^YELLOW%^o%^RESET%^%^ORANGE%^ld %^RESET%^hang between the archways, drawing out the colors of the angular %^MAGENTA%^ma%^BOLD%^r%^RESET%^%^MAGENTA%^ble a%^BOLD%^l%^RESET%^%^MAGENTA%^tar %^RESET%^upon the raised dais just before them. Atop the %^MAGENTA%^a%^BOLD%^l%^RESET%^%^MAGENTA%^tar %^RESET%^are a shallow %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den b%^RESET%^%^ORANGE%^o%^BOLD%^wl %^RESET%^for offerings beside a %^ORANGE%^battered helm %^RESET%^crested with a %^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple p%^BOLD%^l%^RESET%^%^MAGENTA%^ume%^RESET%^. Between them, driving point down into the altar's surface, is a massive %^CYAN%^greatsword %^RESET%^bearing a %^BOLD%^sign %^RESET%^with the %^MAGENTA%^charge %^RESET%^of Cevahir. Wide steps lead up to the dais, which features five straight-backed %^ORANGE%^chairs %^RESET%^arranged in a line interspersed with tall %^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^den can%^BOLD%^d%^RESET%^%^ORANGE%^lest%^BOLD%^i%^RESET%^%^ORANGE%^cks%^RESET%^. Rows of %^ORANGE%^pews %^RESET%^take up the majority of the floor space, with no cushions in sight. To the north, the %^MAGENTA%^m%^BOLD%^o%^RESET%^%^MAGENTA%^s%^ORANGE%^a%^MAGENTA%^i%^RESET%^c%^MAGENTA%^s %^RESET%^are interrupted by a %^CYAN%^glass case %^RESET%^displaying %^ORANGE%^armor %^RESET%^and %^BOLD%^weaponry %^RESET%^from different lands. Off to the south is a smaller area with a wide %^ORANGE%^table %^RESET%^covered in %^CYAN%^layered maps%^RESET%^. A %^ORANGE%^basket %^RESET%^of %^ORANGE%^co%^RED%^l%^ORANGE%^or%^BOLD%^f%^RESET%^%^ORANGE%^ul %^CYAN%^f%^ORANGE%^ig%^GREEN%^u%^ORANGE%^res %^RESET%^is perched atop it, apparently intended to be used in battle plans - or perhaps some elaborate game. Not far away is a %^MAGENTA%^chessboard%^RESET%^, which is often in use by the patrons of Cevahir when they are not perparing for the battlefield.%^RESET%^\n");
   set_items(([
      ({"cliff","sea","ocean"}) : "The flat, rocky outcropping overlooks the sea hundreds of feet below. The sparkling waves of the ocean stretch as far as the eye can see.",
      ({"marble","white marble","floor","ceiling"}) : "This building is crafted from white marble shot through here and there with subtle veins of %^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e%^RESET%^ that seem almost out of place, given the color scheme of the temple. Those who know their history might recognize the marble as a relic of the temple to the departed moon goddess that once stood here.",
      ({"walls","wall","mosaic","mosaics"}) : "Most of the walls of the temple are covered with inlaid mosaics made from polished and painted fragments. A closer look reveals that the pieces seem to be an eclectic collection of items - pottery, stone, and even metal. They have been artfully arranged to depict different battlefields, complete with various styles of armor, weapons, and combat.",
      ({"wall hanging","wall hangings"}) : "Crafted from rich %^MAGENTA%^purple velvet%^RESET%^, the slender wall hangings offer pops of color along the white walls framing the square archways. Each has a border of %^BOLD%^white %^RESET%^bound by %^ORANGE%^thread of g%^YELLOW%^o%^RESET%^%^ORANGE%^ld %^RESET%^. The slim rectangles dangle from %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den rods%^RESET%^ and narrow to a delicate point, ending in %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d fringe%^RESET%^.",
      ({"altar","marble altar","helm","crested helm","sword","greatsword","bowl","golden bowl"}) : "The %^MAGENTA%^ma%^BOLD%^r%^RESET%^%^MAGENTA%^ble a%^BOLD%^l%^RESET%^%^MAGENTA%^tar %^RESET%^is deep purple shot though with lighter veins and flecks of %^RESET%^%^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^. It has been carved smooth and is spartan in design, supporting a wide but shallow %^YELLOW%^go%^RESET%^%^ORANGE%^l%^BOLD%^den b%^RESET%^%^ORANGE%^o%^BOLD%^wl %^RESET%^filled with a smattering of offerings including game pieces carved from gemstones and gold coins from faraway lands. Beside the bowl is a battered helm with a %^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple p%^BOLD%^l%^RESET%^%^MAGENTA%^ume%^RESET%^. Strangely, the helm has no opening for the face, not even a narrow eye slit. Driven into the marble is a towering greatsword that seems nearly as wide as a halfling with an enormous %^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^th%^RESET%^y%^MAGENTA%^st %^RESET%^set into the pommel. Hanging from the crossguard is a simple sign bearing Cevahir's charge.",
      ({"chair","chairs"}) : "Like much of the temple, the chairs are somewhat impressive in their simplicity. They are crafted from burnished oak that gleams like gold, and thin %^MAGENTA%^purple cushions %^RESET%^line their seats. The backs are fitted with %^BOLD%^white %^RESET%^fabric hangings lined in %^MAGENTA%^purple %^RESET%^and %^ORANGE%^go%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^, each bearing the symbol of Cevahir. During ceremonies, these chairs are filled with the ranking priests of the Warlord.",
      ({"candlestick","candlesticks"}) : "The golden candlesticks are fashioned to look like greatswords poised tip down, just like the one on the altar. Each holds a single thick pillar candle in brilliant white",
      ({"pew","pews"}) : "Crafted from burnished oak, the pews are arranged in rigid rows to offer seating to many members of the faith.",
      ({"case","glass case","weaponry","armor"}) : "The %^CYAN%^glass case %^RESET%^along the northern wall seems to be of gnomish make, given its transparency and impeccable design. The true treasure lies inside, where weapons and pieces of armor from all across the realms are on display alongside small markers detailing their origin.",
      ({"table","colorful figures","figures","maps"}) : "The simple oak table to the south is rectangular and surrounded by several stools. Its surface is covered with a stack of maps, some old and weathered, others new and pristine. A woven basket perched on the edge has carved wooden pieces in a variety of colors and shapes so that the faithful can strategize the placement of different units in battle."
   ]));
   set_smell("default","The salty sea air carries an occasional whiff of incense and oil.");
   set_listen("default","The distant sound of the ocean is obscured by the clash of weapons and the murmur of voices.");
   set_exits(([
      "out": "/d/dagger/road/road15"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
   if(!present("chessboard")) new("/d/magic/temples/misc/cevahir_chess")->move(TO);
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Cevahir charges their followers with this message:%^RESET%^%^CYAN%^
Luck is for those unable to plan. Place your faith in strategy and devote your energy to learning all you can. Do not focus only on your enemies for that way lies folly. Learn your own strengths and weaknesses and determine how they fit with those of your enemy. Honor those fallen in battle and give them the recognition they deserve. Every battle must have at least two sides, so learn to recognize your allies and never hesitate to aid your fellow soldiers. Trust in the inevitability of battle and conduct yourself according to the teachings of Cevahir if you want to assure your victory. Know that sometimes losing a single battle is necessary to win the war.

%^RESET%^---

%^BOLD%^Cevahir has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^None

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}