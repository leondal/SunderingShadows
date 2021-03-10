//armorer.c - updated by ~Circe~ for new Seneca 12/11/07
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create(){
   ::create();
   set_name("Angus");
   set_id(({"Angus","angus","metalsmith","armorer","armorsmith","shopkeeper","young","Angus Young"}));
   set_short("Angus Young, Seneca Metalsmith");
   set_long("%^RESET%^%^CYAN%^Named for a famous ancestor who "+
      "fought in the Cartahenan army against the Kinnesaruda "+
      "Empire, Angus Young is a master armorsmith and well-"+
      "respected in Seneca.  He has %^BOLD%^%^BLACK%^curly "+
      "black hair %^RESET%^%^CYAN%^hanging over a prominent "+
      "forehead, and he is just this side of chubby.  Most of "+
      "his bulk has been trained into muscle now with the "+
      "promise of fat to come in his later inactive years.  "+
      "Thick arms banded with muscle are scarred from years "+
      "of working in the forge, though his skill has now earned "+
      "him the dedication of several apprentices who do some "+
      "of the work for him.  He wears the thick leather apron "+
      "that is the trademark of a smith, and he has a quiet, "+
      "serious demeanor that makes him seem more contemplative "+
      "than he might be.");
/*Taking out this description - he would be over 200 years old now ~Circe~ 12/11/07
set_long("
    Angus is a middle aged human fighter turned metalsmith.  He once serviced the Cartahenan army before they were slaughtered by the Kinnesaruda Empire of the Black Dawn.  He watches you carefully as you look around his shop.

%^CYAN%^<help shop> will get you a list of shop commands.\n");
*/
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_property("no attack",1);
   set("aggressive", 0);
   set_level(59);
   set_hd(59,3);
   set_max_hp(query_hp());
   set_storage_room(STORAGE"armor_storage.c");
   set_items_allowed("armor");
   set_nwp("armorsmithing",20);
}
