#include <std.h>
#include "../yntala.h"


inherit "/std/monster";
object ob;

void create() {

  ::create();
  set_name("shalarin");
  set_id(( { "shalarin", "fish"} ));
  set_race("Shalarin");
  set_gender("female");
  set_short("%^RESET%^A %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^BLACK%^e%^WHITE%^r%^RESET%^y %^BOLD%^%^WHITE%^white %^RESET%^shalarin%^RESET%^");
  set_long("%^RESET%^This graceful swimmer's long legs and arms"
" end in webbed fingers and toes.  Her skin is smooth and scaleless"
" and is a beautiful %^BOLD%^%^WHITE%^h%^RESET%^u%^BOLD%^%^BLACK%^"
"e %^RESET%^of %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^"
"%^BLACK%^l%^RESET%^v%^BOLD%^%^BLACK%^e%^WHITE%^r.  %^RESET%^"
"She has a large dorsal fin that begins at the bridge of"
" her nose, goes over her skull, reaches it's highest point"
" between her shoulder blades, and finally ends at her tailbone."
"  Gill slits can be seen along her collar bone and ribcage on"
" either side of her slender torso.%^RESET%^\n");
  set_hd(15,2);
  set_alignment(5);
  set_body_type("merfolk");
  set_size(2);
  set_hp(random(50)+100);
  set_stats("dexterity",14);
  set_overall_ac(-2);
  set_exp(700);
  set_moving(1);
  set_nogo(({INRMS+"spring"}));
  set_speed(10);
  set_property("water breather",1);
  set("aggressive", 2);
  set_emotes(1, ({
  "%^BOLD%^%^CYAN%^The shalarin curls into a ball and does a graceful underwater sommersault before straightening back out, not taking any notice of you.%^RESET%^",
"%^RESET%^%^CYAN%^The shalarin floats effortlessly in the water.%^RESET%^",
"%^RESET%^%^BLUE%^The shalarin's gills quietly open and close as she dances in the water.",
}), 0);
    ob=new(LGSW+"trident.c");
    ob->set_property("enchantment",2);
    ob->set_long("%^BOLD%^%^WHITE%^This is a beautiul trident crafted from a long, solid piece of ivory that"
" branches into three tines that are tipped with %^CYAN%^di%^WHITE%^a%^CYAN%^mo%^WHITE%^n%^CYAN%^d %^WHITE%^heads"
" to create three very sharp points.  The center tine is slightly longer than the two side ones and has been"
" engraved with small undecipherable %^CYAN%^aqua runes.  %^WHITE%^The handle of the trident has been encrusted"
" with many small, s%^CYAN%^h%^WHITE%^imm%^CYAN%^e%^WHITE%^ring pe%^CYAN%^a%^WHITE%^rls that create an excellent"
" grip.%^RESET%^");
    ob->move(TO);
    command("wield trident");
    new(OBJD+"pbreastplatereg.c")->move(TO);
    command("wear plate");
}
