//Temple of Khyron - created by ~Circe~ 11/30/19
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(4);
   set_indoors(0);
   set_temple("khyron");
   set_name("Temple of Khyron");
   set_short("%^BOLD%^%^RED%^Temple of Khyron%^RESET%^");
   set_long("%^BOLD%^%^RED%^Temple of Khyron%^RESET%^\n%^RESET%^%^ORANGE%^This open-air temple welcomes the %^RED%^e%^BOLD%^l%^RESET%^%^ORANGE%^e%^BOLD%^m%^RESET%^%^CYAN%^e%^GREEN%^n%^BOLD%^t%^BLACK%^s%^RESET%^%^ORANGE%^. The %^RESET%^rocky ground %^ORANGE%^here bears the scorch marks of %^YELLOW%^lightning%^RESET%^%^ORANGE%^, and the typical %^RESET%^gra%^BOLD%^%^BLACK%^n%^RESET%^ite %^RESET%^%^ORANGE%^of the nearby land gives way, seemingly impossibly, to %^RESET%^pumice %^ORANGE%^and %^BOLD%^%^BLACK%^ob%^WHITE%^s%^BLACK%^id%^WHITE%^i%^BLACK%^an%^RESET%^%^ORANGE%^, much more at home on volcanoes than peaceful mountainsides. The grove of %^GREEN%^dense trees %^ORANGE%^bends outward as if nearly flattened by violent %^CYAN%^winds%^ORANGE%^, and three %^RESET%^pillars %^ORANGE%^rise high overhead, their jagged tops lost in the %^BOLD%^%^BLACK%^st%^WHITE%^o%^BLACK%^rmc%^WHITE%^l%^BLACK%^ouds %^RESET%^%^ORANGE%^perpetually gathered in the sky. In the center of the grove is a tall hill with the top sheared off, leaving it unnaturally flat. Rather than an altar, the hilltop features a %^RESET%^ring %^ORANGE%^where a %^RED%^bo%^BOLD%^n%^YELLOW%^f%^RED%^i%^RESET%^%^RED%^re %^ORANGE%^burns endlessly, sending its %^BOLD%^%^BLACK%^black smoke %^RESET%^%^ORANGE%^up to disappear into the clouds. Surrounding the %^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re %^RESET%^%^ORANGE%^is a low %^BOLD%^%^BLACK%^iron wall %^RESET%^%^ORANGE%^with letters carved out so that the fire illuminates them from within, revealing Khyron's %^BOLD%^%^BLACK%^ch%^RED%^a%^BLACK%^r%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^to his followers. Nearby, an immense stand of %^BOLD%^%^WHITE%^lightning glass %^RESET%^%^ORANGE%^bears a %^RESET%^bowl %^ORANGE%^made of %^RESET%^pumice%^ORANGE%^, filled with offerings to the Tempest. At its base is an %^BOLD%^%^BLACK%^ob%^WHITE%^s%^BLACK%^id%^WHITE%^i%^BLACK%^an slab%^RESET%^%^ORANGE%^, which has been carved to detail the services the temple provides.%^RESET%^\n");
   set_items(([
      ({"ground","rocky ground"}) : "The ground here is an uneven mix of pumice and obsidian, marred by scorch marks and broken in places as if from an earthquake. Loose rocks make footing treacherous, though the devout seem to have fewer problems than others.",
      "scorch marks" : "Long, jagged black lines streak across the earth here, evidence of the frequent lightning strikes that seem centered on the area.",
      ({"tree","trees","grove","dense trees"}) : "The tall evergreens of the grove are healthier than those of the surrounding mountainside, though they seem to have been blown away from the clearing. Some lean nearly horizontal while others stand defiantly, stretching toward the sky.",
      ({"pillar","pillars"}) : "The tall stone pillars are weather-beaten and pockmarked. Small holes have been drilled throughout them, letting the wind whistle through and create an eerie music. Their tops disappear into the roiling black stormclouds overhead.",
      ({"stormclouds","clouds"}) : "The stormclouds churn ceaselessly, brilliant lightning flashing in their depths.",
      ({"hill","bonfire"}) : "The hill features a flat top, smooth and nearly as reflective as a black mirror. In the middle of the hilltop is a roaring bonfire bounded by a low iron wall.",
      ({"smoke","black smoke"}) : "The bonfire streams black smoke that drifts upward, joining the stormclouds.",
      ({"wall","iron wall","charge"}) : "The iron wall stands about three feet high and stretches all the way around the bonfire. Words have been carved straight through the iron, letting the fire illuminate Khyron's charge to his followers.",
      ({"glass","lightning glass","stand of lightning glass","bowl","bowl of pumice","pumice bowl","offerings"}) : "Twisting and jagged almost like a living creature, the single piece of lightning glass is roughly the size of a dwarf. Milky white in color, the branches of the glass support a wide pumice bowl filled with offerings to the Ravager - obsidian and driftwood and even a small metal carving of the tarrasque.",
      ({"slab","obsidian slab","sign"}) : "The obsidian slab is a squat, ugly thing that looks as though it could withstand any storm, unlike the lightning glass stand. A sign has been carved into its smooth face that you could read."
   ]));
   set_smell("default","The air is filled with the scent of ozone and smoke.");
   set_listen("default","The wind whistles through the stone pillars and thunder rumbles in the sky.");
   set_exits(([
      "out": "/d/shadow/room/kildare/rooms/roads/eroad06"
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
%^BOLD%^Khyron charges his followers with this message:%^RESET%^%^CYAN%^
Let the world burn and the seas roil with the fury of the Ravager. Strike out like lightning, leaving mortals quivering in fear of Khyron's wrath. Chaos and destruction go hand in hand, and true power comes from harnessing the raw energy of the storm. Never act out against Khyron, for to defy him is to meet your final end, but do not hesitate to demonstrate his might against those who question it. Burn them, freeze them, drown them in the depths of the sea, and give all glory to the Elemental Reaver.

%^RESET%^---

%^BOLD%^Khyron has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Nilith
%^CYAN%^Enemies: %^RESET%^Nimnavanon, Kreysneothosies, Seija

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}
