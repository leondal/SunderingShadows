#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

object glyph;

void create() {
    ::create();
    set_spell_name("snare");
    set_spell_level(([ "ranger" : 2,"druid" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS snare");
    set_description("In casting this spell, the ranger sets a snare in the location, which will harm the first bypasser "
"to trigger it. Anyone already present when the spell is cast will be aware of the snare, and may come and go without "
"disturbing it. Additionally, thieves have a chance to actively search for the snare and can remove it, but they must do "
"so in the room before the trapped location or they will trigger it.\n\nThe caster's attunement to the wilds will alert "
"them when their snare is tripped.  They may only rig one snare at a time, but do not need to remain with it for it to "
"function.  Snares can only be set in natural surroundings.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    string terrain;
    if(caster->query_property("glyphed")){
      tell_object(caster,"You have already set a snare or glyph!");
      return 0;
    }
    terrain = place->query_terrain();
    if (!terrain || terrain == "" || isCivilization(terrain)) {
      tell_object(caster,"%^BOLD%^%^GREEN%^You can't set a snare in a town!%^RESET%^");
      dest_effect();
      return 0;
    }
    return 1;
}

string query_cast_string() {
   return "%^RESET%^%^GREEN%^"+caster->QCN+" props some sharp spikes into the earth and begins carefully concealing them "
"with the natural surroundings.%^RESET%^";
}

void spell_effect(int prof) {
   int int_bonus,i,duration;
   object temp, *inv, room, mini_me;
   string *exits;

   ::spell_effect();

   if(present("glyphx111")) {
      tell_object(caster,"%^BOLD%^%^GREEN%^The present energies of a hidden trap "+
         "repel the magic of the one you are trying to cast!%^RESET%^");
      TO->remove();
      return;
   }
   tell_object(caster,"%^RESET%^%^ORANGE%^Setting some tiny spikes "+
      "into the earth, you go about concealing them carefully with "+
      "natural surroundings, weaving natural energies into the "+
      "camouflage as you do.%^RESET%^");
   tell_room(place,"%^BOLD%^%^GREEN%^A momentary pulse of natural "+
      "energy ripples across the now-concealed trap and then "+
      "vanishes.%^RESET%^");
   caster->set_paralyzed(5,"You are concentrating on the snare!");
   glyph = new("/d/magic/obj/snare.c");
   inv = ({});
   inv = all_living(environment(caster));
   glyph->set_mygroup(inv);
   for(i=0;i<sizeof(inv);i++){
      inv[i]->remove_property("already_there");
      inv[i]->set_property("already_there",caster->query_name());
   }
   glyph->set_mycaster(caster->query_name());
   glyph->move(environment(caster));
   if(!objectp(glyph)) {
      tell_object(caster,"%^BOLD%^RED%^Something is wrong that "
          "a wiz might want to look at!");
      dest_effect();
      return;
   }
   int_bonus = caster->query_stats("wisdom");
   int_bonus = (int_bonus - 10) / 2;
   glyph->set_glyph_power(CLEVEL + int_bonus);
   exits = environment(caster)->query_exits();
   for(i=0;i<sizeof(exits);i++){
      room = find_object_or_load(environment(caster)->query_exit(exits[i]));
      if(!objectp(room)) break;
      mini_me = new("/d/magic/obj/mini_snare");
      mini_me->set_main_ob(glyph);
      mini_me->set_mycaster(caster->query_name());
      mini_me->set_myroom(place);
      mini_me->set_glyph_power(CLEVEL + int_bonus);
      glyph->add_mini_me(mini_me);
      mini_me->move(room);
   }
   duration = 9 * (int)CLEVEL * ROUND_LENGTH;
   glyph->set_myroom(place);
   addSpellToCaster();
   caster->set_property("glyphed",TO);
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
   return;
}

void dest_effect() {
    if (!objectp(place)) {
        TO->remove();
        return;
    }
    if(objectp(glyph)) glyph->self_destruct();
    if(objectp(caster)) caster->remove_property("glyphed");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
