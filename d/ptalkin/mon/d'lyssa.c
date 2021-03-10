#include <std.h>

inherit MONSTER;
void create() {
   ::create();
set_name("D'lyssa, hotel owner");
set_id(({"D'lyssa", "d'lyssa", "hotel owner", "owner", "elf"}));
   set("aggressive", 0);
set_short("%^BOLD%^BLUE%^D'lyssa, Hotel Owner");
   set_level(19);
set_long("%^BOLD%^CYAN%^D'lyssa is a tiny little lady even for an elf.  Her golden hair surrounds a perfect face with a halo of unruly curls.  Her bright blue eyes sparkle with mischief as her bow shaped mouth curves sensually into a smile.  She wears a long dress made of deep blue velvet with a low bodice showing off her substantial attributes.  The dress hugs her tiny waist and then swirls to the floor in graceful lines.  Tiny silver slipper shod feet peek from beneath her gown.");
set_gender("female");
   set_alignment(4);
set("race", "elf");
set_size(2);
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
}
