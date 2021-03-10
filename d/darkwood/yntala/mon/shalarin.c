#include <std.h>
#include "../yntala.h"


inherit "/std/monster";

void create() {

  ::create();
  set_name("shalarin");
  set_id(( { "shalarin", "fish"} ));
  set_race("Shalarin");
  set_gender("female");
  set_short("%^RESET%^%^CYAN%^A %^GREEN%^g%^CYAN%^r%^BOLD%^%^CYAN%^e%^GREEN%^e%^BLUE%^n%^RESET%^%^CYAN%^i%^BLUE%^s%^GREEN%^h %^CYAN%^shalarin%^RESET%^");
  set_long("%^CYAN%^This graceful swimmer's long legs and arms"
" end in webbed fingers and toes.  Her skin is smooth and scaleless"
" and is a beautiful %^GREEN%^h%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^e"
" of %^GREEN%^g%^CYAN%^r%^BOLD%^%^CYAN%^e%^GREEN%^e%^BLUE%^"
"n%^RESET%^%^CYAN%^i%^BLUE%^s%^GREEN%^h-%^CYAN%^b%^BLUE%^l%^BOLD%^"
"%^BLUE%^u%^CYAN%^e.  %^RESET%^%^CYAN%^She has a large dorsal"
" fin that begins at the bridge of her nose, goes over her"
" skull, reaches it's highest point between her shoulder blades,"
" and finally ends at her tailbone.  Gill slits can be seen along"
" her collar bone and ribcage on either side of her slender torso"
".%^RESET%^\n");
  set_hd(20,2);
  set_alignment(5);
  set_body_type("merfolk");
  set_class("fighter");
  set_size(2);
  set_hp(random(50)+100);
  set_stats("dexterity",14);
  set_overall_ac(-2);
  set_exp(2000);
  set_max_level(15);
  set_moving(1);
  set_nogo(({INRMS+"spring"}));
  set_speed(10);
  set_property("water breather",1);
  set("aggressive", 2);
  set_emotes(1, ({
  "%^BOLD%^%^CYAN%^The shalarin curls into a ball and does a graceful underwater sommersault before straightening back out and looking at you.%^RESET%^",
"%^RESET%^%^CYAN%^The shalarin floats quietly in the water, her eyes studying you.%^RESET%^",
"%^RESET%^%^BLUE%^The shalarin's gills quietly open and close as she watches you.",
}), 0);
    switch(random(7)){
       case 0..5:
          new(OBJD+"uspear.c")->move(TO);
       break;
       case 6:
          new(OBJD+"luspear.c")->move(TO);
       break;
    }
    command("wield spear");
    new(OBJD+"pbreastplatereg.c")->move(TO);
    command("wear plate");
}

