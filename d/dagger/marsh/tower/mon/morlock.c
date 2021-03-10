//General difficulty increase Octothorpe 5/25/09
//changed by Circe 12/14/03 to fix powder bug.
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit MONSTER; 

void create() {
    :: create();
    set_name("morlock");
    set_id(({
        "morlock","graverobber"
    }));
    set_short("%^RESET%^%^GREEN%^Morlock%^RESET%^");
    set_long(
        "The humanoid shape before you can only be a Morlock, creatures "
	"which live beneath the earth, fearing the daylight sun. Many "
	"relate Morlocks to vampires, but this is far from the truth...they "
	"are not undead. However, they are known to butcher humans and "
	"humanoid races for the meat on their bodies. They also are "
	"very capable graverobbers and actively seek to plunder places "
	"of burial in search for the powerful objects and gold which "
	"is often buried along with the dead. Dressed in dirty rags and with "
	"a face only a mother could love, looking upon one makes you shudder. "
	"Normally highly aggressive, this one pays you little heed; obviosly "
   "it has other more important pressing issues on its mind than dinner."
    );
    set_gender("male");
    set_level(28);
    set_alignment(9);
    set_hd(28,6);
    set("aggressive",50);
    set_size(2);
    set_weight(70);
    set_wielding_limbs(({"right hand","left hand"})); 
    set_overall_ac(-19);
    set_property("no steal",1);
    set_body_type("humanoid");
    set_race("morlock");
    set_class("thief");
    set_guild_level("thief",28);
    set_stats("strength",25);
    set_stats("constitution",20);
    set_stats("dexterity",30);
    set_stats("wisdom",15);
    set_stats("intelligence",15);
    set_stats("charisma",-3);
    set_mob_magic_resistance("average");
    set_exp(22000);
    set_thief_skill("hide in shadows",95);
    set_max_level(36);
     set_thief_skill("move silently",2);
     set_scrambling(1);
    set_max_hp(460);
    set_hp(360);
    add_money("gold",random(1000));
    set_emotes(1,({
        "%^BLUE%^The morlock scowls in your direction.%^RESET%^",
	"%^RED%^The morlock seems to think deeply then cackles out loud.",
	"The morlock licks you!",
        "%^MAGENTA%^Morlock says: %^RESET%^It has to be here! Where did he hide it me wonders hmm?",
    }),0);	
    set_funcs(({"throw"}));
    set_func_chance(50);
    new( OPATH "rending.c" )->move(TO);
    command("wield knife in left hand");
    new( "/d/dagger/drow/obj/bldagger.c" )->move(TO);
    command("wield dagger in right hand");
    new( "/d/tharis/obj/bpowder.c" )->move(TO);
    set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes"
    })); 	
}
void throw(object targ){
    if(!targ) return;
    TO->force_me("say Hahaha! So now we see what we will see fool!");
    TO->force_me("toss powder at "+targ->query_name()+"");
    return 1;
}
void die(object ob) {
    message("environment",
	"%^MAGENTA%^Morlock says: %^RESET%^And you would have made a lovely dinner dammit!"
    ,environment(TO));
    :: die(ob);
}
