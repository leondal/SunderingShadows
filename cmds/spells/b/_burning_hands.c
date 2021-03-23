//      Burning Hands
//      Thorn@Shadowgate
//      10/16/94
//      Totally modified and updated by Vashkar
//      11/1/95

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void dest_effect();
void damage(object mytarg, int bonus);
string element;

void create() {
    ::create();
    set_spell_name("burning hands");
    set_spell_level(([ "mage" : 1, "monk" : 3, "oracle" : 1, "magus" : 1 ]));
    set_mystery("flame");
    set_spell_sphere("alteration");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS burning hands on TARGET");
    set_description("This spell begins by the caster fanning out his hands while chanting the spell.  Flames will flare "
"out and do a small amount of damage to the target and those near him. A versatile arcanist can manipulate the base element "
"of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
   return caster->QCN+" fans out "+caster->QP+" hands and begins to chant.";
}

void spell_effect(int prof) {
    int counter;
    int bonus = prof/10 - 10;
    int x;
    object * allies;
    object * targets;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }
    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }
    targets = target_selector();

    targets -= ({target});
    //lets remove caster because that would mean the fire bonces straight back (assume the player is smart enough to move
    targets -= ({caster});

    if (target->query_party())
        allies = PARTY_D->query_party_members(target->query_party());
    else {
        allies = ({caster});
    }

    if (sizeof(caster->query_classes()) == 1) {
        targets -= allies;
        if (caster->query_followers())
            targets -= caster->query_followers();
    }
    element = (string)caster->query("elementalist");
    switch(element) {
      case "acid":
        tell_object(target,"%^GREEN%^"+caster->QCN+" aims a %^BOLD%^spray %^RESET%^%^GREEN%^of %^YELLOW%^corrosive %^GREEN%^acid %^RESET%^%^GREEN%^at you!");
        tell_object(caster,"%^GREEN%^You aim a %^BOLD%^spray %^RESET%^%^GREEN%^of %^YELLOW%^corrosive %^GREEN%^acid %^RESET%^%^GREEN%^at "+target->QCN+"!");
        tell_room(place, "%^GREEN%^"+caster->QCN+" aims a %^BOLD%^spray %^RESET%^%^GREEN%^of %^YELLOW%^corrosive %^GREEN%^acid %^RESET%^%^GREEN%^at "+target->QCN+"!",({ caster, target}) );
      break;
      case "cold":
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" sends a burst of frigid %^RESET%^%^CYAN%^air %^BOLD%^%^CYAN%^filled with shards of %^WHITE%^ice %^CYAN%^at you!");
        tell_object(caster,"%^BOLD%^%^CYAN%^You send a burst of frigid %^RESET%^%^CYAN%^air %^BOLD%^%^CYAN%^filled with shards of %^WHITE%^ice %^CYAN%^at "+target->QCN+"!");
        tell_room(place, "%^BOLD%^%^CYAN%^"+caster->QCN+" sends a burst of frigid %^RESET%^%^CYAN%^air %^BOLD%^%^CYAN%^filled with shards of %^WHITE%^ice %^CYAN%^at "+target->QCN+"!",({ caster, target}) );
      break;
      case "electricity":
        tell_object(target,"%^ORANGE%^Threads of %^BOLD%^lightning %^WHITE%^erupt %^RESET%^%^ORANGE%^from "+caster->QCN+"'s fingertips towards you!");
        tell_object(caster,"%^ORANGE%^Threads of %^BOLD%^lightning %^WHITE%^erupt %^RESET%^%^ORANGE%^from your fingertips towards "+target->QCN+"!");
        tell_room(place, "%^ORANGE%^Threads of %^BOLD%^lightning %^WHITE%^erupt %^RESET%^%^ORANGE%^from "+caster->QCN+"'s fingertips towards "+target->QCN+"!",({ caster, target}) );
      break;
      case "sonic":
        tell_object(target,"%^MAGENTA%^A %^RESET%^hazy %^MAGENTA%^burst of %^BOLD%^%^WHITE%^resonant energy %^RESET%^%^MAGENTA%^surges from "+caster->QCN+"'s hands towards you!");
        tell_object(caster,"%^MAGENTA%^A %^RESET%^hazy %^MAGENTA%^burst of %^BOLD%^%^WHITE%^resonant energy %^RESET%^%^MAGENTA%^surges from your hands towards "+target->QCN+"!");
        tell_room(place, "%^MAGENTA%^A %^RESET%^hazy %^MAGENTA%^burst of %^BOLD%^%^WHITE%^resonant energy %^RESET%^%^MAGENTA%^surges from "+caster->QCN+"'s hands towards "+target->QCN+"!",({ caster, target}) );
      break;
      default:
        element = "fire";
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" sends a sheet of flame straight at you!");
        tell_object(caster,"%^BOLD%^%^RED%^You send a sheet of flame straight at "+target->QCN+"!");
        tell_room(place, "%^BOLD%^%^RED%^"+caster->QCN+" sends a sheet of flame at "+target->QCN+"!",({ caster, target}) );
      break;
    }
    damage(target, bonus);
    counter += (int)target->query_size();
    for (x=0;x < sizeof(targets) && counter < 4;x++)
    {
        if(!objectp(targets[x])) { continue; }
        if (!random(3))
        {
            damage(targets[x], bonus-random(5));//5 for the 5 feet spread
            counter+=(int)targets[x]->query_size();
        }
    }
    dest_effect();
}

