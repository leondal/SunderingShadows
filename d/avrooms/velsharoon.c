#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Chamber of Bones");
   set_short("%^RED%^C%^ORANGE%^h%^RED%^a%^ORANGE%^m%^RED%^b%^ORANGE%^e"
      "%^RED%^r %^GREEN%^of %^BOLD%^%^WHITE%^Bones%^RESET%^");
   set_long("%^MAGENTA%^This %^RED%^c%^ORANGE%^h%^RED%^a%^ORANGE%^m"
      "%^RED%^b%^ORANGE%^e%^RED%^r%^MAGENTA%^ is comprised entirely "
      "from the %^BOLD%^%^WHITE%^bones%^RESET%^%^MAGENTA%^ of "
      "humanoids, animals, beasts, and other %^BOLD%^alien%^RESET%^"
      "%^MAGENTA%^ creatures unknown to this Realm. The floor is "
      "strewn with what can only be described as %^BOLD%^%^YELLOW%^"
      "fine %^RESET%^%^ORANGE%^ sand%^MAGENTA%^. There is a %^BOLD%^"
      "%^YELLOW%^workstation%^RESET%^%^MAGENTA%^ on the far west wall "
      "with an assortment of wicked looking tools and various vials. "
      "Just off of the north wall, there is a row of full skeletons "
      "ranging from anything imaginable. The eastern and southern "
      "walls are dominated by massive %^CYAN%^bookcases%^MAGENTA%^ "
      "full of various %^BOLD%^%^BLACK%^tomes%^RESET%^%^MAGENTA%^ "
      "and %^RESET%^scrolls%^MAGENTA%^. Mounted upon a pedestal, "
      "comprised from a strange %^BOLD%^%^GREEN%^pulsating %^RED%^"
      "red %^RESET%^%^MAGENTA%^ stone with %^BOLD%^%^BLUE%^unholy "
      "%^BLACK%^black %^RESET%^%^MAGENTA%^ runes, is a large "
      "%^ORANGE%^book%^MAGENTA%^, laying open. This room has no "
      "accoutrements for comfort, nor do you see anything edible "
      "or drinkable. The whole chamber is awash in a pervasive "
      "%^RED%^maroon%^MAGENTA%^ %^BOLD%^%^YELLOW%^glow%^RESET%^"
      "%^MAGENTA%^ that seems to come from between the bones "
      "surrounding the chamber.%^RESET%^\n");
   set_smell("default","It smells musty with an overpowering scent of embalming fluid.");
   set_listen("default","You hear the brittle cracking of small bones.");
   set_items(([
      ({"sand","fine sand"}) : "%^BOLD%^%^WHITE%^What at first "
         "appeared as sand is in fact powdered bone, it seems to "
         "cover anything and everything, except for the pedestal "
         "and book.%^RESET%^",
      "floor" : "%^BOLD%^%^BLUE%^The floor is covered in a "
         "%^YELLOW%^fine %^RESET%^%^ORANGE%^sand%^BOLD%^%^BLUE%^.%^RESET%^",
      "workbench" : "%^ORANGE%^This workbench is strewn with "
         "different sizes of knives and other slicing instruments. "
         "On one side of the bench stands an array of viscous "
         "liquids and unknown powders. The table seems to be "
         "permanently stained with old %^RED%^blood%^ORANGE%^.",
      ({"bookshelf", "bookshelves", "east wall", "eastern wall", "south wall", "southern wall"}) : 
         "%^BLUE%^These bookshelves are crammed full of old tomes, "
         "books, manuscripts, and scrolls. The contents obviously "
         "look ancient, but you can feel an %^BOLD%^%^CYAN%^aura"
         "%^RESET%^%^BLUE%^ of magic surrounding all of them.%^RESET%^",
      "pedestal" : "This pedestal emits an aura of %^GREEN%^wrongness"
         "%^RESET%^ about it. The %^RED%^red%^RESET%^ stone seems to "
         "flow up from the ground. The %^BOLD%^%^BLACK%^runes%^RESET%^ "
         "carved into the surface cause the stone to %^BOLD%^%^GREEN%^"
         "pulse%^RESET%^ and makes the whole thing hard to gaze upon "
         "for too long.",
      "book" : "%^BOLD%^%^GREEN%^A malignant presence tries to worm "
         "its way into your mind as you look at the book and causes "
         "you to turn away suddenly!%^RESET%^",
      ({"glow", "maroon", "maroon glow"}) : "%^BOLD%^%^YELLOW%^The "
         "%^RESET%^%^RED%^glow %^BOLD%^%^YELLOW%^seems to come from "
         "some sort of mortar sealing the bones together.%^RESET%^"
   ]));
   set_exits(([
      "lounge" : "/d/dagger/avalounge"
   ]));
}
