//Octothorpe (9/2/08)
//Underdark Mining Caverns, Svirfneblin Warrior

#include <std.h>
#include "../defs.h"
inherit MON+"gnobasic";

void create(){
   ::create();
   set_id(({"gnome","deep gnome","svirfneblin","warrior"}));
   set_short("%^RESET%^wiry, armored d%^BOLD%^%^BLACK%^ee%^RESET%^p "+
      "gnome");
   set_long("%^ORANGE%^This armored gnome stands guard over the mining "+
      "operation. He is wielding a solid mining pick, and is wearing a "+
      "well-crafted suit of scale armour. This gnome has %^BOLD%^"+
      "%^BLACK%^gray %^RESET%^%^ORANGE%^pulled over a compact, wiry "+
      "frame. This warrior moves about with the skill and confidence "+
      "of a veteran.%^RESET%^");
   set_max_hp(random(50)+275);
   set_hp(query_max_hp());
   new(OBJ"gnochain")->move(TO);
   command("wear chain");
}
