//Ryanallynella - ticket seller and inventor of airships
//~Circe~ 5/26/07

#include <std.h>
inherit NPC;

void create(){
    ::create();
    set_id(({"ryanallynella","Ryanallynella","ryan","Ryan","seller","ticket seller"}));
    set_name("ryanallynella");
    set_short("Ryanallynella the Ticket Seller");
    set_long(
@CIRCE
Ryanallynella is a young female gnome who seems to be in her forties.  She wears a bright %^BOLD%^%^MAGENTA%^pink lab coat %^RESET%^%^CYAN%^over thick %^ORANGE%^brown leather boots%^CYAN%^ that clunk when she walks.  Her %^BOLD%^%^WHITE%^silver hair %^RESET%^%^CYAN%^is pulled into pigtails over her ears, and a pair of %^ORANGE%^leather-bound goggles %^CYAN%^rests atop her head.  Her eyes are a curious, sparkling %^BOLD%^blue %^RESET%^%^CYAN%^that twinkle with intelligence.  She moves with a purpose despite the bounce in her step, and she seems to have a supreme confidence in herself.
CIRCE
    );
    set_race("gnome");
    set_gender("female");
    set_size(1);
    set_hd(19,2);
    set_hp(200+random(50));
    set_overall_ac(-10);
    set_exp(100);
    set_alignment(1);
    set("aggressive",0);
}