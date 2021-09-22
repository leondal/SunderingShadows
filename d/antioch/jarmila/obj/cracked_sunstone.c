#include <std.h>
#include "../jarmila.h"


inherit BAG;

void create(){
    ::create();
    set_name("cracked sunstone");
    set_id(({"sunstone","cracked sunstone","stone"}));
    set_short("%^C226%^c%^C186%^rac%^C226%^"+
	"k%^C186%^ed su%^C226%^n%^C186%^sto%^C226%^n%^C186%^e (%^C196%^glowing%^C186%^)%^CRST%^");
    set_long("%^C226%^This sunstone is much like all the rest around you, however it is hollow inside and could contain wonderous thingss!\n%^CRST%^");
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
