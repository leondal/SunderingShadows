#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("pirate");
    set_id(({"pirate","bald","human fighter"}));
    set_short("Bald Bolarny");
    set_long("
Bald Bolarny is so named because of his lack of hair.  Although not
particularly bright, he has proven himself reliable in combat, which
is what the pirates need.  He is not evil but lacks the self-will and
determination to think for himself.
    ");
    set_race("human");
    set_gender("male");
    set_hd(14,6);
    set_size(2);
    set_class("fighter");
    set_guild_level("fighter",14);
    set_max_hp(140);
    set_hp(140);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set_stats("intelligence",5);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(1600);
    set_alignment(5);
    set_emotes(5,({
   "%^MAGENTA%^Bald says:%^RESET%^ Have you ever seem my puppies?",
   "%^MAGENTA%^Bald says:%^RESET%^ I raised my puppies to be great hunting dogs.",
    }),0);
    new("/d/dragon/obj/armor/plate")->move(this_object());
    command("wear plate");
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield sword in right hand");
  new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger in left hand");
    set_overall_ac(0);
}
void die(object ob) {
    message("environment",
	"My dogs will live forever in the wilderness."
    ,environment(ob));
    :: die(ob);
}
