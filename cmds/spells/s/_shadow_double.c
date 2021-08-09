//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void make_sword();

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("shadow double");
    set_spell_level(([ "innate" : 7, "monk" : 13, "psion" : 8, ]));
    set_spell_sphere("illusion");
    set_discipline("egoist");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS shadow double");
    set_description("This spell will conjure a ghostly double of the caster, drawn from his or her own "
"shadow. The shadow will automatically follow and protect you. Should you lose it, though, simply go into the room with "
"it and <command shadow to follow>. This is a greater summons, and cannot be used simultaneously with other greater summons.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
   if(caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster,"%^CYAN%^You are incapable of controling two such powerful summonings.%^RESET%^");
        return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^MAGENTA%^You make a brief, subtle motion to the side with one hand.%^RESET%^");
   tell_room(place,"%^MAGENTA%^"+caster->QCN+" makes a brief, elusory motion to the side with one hand.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
	if(!objectp(environment(caster)))	{
		dest_effect();
		return;
	}
	place = environment(caster);
      make_sword();
      addSpellToCaster();
}

void make_sword() {
    object ob, thing;

    tell_object(caster,"%^MAGENTA%^Your shadow moves, as if of its own accord, and rises to stand beside you.%^RESET%^");
    tell_room(place,"%^MAGENTA%^You see "+caster->QCN+"'s shadow move, as if of its own accord, and rise to stand beside "+caster->QO+".%^RESET%^",caster);
    control = new("/d/magic/obj/shadowremote");
    control->set_caster(caster);
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    ob=new("/d/magic/obj/ashadow.c");
    control->set_sword(ob);
    caster->add_follower(ob);
    ob->set_gender(caster->query_gender());
    ob->set_alignment(caster->query_alignment());

    ob->set_heart(1);
    ob->set_stats("intelligence",8);
    ob->set_stats("dexterity",20);
    ob->set_stats("strength",20);
    ob->set_attack_limbs(({"left hand","right hand"}));
    ob->set_base_damage_type("slashing");
    ob->set_attacks_num(clevel/12+1);
    ob->set_damage(clevel/4,6);
    ob->set_overall_ac(-clevel);
    ob->set_hd(clevel,12);
    ob->set_stats("strength",15);
    ob->set_max_hp(clevel*12+100);
    ob->set_hp(ob->query_max_hp());
    ob->set_caster(caster);
    ob->move(environment(caster));
    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_property("effective_enchantment", ((int)CLEVEL / 7));
    caster->set_property("mages_sword",ob);
    return;
}

void dest_effect() {
    object sword;

    if (objectp(caster)) {
        tell_room(environment(caster),"%^CYAN%^The shadowy being beside "+caster->QCN+" fades away.%^RESET%^",caster);
        tell_object(caster,"%^CYAN%^The shadow fades away.%^RESET%^");
    }

    if(objectp(control)) {
		if (objectp(sword = control->query_sword())){
			sword->remove();
			destruct(control);
		}
    }
    if(objectp(caster)) { caster->remove_property("mages_sword"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
