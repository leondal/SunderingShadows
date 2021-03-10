//bard_malar.c - Bard of malar reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit RALLYDARK;

void create(){
    ::create();
//    set_name("malar instrument");
    set_id(({"set of bones","bones","set","instrument"}));
    set_short("%^BOLD%^A set of bones%^RESET%^");
    set_long(
      "While most %^BOLD%^sets of bones %^RESET%^are made from ivory "+
      "or another similar substance, this particular set has been "+
      "created from the very material it is named after.  These "+
      "are bones that have been taken from various creatures - "+
      "from %^RED%^human finger bones%^RESET%^ and %^CYAN%^el%^RED%^ve%^CYAN%^n "+
      "%^RED%^ribs %^RESET%^all the way to shortened %^GREEN%^gn%^RED%^omi%^GREEN%^sh "+
      "%^RED%^femurs%^RESET%^.  The bones seem to have been enchanted "+
      "somehow and look to be constantly %^BOLD%^%^RED%^oozing blood "+
      "%^RESET%^although they are completely dry.  A message can be "+
      "seen when all the bones are laid side by side.  The bones may be played "+
      "by placing them between the musician's fingers and tapping out a "+
      "beat."
    );
    set_read("%^BOLD%^%^RED%^May the fury of the hunt overcome your "+
       "foes.  You may use these bones to call on the mighty hunter to "+
       "%^WHITE%^<%^RED%^rally%^WHITE%^> %^RED^your companions for the hunt or "+
       "%^WHITE%^<%^RED%^play%^WHITE%^> %^RED%^to create a globe of darkness.");
    set_weight(8);
    set_value(0);
    set_lore("Bards who follow the Lord of the Hunt are rare, but "+
       "there tend to be several storytellers among his number.  Those who "+
       "do follow this path have long since created instruments such as these "+
       "taken from the bones of those they kill.  This set, however, is one "+
       "of the rare sets that mystically appear in the hand of a blessed "+
       "follower of Malar.  Some say he crafts these bones himself from his "+
       "own personal kills.");
    set_property("lore difficulty",12);
}
