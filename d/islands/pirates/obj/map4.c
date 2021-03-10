#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_id(({"map","map fragment","fragment of a map","fragment of an old map","old map"}));
   set_name("map");
   set_short("fragment of an old map");
   set_long("%^ORANGE%^This crumpled parchment appears to be a map of something, though it is torn along two "
"edges, as if it is only one part of a whole.  Maybe it leads to pirate treasure!  You should %^WHITE%^read "
"%^ORANGE%^it.%^RESET%^");
   set_weight(0);
   set_value(0);
   set("read","\n%^ORANGE%^    /\\___.--`\\__/'.__.---'~\\_\n"
"%^ORANGE%^   /%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   \\%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   {%^BLUE%^000%^CYAN%^%^BOLD%^~%^RESET%^%^BLUE%^000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   /%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   )%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   \\%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   /%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   }%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   \\%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   /%^BLUE%^0000000000000000%^RED%^%^BOLD%^*\\_/\\%^RESET%^%^BLUE%^0000%^ORANGE%^|\n"
"%^ORANGE%^   )%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   \\%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   }%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   \\%^BLUE%^00000%^CYAN%^%^BOLD%^~%^RESET%^%^BLUE%^0000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   /%^BLUE%^0000000000000000000000000%^ORANGE%^|\n"
"%^ORANGE%^   `~------------------------`\n\n"
"%^ORANGE%^~ Be not much treasure ta be had out this far ~");
}


