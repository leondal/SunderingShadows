//Temple of Kismet - created by Eris 11/18
//updated by ~Circe~ 10/5/19 to include allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_indoors(1);
   set_temple("kismet");
   set_name("Temple of Kismet");
   set_short("%^BOLD%^%^BLUE%^Temple of Kismet%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Temple of Kismet%^RESET%^\n%^BOLD%^The entirety of the temple is made of a strange %^BLUE%^b%^CYAN%^l%^BLUE%^u%^CYAN%^e %^WHITE%^stone. The %^CYAN%^s%^GREEN%^p%^ORANGE%^i%^RED%^r%^MAGENTA%^a%^BLUE%^l %^WHITE%^roof on this temple rises up far above your head. The ceiling is painted in a %^RESET%^%^CYAN%^b%^BOLD%^%^BLUE%^e%^RESET%^%^MAGENTA%^a%^YELLOW%^u%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^i%^RESET%^%^MAGENTA%^f%^YELLOW%^u%^RESET%^%^CYAN%^l %^BOLD%^%^WHITE%^and realistic portrayal of the %^CYAN%^s%^RESET%^%^CYAN%^k%^BOLD%^%^WHITE%^y that magically changes with the weather and seasons. The walls are adorned with tapestries of famous magic users. There are innumerable scroll shelves and bookshelves stretched along the walls. Rows of pews are interspersed with rows of cushions seated on the floor in circles. %^ORANGE%^G%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d %^BOLD%^%^WHITE%^and %^CYAN%^o%^BLUE%^p%^MAGENTA%^a%^WHITE%^l candelabras wind their way through the temple's long aisles, spaced at even intervals among the seats. Well-cared-for songbirds are held in cages, singing. At the end of the aisle sits a large, solid opal altar littered with %^RESET%^%^ORANGE%^o%^BOLD%^f%^WHITE%^fe%^RESET%^%^ORANGE%^r%^BOLD%^i%^WHITE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^WHITE%^s of scrolls and spell components. A single blue candle burns on the altar, held in a candle holder shaped as a s%^BLACK%^c%^WHITE%^r%^BLACK%^o%^WHITE%^l%^BLACK%^l%^WHITE%^. A banner behind the altar bears the symbol of Kismet.%^RESET%^\n");
   set_smell("default","The smell of old parchment and drying ink wafts through the area.");
   set_listen("default","The souds of scribbling and chanting pleasntly plays in your ears.");
   set_exits(([
      "out": "/d/shadow/room/forest/road5"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^%^WHITE%^Kismet charges her followers with this message:
%^RESET%^%^CYAN%^Respect the weave above all things. The weave is simply an extension of your art, just as a paintbrush is to a painter, or clay to a sculptor. The weave is neither kind nor cruel, good nor evil. Accept the weave for what it is. All who seek this power shall be accepted under my wing. Seek knowledge, improve your arts, and serve the weave as an extension of me. Seek knowledge wherever you go and from all you meet. All knowledge, even the seemingly insignificant, is of great value. Destroy those who seek to ravage the world and disrupt the weave. 

%^RESET%^---

%^BOLD%^Kismet has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^None

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.

CHARGE
   );
   return 1;
}
