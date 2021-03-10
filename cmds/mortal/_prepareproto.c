#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <dirs.h>
inherit DAEMON;

mapping LEV_AND_COLORS = ([
                              1 : "%^BOLD%^%^BLACK%^",
                              2 : "%^RED%^",
                              3 : "%^GREEN%^",
                              4 : "%^MAGENTA%^",
                              5 : "%^CYAN%^",
                              6 : "%^BOLD%^%^BLUE%^",
                              7 : "%^BOLD%^%^RED%^",
                              8 : "%^BOLD%^%^GREEN%^",
                              9 : "%^BOLD%^%^MAGENTA%^"
                              ]);

int cmd_prepare(string str)
{

}

void help()
{
    write("");
}
