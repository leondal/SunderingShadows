#include <std.h>
#include "../dagger.h"
inherit WEAPONLESS;

void create() {
    ::create();
    set_id(({"whispy","whispy ghost","ghost"}));
    set_name("ghost");
    set_short("%^RESET%^%^CYAN%^whispy ghost%^RESET%^");
    set_long("%^RESET%^Tendrils of %^CYAN%^mist %^RESET%^are all that make up this translucent creature. Its "
"ghostly form resembles that of a person, trapped forever between life and death. It fades in and out of view, "
"so difficult to make out at times that it slips from your vision, only to be noticed again a moment later out "
"of the corner of your eye. A %^RED%^pained %^RESET%^expression is drawn across its blurred facial features, "
"as it whispers its suffering to the wind.");
    set_race("ghost");
    set_body_type("human");
    if (random(2)) set_gender("male");
    else set_gender("female");
    set_alignment(5);
// keep adding the fey-expanded section here - the ghosts should not want to go near it
    set_nogo(({GATES+"Egate",GATES+"Wgate",GATES+"Sgate",GATES+"Ngate",STREETS+"street14",STREETS+"street15",STREETS+"street16",STREETS+"street21",STREETS+"street22",STREETS+"street27",STREETS+"street28",STREETS+"street29"}));
    set_speed(15);
    set_moving(1);
    set_class("fighter");
    set_hd(10,8);
    set_guild_level("fighter",10);
    set_mlevel("fighter",10);
    set_max_hp(250);
    set_hp(250);
    set_property("swarm",1);
    set_exp(100);
    set_overall_ac(-5);
    set("aggressive",0);
    set_attack_limbs(({"left hand","right hand"}));
    set_attacks_num(1);
    set_base_damage_type("slash");
    set_damage(1,4);
    set_property("undead",1);
    command("message in floats in.");
    command("message out drifts $D.");
    TO->setenv("MINVIS","$N's transparent form fades from view.");
    TO->setenv("MVIS","$N drifts back into view.");
    set_emotes(1, ({"%^CYAN%^The spirit whispers nearly inaudible words to the wind.",
"%^BLUE%^A soft sobbing comes from the ghost.",
"%^GREEN%^The ghost's translucent form nearly disappears from view.",
"%^BOLD%^%^WHITE%^The spirit brushes past you, sending chills down your spine.",
"%^MAGENTA%^The spirit fades from your vision, only to reappear again a few seconds later."}), 0);
}

void heart_beat()
{
    ::heart_beat();

    if(!objectp(TO)) { return; }
    
    if(!sizeof(TO->query_attackers())) 
    {
        if(TO->query_hidden()) TO->set_hidden();
        else 
        {
            if(!random(10)) TO->set_hidden(1);
        }
    }
}

void die(object ob) {
   tell_room(ETO,"The ghost lets out a soft sigh as it shimmers and disappears from view.");
   TO->remove();
}