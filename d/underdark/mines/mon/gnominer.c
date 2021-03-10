//Octothorpe (8/25/08)
//Underdark Mining Caverns, Svirfneblin Miner

#include <std.h>
#include "../defs.h"
inherit MON+"gnobasic";

void create(){
   object ob;
   ::create();
   set_id(({"gnome","deep gnome","svirfneblin","miner"}));
   set_short("%^RESET%^wiry, lightly armored d%^BOLD%^%^BLACK%^ee"+
      "%^RESET%^p gnome");
   set_long("%^ORANGE%^This lightly armored gnome participates in "+
      "the mining operation. He is wielding a solid mining pick, and "+
      "is clothed in a light, leather jack.  This gnome has %^BOLD%^"+
      "%^BLACK%^gray %^RESET%^%^ORANGE%^pulled over a compact, wiry "+
      "frame. The miner moves about with the skill and confidence of "+
      "a veteran warrior, suggesting that the miners, and the guards "+
      "that patrol the area, are one and the same.%^RESET%^");
   new(OBJ"gnojack")->move(TO);
   command("wear jack");
}
