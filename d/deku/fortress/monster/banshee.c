#include <std.h>
inherit "/std/monster";
// void wail(object targ);

create()
{
  ::create();
  set_name("banshee");
  set("id", ({"banshee", "a banshee", "the banshee"}) );
  set_short("a Banshee");
  set_long("This spirit looks almost beautiful if not for the fact that its face is twisted into a mask of eternal pain and anger, her hair unkept, and her eyes (that burn like red coals) are full of hatred and ire. You can almost see the landscape through her and what clothing she wears is tattered and torn.");
  set_race("elf");
  set_gender("female");
  set_body_type("elf");
  set_hd(7);
  set_overall_ac(0);
  set_property("strength", "magic");
  set_alignment(9);
  set_size(2);
  set_max_hp(65);
  set_hp(70);
   //set_exp(13000);
	set_new_exp(10, "low");
  set("aggressive", 26);
   add_money("gold", 500 + random(500));
  set_wimpy(20);
  set_wimpydir("north");
  set_emotes(10, ({"%^BOLD%^The Banshee wails horribly, freezing you to the spot!", "%^BOLD%^%^BLACK%^WWWWWWWWWAAAAAAIIIIIIIILLLLLLLLLLLLLLL!!!!!!!!!!"}) );
    set_achats(10, ({"%^BOLD%^%^BLACK%^The Banshee says: %^RESET%^%^BOLD%^Foolish Mortal, you shall not escape me!!"}) );
    set_funcs( ({ "wail" }) );
    set_func_chance(30);
}
void wail(object targ)
{
    if(!targ) return 0;
    tell_room(environment(targ),"The banshee screeches a "+
        "deathly wail at "+targ->query_cap_name()+"!",targ);
    tell_object(targ,"%^BOLD%^%^WHITE%^You are paralyzed by "+
        "the screech of the banshee!");
    targ->set_paralyzed(random(10)+5,"You are paralyzed in fear.");
return 1;
}
