#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"glyph","glyph of fire"}));
    set_short("%^RED%^%^BOLD%^Glyph of fire%^RESET%^");
    set_name("glyph");
    set_long("%^RED%^This glyph has been placed upon a velcrum scroll. Although "
             "you do not understand what it is used for, you can assume it is possible "
             "to transfer it to a surface through %^ORANGE%^<inscribe glyph>%^RESET%^."
        );
    set_weight(1);
}

