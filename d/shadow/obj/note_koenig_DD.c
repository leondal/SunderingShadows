//changed by Circe 11/8/03 to reflect changes to Koenig and the Pipe Quest.
#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_id(({"paper","note"}));
  set_name("koenig note");
  set_short("A faded note");
  set_long("This is a crumpled piece of paper with some faded writing on it.  "
              "Perhaps you can still read some of it if you try.");
  set_read(
@CIRCE
                   %^YELLOW%^The note reads:
%^BOLD%^%^CYAN%^There is no dragon in the northern caverns so named,
%^BOLD%^%^CYAN%^Yet danger abounds - but so might your fame!
%^BOLD%^%^CYAN%^To Shadow city to the east you must go
%^BOLD%^%^CYAN%^And from there, north along the main road
%^BOLD%^%^CYAN%^To enter, search the mountains with care
%^BOLD%^%^CYAN%^And explore those great caverns...if you dare!%^RESET%^
CIRCE
   );
  set_weight(1);
  set_value(0);
}
/*ORIGINAL MESSAGE.  CHANGED TO REFLECT CHANGES IN KOENIG & PIPE QUEST BY CIRCE.  11/8/03
  write("%^YELLOW%^The note reads:  %^RESET%^\n");
  write("%^BOLD%^%^CYAN%^There is no dragon in the nearby caverns so named,\n"
    "Yet danger abounds but so might your fame!\n"
    "The Lady Bandolar would send you there for a mission,\n"
    "Her location and the entrance, of course though, are hidden.\n"
    "Search Shadow 'til you find her and the knowledge she'll share.\n"
    "And the bowels of those caverns... of course, IF you dare.\n");
  return 1;
}
*/