//riddle_quest.c

#include <std.h>

inherit "std/quest_ob";

void create() {
::create();
set_name("Riddle Quest");
set_quest_points(15);
add_id("Riddle Quest");
}
