#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Master bedroom"
  );
  set_property("indoors",1);
  set_long(
  "  This is the bedroom of the old king of Torm."
    "  It's richly decorated, with gold leaf and precious stones accenting the light from the large fireplace in the east wall."
    "  An immense four poster bed sits with its head against the west wall with a equally huge wardrobe to the south."
  "  The only way out of here appears to be the door to the north."
  );
  set_exits(([
  "north":TCITY+"c139",
  ]));
  set_items(([
    "wardrobe":"It's full of rich looking clothes except for right at the back there are some old worn out traveling mages robes, a suit of beat up chainmail and a sheathed beaten looking sword.",
    "bed":"It's well made but looks unslept in for some time.",
    "fireplace":"It's blazing away but seems to do little to take the chill from the room.",
  "walls":"The marble walls are covered in paintings and tapestries.",
  "floor":"The marble floor shows signs of much travel recently.  Its clean and polished but cracked and needing repairs in places.",
      (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
