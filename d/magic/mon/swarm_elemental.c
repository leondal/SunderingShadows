//For the druid spell Elemental Swarm
//Coded by Ares, described/colored by Circe
//3/22/13
#include <std.h>

inherit MONSTER;

object spell;

void create()
{
    // these get replaced in the setup function below
    ::create();
    set_name("a temp name");
    set_short("a temp short");
    set_id(({"elemental"}));
    set_long("an elemental");
    set_race("elemental");
    set_gender("neuter");
    set_body_type("humanoid");
    set_attack_limbs(({"right hand","left hand"}));
    set("magic",1);
    call_out("check",5);
}

void check()
{
    object caster;

    if(!objectp(spell))
    {
        die(TO);
        return;
    }

    if(!objectp(caster = spell->query_caster()))
    {
        die(TO);
        return;
    }

    if(!sizeof(caster->query_attackers()))
    {
        if(objectp(TO)) { die(TO); }
        if(objectp(spell)) { spell->dest_effect(); }
        return;
    }

    call_out("check",5);
}



void setup_elemental(string str,object obj)
{
    if(!objectp(obj)) { return; }

    spell = obj;

    switch(str)
    {
    case "fire":

        set_name("ancient fire elemental");
        set_short("%^RESET%^%^RED%^an anc%^BOLD%^i%^RESET%^%^RED%^ent "
           "%^BOLD%^f%^MAGENTA%^i%^RESET%^r%^BOLD%^%^RED%^e %^RESET%^%^RED%^elemental%^RESET%^");
        set_id(({"elemental","fire elemental","ancient fire elemental" }));
        set_long("%^RESET%^%^RED%^Looming over eight feet tall, this "
           "%^BOLD%^f%^MAGENTA%^i%^RESET%^r%^BOLD%^%^RED%^e elemental "
           "%^RESET%^%^RED%^fills the area with menacing %^BOLD%^fl"
           "%^YELLOW%^a%^RED%^mes%^RESET%^%^RED%^.  Seemingly possessing "
           "no concrete form, the elemental shifts, shrinking and expanding "
           "as it takes a vaguely humanoid form.  Mimicking the appearance "
           "of a normal flame, the base of the fire elemental is %^BLUE%^deep "
           "blue%^RED%^, giving way to %^BOLD%^%^RED%^reds%^RESET%^%^RED%^, "
           "%^ORANGE%^oranges%^RED%^, and %^YELLOW%^yellows %^RESET%^%^RED%^"
           "with flickers of %^BOLD%^%^WHITE%^white %^RESET%^%^RED%^and "
           "%^BOLD%^%^BLACK%^ashy gray%^RESET%^%^RED%^.  Although it has no "
           "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
        break;        

    case "air":

        set_name("ancient air elemental");
        set_short("%^RESET%^%^CYAN%^an ancient a%^BOLD%^%^WHITE%^i%^CYAN%^r %^RESET%^%^CYAN%^elemental%^RESET%^");
        set_id(({"elemental","air elemental","ancient air elemental" }));
        set_long("%^RESET%^%^CYAN%^Like an eight-foot tall %^BOLD%^%^BLACK%^"
           "cyclone%^RESET%^%^CYAN%^, this elemental creates a miniature storm "
           "around it, full of fierce %^BOLD%^winds %^RESET%^%^CYAN%^and a biting "
           "chill.  A gaping %^BOLD%^%^BLACK%^black maw %^RESET%^%^CYAN%^appears "
           "and vanishes where the creature's head should be, and thunderous, "
           "thick columns of air make up its arms.  At times, portions of the "
           "elemental seem to dissipate into the wind, only to reform into a "
           "translucent shape of %^BOLD%^%^BLACK%^gray%^RESET%^%^CYAN%^, "
           "%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^, and %^BOLD%^sky blue%^RESET%^%^CYAN%^.  Although it has no "
           "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
        break;

    case "earth":

        set_name("ancient earth elemental");
        set_short("%^RESET%^%^ORANGE%^an ancient %^YELLOW%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^t%^YELLOW%^h%^RESET%^%^ORANGE%^ elemental%^RESET%^");
        set_id(({"elemental","earth elemental","ancient earth elemental" }));
        set_long("%^RESET%^%^ORANGE%^This hulking eight-foot tall elemental "
           "looks like a small moving mountain covered in plates of %^BOLD%^%^BLACK%^"
           "sha%^WHITE%^l%^BLACK%^e%^RESET%^%^ORANGE%^ and %^RESET%^q%^CYAN%^u%^BOLD%^"
           "%^WHITE%^a%^RESET%^r%^YELLOW%^t%^BOLD%^%^BLACK%^z %^RESET%^s%^ORANGE%^p"
           "%^BOLD%^%^WHITE%^i%^RESET%^k%^RED%^e%^RESET%^s%^ORANGE%^.  Every movement "
           "of the vaguely humanoid shape is punctuated with the sound of rocks grinding, "
           "and its powerful arms look as though they could crush any foe despite the "
           "elemental's relatively small size.  Although it has no "
           "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
        break;

    case "water":

        set_name("ancient water elemental");
        set_short("%^BOLD%^%^BLUE%^an ancient w%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^t%^RESET%^e%^BOLD%^%^BLUE%^r elemental%^RESET%^");
        set_id(({"elemental","water elemental","ancient water elemental" }));
        set_long("%^BOLD%^%^BLUE%^Like a tidal wave just before it crashes, this "
           "water elemental %^WHITE%^crests %^BLUE%^at just over eight feet tall.  "
           "Its body is a churning mass of water, full of the %^RESET%^%^BLUE%^"
           "deep blues %^BOLD%^and %^RESET%^%^CYAN%^vibrant greens %^BOLD%^%^BLUE%^"
           "of the sea.  The humanoid body splits and combines, forming arms here "
           "and there that lash out, ready to smite its targets with the relentless "
           "power of %^RESET%^%^CYAN%^water%^BOLD%^%^BLUE%^.  Although it has no "
           "visible eyes, this creature seems to have no trouble seeking out its enemies.%^RESET%^");
        break;
    }
}

void die(object ob)
{
   tell_room(ETO,"%^BOLD%^The ancient elemental howls in the throes of death and disappears back into its home plane!%^RESET%^");
   
   if(objectp(spell))
   {
       spell->swarm("new elemental");
   }
   
   remove();
   return;
}

