//corpse.c - Corpse of thief for Lothwaite quest.
//Circe 11/20/04
#include <std.h>
#include "../lothwaite.h"

#define BODIES ({"human","human","human","human","half-elf","elf","dwarf","gnome","halfling","drow","half-drow","orc","half-orc","half-orc","half-orc","half-orc","goblin","goblin"})

inherit BAG;

void create() {
   int i;
   string MYTYPE,GENDER;
   ::create();
      i = random(sizeof(BODIES));
      MYTYPE = BODIES[i];
      set_id(({"thief's corpse","body","dead body","lifeless body"}));
      set_name("lifeless body");
      set_short("a lifeless body");
      set_weight(500);
      if(random(3)){
         GENDER = "male";
      }else{
         GENDER = "female";
      }
      set_long("This is the body of a "+GENDER+" "+MYTYPE+".  There "+
         "seems to be no sign of life left within the hapless corpse, "+
         "and the skin has grown deathly white.  No mark mars the "+
         "body, suggesting it might have been the wrath of the ghosts "+
         "that caused its untimely demise.");
      set_value(0);
      set_max_internal_encumbrance(30);
      new(OBJ"ghostbelt")->move(TO);
}
