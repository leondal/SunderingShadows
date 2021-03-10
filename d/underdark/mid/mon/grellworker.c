#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

int following;

void create() {
    object ob;
    ::create();
    set_id(({"grell","worker grell"}));
    set_name("grell");
    set_short("%^RESET%^%^ORANGE%^A floating grell%^RESET%^");
    set_long("%^RESET%^The creature before you looks remarkably like a giant floating brain. A solid crest of "
"several %^RED%^dark bony protrusions %^RESET%^marks a line down the centre of its head. It has a %^YELLOW%^"
"vicious beak %^RESET%^protruding from one end, presumably the front, though there seem to be no eyes or "
"sensory organs, leaving you wonder how it manages to direct itself. It seems to have no problems with this "
"though, floating about in the air by some form of levitation, with about %^ORANGE%^ten tentacles %^RESET%^"
"curling and writhing along beneath it.%^RESET%^");
    set_race("grell");
    set_race("human");
    set_gender("male");
    set_alignment(6);
    remove_limb("neck");
    remove_limb("right foot");
    remove_limb("left foot");
    remove_limb("right hand");
    remove_limb("left hand");
    remove_limb("left leg");
    remove_limb("right leg");
    remove_limb("left arm");
    remove_limb("right arm");
    remove_limb("waist");
    remove_limb("head");
    add_limb("first tentacle","torso", 0, 0, 0);
    add_limb("second tentacle","torso", 0, 0, 0);
    add_limb("third tentacle","torso", 0, 0, 0);
    add_limb("fourth tentacle","torso", 0, 0, 0);
    add_limb("fifth tentacle","torso", 0, 0, 0);
    add_limb("sixth tentacle","torso", 0, 0, 0);
    add_limb("seventh tentacle","torso", 0, 0, 0);
    add_limb("eighth tentacle","torso", 0, 0, 0);
    add_limb("ninth tentacle","torso", 0, 0, 0);
    add_limb("tenth tentacle","torso", 0, 0, 0);
    set_class("fighter");
    set_hd(26,12);
    set_guild_level("fighter",26);
    set_mlevel("fighter",26);
    set_max_hp(200);
    set_hp(200);
    set_property("swarm",1);
    set_stats("strength",17);
    set_exp(2000);
    set_overall_ac(-12);
    set("aggressive",25);
    set_attack_limbs(({"third tentacle","fourth tentacle","fifth tentacle","sixth tentacle","seventh tentacle","eighth tentacle","ninth tentacle","tenth tentacle"}));
    if(!random(3)) { new(OBJ"lightningspear")->move(TO); }
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    set_damage(1,4);
    set_property("no steal",1);
    set_property("strength","electrcity");
    set_funcs(({"zap_me"}));
    set_func_chance(10);
    add_search_path("/cmds/wizard");
}

void zap_me(object targ) {
    if(!objectp(TO) || !objectp(targ)) return;
    if(!present(targ->query_name(),ETO)) return;
    tell_room(ETO,"%^CYAN%^The grell raises its spear, and releases a crackling charge of %^YELLOW%^ele"
"%^WHITE%^c%^YELLOW%^tri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^CYAN%^down its length at "+targ->QCN+"!"
"%^RESET%^",targ);
    tell_object(targ,"%^CYAN%^The grell raises its spear, and releases a crackling charge of %^YELLOW%^ele"
"%^WHITE%^c%^YELLOW%^tri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^CYAN%^down its length at "+targ->QCN+"!%^RESET%^");
    new("/cmds/spells/c/_chain_lightning")->use_spell(TO,targ,20,100,"mage");
}

void init(){
   object ob;
   ::init();
   if(!following) {
     if(ob = present("grell philosopher",ETO)) {
       ob->add_follower(TO);
       following = 1;
     }
   }
}
