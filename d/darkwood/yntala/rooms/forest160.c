//forest160
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"north":INRMS+"forest159",
"east":INRMS+"forest161"
]));
}
void reset() {
  object ob;
  ::reset();
  if(!present("girallon")){
     new(TMONDIR+"girallon.c")->move(TO);
  }
}