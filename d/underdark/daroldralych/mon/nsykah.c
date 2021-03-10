#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("nsykah");
   set_id(({"n'sykah","priestess","nightcloak","Nightcloak","nightcloak of shar","high nightcloak"}));
   set_short("%^RESET%^%^MAGENTA%^N'sykah, High Nightcloak of Shar%^RESET%^");
   set_long("%^MAGENTA%^The elegant elven creature before you holds herself with a bearing and regality that "
"could only be possessed by the high-priestess of this temple.  Her %^RED%^intense crimson gaze%^MAGENTA%^ "
"bespeaks a great power she holds within, as she keeps an attentive watch over the temple here.  Her garments "
"also depict her high status: she is clad in a smooth spidersilk gown, so dark a hue of black as if it were "
"made of %^BOLD%^%^BLACK%^pure darkness %^RESET%^%^MAGENTA%^itself.  Even her skin, despite its charcoal "
"colouring, is lighter than the garment.  Her %^WHITE%^snowy-white hair %^MAGENTA%^is ornately pinned back "
"with several clasps in the shape of %^BOLD%^%^BLACK%^black spiders%^RESET%^%^MAGENTA%^.  A matching brooch "
"adorns the front of her clothing, of a great arachnid decorated with chips of sparkling amethyst.%^RESET%^");
   set_alignment(6);
   set_race("drow");
   set_class("cleric");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
   set_property("no bow",1);
   force_me("speak drow");
   force_me("speech speak in a sinuous hiss");
}
