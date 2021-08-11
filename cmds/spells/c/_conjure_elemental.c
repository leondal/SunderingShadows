// elemental conjuration spells merged for ease of use. Nienne, 11/09
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

object elem;

void create() {
    ::create();
    set_spell_name("conjure elemental");
    set_spell_level(([ "mage" : 5, "innate" : 1, "cleric" : 5, "oracle" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_mystery( ({ "flame", "waves" }) );
    set_syntax("cast CLASS conjure elemental on water|fire|earth|air");
    set_description("This spell will summon an elemental for you to command. Such creatures are native to different planes, and existence in this plane is extremely painful for them. They resent being summoned here and hate the mage who summoned them. There is a chance that the caster will lose control over the creature and the creature will attack him/her immediately and viciously.
To command elemental, use %^ORANGE%^<command elemental to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^.
To command lost elemental to follow you once again, use %^ORANGE%^<command elemental to follow>%^RESET%^.
To dismiss elemental use %^ORANGE%^<dismiss elemental>%^RESET%^.");
    set_silent_casting(0);
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_casting_time(2);
    set_components(([
      "mage" : ([ "soft clay" : 2, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string() {
    switch (arg) {
      case "water":
      return "%^BOLD%^%^CYAN%^"+caster->QCN+" drops a bit of sand on the ground and "
      +"pours a small amount of water on top. As "+caster->QS+" chants over the "
      +"mixture it starts to sizzle.";
      break;

      case "fire":
      return "%^BOLD%^%^YELLOW%^"+caster->QCN+" crushes a bit of phosphorus and "
      +"sulfur together in a small bowl. "+capitalize(caster->QS)+" then, with a single "
      +"gesture, causes a small flame to appear near the mixture. With a loud scream the "
      +"mage throws both fire and bowl crashing to the ground with an enormous explosion.";
      break;

      case "earth":
      return "%^BOLD%^%^RED%^"+caster->QCN+" starts to model a bit of clay. "
      +"A slightly humanoid form made of the clay begins to form. "+capitalize(caster->QS)+
      " raises the figure high in the air and screams out the arcane language of mages "
      +"then crushes the figure in "+caster->QP+" hand.";
      break;

      case "air":
      return "%^BOLD%^%^BLUE%^"+caster->QCN+" lights a small bit of incense and raises "
      +"it high in the air then plants it firmly at the edge of the small circle "
      +caster->QS+" is standing in. %^BOLD%^%^CYAN%^Blank faced, "+caster->QCN+" looks "
      +"up at the smoke and cries uninterpretable utterances!";
      break;
    }
}

int preSpell() {
    if(caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster,"You already have a powerful summoned creature under your control.");
        return 0;
    }
    if(arg != "water" && arg != "fire" && arg != "earth" && arg != "air") {
        tell_object(caster,"You can only summon an elemental of water, fire, earth or air!");
        return 0;
    }
    if(spell_type == "innate" && FEATS_D->usable_feat(caster,"command the stone") && arg != "earth") {
        tell_object(caster,"You can only summon an elemental of earth!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    string him;
    mapping tmp;
    caster = CASTER;
    place = PLACE;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->QCN;

    tell_room(place,"%^BOLD%^%^BLUE%^"+him+" raises "+caster->QP+" hands in what looks like sheer agony."
              +" Mists swirl rapidly above "+caster->QP+" head. "
              +" You almost see a small hole in the fabric of the world in the middle.", caster);
    tell_object(caster,"%^BOLD%^%^BLUE%^You hands are lifted above you by a tremendous force."
                +" Dark mists swirl above your head. You see a small opening in the middle of those mists.");
    caster->set_property("has_elemental",1);
    call_out("next_step",ROUND_LENGTH, prof);
}

void next_step(int prof) {
    string him;
    object ob,device;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    him = caster->QCN;

    switch (arg) {
    case "water":
      tell_room(place,"%^BOLD%^%^CYAN%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
      tell_object(caster,"%^BOLD%^%^CYAN%^You struggle with the being on the other end."
                +" Gradually you pull it closer to you. then suddenly......");
      tell_room(place,"%^BOLD%^%^CYAN%^Before you stands a water elemental!");

      ob = new("/d/magic/mon/mage_welemental");
    break;

    case "fire":
      tell_room(place,"%^BOLD%^%^YELLOW%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
      tell_object(caster,"%^BOLD%^%^YELLOW%^You struggle with the being on the other end."
                +" Gradually you pull it closer to you. then suddenly......");
      tell_room(place,"%^BOLD%^%^YELLOW%^Before you stands a fire elemental!");

      ob = new("/d/magic/mon/mage_felemental");
    break;

    case "earth":
      tell_room(place,"%^BOLD%^%^RED%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
      tell_object(caster,"%^BOLD%^%^RED%^You struggle with the being on the other end."
                +" Gradually you pull it closer to you. then suddenly......");
      tell_room(place,"%^BOLD%^%^RED%^Before you stands an earth elemental!");

      ob = new("/d/magic/mon/mage_eelemental");
    break;

    case "air":
      tell_room(place,"%^BOLD%^%^CYAN%^The struggle seems to last an eternity, "
              +"but it ends with "+him+" over powering the prey and .....",caster);
      tell_object(caster,"%^BOLD%^%^CYAN%^You struggle with the being on the other end."
                +" Gradually you pull it closer to you. then suddenly......");
      tell_room(place,"%^BOLD%^%^CYAN%^Before you stands an air elemental!");

      ob = new("/d/magic/mon/mage_aelemental");
    break;
    }

    ob->setup_elemental(caster);
    ob->set_property("spelled", ({TO}));
    elem = ob;
    device = new("/d/magic/obj/holder");
    device->set_property("spell", TO);

    if ((object *)caster->query_attackers() != ({})) {
        ob->move(place);
        tell_object(caster,"%^BOLD%^Unable to keep your concentration due to being attacked."
                    +" You lose control over the elemental and the irate being attacks viciously!\n");
        tell_room(place,"%^BOLD%^Unable to keep control over the being, "+him+" is attacked viciously"
                  +" by the irate monster!",caster);
        spell_kill(ob, caster);
        caster->add_follower(ob);
        device->set_elemental(ob);
        device->set_caster(caster);
        device->set_freed(1);
        device->move(caster);
        return;
    }

    device->set_elemental(ob);
    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    ob->set_property("spell_creature", TO);
    ob->set_property("spell", TO);
    ob->set_property("minion", caster);
    if (prof > random(100)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^Unable to resist your power the irate"
                    +" being bows in acquiescence and awaits your command.\n");
        tell_room(place,"%^BOLD%^%^CYAN%^Unable to resist "+him+"'s power, the elemental "
                  +" bows down to "+caster->QO+"!",caster);
        ob->move(place);
    }
    else {
        tell_object(caster,"%^BOLD%^%^CYAN%^The irate being fights your control and wins. The being sees you as the absolute enemy!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+him+" is unable to control the beast, as the elemental breaks into this world it goes berserk and attacks "+him+".",caster);
        ob->add_attacker(caster);
        ob->move(place);
    }
    if (prof > 100) {
        ob->add_attack_bonus(prof/10-10);
        ob->add_damage_bonus(prof/10-10);
        ob->set_hp((int)ob->query_hp() + (prof/10));
    }
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(caster)) { caster->remove_property("has_elemental"); }
    if(!objectp(elem)){
        TO->remove();
        return;
    }
    tell_room(environment(elem), "%^BOLD%^%^CYAN%^The elemental shrieks then is suddenly no more.");
    elem->move("/d/shadowgate/void");
    elem->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
