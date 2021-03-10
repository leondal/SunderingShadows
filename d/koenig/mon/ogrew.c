#include <std.h>
#include "../koenig.h"

inherit MONSTER;

void create (){

::create ();
   set_name("Ogre Warrior");
   set_id(({"ogre","Ogre","ogre warrior"}));
   set_short("A large ogre");
   set_long("%^RESET%^This is a large and grotesque creature,"
" standing nearly nine feet tall. He walks slightly hunched"
" over, causing his long, %^BOLD%^%^BLACK%^greasy dark hair"
" %^RESET%^to fall over his huge shoulders. His thick hide is"
" is covered in dark, %^GREEN%^warty %^RESET%^bumps that give"
" off a terrible smell. He wears loose fitting, ugly skins and"
" furs that have a fairly unique, but equally disgusting smell."
" His face is always crumpled into a frown, and his large teeth"
" curve up over his upper lip, nearly touching his snout-like"
" nose.");
   set_race("ogre");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(-3);
   set_hd(10,2);
   set_size(3);
   set_stats("intelligence",6);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",18);
   set_stats("charisma",4);
   set_money("gold",random(90));
   set_hp(random(50)+100);
   set_max_hp(query_hp());  
   //set_exp(150);
   set_exp(800);
   set_moving(1);
   set_speed(20);
   set_nogo(({INRMS+"path6.c","/d/koenig/streams/path6"}));
   set_alignment(9);
   set("aggressive",19);
   set_achats(5, ({"%^BOLD%^%^BLACK%^The ogre swings his club wildly over his head before attacking you again!%^RESET%^"}) );
      new("/d/common/obj/weapon/club_lg.c")->move(TO);
      command("wield club");
}
