//bard_shaundakul.c - Bard of Shaundakul reward for Nereid Riddle Quest.
//Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit RALLYDETECT;

void create(){
    ::create();
//    set_name("shaundakul instrument");
    set_id(({"birch fiddle","fiddle","instrument"}));
    set_obvious_short("%^BOLD%^%^WHITE%^A worn birch fiddle%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Tr%^RESET%^%^CYAN%^a%^BOLD%^"+
		"%^WHITE%^v%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^ll"+
		"er's %^RESET%^%^CYAN%^Fi%^MAGENTA%^dd%^CYAN%^le"+
		"%^RESET%^");
    set_long("%^RESET%^Pale %^BOLD%^%^WHITE%^birch%^RESET%^ wood has been used in the constriction of this fiddle.  The well worn fiddle gives the appearance of being quite old and well used.  "
"Despite its apparent condition, the fiddle looks well cared for.  %^BOLD%^%^BLACK%^Scorched%^RESET%^ into the body of the pale fiddle is an interwoven, interlocking braided %^CYAN%^geometric"
"%^RESET%^ pattern. A short phrase can be made out in the pattern.  The intricate pattern only adds to the feeling of antiquity from the fiddle.  %^BOLD%^%^WHITE%^Silver%^RESET%^ caps along "
"the neck of the fiddle allow for the %^MAGENTA%^catgut%^RESET%^ strings to be tuned.  The %^BOLD%^%^WHITE%^birch%^RESET%^ wood fiddle comes with a matching bow, strung with a plethora of "
"%^MAGENTA%^catgut%^RESET%^ strings.  When played the fiddled tends to produce rich %^CYAN%^tenor%^RESET%^ notes.");
    set_read("%^CYAN%^May the power of this fiddle aid your travels"+
		" and grant you the desire to always explore over the "+
		"next horizon.  With this fiddle you may: "+
       	"%^MAGENTA%^<rally>%^CYAN%^ your companions, or "+
       	"%^MAGENTA%^<play> %^CYAN%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("The fiddle is often the favored instrument for travelers and caravans.  The range of the fiddle is prized due to the ability to play both light hearted songs and the sweet tender "
"tenor melody produced for slower songs.  Stories of travelers and caravans sitting around a campfire at night, entertained by a skilled musician with the fiddle were once very common.  Often "
"times, a skilled fiddle master was received a warmer reception than one skilled in a lute or lyre.");
    set_property("lore difficulty",12); 
}
