#include <std.h>

inherit MONSTER;

object owner, victim, eye_owner;
int duration;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();

int power;

void destroy_eye()
{
    if(!objectp(eye_owner))
    {
        TO->remove();
        return;
    }
    if(!random(20))
    {
        eye_owner->adjust_max_eyes(-1);
    }
    eye_owner->eye_failure(TO);
    TO->remove();
    return;
}

int set_duration(int x) { duration = x; }

void create()
{
    ::create();

    set_name("bloated eye");
    set_id(({"eye", "bloated eye", "listening eye"}));

    set_long("%^BOLD%^%^RED%^This tiny bloated eye stares constantly, unblinking. "+
    "It is floating in the air with a portion of what looks like a %^RESET%^%^ORANGE%^"+
    "tentacle%^BOLD%^%^RED%^ attached to it. It looks almost humanoid but something is quite "+
    "off about it.%^RESET%^");

    set_short("%^BOLD%^%^RED%^bloated %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^RESET%^");
    set_invis();

    set_skill("spellcraft", 70); // To bypass passive perception

    set_hd(1,2);
    set_hp(10);
    set_max_hp(10);
    set_new_exp(1, "very low");
    set_race("eye");
    set_body_type("eye");

    add_limb("body","",0,0,0);
}

int move(mixed dest)
{
    ::move(dest);
}

set_eye_owner(object ob)
{
    eye_owner = ob;
}

set_owner(object ob)
{
    owner = ob;
}

void query_mycaster()
{
    return owner;
}

set_victim(object ob)
{
    victim = ob;
}

void die(object ob)
{
    destroy_eye();
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(eye_owner) || !objectp(victim)
    || !objectp(owner))
    {
        destroy_eye();
        return;
    }
    if(ETO != environment(victim))
    {
        move(environment(victim));
    }
    if(ETO->query_property("no scry"))
    {
        destroy_eye();
        return;
    }
    if(victim->query_true_invis())
    {
        destroy_eye();
        return;
    }
    if(present("blockerx111", victim))
    {
        destroy_eye();
        return;
    }
    duration--;
    if(duration <= 0)
    {
        destroy_eye();
        return;
    }
}

dest_me()
{
//   tell_room(ETO,"%^BLACK%^%^BOLD%^A shadow off to one side shimmers and disappears.",TO);
//Removing this since the spells are now detectable through normal
//scrying detections ~Circe~ 5/27/08
    destroy_eye();
}

catch_tell(string str)
{
    if(!objectp(owner))
    {
        destroy_eye();
        return;
    }
    tell_object(owner, "%^RESET%^%^ORANGE%^An %^BOLD%^%^GREEN%^e%^YELLOW%^y%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^ telepathically "+
    "relays: %^RESET%^ "+str);

}

object query_caster() { return owner; }

int is_scry_object(){ return 1; }

void set_invis()
{
    if (TO->query_invis()) return;
    else ::set_invis();
    return;
}

void set_scry_power(int x)
{
    power = x;
}

void query_scry_power()
{
    return power;
}
