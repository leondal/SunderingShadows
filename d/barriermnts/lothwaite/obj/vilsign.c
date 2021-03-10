#include <std.h>
#include "../lothwaite.h"
inherit OBJECT;

void create()
{
   ::create();
   set_name("sign");
   set_short("A huge wooden sign");
   set_id(({"sign","sign post","post"}));
   set_long("A wooden sign containing directions.  The script seems slightly "+
      "unusual, but you could probably make out the message.");
   set("read",
@CIRCE
%^YELLOW%^><><><><><><><><><><><><><><><><><><><><><><><><><><><><
%^GREEN%^
                 +-+-+-+-+-+-+-+-+-+
                 |%^WHITE%^L%^GREEN%^|%^WHITE%^o%^GREEN%^|%^WHITE%^t%^GREEN%^|%^WHITE%^h%^GREEN%^|%^WHITE%^w%^GREEN%^|%^WHITE%^a%^GREEN%^|%^WHITE%^i%^GREEN%^|%^WHITE%^t%^GREEN%^|%^WHITE%^e%^GREEN%^|
                 +-+-+-+-+-+-+-+-+-+

%^BOLD%^%^WHITE%^Arrows pointing in different directions are labelled:

             %^BOLD%^Southwest %^GREEN%^-%^YELLOW%^> %^BLACK%^Smithy
             %^BOLD%^%^WHITE%^Southeast %^GREEN%^-%^YELLOW%^> %^RESET%^%^GREEN%^Village Green
                          %^YELLOW%^Golden Perch Inn
                          %^BLUE%^East Gates
             %^BOLD%^%^WHITE%^Northwest %^GREEN%^-%^YELLOW%^> %^MAGENTA%^Lake Tearmann Dock
                          %^BLUE%^West Gates

%^YELLOW%^><><><><><><><><><><><><><><><><><><><><><><><><><><><><%^RESET%^
CIRCE
   );
   set_weight(1000000);
   set_property("no animate",1);
   set_value(0);
}
