//~Circe~ 10/30/07
#include <std.h>

inherit OBJECT;

#define COLORS ({"%^BOLD%^%^RED%^red","%^BOLD%^%^MAGENTA%^pink","%^RESET%^%^MAGENTA%^purple","%^BOLD%^%^BLUE%^blue","%^BOLD%^%^CYAN%^aquamarine","%^ORANGE%^tan","%^YELLOW%^yellow"})

void create(){
   string COLOR;
   COLOR = COLORS[random(sizeof(COLORS))];
   ::create();
   set_name("shell rose");
   set_short("a "+COLOR+" conch shell rose%^RESET%^");
   set_id(({"rose","shell rose","conch shell rose"}));
   set_long("This rose is created from a perfect %^BOLD%^conch shell "+
      "%^RESET%^banded with "+COLOR+"%^RESET%^.  The "+COLOR+" rose %^RESET%^"+
      "has been attached to a metal stem wrapped in %^GREEN%^"+
      "green fabric%^RESET%^.  Just beneath the rosebud, finishing "+
      "touches of little %^GREEN%^leaves %^RESET%^and %^ORANGE%^"+
      "thorns %^RESET%^have been added to this ingenious flower.");
   set_weight(1);
   set_value(15);
}