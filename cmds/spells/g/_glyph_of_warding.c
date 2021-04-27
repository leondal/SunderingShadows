//Glyph of Warding
//Creation domain spell
//Based in part on protection from scrying by Thorn
//~Circe~ 12/31/07

#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object glyph;

void create() {
    ::create();
    set_spell_name("glyph of warding");
    set_spell_level(([ "cleric" : 3, "inquisitor" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS glyph of warding");
    set_description("By casting this spell, the priest uses his powers of generation to create a mystical glyph that will "
"protect a small circle around the area in which he stands.  The glyph will alert the caster should any creature enter "
"the area protected by the glyph, and it will deliver a bit of a shock to the one who does.  Any creature already within "
"the protected area may leave without disturbing the glyph.  If a creature was within the glyph when it was created, he "
"or she may enter again without triggering the protective response.\n\nTypically, priests have been known to use this "
"spell to protect areas with treasure or to help ensure privacy.  Because the glyph generates energy that protects a "
"circle, it will guard all exits in a room.  However - like a circle - when it has been breached once, the energy will "
"dissipate, and the spell will end.  Additionally, thieves have a chance to search out and disable glyphs, though it does "
"take active concentration on their part.  A thief must make the search in the room preceding the room the glyph is "
"thought to be in.\n\nA priest may concentrate on only one glyph at a time, but he does not have to remain in the room "
"for the glyph to remain.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("glyphed")){
      tell_object(caster,"You already have a glyph under your control!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
   return "%^RESET%^%^ORANGE%^"+caster->QCN+" grasps "+caster->QP+" "+
      "holy symbol and traces %^BOLD%^%^CYAN%^runes %^RESET%^%^ORANGE%^"+
      "in the air.%^RESET%^";
}

void spell_effect(int prof) {
   int int_bonus,i,duration;
   object temp, *inv, room, mini_me;
   string *exits;

   ::spell_effect();
   place = PLACE;
   caster = CASTER;
   if(present("glyphx111")) {
      tell_object(caster,"%^BOLD%^RED%^The present glyph of warding "+
         "repels the magic of the one you are trying to cast!%^RESET%^");
        if(objectp(TO)) TO->remove();
      return;
   }
   tell_object(caster,"%^RESET%^%^ORANGE%^You grasp your holy "+
      "symbol and trace %^BOLD%^%^CYAN%^runes %^RESET%^%^ORANGE%^in "+
      "the air, calling upon the power of your deity.%^RESET%^");
   tell_room(place,"%^BOLD%^%^WHITE%^Motes of light dance and "+
      "coalesce, forming a shimmering %^CYAN%^glyph %^WHITE%^"+
      "that flashes into being and settles on the ground before "+
      "disappearing.%^RESET%^");
   caster->set_paralyzed(5,"You are concentrating on the glyph!");
   glyph = new("/d/magic/obj/glyphofwarding.c");
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
      mini_me = new("/d/magic/obj/mini_glyph");
      mini_me->set_main_ob(glyph);
      mini_me->set_mycaster(caster->query_name());
      mini_me->set_myroom(place);
      mini_me->set_glyph_power(CLEVEL + int_bonus);
      glyph->add_mini_me(mini_me);
      mini_me->move(room);
   }
   glyph->set_myroom(place);
   addSpellToCaster();
   caster->set_property("glyphed",TO);
   spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
   set_end_time();
   call_out("dest_effect",spell_duration);
   return;
}

void dest_effect() {

    if(objectp(glyph)) glyph->self_destruct();
    if(objectp(caster)) caster->remove_property("glyphed");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
