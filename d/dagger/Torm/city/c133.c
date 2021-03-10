#include <std.h>
#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
  set_short("Patio out front of Torm's townhall");
  set_long(
    "  You stand on the patio at the front of Torm's town hall."
    "  It's a grand two story building which once served as the private residence of Torm's king, but has since been converted to public use on the main floor."
    "  You can see gleaming gilded spires extend into the sky from the top of the ornate roof."
  );
  set_exits(([
  "north":TCITY+"c131",
  "east":TCITY+"c134",
  "stairs":TCITY+"c111",
  ]));
  set_items(([
  "patio":"Well cut and placed marble has been set into a very ornate patio.  The railings along the edges of the patio are gilded iron, and polished to gleam in the sun.",
  (({"railings","railing"})):"The iron railing has been covered in gold flake and polished to gleam in the sun.",
  "mansion":"The mansion towers above you and you feel a slight unease lurking under its ornate appearance.",
   "spires":"Gold leafed spires extend form the top of the mansion's roof",
  "stairs":"Expensive looking stairs lead down onto the path around the park.",
  ]));
}
