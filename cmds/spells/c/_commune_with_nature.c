#include <std.h>
#include <daemons.h>
inherit SPELL;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("commune with nature");
    set_spell_level(([ "ranger" : 4, "druid" : 4, "cleric" : 4 ]));
    set_domains("animal");
    set_spell_sphere("divination");
    set_syntax("cast CLASS commune with nature");
    set_description("This spell allows the ranger to become one with nature, sensing abnormal presences within their "
"surroundings. ");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string(){
     tell_object(caster,"%^GREEN%^You place your hands upon the ground and concentrate, casting your senses out through "
"the earth.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" places "+caster->QP+" hands upon the ground and concentrates.",caster);
    return "display";
}

void spell_effect(int prof){
    string myloc, *exploded, mydir, terrain;
    object *peo, *targets;
    int i, j;

    if(!objectp(place)) {
      dest_effect();
      return;
    }

    myloc = base_name(place);
    exploded = explode(myloc,"/");
    if(!sizeof(exploded)) {
      dest_effect();
      return;
    }
    exploded -= ({ exploded[(sizeof(exploded))-1] });
    if(!sizeof(exploded)) {
      dest_effect();
      return;
    }
    mydir = "/"+implode(exploded,"/")+"/";

    spell_successful();
    terrain = place->query_terrain();
    if (!terrain || terrain == "" || isCivilization(terrain)) {
      tell_object(caster,"%^BOLD%^%^GREEN%^The lack of true wilderness here dulls your senses!%^RESET%^");
      dest_effect();
      return;
    }
    if(place->is_temple() || place->is_dock()) {
      tell_object(caster,"%^BOLD%^%^GREEN%^Something unsettling seems to dull your senses here.%^RESET%^");
      dest_effect();
      return;
    }
    peo = ({});
    peo += users();
    if(member_array(caster,peo) != -1) peo -= ({ caster });
    if(!sizeof(peo)) {
      tell_object(caster,"%^BOLD%^%^GREEN%^You can sense no intruders nearby!%^RESET%^");
      dest_effect();
      return;
    }
    targets = ({});
    for(i=0;i<sizeof(peo);i++) {
      if(!objectp(peo[i])) continue;
      if(!objectp(environment(peo[i]))) continue;
      if(peo[i]->query_true_invis()) continue;
      if(strsrch(base_name(environment(peo[i])),mydir) != -1) targets += ({ peo[i] });
    }
    targets = filter_array(targets,"is_non_immortal",FILTERS_D);
    if(!sizeof(targets)) {
      tell_object(caster,"%^BOLD%^%^GREEN%^You can sense no intruders nearby!%^RESET%^");
      dest_effect();
      return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You can sense the presence of interlopers nearby...\n%^RESET%^");
    for(i=0;i<sizeof(targets);i++) {
      tell_object(caster,""+targets[i]->getWholeDescriptivePhrase()+"%^RESET%^ is near "
+(environment(targets[i]))->query_short()+"%^RESET%^.\n");
    }
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
