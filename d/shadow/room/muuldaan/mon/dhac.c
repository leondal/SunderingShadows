#include <std.h>
#include "../defs.h"
inherit "/std/psychic.c";

void create(){
   ::create();
   set_name("dhac");
   set_short("Dhac, goblin shaman");
   set_id(({"dhac","shaman","Dhac","goblin shaman","priest"}));
   set_long("This scrawny little creature is a goblin, clad in tattered robes as dirty as the rest of her.  "
"Despite her stature she has quite a fierce appearance, with a squat nose and a wide mouth full of sharp "
"yellow teeth.  Her eyes are the blazing red hue of lit coals, and her skin is a dull shade of orange-brown"
".  Her greasy black hair hangs in limp strands around her shoulders, and a leather necklace is tied at her "
"neck, tied to a small rended hand that probably belonged to a child, or a halfling.");
   set_race("goblin");
   set_body_type("human");
   set_class("cleric");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_spells(({"flame strike","flame strike","cause critical wounds","cause critical wounds","cause blindness","hold person","storm cone"}));
   set_spell_chance(70);
   set_diety("talos");
   new(OBJ"rattyrobe")->move(TO);
   command("wear robe");
   new(OBJ"hand")->move(TO);
   command("wear hand");
   set_alignment(9);
   set_gender("female");
   set_spoken("undercommon");
}

void init(){
   ::init();
   if (TP->query_ghost()) call_out("whisper_dead",1,TP);
}

void whisper_dead(object who){
   command("whisper "+who->query_name()+" You can %^YELLOW%^pray%^RESET%^, to get a new body. If you need help once you have prayed, we can %^YELLOW%^reequip %^RESET%^you with basic items here.");
}
