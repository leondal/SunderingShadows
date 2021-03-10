//~Circe~ 12/1/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LANDING;

void create(){
   ::create();
   add_item("painting","This painting has been framed in wood "+
      "tipped with %^ORANGE%^bronze %^RESET%^and shows a "+
      "%^CYAN%^gemcutter %^RESET%^at work.  The artist has "+
      "captured the gemcutter in mid-cut, seated at a neat "+
      "%^ORANGE%^worktable %^RESET%^with dozens of %^BOLD%^"+
      "tools %^RESET%^near at hand.  The gemcutter is an "+
      "aging man with thick %^BOLD%^%^BLACK%^s%^WHITE%^a"+
      "%^BLACK%^l%^WHITE%^t%^BLACK%^-%^WHITE%^a%^BLACK%^n"+
      "%^WHITE%^d%^BLACK%^-%^WHITE%^p%^BLACK%^e%^WHITE%^p"+
      "%^BLACK%^p%^WHITE%^e%^BLACK%^r %^RESET%^hair who "+
      "is using a jeweler's loupe to aid him in cutting the "+
      "brilliant %^MAGENTA%^ame%^BOLD%^t%^RESET%^%^MAGENTA%^"+
      "hyst %^RESET%^before him.");
   set_exits(([
      "down" : ROOMS"psi_landing1",
      "up" : ROOMS"psi_landing3",
      "west" : ROOMS"psi_foyer"
   ]));
   set_pre_exit_functions(({"up","down"}),({"do_banister","do_banister"}));
}