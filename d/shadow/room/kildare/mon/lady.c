#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("cieren");
   set_id(({"lady","young lady","cieren","Cieren","wife","shepherd's wife"}));
   set_short("Cieren, the Shepherd's Wife");
   set_long(
      "This young woman appears to be in her early twenties.  She "+
      "has long black hair that reaches past her waist and is pulled "+
      "back with a simple leather cord at the base of her neck.  She "+
      "has brilliant blue eyes that seem haunted somehow, and she rings "+
      "her hands as she moves around the house continuing her housework.  "+
      "She wears a simple yellow dress and is barefoot.  The only adornment "+
      "on her is the golden wedding band she wears, which seems rather new.  "+
      "Something is clearly troubling her, though she tries to keep a "+
      "brave face."
      );
   set_gender("female");
   set_race("human");
   set_body_type("humanoid");
   set_hd(1,4);
   set_exp(1);
   set_emotes(1,({
      "Cieren runs a cloth along the table, wiping it free of dust.",
      "Cieren pauses with a frown before sighing and brushing back her hair.",
      "Cieren sweeps the stone floor in front of the hearth.",
      "Cieren seems to whisper to herself as she works."
      }),0);
}   
