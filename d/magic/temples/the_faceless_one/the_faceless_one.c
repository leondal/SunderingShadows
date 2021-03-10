//Temple of the Faceless One - created by Nienne 2/18
//updated by ~Circe~ 10/5/19 to include enemies and allies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("the faceless one");
   set_name("Temple of the Faceless One");
   set_short("%^RESET%^%^RED%^Temple of the Faceless One%^RESET%^");
   set_long("%^RESET%^%^RED%^Temple of the Faceless One%^RESET%^\n%^BOLD%^%^WHITE%^You have set foot within a long underground cavern, its roof and corners shrouded from your vision by %^BOLD%^%^BLACK%^sh%^RESET%^if%^BOLD%^%^BLACK%^ti%^RESET%^n%^BOLD%^%^BLACK%^g sha%^RESET%^do%^BOLD%^%^BLACK%^ws%^BOLD%^%^WHITE%^.  Stalactites stretch downwards from the %^RESET%^%^BLUE%^darkness%^BOLD%^%^WHITE%^, reaching out for their stalagmite cousins below, and the stone floor underfoot is rough and uneven.  While the chamber seems naturally formed, as you move deeper you find yourself passing by %^RESET%^%^MAGENTA%^ancient pillars %^BOLD%^%^WHITE%^and remnants of %^RESET%^%^ORANGE%^old stonework %^BOLD%^%^WHITE%^embedded into the rocky walls.  At the far end of the cavern, worn stone stairs lead upwards to a broad dais, where a massive slab of %^BOLD%^%^BLACK%^slate %^BOLD%^%^WHITE%^stands in place as an altar.  The wall behind the altar bears a triangular formation of teardrops painted in some %^RESET%^%^RED%^blood-red substance%^BOLD%^%^WHITE%^, beneath which is etched the charge of the Faceless One into the stone itself.  Torches stand atop poles at each corner of the dais, their %^RESET%^%^BLUE%^fl%^CYAN%^ic%^BOLD%^%^CYAN%^ke%^RESET%^%^CYAN%^ri%^BLUE%^ng %^BOLD%^%^WHITE%^flames casting eerily dancing shadows across the cavern walls.  To all sides, smaller tunnels lead away from the dimly-lit cavern into the %^BOLD%^%^BLACK%^darkness %^BOLD%^%^WHITE%^beyond...\n%^RESET%^");
   set_smell("default","The air carries a damp, earthy smell.");
   set_listen("default","Sounds here are oddly muted by the stone.");
   set_exits(([
      "out": "/d/magic/temples/the_faceless_one/the_faceless_oneentry"
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
%^BOLD%^The Faceless One charges its followers with this message:%^RESET%^%^CYAN%^
The world and all its treasures are open for the taking, for those of quick wit and subtle hands.  Do not be bound by the petty rules and standards of 'civilisation', for in the end they are merely illusions, a veneer of order to hide the true chaos that lies in every heart.  A deception can be as sharp a tool as a blade, and each has its uses.  Learn to blur the lines between truth and fiction, so that others may not perceive the difference; honesty is for fools, but apparent honesty is valuable indeed.  Force becomes unnecessary when others can be manipulated into action, or to thinking a decision is of their own free will.  Trust in the shadows, for the bright way makes for easy targets.

%^RESET%^---

%^BOLD%^The Faceless One has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^Jarmila, Callamir, Kreysneothosies

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}