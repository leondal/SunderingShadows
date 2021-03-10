// She's moved from the Consortium to be used in /d/player_houses/solaren tower for the new mage guild *Styx*  6/17/03

#include <std.h>

inherit TOWNSMAN;

void create(){
   ::create();

   set_name("Mrs. Thazorus");
   set_short("Mrs. Thazorus");
   set_id(({"Thazorus","thazorus","Mrs. Thazorus"}));
   set_gender("female");
   set_long(
   "This is a very old, more mature woman.  Her eyes glare stonily around the"+
   " room making sure no-one gets louder than a whisper.  Her uncharismatic style"+
   " vaguely depicts the sophistication of the owners of the library.  Also she"+
   " collects the funds for use of the books and quickly deposits it into the guild treasury."
   );
   set_race("human");
   set_hd(1,10);
   set_hp(10);
   set_overall_ac(10);
   set_alignment(2);
}


