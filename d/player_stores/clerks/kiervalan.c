

#include <std.h>

#define KHOUSE "/d/player_houses/kiervalan/"
#define MAX_ITEMS 10

inherit "/std/vendor_pstore";

create() {
   ::create();
   make_me();
   set_hd(28,2);
   set("aggressive", 0);
   set_level(29);
   set_class("mage");
   set_mlevel("mage", 35);
   set_guild_level("mage",35);
   set_alignment(5);
   add_money("gold", random(500));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",18);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person",
"powerword stun", "magic missile", "magic missile", "wall of fire",
"phantom guardians", "prismatic spray" }));
   set_shop(KHOUSE+"shop");
}

void heart_beat() {
    object *killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_hp() < 80) {
       command("say Lord Wolf will hear of this!!");
       tell_room(ETO, "%^RESET%^%^RED%^The clerk throws a bag of "+
"something on the ground!%^RESET%^\n");
       tell_room(ETO, "%^RESET%^%^RED%^There is an ear "+
"shattering %^BOLD%^BANG%^RESET%^%^RED%^ and a bright %^CYAN%^%^BOLD%^chemical "+
"flash%^RESET%^%^RED%^!\n");
       killers = query_attackers();
       for(i=0;i<sizeof(killers);i++) {
          killers[i]->cause_typed_damage(killers[i], "head", roll_dice(10, 5), "untyped");
       }
    tell_room(ETO, "%^BLACK%^%^BOLD%^When you regain your senses, "+
"you find the clerk is gone.%^RESET%^");
    TO->move("/d/Shadowgate/void");
    TO->remove();
    }
}


void make_me() {
   switch(random(2)) {
      case 0:
        set_name("Sanada");
        set_id(({ "shop clerk","shopkeeper","clerk", "sanada",
            "Sanada Yoshitsune", "Yoshitsune", "Yoshi"}));
        set_gender("female");
        set_race("half-elf");
        set_short("%^RESET%^%^MAGENTA%^San%^BOLD%^a%^RESET%^%^MAGENTA%^da "+
"Yoshit%^BOLD%^s%^RESET%^%^MAGENTA%^une%^RESET%^");
        set_long("%^BLACK%^%^BOLD%^Sanada is a svelte young half-elf dressed in "+
"form fitting %^RESET%^black leather armor%^BLACK%^%^BOLD%^ and a %^RESET%^long "+
"black cowled robe%^BLACK%^%^BOLD%^ that flows off of her body. %^RESET%^%^ORANGE%^Long "+
"brown hair%^BLACK%^%^BOLD%^ is braided and hangs down over her shoulder and she would "+
"be extremely beautiful if not for a %^RESET%^%^RED%^vicious angry scar%^BLACK%^%^BOLD%^ "+
"running from her left temple down along her cheek and disapearing by her "+
"collarbone. %^GREEN%^%^BOLD%^Cold green eyes%^BLACK%^%^BOLD%^ regard "+
"the %^RESET%^%^ORANGE%^shop%^BLACK%^%^BOLD%^ with a measured arrogance. "+
"Over her heart on the studded is a %^RESET%^small steel pin%^BLACK%^%^BOLD%^ "+
"in the shape of a %^RESET%^wolf's paw%^BLACK%^%^BOLD%^, denoting her "+
"allegience.%^RESET%^\n");
        break;
     case 1:
        set_name("Zizka");
        set_id(({ "shop clerk","shopkeeper","clerk", "zizka", "jan zizka",
"jan"}));
        set_gender("male");
        set_race("human");
        set_short("%^RESET%^%^ORANGE%^Jan Z%^BLACK%^%^BOLD%^i%^RESET%^%^ORANGE%^zka%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^Jan is a burly older gentleman, perhaps in his sixties, "+
"that looks to be from the %^RESET%^%^CYAN%^northern Dagger region%^RESET%^%^ORANGE%^. His "+
"form is one that has obviously been through the vigors of life, and come out better for "+
"it. %^RESET%^%^RED%^Toned muscles%^RESET%^%^ORANGE%^ are still evident under "+
"his %^BLACK%^%^BOLD%^leather jerkin%^RESET%^%^ORANGE%^ and his tanned skin is %^YELLOW%^weather "+
"blasted%^RESET%^%^ORANGE%^. His short cropped %^BLACK%^%^BOLD%^black hair%^RESET%^%^ORANGE%^ "+
"hangs over his one good %^BLUE%^%^BOLD%^blue eye%^RESET%^%^ORANGE%^, the other covered with "+
"a %^BLACK%^%^BOLD%^black eye patch%^RESET%^%^ORANGE%^. He watches the shop like a hawk, but "+
"tends to smile more often then not as people look over the wares. Over his heart on his "+
"jerkin is a %^RESET%^%^BOLD%^small ivory pin %^RESET%^%^ORANGE%^in the shape of "+
"a %^RESET%^wolf's paw%^RESET%^%^ORANGE%^, denoting his allegience.%^RESET%^\n");
        break;
   }
}

