// koboldf1.c - Kobold for the newbietown forest

#include <std.h>
#include "../../../newbie.h"
#include "../drownew.h"

inherit "/std/monster";

void kill_baddies(object targ);

void create() 
{
    object ob;
    ::create();
    set_name("kobold");
    set_id( ({ "kobold", "koboldf1" }) );
    set_race("kobold");
    set_gender("male");
    set_short("red-eyed, smelly kobold");
    set_long(
@STYX
This ugly little creature has beady red eyes and two small horns that protrude from the top of its head.  Almost lizardlike in appearance with large pointy ears, it has dark rusty-brown scaly hide and a long hairless tail but stands upright on two legs.  Long skinny fingers end in sharp-looking and pointy fingernails that look more like animal claws.  It smells like something between a wet dog and stagnant water.
STYX
   );
	set_class("thief");
	set_level(4);
    set_mlevel("thief",4);
    set_body_type("human");
    set("aggressive", "hate_types");
    set_alignment(6);
    set_size(1);
    set_hd(5,2);
    set_hp(70);
    set_overall_ac(7);
    set_stats("intelligence",6);
    set_stats("wisdom",6);
    set_stats("strength",15);
    set_stats("charisma",5);
    set_stats("dexterity",16);
    set_stats("constitution",14);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    if(random(5) < 2) 
    {
        new(CMISC"fishing_pole")->move(TO);
        new("/d/common/obj/misc/thief_tools")->move(TO);
    }
	new(CWEAP"dagger")->move(TO);
    command("wield dagger");
    new(CWEAP"dagger")->move(TO);
    command("wield dagger");
    if(!random(5)) 
    {
        new(CMISC"fishing_rod")->move(TO);
        new(CMISC"fish")->move(TO);
    }
    if(random(5) < 2) 
    {
        new(CMISC"sack")->move(TO);
        new(CMISC"climb_tool")->move(TO);
        new(CMISC"torch")->move(TO);
        command("put tools in sack");
        command("put torch in sack");
    }

    set_wimpy(4);
    add_money("gold",random(50)+20);
    add_money("silver",random(150)+30);
    add_money("copper",random(520)+50);
    set_exp(60);
    add_search_path("/cmds/thief");
    set_thief_skill("pick pockets", 40);
    toggle_steal();
    set_scrambling(1);
    ob = new(DNOBJ+"i_key");
    ob->move(TO);
    ob = new("/d/common/obj/misc/pouch.c");
  	ob->move(TO);
    command("wear pouch");
    command("put key in pouch");
    set_property("swarm",1);
    set_achats(5, ({"%^RED%^The kobold hides behind a tree and throws rocks.%^RESET%^", 
	"%^RED%^The kobold's tail twitches as he jumps around.%^RESET%^"}) );
    set_emotes(2, ({"The kobold smirks and licks some blood from it's spear.", 
	"The kobold's tail twitches as he points his spear at you.", 
	"The kobold's beady red eyes seem to be sizing you up.", 
	"The kobold darts past and tries to steal something." 
    }), 0);
    set_monster_feats(({
        "dodge",
        "mobility",
        "evasion",
        "scramble",
    })); 	
    set_new_exp(1, "very low");
}

int hate_types(){
if(wizardp(TP))return 1;
if(TP->query_invis())return 1;
if(!TO->query_invis()) kill_baddies(TP);
}

void kill_baddies(object targ) {
   string race;
   race = (string)targ->query_race();
   if( race == "human" || race == "half-elf" || race == "dwarf" || race == "elf" || race == "halfling" || race == "half-ogre") {
        force_me("say Shoo SHOO, you baddie "+race+"!!");
        force_me("say %^MAGENTA%^Mebbe we kill em if dey don't run!!");
        force_me("kill "+targ->query_name());
        return;
    }
   if( race == "gnome" || race == "goblin" || race == "bugbear" || race == "ogre") {
      	force_me("say We HATE your kind baddie "+race+"!!  %^BOLD%^%^RED%^EEIIIAAEEE!!! Hate hate!!!\nKill em!");
        force_me("kill "+targ->query_name());
        command("scramble");
        return;
   }
}
