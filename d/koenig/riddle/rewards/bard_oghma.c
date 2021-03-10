//bard_oghma.c - Bard of Oghma reward for Nereid Riddle Quest.  Circe 4/13/03
#include <std.h>
#include "../../nereid.h"

inherit RALLYDETECT;

void create(){
    ::create();
//    set_name("oghma instrument");
    set_id(({"rosewood lute","lute","instrument"}));
    set_obvious_short("A rosewood lute");
    set_short("%^RED%^Lute of the Captive Melody%^RESET%^");
    set_long(
       "%^RED%^Rich rosewood has been used in the creation of "+
       "this lute.  Inlays of %^YELLOW%^golden %^RESET%^%^RED%^and "+
       "%^MAGENTA%^purple %^RED%^symbols covers the front and "+
       "back of the body of the lute.  Some of the runes you can "+
       "make out and recall their meaning as you read them over.  "+
       "The lute is strung with five catgut strings, the trusted "+
       "material for entertainers' and bards' instruments.  A pair "+
       "of twin %^YELLOW%^knobs %^RESET%^%^RED%^allows for one to "+
       "tune the instrument to get the perfect pitch.  When played "+
       "this lute tends to allow an entertainer to play a variety of "+
       "melodies, from low somber tunes to light hearted ones full of "+
       "gaiety.  A very useful lute indeed!  Why the craftsmanship "+
       "alone compares to nothing you have ever seen before."
    );
    set_read("%^RESET%^%^RED%^May the power of this lute bring knowledge to "+
       "you and the Binder's libraries.  You may use the lute to "+
       "%^MAGENTA%^<%^RED%^rally%^MAGENTA%^> %^RED%^your companions, or "+
       "%^MAGENTA%^<%^RED%^play%^MAGENTA%^> %^RED%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("The archetypal bardic instrument, the lute, has long "+
       "been the chosen instrument of the Binder's faithful.  This "+
       "particular lute has been infused with the spells crafted "+
       "from the Binder's knowledge to have special powers.  Being "+
       "gifted with such an instrument makes the bard a favored of "+
       "Oghma in many eyes.");
    set_property("lore difficulty",12);
}
