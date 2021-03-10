#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("spirit dancer");
    set_id(({"spirit dancer","spirit","spiritdancer", "dancer"}));
    set_short("%^BOLD%^%^CYAN%^Spirit dancer");
    set_long("
    %^CYAN%^The spirit dancer is a flaming wisp that moves freely through the air.  It is a member of the will-o-wisp family of spiritual presences and are so named because of the eratic movements they make.  They almost seem to dance as they lunge and stretch around through the air.");
    set_gender("female");
    set_hd(26,6);
    set_size(2);
    set_overall_ac(-4);
    set_class("fighter");
    set_guild_level("fighter",16);
    set_max_hp(140);
    set_hp(140);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_race("will-o-wisp");
    set_property("swarm",1);
      set_property("magic",1);
    set_moving( 1 );
     set("aggressive", 15);
    set_speed ( 8 );
    set_property("full attacks",1);
    set_stats("dexterity",18);
    set_stats("constitution",17);
     set_stats("strength",22);
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(3000);
    set_emotes(5,({
        "%^BOLD%^%^CYAN%^Spirit dancer darts past your head!",
      "The wind around you seems to pick up!",
        "Smaller wisps twinkle and fade as they break away from the central form!",
        "Spirit dancer floats ominously around you.",
        "You feel a strange presence upon you!",
        "The ground beneath you begins to feel uneasy.",
        "A shiver runs the length of your spine."
    }),0);
}
void init(){
// added ::init() to fix/prevent bugs & changed wizardp to check true invis 2/23/03 *Styx*
    ::init();
    if(TP->query_invis() && !TP->query_true_invis()) {
//          if(TP->query_invis()&&!wizardp(TP)){
      tell_room(ETO,"You feel a hush like a shadow fall upon you!");
      TP->set_invis();
        kill_ob(TP,1);
    }
}
void die(object ob) {
    message("environment",
        "The Spirit wisp changes to a dark blue.\n""%^BLUE%^A cloud of dark matter speeds upwards from the center of the Spirit dancer." ,ETO);
      ::die(ob);
}
