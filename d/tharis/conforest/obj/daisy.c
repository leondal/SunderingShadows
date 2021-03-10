#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("daisy");
  set_id( ({"daisy", "flower"}) );
  set_short("%^WHITE%^A Small%^BOLD%^ White Daisy%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^\n"+
    "                           \n"+
    "            .-.            \n"+
    "      __   /   \\   __      \n"+
    "     (  `'.\\%^YELLOW%^ _%^WHITE%^ /.'`  )     \n"+
    "      '-._.%^YELLOW%^(;;;)%^WHITE%^._.-' \n"+
    "      .-'  ,%^YELLOW%^`\"`%^WHITE%^,  '-.\n"+
    "     (__.-'/   \\'-.__)     \n"+
    "           \\   /%^GREEN%^\\ \n"+
    "     %^WHITE%^       '-'%^GREEN%^  \\         \n"+
    "             ,    |        \n"+
    "             |\\   |        \n"+
    "             \\ |  |        \n"+
    "              | \\ /        \n"+
    "               \\|/    _,   \n"+
    "                /  __/ /   \n"+
    "               | _/ _.'    \n"+
    "               |/__/       \n"+
    "                \\          \n"+
    "%^RESET%^\n");
  set_weight(1);
  set("value", 1);
}
