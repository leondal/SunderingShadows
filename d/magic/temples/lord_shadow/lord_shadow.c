//Temple of Lord Shadow - created by Nienne 2/18
//updated by ~Circe~ 10/5/19 with allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("lord shadow");
   set_name("Temple of Lord Shadow");
   set_short("%^BOLD%^%^CYAN%^Temple of Lord Shadow%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^Temple of Lord Shadow%^RESET%^\n%^BOLD%^%^WHITE%^The main cella of the temple rises around you, in all aspects conveying the fine architecture of ancient Zin'Charu style.  Great columns of %^BOLD%^%^BLACK%^ve%^RESET%^in%^BOLD%^%^BLACK%^ed bla%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^k ma%^RESET%^r%^BOLD%^%^BLACK%^ble %^BOLD%^%^WHITE%^march along either side of this room, elaborately carved at base and capital with %^RESET%^%^RED%^beasts %^BOLD%^%^WHITE%^of terrible aspect.  Fine tapestries line the walls, each threaded upon %^BOLD%^%^BLACK%^inky canvas %^BOLD%^%^WHITE%^in distinctive %^RESET%^white%^BOLD%^%^WHITE%^-and-%^BOLD%^%^CYAN%^azure %^BOLD%^%^WHITE%^to show the history of the Lord of the temple, from his rise to high arcanist, then sole leader of the Shadovar, and finally to divinity.  %^RESET%^%^MAGENTA%^Duskwood pews %^BOLD%^%^WHITE%^stand in orderly rows to either side, between which runs a line of %^RESET%^luxurious white velvet %^BOLD%^%^WHITE%^from entry to dais, like a carpet of new-fallen snow.  The altar itself is a massive chunk of %^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^bs%^BOLD%^%^BLACK%^id%^RESET%^%^BLUE%^ia%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^, glossy-black and cut only roughly to leave each face rugged and unfinished save for the front, upon which Lord Shadow's charge to his followers has been etched in %^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^g %^BOLD%^%^WHITE%^letters.\n%^RESET%^");
   set_smell("default","The heady, sweet aroma of an exotic incense is in the air.");
   set_listen("default","You hear the whispers of the acolytes and the faithful all around you.");
   set_exits(([
      "out": "/d/magic/temples/lord_shadow/lord_shadowentry"
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
%^BOLD%^Lord Shadow charges his followers with this message:%^RESET%^%^CYAN%^
The world is filled with darkness, fear and suffering - the only separation is between the powerful who wield these gifts, and the powerless who cower before them.  Hope is merely a temporary shelter for the weak, for as each day inevitably ends beneath the cloak of night, so will all things inevitably succumb to darkness.  Submit to the word of Lord Shadow and his ranking clergy, for true power can only be gained through unwavering loyalty.  Spread His fear across the realm, and strike down those who would defy His will, so that all may come to know servitude in His name.

%^RESET%^---

%^BOLD%^Lord Shadow has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^Jarmila, Callamir, Lysara

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.

CHARGE
   );
   return 1;
}