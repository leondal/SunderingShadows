#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("drow");
   set_id(({"bard","bardess","dancer"}));
   set_short("%^RESET%^%^MAGENTA%^A lithe drow woman garbed in silks%^RESET%^");
   set_long("%^MAGENTA%^This beautiful specimen of an elf moves with unnatural %^CYAN%^grace%^MAGENTA%^, the "
"kind more familiar with a feline than a humanoid.  Her lithe figure is shrouded in a series of %^GREEN%^la"
"%^ORANGE%^ye%^RED%^re%^MAGENTA%^d s%^BLUE%^il%^CYAN%^ks %^MAGENTA%^that reveal her body in just the right "
"places, leaving barely enough to the imagination.  Long curls of thick %^WHITE%^whi%^BOLD%^t%^RESET%^%^WHITE%^"
"e %^MAGENTA%^hair roll in waves down past her shoulders and over her back, only held back by the occasional "
"well-placed braid or comb.  Her striking %^ORANGE%^amber eyes %^MAGENTA%^and fine-boned features give her an "
"unusual, %^CYAN%^exotic %^MAGENTA%^appearance that set her well apart from most of her kind.%^RESET%^");
   set_alignment(6);
   set_race("drow");
   set_class("bard");
   set_body_type("human");
   set_hd(25,8);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
   set_property("no bow",1);
   set_scrambling(1);
}
