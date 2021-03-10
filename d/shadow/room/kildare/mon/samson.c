#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("healer");
   set_id(({"healer","apothecary","old man","human","samson"}));
   set_short("Samson, the Village Healer");
   set_long(
      "This aged man stands just under six feet tall but stoops and "+
      "hunches his shoulders, making him seem much shorter.  He seems "+
      "to have been the healer here for many decades, and he knows "+
      "every villager by name.  They all seem quite fond of him, and he "+
      "is kind, though quiet.  He wears a wedding band, but seems to live "+
      "alone, and his hazel eyes reveal a sadness beneath his ready smile.  "+
      "He is dressed simply, in brown suede breeches and a white tunic, worn "+
      "under an apron.  The tunic matches his stark white hair, which is "+
      "worn down to his shoulders."
      );
   set_gender("male");
   set_alignment(5);
   set_race("human");
   set_body_type("humanoid");
   set_hd(6,1);
   set_exp(1);
   set_emotes(1,({
      "Samson grinds a few dried herbs with a mortar and pestle.",
      "Samson mutters to himself as he peruses the herbs on the bookshelf.",
      "Samson smiles kindly as he glances around the room."
      }),0);
}   

int should_interact(object ob){
   return 1;
}
