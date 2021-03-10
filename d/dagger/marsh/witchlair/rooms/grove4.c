#include <std.h>
#include "../witchlair.h"
inherit BASE"grove_inherit.c";

void create() {
 ::create();
 set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A wall of blackened vines "
"rises from the ground here, the %^RESET%^%^GREEN%^thorn-covered "
"%^BOLD%^%^BLACK%^twisting mass surrounding the grove in a ring.");
 add_items(({"wall","thorns","wall of thorns"}),"%^RESET%^%^GREEN%^A "
"great barrier of t%^BOLD%^%^GREEN%^h%^BLACK%^o%^RESET%^%^GREEN%^"
"rny vines grows here, rising into the thick mist beyond your vision."
" You suspect if you followed it, you'd find it to completely "
"surround this dark copse.");
 set_exits(([
  "west":ROOMS"grove3",
  "northwest":ROOMS"grove6",
  "north":ROOMS"grove7",
  "southwest":ROOMS"grove1",
 ]));
}
