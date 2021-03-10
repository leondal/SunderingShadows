#include <std.h>
#include "../defs.h"
inherit "/std/fence";

void create(){
   ::create();
   set_name("snarfblat");
   set_id(({"snarfblat","goblin hoarder","fence","thief"}) );
   set_short("Snarfblat, goblin hoarder");
   set_long("Snarfblat's bright yellow eyes survey her surroundings with a cunning intellect.  "
"Her scrawny frame is orange-skinned where it is not covered in rags and scraps of clothing, and a "
"mess of dark hair covers her head.  She regularly grins, perhaps in an attempt to seem friendly, "
"but her yellowed fangs tend to make this a more unsettling expression than welcoming.");
   set_gender("female");
   set_alignment(9);
   set_race("goblin");
   set_body_type("human");
   set_class("thief");
   set_hd(15,1);
   set_exp(10);
   set_property("no bump", 1);
   set_spoken("undercommon");
}
