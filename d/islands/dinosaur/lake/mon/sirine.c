#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MONSTER;

void create(){
    ::create();
    set_property("swims", 1);
    set_name("Sirine");
    set_id( ({"sirine", "siren", "water chick"}) );
    set_short("%^BOLD%^%^CYAN%^Sirine");
    set_long(
      "This amazingly beautiful woman is very scantily clad in the simplest of clothes.  Her beauty charms your eyes, and as you watch the fluid motion through the water, her voice sings a song touching the deepest parts of your heart."
    );
    set_race("sirine");
    set_body_type("humanoid");
    set_alignment(random(9)+1);
    set_gender("female");
    set_overall_ac(-4);
    set_hd(26, 9);
    set_hp(250+random(200));
    set_stats("charisma", 21);
    set_stats("dexterity", 18);
    set_stats("strength", 15);
    set_stats("constitution", 12);
    set_stats("intelligence", 16);
    set_stats("wisdom", 16);
    add_money("gold", random(250));
    add_money("platinum", random(100));
    set_exp(5000);
    new("/d/shadow/obj/weapon/dagger.c")->move(TO);
    new("/d/shadow/obj/weapon/shortsword.c")->move(TO);
    if(!random(10)){
      new(OPATH "float_belt.c");
      command("wear belt");
    }
    command("wield shortsword");
    command("wield dagger");
    set_funcs( ({"dumber", "song"}) );
    set_func_chance(90);
    set_wimpy(20);
}

void run_away(){
    tell_room(ETO, "%^BOLD%^%^CYAN%^The Sirine looks at her wounds then starts to swim away, and starts to fade out!");
    if(!TO->query_invis()) TO->set_invis();
    ::run_away();
    ::run_away();
}
int dumber(object targ){
    int x;
    if(!"daemon/saving_d.c"->saving_throw(targ, "spell")){
      tell_room(ETO, "%^BOLD%^The Sirine begins to sing an eerie song as she looks at "+targ->query_cap_name(), targ);
      tell_object(targ, "%^BOLD%^%^CYAN%^The Sirine looks at you and begins to sing an eerie song.");
      tell_room(ETO, "%^BOLD%^"+targ->query_cap_name()+" gets a blank look on his face.", targ);
      tell_object(targ, "%^BOLD%^%^CYAN%^You suddenly have a hard thing thinking about anything but the beautiful woman in front of you.");
      x = targ->query_stats("intelligence");
      x = x - 2;
      targ->add_stat_bonus("intelligence", -(x));
    } else {
      tell_room(ETO, "%^BOLD%^%^CYAN%^The Sirine sings an eerie song.");
    }
    return 1;
}

int song(object targ){
    if(!"daemon/saving_d.c"->saving_throw(targ, "spell", -3)){
      tell_room(ETO, "%^BOLD%^%^GREEN%^The Sirine looks at "+targ->query_cap_name()+" and sings a strange and beautiful song to "+targ->query_objective()+".",targ);
      tell_object(targ, "%^BOLD%^%^GREEN%^The Sirine sings a strange song to you, and you are overwhelmed by her and her beauty.");
     if(sizeof(query_attackers()) > 1) {
      TO->remove_attacker(targ);
      targ->set_attackers(TO->query_attackers());
      targ->force_me("protect sirine");
     } else {
      tell_object(targ, "%^BOLD%^%^CYAN%^Your heart is crushed that you would attack such a beautiful creature!");
      targ->do_damage("torso", roll_dice(4,10));
     }
    } else {
      tell_room(ETO, "%^BOLD%^%^GREEN%^The Sirine starts to sing an eerie song while looking at "+targ->query_cap_name()+", but "+targ->query_subjective()+" shakes her melody out of "+targ->query_possessive()+" head.", targ);
      tell_object(targ, "%^BOLD%^%^GREEN%^The Sirine looks at you and sings a strange song, but you are able to ignore it.");
    }
    return 1;
}
