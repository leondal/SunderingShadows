#include <std.h>
#include <move.h>
#include "../wemic.h"

inherit CROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("Wide trail through the jungle");
  set_short("Wide %^ORANGE%^trail%^RESET%^ through the %^BOLD%^%^GREEN%^"
    +"j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e");
  set_long( "This wide trail winds through the%^BOLD%^%^GREEN%^"
    +" j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e%^RESET%^"
    +" in a fairly leisurely fashion. The %^GREEN%^trees%^RESET%^ and"
    +" other %^BOLD%^%^GREEN%^plants%^RESET%^ have been kept back from"
    +" the dirt trail, and it's clear that it is maintained from time to"
    +" time. The claw marks on the nearby trees are probably nothing to"
    +" worry about." );
    set_items(([
      ({"path", "trail" }): "The trail leads inland through the jungle"
      +" from the beach. It is reasonably wide and bright, inspiring some"
      +" confidence in its safety. There are some claw marks on the trees"
      +" either side of the trail, though.",
   
      "jungle" : "The %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l"
        +"%^BOLD%^e%^RESET%^ is a dense tangle of %^BOLD%^%^BLACK%^ancient %^RESET%^"
        +"%^GREEN%^trees%^RESET%^ and %^GREEN%^thick %^ORANGE%^u%^GREEN%^nd%^ORANGE%^e"
        +"%^GREEN%^rgr%^ORANGE%^o%^GREEN%^wth%^RESET%^, unpassable unless a %^ORANGE%^"
        +"path%^RESET%^ has been cut through it.",

      ({"marks", "claw marks", "trees"}) : (:TO, "claw_desc":),

    ] ));

  set_smell("default","The smells of the jungle reach you. There's also a"
                     +" faint but nonetheless unmistakable scent of damp"
                     +" cat.");
  set_listen("default","The jungle rustles with the movement of small creatures,"
    +" and echoes with the calls of birds. Occasionally, larger beasts can be"
    +" heard in the distance");
}

void init() {
   ::init();
}

string claw_desc(){ 
  int survival_skill;
  string result;
  survival_skill = TP->query_skill("survival");
  switch (survival_skill)
  {
  case 0:
    result = "The trees near the trail have some claw marks. You don't really know"
      +" what sort. It's kind of remarkable that you noticed them at all really,"
      +" with your level of wilderness survival skills.";
    break;
  case 1..10:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory.";
    break;
  case 11..20:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory.";
    break;
  case 21..30:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory. Even at a distance,"
      +" you can recognise the spread pattern of the claws as coming from a large cat,"
      +" possibly a big lion.";
  default:
    result = "The trees near the trail have some claw marks. They are fairly deep"
      +" and the spread of the claws, along with the height they reach up the trees,"
      +" suggests some kind of large predator marking its territory. You immediately"
      +" recognise them as wemic claw marks";
  } 
  return result;
}



