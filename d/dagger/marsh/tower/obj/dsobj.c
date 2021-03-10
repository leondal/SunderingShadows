// added objectp checks to all callout functions-last change was 4/02  *Styx* 8/2003

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_long("This is a great storm of destruction!");
    set_short("%^RESET%^%^RED%^DEMONSTORM");
    set_name("demonstormobj");
    set_id( ({"demonstormobj", "dsobj", "demonstorm", "storm"}) );
    set_weight(1000000);
    set_property("no offer", 1);
    set_property("no animate", 1);
}

void start_obj(){
    call_out("flash_fun", 3);
    call_out("fire_fun", 5);
    call_out("fire_fun", 15);
    call_out("fire_fun", 30);
    call_out("endflame_fun", 31);
}

int fire_fun(){
    object ob,here,sucker,*players;
    int x,num_p;

    here=environment(TO);
    players=all_living(here);
    num_p=sizeof(players);
    if(!objectp(TO) || !objectp(ETO))   return 1;
    for(x=0;x<num_p;x++){
        sucker=players[x];
        if(sucker->query_true_invis()) continue;
        if((living(sucker)) && sucker != TO && (string)sucker->query_name() != "krykoth") {
            tell_object(sucker, "%^BOLD%^CYAN%^The chaotic confusion of the minor minions swirling within the storm enter and exit your soul repeatedly!%^RESET%^");
            tell_room(environment(sucker), "%^BOLD%^%^CYAN%^"+sucker->query_cap_name()+" screams out as minions of the Demonstorm enter and exit "+sucker->query_possessive()+" soul repeatedly!%^RESET%^", sucker);
            "/std/effect/status/sickened"->apply_effect(sucker,roll_dice(1,6));
            sucker->do_damage("torso",roll_dice(6,6));
            sucker->add_attacker(TO);
            sucker->continue_attack();
            if(!objectp(sucker)) continue;
            sucker->remove_attacker(TO);
        }
    }
    return 1;
}

int flash_fun() {
  if(!objectp(TO) || !objectp(ETO))   return 1;
    tell_room(ETO, "%^BOLD%^%^RED%^The area is suddenly engulfed with the Demonstorming!%^RESET%^");
    return 1;
}

int endflame_fun() {
  if(!objectp(TO) || !objectp(ETO))   return 1;
    tell_room(ETO, "%^BOLD%^%^CYAN%^The %^RED%^Demonstorm%^CYAN%^ vanishes in a swirling cloud back to the Abyss!%^RESET%^");
    TO->remove();
    return 1;
}
