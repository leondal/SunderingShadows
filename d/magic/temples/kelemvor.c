#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("stone mausoleum");
   set_short("A simple stone mausoleum");
   set_long("%^BOLD%^%^WHITE%^A simple stone mausoleum%^RESET%^\n"
"This plain %^ORANGE%^stone %^RESET%^mausoleum is the only structure within the graveyard, and is not particularly "
"distinctive to look at.  It consists merely of tall walls and a tapered roof of stone tiles, with "
"no door installed at its entry to restrict access.  Within, simple sconces support %^YELLOW%^torches %^RESET%^"
"that seem never to burn down, shedding flickering light across the numerous alcoves that line the "
"walls.  Each bears a small plate with etchings.  In the center of the building stands a single "
"%^BOLD%^%^BLACK%^stone sarcophagus%^RESET%^ carved with an image of a man at rest.  His hands lie "
"closed across his chest, holding the hilt of a %^CYAN%^greatsword %^RESET%^with its point towards his feet.\n");
   set_items(([
      ({"sconce","sconces","torches"}) : "The %^BOLD%^%^BLACK%^iron sconces "
         "%^RESET%^into the stone walls are simple brackets that hold lit "
         "%^YELLOW%^torches %^RESET%^that burn at all times, day or night. "
         "Their flickering flames provide just enough light to see the "
         "%^BOLD%^%^BLACK%^iron plates %^RESET%^beside each alcove.",
      ({"plate","plates","small plate","small plates"}) : "Each plate once bore "
         "a name, but they have become faded and nearly impossible to read with "
         "the passage of time.",
      ({"sarcophagus","man","image"}) : "The %^BOLD%^stone sarcophagus %^RESET%^is "
         "weathered but seems to have survived better than other parts of the temple. "
         "The carving depicts a solemn man in his eternal rest with his hands "
         "grasping the hilt of his greatsword.",
      ({"alcove","alcoves"}) : "Each stone alcove houses a simple stone coffin "
         "sealed shut against time."
   ]));
   set_exits(([
      "out":"/d/tharis/cemetery/cemetery8"
   ]));
   set_smell("default","The thick, musty smell of the tomb surrounds you.");
   set_listen("default","It is deathly silent here.");
}