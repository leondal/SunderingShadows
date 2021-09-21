#include <std.h>
#include "../jarmila.h"


inherit BAG;

void create(){
    ::create();
    set_name("cracked sunstone");
    set_id(({"sunstone","cracked sunstone","stone"}));
    set_short("%^cracked sunstone");
    set_long(". \n");
    set_property("no_animate",1);
    set_weight(50000);
      set_value(0);
      set_max_internal_encumbrance(100);
      switch(random(10)){
      case 0..3: new(OBJ"eater")->move(TO); break;
      case 4..6: new(OBJ"divinewrath")->move(TO); break;
      default: new(OBJ"tikelen_belt")->move(TO); break;
      }
	  switch(random(10)){
      case 0..3: new(OBJ"melody")->move(TO); break;
      case 4..6: new(OBJ"revan_edge")->move(TO); break;
      default: new(OBJ"urzel_brush")->move(TO); break;
      }
	  switch(random(10)){
      case 0..3: new(OBJ"splitter")->move(TO); break;
      case 4..6: new(OBJ"vashapride")->move(TO); break;
      default: new(OBJ"rise_of_mists")->move(TO); break;
      }
}
