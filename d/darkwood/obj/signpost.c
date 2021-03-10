#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("sign");
  set_id( ({"sign"}) );
  set_short("Sign");
  set_long("%^BOLD%^*******************************\n"+
           "*                             *\n"+
           "*%^RESET%^%^RED%^       *%^RESET%^%^BOLD%^                     *\n"+
           "*%^RESET%^%^RED%^      ***%^RESET%^%^BOLD%^                    *\n"+
           "*%^RESET%^%^RED%^     *****%^RESET%^%^BOLD%^                   *\n"+
           "*%^RESET%^%^RED%^    *******%^RESET%^%^BOLD%^    Merchants     *\n"+
           "*%^RESET%^%^RED%^   *********%^RESET%^%^BOLD%^     trail       *\n"+
           "*%^RESET%^%^RED%^      ***%^RESET%^%^BOLD%^         to         *\n"+
           "*%^RESET%^%^RED%^      ***%^RESET%^%^BOLD%^    Stormpemhauder  *\n"+
           "*%^RESET%^%^RED%^      ***%^RESET%^%^BOLD%^                    *\n"+
           "*%^RESET%^%^RED%^      ***%^RESET%^%^BOLD%^                    *\n"+
           "*                             *\n"+
           "*******************************\n");
  set_weight(10000);
  set_value(0);
}

