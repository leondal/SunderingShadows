//Circe 8/24/05
#include <std.h>
#include "../../nereid.h"

inherit CALMDETECT;

void create(){
    ::create();
    set_name("bronzed hautbois");
    set_id(({"hautbois","bronzed hautbois","instrument","hautbois of serenity"}));
    set_obvious_short("a bronzed hautbois");
    set_short("%^ORANGE%^Hautbois of %^BOLD%^%^CYAN%^Serenity%^RESET%^");
    set_long(
       "%^ORANGE%^Fashioned from %^RESET%^silver %^ORANGE%^edged "+
       "with bronze, this hautbois is an intricate instrument "+
       "that features no fewer than eighteen fingerholes.  "+
       "Several of the fingerholes have been covered with cleverly-"+
       "designed lids that may be lifted through a complex series "+
       "of levers and keys.  The mouthpiece is fitted with very "+
       "narrow %^RESET%^reeds%^RESET%^%^ORANGE%^, which give it a light, "+
       "%^CYAN%^airy %^ORANGE%^sound perfect for complex melodies.  "+
       "A message you could read has been inscribed along the "+
       "length of the instrument in a thin, flowing script.%^RESET%^"
    );
    set_read("%^RESET%^%^CYAN%^May the power of this hautbois "+
       "enlighten your mind and bring you serenity.  You may "+
       "use the hautbois to %^ORANGE%^<%^%^BOLD%^%^CYAN%^%^calm"+
       "%^RESET%^%^ORANGE%^> %^CYAN%^your enemies, or "+
       "%^ORANGE%^<%^%^BOLD%^%^CYAN%^%^play"+
       "%^RESET%^%^ORANGE%^> %^CYAN%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("The Lord of Reason possesses a largely human following, "+
       "and it is an almost uniquely human instrument that his "+
       "bards choose to use.  Most of Auppenser's bards are "+
       "lore masters, insterested in furthering their own knowledge "+
       "and spreading their experiences so it might help others "+
       "find enlightenment.  Quite a few bards dedicated to "+
       "Auppenser find the intricate melodies possible on the "+
       "hautbois can expand their minds.");
}
