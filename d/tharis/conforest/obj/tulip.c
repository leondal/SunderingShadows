#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("tulip");
  set_id( ({"tulip", "flower"}) );
  set_short("%^WHITE%^A Pretty%^MAGENTA%^%^BOLD%^ Purple Tulip%^RESET%^");
  set_long("%^MAGENTA%^\n"+
    "                                      \n"+
    "                  .-\"\"--.,            \n"+
    "                /` \\.-.{/ \\           \n"+
    "               /  .' ; '.  \\          \n"+
    "               | /       \\ |          \n"+
    "               |/         \\|          \n"+
    "               T      :    Y          \n"+
    "               |      :    ;          \n"+
    "               |      :    |     %^GREEN%^     \n"+
    "         |\\. %^MAGENTA%^  \\     :     / %^GREEN%^         \n"+
    "         | \\'. %^MAGENTA%^ '.  .    .'     %^GREEN%^      \n"+
    "         | |  \\ %^MAGENTA%^  `\"T=T\"`    %^GREEN%^         \n"+
    "         | /   \\    | |               \n"+
    "         |` :   |   | |               \n"+ 
    "         \\   :  |   | |    _          \n"+
    "          |   .  \\  | |  /` `-._      \n"+
    "          |   :   | | | |   .'  /'.   \n"+
    "          \\   .   | | | |  .   |   `\\ \n"+ 
    "          |       | | | |      /     |\n"+ 
    "          |   '    \\| | | :   /'-.   |\n"+
    "           \\   '   || |/  ;   |   \\  /\n"+
    "           |   :   ;| ||  .   |   '-' \n"+
    "           \\   :   || |/ ;    /       \n"+
    "            |   '  ;| |  '   |        \n"+
    "             \\  :  || | '   /         \n"+  
    "              `\\ ' \\| ;'   /          \n"+
    "                `\\' | |  /`           \n"+
    "                  `\\| |/`             \n"+
    "                    | |               \n"+
    "                    | |               \n"+
    "                    | |               \n"+
    "                    |/                \n"+
    "%^RESET%^\n");
  set_weight(1);
  set("value", 1);
}
