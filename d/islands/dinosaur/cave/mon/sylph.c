#include <std.h>
inherit MONSTER;

void create(){
    ::create();
    set_name("sylph");
    set_id( ({"sylph"}) );
    set_short("Sylph");
    set_long(
      "This small beautiful winged woman floats easily on the air in front of you.  Two small wings like dragonfly wings shimmering iridescent in the light flutter behind her, as her long blue hair waves in the wind."
    );
    set_gender("female");
    set_race("sylph");
    set_body_type("humanoid");
    add_limb("left wing", "torso", 0,0,0);
    add_limb("right wing", "torso", 0,0,0);
    set_hd(8,1);
    set_hp(75+random(25));
    add_money("gold", random(100));
    add_money("platinum", random(10));
    set_alignment(5);
    set_func_chance(100);
    set_funcs( ({"spellcast", "summon"}) );
}

void hide(object targ){
   if(TO->query_invis()) return;

    tell_room(ETO, "The sylph closes her eyes and disapears!");
    TO->set_invis();
    TO->run_away();
    TO->run_away();
}

void summon(object targ){
    object ob;

    tell_room(ETO, "The sylph closes her eyes, and summons an air elemental!");
    set_funcs( ({"spellcast"}) );
    ob = new("/d/magic/mon/priest_aelemental");
    ob->move(ETO);
    ob->force_me("kill "+targ->query_name());
}

void spellcast(object targ){
    int x;

    x = random(5);
    switch(x){
    case 0:
      new("/cmds/spells/m/_magic_missile")->use_spell(TO, targ->query_name(), 12, 100, "mage");
      break;
    case 1:
      new("/cmds/spells/r/_ray_of_enfeeblement")->use_spell(TO, targ->query_name(), 12, 100, "mage");
      break;
    case 2:
      new("/cmds/spells/w/_web")->use_spell(TO, targ->query_name(), 12, 100, "mage");
      break;
    case 3:
      new("/cmds/spells/i/_ice_storm")->use_spell(TO, targ->query_name(), 12, 100, "mage");
      break;
    case 4:
      new("/cmds/spells/h/_hold_person")->use_spell(TO, targ->query_name(), 12, 100, "mage");
      break;
    case 5:
      new("/cmds/spells/b/_blink")->use_spell(TO, TO->query_name(), 12, 100, "mage");
      break;
    }
}
