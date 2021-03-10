#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("thistle");
  set_id( ({"thistle", "flower"}) );
  set_short("%^WHITE%^A Thorny %^MAGENTA%^%^BOLD%^Purple Thistle%^RESET%^");
  set_long("%^BOLD%^%^MAGENTA%^\n"+
    "          ,,::,, %^RESET%^%^MAGENTA%^\n"+
    "         (%^BOLD%^::..::%^RESET%^%^MAGENTA%^)\n"+
    "          \\\\||//              \n"+
    "         /;;;;;;\\ %^BOLD%^%^GREEN%^    ,\n"+
    "  %^RESET%^%^MAGENTA%^       |;;;;;;|  %^BOLD%^%^GREEN%^  /|,\n"+
    "    ,  ,%^RESET%^%^MAGENTA%^ \\;;;;;;/ %^BOLD%^%^GREEN%^ `< /_\n"+
    "   `)\\/\\%^RESET%^%^MAGENTA%^  >\";;\"<%^BOLD%^%^GREEN%^/`-'_(`\n"+
    "  -<_  _`'.>  <^.(`,) `  \n"+
    "    '\\/ )/%^RESET%^%^GREEN%^ ')(`%^BOLD%^%^GREEN%^  `\n"+
    "%^BOLD%^%^GREEN%^     '  `%^RESET%^%^GREEN%^  `)(`\n"+
    "           '\\/`               \n"+
    "           `||~               \n"+
    "           ~||'               \n"+
    "           '||`               \n"+
    "           `||~               \n"+
    "                     %^RESET%^");
  set_weight(1);
  set("value", 1);
}
