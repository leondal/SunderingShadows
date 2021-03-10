#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("sign");
   set_id(({"sign","map"}));
   set_short("%^RESET%^%^ORANGE%^A sign drawn with a map%^RESET%^");
   set_weight(1000000);
   set_property("no animate", 1);
   set_long("%^GREEN%^(34)  (35)  (36)%^MAGENTA%^ (46)  (45)  (44)"
"\n%^GREEN%^    \\  |   \/    %^MAGENTA%^     \\  |   \/"
"\n%^GREEN%^(33) (hall) (37)%^MAGENTA%^ (47) (hall) (43)"
"\n%^GREEN%^   \\   |    \/   %^MAGENTA%^     \\  |   \/"
"\n%^GREEN%^(32)-(hall)-(38)%^MAGENTA%^ (48)-(hall)-(42)"
"\n%^GREEN%^       |        %^MAGENTA%^        |"
"\n%^GREEN%^(31)-(hall)-(39)%^MAGENTA%^ (49)-(hall)-(41)"
"\n%^GREEN%^       | \\      %^MAGENTA%^      \/ |"
"\n%^GREEN%^     (30) \\     %^MAGENTA%^     \/ (40)"
"\n%^GREEN%^           \\    %^MAGENTA%^    \/"
"\n%^CYAN%^            ( TENT )--( FOYER )--( OUTSIDE )"
"\n%^BOLD%^%^MAGENTA%^           \/    %^WHITE%^    \\"
"\n%^BOLD%^%^MAGENTA%^     (60) \/     %^WHITE%^     \\ (50)"
"\n%^BOLD%^%^MAGENTA%^       | \/      %^WHITE%^      \\ |"
"\n%^BOLD%^%^MAGENTA%^(61)-(hall)-(69)%^WHITE%^ (59)-(hall)-(51)"
"\n%^BOLD%^%^MAGENTA%^       |        %^WHITE%^        |"
"\n%^BOLD%^%^MAGENTA%^(62)-(hall)-(68)%^WHITE%^ (58)-(hall)-(52)"
"\n%^BOLD%^%^MAGENTA%^    \/  |   \\    %^WHITE%^     \/  |   \\"
"\n%^BOLD%^%^MAGENTA%^(63) (hall) (67)%^WHITE%^ (57) (hall) (53)"
"\n%^BOLD%^%^MAGENTA%^    \/  |   \\    %^WHITE%^     \/  |   \\"
"\n%^BOLD%^%^MAGENTA%^(64)  (65)  (66)%^WHITE%^ (56)  (55)  (54)\n");
   set_value(0);
}