void damage(object mytarg, int bonus) {
    string before, after, *immunities;
    int i;

    if(do_save(mytarg,0)) {
      switch(element) {
        case "acid":
          tell_room(place,"%^GREEN%^"+mytarg->QCN+" jumps out of the way just as the acid is about to hit!", mytarg);
          tell_object(mytarg,"%^GREEN%^You are only splashed by a few drops of the acid.");
        break;
        case "cold":
          tell_room(place,"%^CYAN%^"+mytarg->QCN+" jumps out of the way just as the freezing air is about to hit!", mytarg);
          tell_object(mytarg,"%^CYAN%^You are only slightly chilled by the ice.");
        break;
        case "electricity":
          tell_room(place,"%^ORANGE%^"+mytarg->QCN+" jumps out of the way just as the lightning is about to hit!", mytarg);
          tell_object(mytarg,"%^ORANGE%^You are only slightly jolted by the lightning.");
        break;
        case "sonic":
          tell_room(place,"%^MAGENTA%^"+mytarg->QCN+" jumps out of the way just as the sonic waves are about to hit!", mytarg);
          tell_object(mytarg,"%^MAGENTA%^You are only slightly shaken by the waves of sonic.");
        break;
        default:
          tell_room(place,"%^RED%^"+mytarg->QCN+" jumps out of the way just as the flames are about to hit!", mytarg);
          tell_object(mytarg,"%^RED%^You are only slightly singed by the flames.");
        break;
      }
      damage_targ(mytarg, "torso", to_int(sdamage / 2),element);
    }
    else {
      switch(element) {
        case "acid":
          tell_room(place,"%^BOLD%^%^GREEN%^"+mytarg->QCN+" is burned by the spray of acid!", mytarg);
          tell_object(mytarg,"%^BOLD%^%^GREEN%^The acid burns you badly!");
        break;
        case "cold":
          tell_room(place,"%^BOLD%^%^CYAN%^"+mytarg->QCN+" is sliced by the shards of ice!", mytarg);
          tell_object(mytarg,"%^BOLD%^%^CYAN%^The shards of ice slice your skin!");
        break;
        case "electricity":
          tell_room(place,"%^BOLD%^%^ORANGE%^"+mytarg->QCN+" is shocked by the threads of lightning!", mytarg);
          tell_object(mytarg,"%^BOLD%^%^ORANGE%^The lightning shocks you badly!");
        break;
        case "sonic":
          tell_room(place,"%^BOLD%^%^MAGENTA%^"+mytarg->QCN+" is badly shaken by the wave of sonic energy!", mytarg);
          tell_object(mytarg,"%^BOLD%^%^MAGENTA%^The sonic waves shake you!");
        break;
        default:
          tell_room(place,"%^BOLD%^%^RED%^"+mytarg->QCN+" is scorched by the sheet of flame!", mytarg);
          tell_object(mytarg,"%^BOLD%^%^RED%^The flames scorch you badly!");
        break;
      }
      damage_targ(mytarg, "torso", sdamage,element);
    }
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
