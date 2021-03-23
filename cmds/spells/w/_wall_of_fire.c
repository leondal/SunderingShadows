//      Wall of fire
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, hpcount;
string tempstr, element;
object endplace, outside, wall, wall2;

string *dir_listing(string tempfil);

void create() {
    ::create();
    set_spell_name("wall of fire");
    set_spell_level(([ "mage" : 4, "monk" : 13, "oracle" : 4, "magus" : 4, "druid" : 5, "cleric" : 5 ]));
    set_mystery(({"battle","flame"}));
    set_domains("fire");
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS wall of fire [on <exit>]");
    set_description("The spell, wall of fire, is an impressive spell for the magi indeed.  The wizard can cast the wall "
"around himself, protectively, or in front of an exit, so all who pass through that exit will be scorched by the flames.  "
"To cast the wall around him/herself, the mage simply types <cast classname wall of fire>.  Otherwise, the mage might "
"type <cast classname wall of fire on north> to damage those passing through the exit.  Be warned however, the mage who "
"casts this spell must keep concentration on the wall to maintain its existence.  The mage may type <remove wall> to "
"quench the flames. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([
      "mage" : ([ "phosphorus":1, ]),
    ]));
    set_helpful_spell(1);
    traveling_spell(1); // For damage calculations only
}

