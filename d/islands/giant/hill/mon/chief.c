#include "/realms/terrato/giant/giant.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("Chief Glacor");
   set_id(({"chief","giant","hill giant","glacor","chief glacor"}));
   set_short("%^YELLOW%^Chief Glacor%^RESET%^");
   set_long(
@TERRATO
   %^YELLOW%^Chief Glacor%^RED%^ rules all the other giants in his domain
through sheer force.  He is a bloodthirsty advisary and cunning leader
His wits and strength has allowed him to kill many who believed that Hill
Giants where stupid or slow.  Should he capture you, you can expect a slow,
painful death in his torture chamber as he watches.
TERRATO
   );
   set_overall_ac(-5);
   set_race("giant");
   set_gender("male");
   set_body_type("human");
   set_hd(25,10);
   set_max_hp(250);
   set_hp(250);
   set_exp(20000);
   set_size(4);
   set_stats("strength",19);
   set_stats("intelligence",15);
   set_stats("wisdom",17);
   set_stats("dexterity",11);
   set_stats("constitution",19);
   set_stats("charisma",10);
   set_money("gold",1300);
   set_money("silver",5400);
   set_class("fighter");
   set_guild_level("fighter",22);
   add_search_path("cmds/fighter");
   set_property("full attacks",1);
   set_alignment(3);
   set_emotes(20, ({
      "%^MAGENTA%^Glacor says%^RESET%^: You will die puny one!",
      "%^MAGENTA%^Glacor says%^RESET%^: Your skull will sit hollowed on my wall!",
      "%^MAGENTA%^Glacor says%^RESET%^: I will squash you beneath my heel!",
      "%^RED%^Galcor grins as he swing his weapon at you!%^RESET%^",
   }),1);
   set("aggressive","aggfunc");
   new(HOBJ+"ballista.c")->move(this_object());
   command("wield ballista in left hand and right hand");
}

void aggfunc(){
   command("say Come puny one and I will show you how insignificant you truly are!");
   command("say %^RED%^DESTROY THEM%^RESET%^");
   TP->kill_ob(TO,0);
}

void drink(object targ) {
   tell_room(ETO,"%^BOLD%^You see Glacor pull a small vial from a secret pouch in his belt.%^RESET%^");
   tell_room(ETO,"%^BLUE%^Becomes a blur as his speed is greatly increased!");
   tell_room(ETO,"%^RED%^You see Glacor begin firing at you at high speed!");
   command("drink green");
}
