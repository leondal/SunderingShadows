#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("stone");
    set_id( ({"stone", "charcoal", "charcoal stone", "stone_of_render"}) );
    set_short("%^RESET%^%^GREEN%^A charcoal stone%^RESET%^");
    set_long("%^GREEN%^"
      "The small charcoal stone is small and quite plain looking but "
      "very warm to the touch for some unknown reason.\n%^BLUE%^As "
      "you gaze upon the stone a voice fills your head:\n%^MAGENTA%^"
      "     'Take the stone to the place of summoning to `summon` the great `beast` back "
      "from it's imprisonment to roam the Shadowlands once again!'"
      "%^RESET%^"
    );
    set_weight(1);
    set_value(1);
}