string query_cast_string() {
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" stretches "+caster->QP+" arms outward, hands spread open, chanting mightily.";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs, arg;
    object *exits, *inexits, *burned;
    int i, j;
    ::spell_effect();

    hpcount=caster->query_hp();
    if(arg && arg != "" && arg != " ") { arg=lower_case(arg); }

    element = (string)caster->query("elementalist");
    // force-type to fire if anything outside the normal five-element subset. Since the non-interactive doesn't have a switch to fix this, it's necessary.
    if(element != "acid" && element != "cold" && element != "electricity" && element != "sonic") element = "fire";

    if (member_array(arg,place->query_exits()) < 0) {
        switch(element) {
          case "acid":
            tell_object(caster,"%^GREEN%^A cloud of hissing vapor rises up around you.");
            tell_room(place,"%^GREEN%^A cloud of hissing vapor rises up around "+caster->QCN+"!", caster);
            wall=new("/d/magic/obj/vaporcloud.c");
          break;
          case "cold":
            tell_object(caster,"%^CYAN%^An aura of chilling air rises up around you.");
            tell_room(place,"%^CYAN%^An aura of chilling air rises up around "+caster->QCN+"!", caster);
            wall=new("/d/magic/obj/frostcloud.c");
          break;
          case "electricity":
        tell_object(caster,"%^ORANGE%^The air around you seems to come to life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle around you!%^RESET%^");
        tell_room(place,"%^ORANGE%^The air around you seems to come to life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle around "
+caster->QCN+"!%^RESET%^", caster);
            wall=new("/d/magic/obj/staticfield.c");
          break;
          case "sonic":
            tell_object(caster,"%^MAGENTA%^The air around you takes on a dull hum.");
            tell_room(place,"%^MAGENTA%^The air around "+caster->QCN+" takes on a dull hum!", caster);
            wall=new("/d/magic/obj/sonicshield.c");
          break;
          default:
            tell_object(caster,"%^MAGENTA%^%^BOLD%^A massive ring of violet fire rises up around you.");
            tell_room(place,"%^MAGENTA%^%^BOLD%^A massive ring of violet fire rises up around "+caster->QCN+"!", caster);
            wall=new("/d/magic/obj/firewall.c");
          break;
        }
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster,TO);
        return;
    }
    switch(element) {
      case "acid": wall=new("/d/magic/obj/vaporcloud.c"); break;
      case "cold": wall=new("/d/magic/obj/frostcloud.c"); break;
      case "electricity": wall=new("/d/magic/obj/staticfield.c"); break;
      case "sonic": wall=new("/d/magic/obj/sonicshield.c"); break;
      default: wall=new("/d/magic/obj/firewall.c"); break;
    }
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg);
    if (objectp(wall)) wall->move(place);
    else return;

    switch(element) {
      case "acid":
        tell_room(place,"%^GREEN%^A cloud of hissing vapor rises up, blocking the "+arg+"!");
      break;
      case "cold":
        tell_room(place,"%^CYAN%^A cloud of chilling air rises up, blocking the "+arg+"!");
      break;
      case "electricity":
        tell_room(place,"%^ORANGE%^The air around you seems to come to life, and arcs of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^ORANGE%^crackle before the "+ arg+".%^RESET%^");
      break;
      case "sonic":
        tell_room(place,"%^MAGENTA%^The air near the "+arg+" takes on a dull hum!");
      break;
      default:
        tell_room(place,"%^BOLD%^%^MAGENTA%^A wall of blazing violet flames rises up, blocking the "+arg+"!");
      break;
    }
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
      if(base_name(place) == (string)outside->query_exit(ins[i]) || base_name(place)+".c" == (string)outside->query_exit(ins[i]) || base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            switch(element) {
              case "acid": wall2=new("/d/magic/obj/vaporcloud.c"); break;
              case "cold": wall2=new("/d/magic/obj/frostcloud.c"); break;
              case "electricity": wall2=new("/d/magic/obj/staticfield.c"); break;
              case "sonic": wall2=new("/d/magic/obj/sonicshield.c"); break;
              default: wall2=new("/d/magic/obj/firewall.c"); break;
            }
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i]);
            wall2->move(outside);
            switch(element) {
              case "acid":
                tell_room(outside,"%^GREEN%^A cloud of hissing vapor rises up, blocking the "+ins[i]+"!\n%^BOLD%^%^GREEN%^Acid spits out of the cloud towards you!");
              break;
              case "cold":
                tell_room(outside,"%^CYAN%^A cloud of chilling air rises up, blocking the "+ins[i]+"!\n%^BOLD%^%^CYAN%^Shards of frost spit out of the cloud towards you!");
              break;
              case "electricity":
                tell_room(outside,"%^ORANGE%^A crackling field of %^YELLOW%^el%^WHITE%^e%^YELLOW%^ctri%^WHITE%^c%^YELLOW%^ity %^RESET%^%^ORANGE%^appears in the air before the "+ins[i]+".%^RESET%^\n%^YELLOW%^Arcs of static leap out of the field towards you!");
              break;
              case "sonic":
                tell_room(outside,"%^MAGENTA%^The air near the "+ins[i]+" takes on a dull hum!\n%^BOLD%^%^MAGENTA%^Pulses of sound echo towards you!");
              break;
              default:
                tell_room(outside,"%^BOLD%^%^MAGENTA%^A wall of blazing violet flames rises up, blocking the "+ins[i]+"!\n%^BOLD%^%^RED%^Flames spit out of the wall of flame towards you!");
              break;
            }
            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    switch(element) {
                      case "acid":
                        tell_room(outside,"%^BOLD%^%^GREEN%^"+burned[j]->QCN+" recoils from the hissing vapor!%^RESET%^",burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^GREEN%^The vapor burns your skin!%^RESET%^");
                      break;
                      case "cold":
                        tell_room(outside,"%^BOLD%^%^CYAN%^"+burned[j]->QCN+" recoils from the freezing air!%^RESET%^",burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^CYAN%^The freezing air chills you!%^RESET%^");
                      break;
                      case "electricity":
                        tell_room(outside,"%^YELLOW%^"+burned[j]->QCN+" recoils from the crackling air!%^RESET%^",burned[j]);
                        tell_object(burned[j],"%^YELLOW%^The charged air crackles across your skin!%^RESET%^");
                      break;
                      case "sonic":
                        tell_room(outside,"%^BOLD%^%^MAGENTA%^"+burned[j]->QCN+" recoils from the humming air!%^RESET%^",burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^MAGENTA%^The humming air reverberates through you!%^RESET%^");
                      break;
                      default:
                        tell_room(outside,"%^BOLD%^%^RED%^"+burned[j]->QCN+" is struck by the searing-hot flame!",burned[j]);
                        tell_object(burned[j],"%^RED%^The flames from the wall strike you forcefully, and your skin is coated with a sheet of flame!");
                      break;
                    }
                    limbs = burned[j]->query_limbs();
                    if(burned[j]->query_property("undead")) damage_targ(burned[j],limbs[random(sizeof(limbs))],(4+random(13)),element);
                    else damage_targ(burned[j],limbs[random(sizeof(limbs))],(2+random(7)),element);
                }
            }
            break;
      }
    }
    call_out("concentration",4);
    return;
}

void concentration() {
    int flag = 0;
    if ( caster->query_paralyzed() ||
         !objectp(wall) ||
         !objectp(wall2))
        flag = 1;
    if ((int)caster->query_hp() != hpcount) {
        if ((int)caster->query_hp() < hpcount - 30 ) {
            tell_room(environment(caster),"%^ORANGE%^"+caster->QCN+" looks as though "+caster->QS+" just lost "+caster->QP+" concentration!",caster);
            tell_object(caster,"%^YELLOW%^You lose your concentration on maintaining the wall of "+element+" you invoked!");
            flag = 1;
        } else
            hpcount = caster->query_hp();
    }
    if (flag)
        call_out("dest_effect",clevel*3);
    else
        call_out("concentration",4);
    return;
}

void dest_effect() {
    if (objectp(wall))
        wall->remove_wall();
    if (objectp(wall2))
        wall2->remove_wall();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

    return;
}
