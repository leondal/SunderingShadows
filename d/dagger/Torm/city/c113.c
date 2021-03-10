#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_long(
  "  You stand at the entrance to a grand bathhouse in Torm."
    "  Marble stairs lead down into an immense pool to the west while to the south a smaller pool sits."
  "  The north wall has many pegs and shelves for holding clothes and farther to the northwest you see a curtain closing off a part of the room."
    "  Marble columns support the ceiling and a great fish fountain can be seen rising out of the center of the larger pool.",
  );
  set_door("doors",TCITY+"c112","east","Torm masterkey");
  set_exits(([
  "north":TCITY+"c114",
  "out":TCITY+"c112",
  "west":TCITY+"c118",
  "south":TCITY+"c121",
  ]));
  set_open("doors",1);
}
