//pryingeyes.c - for Prying Eyes spell by >> N <<
//Silverwatcher, shadowlistener, and innereye are
//essentially the same file.  If you make a change to
//one, please check to see if the others need it as well.

#include <std.h>
inherit MONSTER;

object caster, follower;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();

int power;

void create(){
    ::create();
    set_name("prying eye");
    set_id(({"eye", "prying eye", "floating eye"}));
    set_long("%^BOLD%^%^WHITE%^It is small and perfectly round %^BOLD%^floati%^BLUE%^ng e%^CYAN%^ye%^RESET%^.");
    set_short("%^RESET%^%^BOLD%^floating eye");

    set_hidden(1);

    set_property("untrackable",1);
    set_hd(1,2);
    set_hp(10000000000);
    set_max_hp(10000000000);
    set_new_exp(1, "very low");
    set_race("eye");
    set_body_type("eye");

    add_limb("body","",0,0,0);
}

set_eye_color(string eyecolor)
{
    set_short("%^RESET%^%^CYAN%^floating%^WHITE%^ "+eyecolor+" %^BLUE%^eye%^RESET%^");
}

int move(mixed dest){
    ::move(dest);
}

void init()
{
    ::init();
    add_action("kill_me","kill");
}

int kill_me(string str)
{
    if(present(str,ETO)!=TO)
        return 0;

    tell_room(ETO,"The eyes blink and disappear!");
    self_destruct();
    return 1;
}

set_caster(object cas){
    caster = cas;
}

void query_mycaster(){
    return caster;
}

set_target(object ob){
    follower = ob;
}

int die()
{
    self_destruct();
    return 1;
}

void heart_beat(){
    if(!objectp(caster))
        self_destruct();
    if(!objectp(follower))
        self_destruct();
    if(ETO != environment(follower))
        move(environment(follower));
    if(ETO->query_property("no scry")) self_destruct();
    if(present("blockerx111", ETO)) self_destruct();
}

dest_me(){
    remove();
}

catch_tell(string str){
    if(!objectp(caster)){
        dest_me();
        return;
    }
    tell_object(caster,"%^BOLD%^%^WHITE%^You see from afar:%^RESET%^   "+str);
}

/* int do_damage(string str, int i){ */
/*     return 0; */
/* } */

int is_invincible(){ return 1;}

object query_caster() { return caster; }

void set_scry_power(int x){
    power = x;
}

void query_scry_power(){
    return power;
}

void self_destruct() {
    int i;
    object casterobj,*spells = ({}), spell;
    casterobj = caster;

    if(objectp(casterobj))
    {
        spells=casterobj->query_property("dispellable spells");
        foreach(spell in spells)
        {
            if(!objectp(spell))
                continue;

            if(spell->query_spell_name() == "prying eyes")
            {
                if(!objectp(spell))
                {
                    tell_object(casterobj,"Your concentration seems to have been lost!", TP);
                }
                tell_object(casterobj,"Something seems to be blocking your concentration!", TP);
                spell->dest_effect();
                break;
            }
        }
    }
    if(objectp(TO))
        TO->remove();
}

int is_priest_scry(){ return 1; }
int is_scry_object(){ return 1; }
