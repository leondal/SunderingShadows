#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("daffodil");
  set_id( ({"daffodil", "flower"}) );
  set_short("A Pretty %^YELLOW%^%^BOLD%^Yellow Daffodil%^RESET%^");
  set_long("%^YELLOW%^%^BOLD%^\n"+
    "                      _..                 \n"+
    "             ;-._   .'   `\               \n"+
    "           .'    `\/       ;              \n"+
    "           |       `\.---._|              \n"+
    "        .--;   . ( .'      '.             \n"+
    "       / _  \\_  './ _.       `-._         \n"+
    "      ( = \\  )`""'\\\;--.           /         \n"+
    "      {= (|  )     /`.         / %^GREEN%^    .'| \n"+
    "  %^YELLOW%^    ( =_/  )__..-\         .'  %^GREEN%^    / /   \n"+
    "  %^YELLOW%^     \\    }/    / ;.____.-;/%^GREEN%^\\   .` /    \n"+
    "  %^YELLOW%^      '--' |  .'   |       \\%^GREEN%^ \\  |  ;    \n"+
    "  %^YELLOW%^           \\  '    /       |%^GREEN%^. ;  \\/     \n"+
    "  %^YELLOW%^            )    .'`-.    / %^GREEN%^; |  /\\     \n"+
    "  %^YELLOW%^           /__.-'  %^GREEN%^ ,%^YELLOW%^ \\_.'  %^GREEN%^| | ;  ;    \n"+
    "                      |\\      |`| |  |    \n"+
    "                       \\`\\    | | |  |    \n"+
    "                        \\ `\\  | | ;  ;    \n"+
    "                         |  ; | | /  /    \n"+
    "                         |  | | |/  /     \n"+
    "                         ;  | | /  /      \n"+
    "                          \\  \\;/  /       \n"+
    "                           \\  \\  /        \n"+
    "                            \\  Y/         \n"+
    "                             |  |         \n"+
    "                             |  |         \n"+
    "                             |  |         \n"+
    "                             |  |         \n"+
    "                             \\  |         \n"+
    "                              \\_/         \n"+
    " %^RESET%^     \n");
  set_weight(1);
  set("value", 1);
}
